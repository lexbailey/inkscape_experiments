#ifndef SEEN_SP_MEASURING_CONTEXT_H
#define SEEN_SP_MEASURING_CONTEXT_H

/*
 * Our fine measuring tool
 *
 * Authors:
 *   Felipe Correa da Silva Sanches <juca@members.fsf.org>
 *   Jabiertxo Arraiza <jabier.arraiza@marker.es>
 * Copyright (C) 2011 Authors
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */
#include <stddef.h>
#include <sigc++/sigc++.h>
#include "ui/tools/tool-base.h"
#include <2geom/point.h>
#include "display/canvas-text.h"
#include <boost/optional.hpp>

#define SP_MEASURE_CONTEXT(obj) (dynamic_cast<Inkscape::UI::Tools::MeasureTool*>((Inkscape::UI::Tools::ToolBase*)obj))
#define SP_IS_MEASURE_CONTEXT(obj) (dynamic_cast<const Inkscape::UI::Tools::MeasureTool*>((const Inkscape::UI::Tools::ToolBase*)obj) != NULL)

class SPKnot;

namespace Inkscape {
namespace UI {
namespace Tools {

class MeasureTool : public ToolBase {
public:
    MeasureTool();
    virtual ~MeasureTool();

    static const std::string prefsPath;

    virtual void finish();
    virtual bool root_handler(GdkEvent* event);
    virtual void showCanvasItems();
    virtual void showCanvasItems(Geom::Point start_point, Geom::Point end_point, bool to_item = false, Inkscape::XML::Node *measure_repr = NULL);
    virtual void reverseKnots();
    virtual void toMarkDimension();
    virtual void toItem();
    virtual void reset();
    virtual void setMarkers();
    virtual void setMarker(bool isStart);
    virtual const std::string& getPrefsPath();
    void setPoint(Geom::Point origin, Inkscape::XML::Node *measure_repr);
    void setLine(Geom::Point start_point,Geom::Point end_point, bool markers = false, guint32 *color = NULL, Inkscape::XML::Node *measure_repr = NULL);
    void setLabelText(const char *value, Geom::Point pos, double fontsize, Geom::Coord angle, guint32 *background = NULL, Inkscape::XML::Node *measure_repr = NULL, CanvasTextAnchorPositionEnum text_anchor = TEXT_ANCHOR_CENTER );
    void knotStartMovedHandler(SPKnot */*knot*/, Geom::Point const &ppointer, guint state);
    void knotEndMovedHandler(SPKnot */*knot*/, Geom::Point const &ppointer, guint state);
    void knotUngrabbedHandler(SPKnot */*knot*/,  unsigned int /*state*/);

private:
    SPCanvasItem* grabbed;
    Geom::Point start_point;
    boost::optional<Geom::Point> explicitBase;
    boost::optional<Geom::Point> last_end;
    SPKnot *knot_start;
    SPKnot *knot_end;
    sigc::connection _knot_start_moved_connection;
    sigc::connection _knot_start_ungrabbed_connection;
    sigc::connection _knot_end_moved_connection;
    sigc::connection _knot_end_ungrabbed_connection;
};

}
}
}

#endif // SEEN_SP_MEASURING_CONTEXT_H

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:fileencoding=utf-8:textwidth=99 :
