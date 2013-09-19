/*  This file is part of the libdepixelize project
    Copyright (C) 2013 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

    GNU Lesser General Public License Usage
    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation; either version 2.1 of the License, or (at your
    option) any later version.
    You should have received a copy of the GNU Lesser General Public License
    along with this library.  If not, see <http://www.gnu.org/licenses/>.

    GNU General Public License Usage
    Alternatively, this library may be used under the terms of the GNU General
    Public License as published by the Free Software Foundation, either version
    2 of the License, or (at your option) any later version.
    You should have received a copy of the GNU General Public License along with
    this library.  If not, see <http://www.gnu.org/licenses/>.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
*/

#ifndef LIBDEPIXELIZE_TRACER_SPLINES_PRIV_H
#define LIBDEPIXELIZE_TRACER_SPLINES_PRIV_H

#include "../splines.h"
#include "homogeneoussplines.h"

namespace Tracer {

template<class T>
Geom::Point to_geom_point(Point<T> p)
{
    return Geom::Point(p.x, p.y);
}

template<class T>
Geom::Path worker_helper(const std::vector< Point<T> > &source, bool optimize)
{
    typedef Geom::LineSegment Line;
    typedef Geom::QuadraticBezier Quad;
    typedef typename std::vector< Point<T> >::const_iterator iterator;

    iterator it = source.begin();
    Geom::Path ret(to_geom_point((source.back() + *it) / 2));

    for ( iterator end = --source.end() ; it != end ; ++it ) {
        Point<T> next = *(it + 1);
        Point<T> middle = (*it + next) / 2;

        if ( !it->smooth ) {
            // TODO: remove redundant colinear points
            ret.appendNew<Line>(Geom::Point(it->x, it->y));
            ret.appendNew<Line>(Geom::Point(middle.x, middle.y));
        } else {
            ret.appendNew<Quad>(Geom::Point(it->x, it->y),
                                Geom::Point(middle.x, middle.y));
        }
    }

    {
        Point<T> next = source.front();
        Point<T> middle = (*it + next) / 2;

        if ( !it->smooth ) {
            ret.appendNew<Line>(Geom::Point(it->x, it->y));
            ret.appendNew<Line>(Geom::Point(middle.x, middle.y));
        } else {
            ret.appendNew<Quad>(Geom::Point(it->x, it->y),
                                Geom::Point(middle.x, middle.y));
        }
    }

    return ret;
}

/**
 * It should be used by worker threads. Convert only one object.
 */
template<class T>
void worker(const typename HomogeneousSplines<T>::Polygon &source,
            Splines::Path &dest, bool optimize)
{
    dest.pathVector.reserve(source.holes.size() + 1);

    for ( int i = 0 ; i != 4 ; ++i )
        dest.rgba[i] = source.rgba[i];

    dest.pathVector.push_back(worker_helper(source.vertices, optimize));

    for ( typename std::vector< std::vector< Point<T> > >::const_iterator
              it = source.holes.begin(), end = source.holes.end()
              ; it != end ; ++it ) {
        dest.pathVector.push_back(worker_helper(*it, optimize));
    }
}

template<typename T>
Splines::Splines(const SimplifiedVoronoi<T> &diagram)
{
    _paths.reserve(diagram.size());

    for ( typename SimplifiedVoronoi<T>::const_iterator it = diagram.begin()
              , end = diagram.end() ; it != end ; ++it ) {
        Path path;

        path.pathVector
            .push_back(Geom::Path(to_geom_point(it->vertices.front())));

        for ( typename std::vector< Point<T> >::const_iterator
                  it2 = it->vertices.begin(), end2 = it->vertices.end()
                  ; it2 != end2 ; ++it2 ) {
            path.pathVector.back()
                .appendNew<Geom::LineSegment>(Geom::Point(it2->x, it2->y));
        }

        for ( int i = 0 ; i != 4 ; ++i )
            path.rgba[i] = it->rgba[i];

        _paths.push_back(path);
    }
}

template<class T>
Splines::Splines(const HomogeneousSplines<T> &homogeneousSplines,
                 bool optimize, int nthreads) :
    _paths(homogeneousSplines.size()),
    _width(homogeneousSplines.width()),
    _height(homogeneousSplines.height())
{
    // TODO: It should be threaded
    iterator paths_it = begin();
    for ( typename HomogeneousSplines<T>::const_iterator
              it = homogeneousSplines.begin(), end = homogeneousSplines.end()
              ; it != end ; ++it, ++paths_it ) {
        worker<T>(*it, *paths_it, optimize);
    }
}

} // namespace Tracer

#endif // LIBDEPIXELIZE_TRACER_SPLINES_PRIV_H

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99 :
