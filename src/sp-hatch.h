/** @file
 * SVG <hatch> implementation
 *//*
 * Author:
 *   Tomasz Boczkowski <penginsbacon@gmail.com>
 *
 * Copyright (C) 2014 Tomasz Boczkowski
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#ifndef SEEN_SP_HATCH_H
#define SEEN_SP_HATCH_H

#include <list>
#include <stddef.h>
#include <glibmm/ustring.h>
#include <sigc++/connection.h>

#include "svg/svg-length.h"
#include "svg/svg-angle.h"
#include "sp-paint-server.h"
#include "uri-references.h"

class SPHatchReference;
class SPHatchPath;
class SPItem;

namespace Inkscape {

class Drawing;
class DrawingPattern;

namespace XML {

class Node;

}
}

#define SP_HATCH(obj) (dynamic_cast<SPHatch*>((SPObject*)obj))
#define SP_IS_HATCH(obj) (dynamic_cast<const SPHatch*>((SPObject*)obj) != NULL)

class SPHatch : public SPPaintServer {
public:
    enum HatchUnits {
        UNITS_USERSPACEONUSE,
        UNITS_OBJECTBOUNDINGBOX
    };

    SPHatch();
	virtual ~SPHatch();

    /* Reference (href) */
	Glib::ustring href;
    SPHatchReference *ref;

    gdouble x() const;
    gdouble y() const;
    gdouble pitch() const;
    gdouble rotate() const;
    HatchUnits hatchUnits() const;
    HatchUnits hatchContentUnits() const;
    Geom::Affine const &hatchTransform() const;
    SPHatch *rootHatch(); //TODO: const

    bool isValid() const;

    Inkscape::DrawingPattern *show(Inkscape::Drawing &drawing, unsigned int key);
    void hide(unsigned int key);
	virtual cairo_pattern_t* pattern_new(cairo_t *ct, Geom::OptRect const &bbox, double opacity);

	void setBBox(unsigned int key, Geom::OptRect const &bbox);

protected:
	virtual void build(SPDocument* doc, Inkscape::XML::Node* repr);
	virtual void release();
	virtual void child_added(Inkscape::XML::Node* child, Inkscape::XML::Node* ref);
	virtual void set(unsigned int key, const gchar* value);
	virtual void update(SPCtx* ctx, unsigned int flags);
	virtual void modified(unsigned int flags);

private:
    struct View {
        View(Inkscape::DrawingPattern *arenaitem, int key);
        //Do not delete arenaitem in destructor.

        Inkscape::DrawingPattern *arenaitem;
        Geom::OptRect bbox;
        unsigned int key;
    };
    typedef std::vector<SPHatchPath *>::iterator ChildIterator;
    typedef std::vector<SPHatchPath const *>::const_iterator ConstChildIterator;
    typedef std::list<View>::iterator ViewIterator;
    void _updateView(View &view);

    static bool _hasHatchPatchChildren(SPHatch const* hatch);

	void _children(std::vector<SPHatchPath*>& l);
	void _children(std::vector<SPHatchPath const *>& l) const;

	Geom::OptInterval _calculateStripExtents(Geom::OptRect bbox);

	/**
	Gets called when the hatch is reattached to another <hatch>
	*/
	void _onRefChanged(SPObject *old_ref, SPObject *ref);

	/**
	Gets called when the referenced <hatch> is changed
	*/
	void _onRefModified(SPObject *ref, guint flags);

    /* patternUnits and patternContentUnits attribute */
    HatchUnits _hatchUnits : 1;
    bool _hatchUnits_set : 1;
    HatchUnits _hatchContentUnits : 1;
    bool _hatchContentUnits_set : 1;
    /* hatchTransform attribute */
    Geom::Affine _hatchTransform;
    bool _hatchTransform_set : 1;
    /* Strip */
    SVGLength _x;
    SVGLength _y;
    SVGLength _pitch;
    SVGAngle _rotate;

    sigc::connection _modified_connection;

    std::list<View> _display;
};


class SPHatchReference : public Inkscape::URIReference {
public:
    SPHatchReference (SPObject *obj) : URIReference(obj) {}
    SPHatch *getObject() const {
        return reinterpret_cast<SPHatch *>(URIReference::getObject());
    }

protected:
    virtual bool _acceptObject(SPObject *obj) const {
        return SP_IS_HATCH (obj);
    }
};

#endif // SEEN_SP_HATCH_H

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
