/** @file
 * @brief SVG flood filter effect
 *//*
 * Authors:
 *   Hugo Rodrigues <haa.rodrigues@gmail.com>
 *
 * Copyright (C) 2006 Hugo Rodrigues
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#ifndef SP_FEFLOOD_H_SEEN
#define SP_FEFLOOD_H_SEEN

#include "sp-filter-primitive.h"
#include "svg/svg-icc-color.h"

#define SP_TYPE_FEFLOOD (sp_feFlood_get_type())
#define SP_FEFLOOD(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SP_TYPE_FEFLOOD, SPFeFlood))
#define SP_FEFLOOD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), SP_TYPE_FEFLOOD, SPFeFloodClass))
#define SP_IS_FEFLOOD(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), SP_TYPE_FEFLOOD))
#define SP_IS_FEFLOOD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), SP_TYPE_FEFLOOD))

class SPFeFloodClass;

class CFeFlood;

class SPFeFlood : public SPFilterPrimitive {
public:
	CFeFlood* cfeflood;

    guint32 color;
    SVGICCColor *icc;
    double opacity;
};

struct SPFeFloodClass {
    SPFilterPrimitiveClass parent_class;
};

class CFeFlood : public CFilterPrimitive {
public:
	CFeFlood(SPFeFlood* flood);
	virtual ~CFeFlood();

	virtual void onBuild(SPDocument* doc, Inkscape::XML::Node* repr);
	virtual void onRelease();

	virtual void onSet(unsigned int key, const gchar* value);

	virtual void onUpdate(SPCtx* ctx, unsigned int flags);

	virtual Inkscape::XML::Node* onWrite(Inkscape::XML::Document* doc, Inkscape::XML::Node* repr, guint flags);

	virtual void onBuildRenderer(Inkscape::Filters::Filter* filter);

private:
	SPFeFlood* spfeflood;
};

GType sp_feFlood_get_type();


#endif /* !SP_FEFLOOD_H_SEEN */

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
