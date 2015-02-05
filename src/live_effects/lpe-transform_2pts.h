#ifndef INKSCAPE_LPE_TRANSFORM_2PTS_H
#define INKSCAPE_LPE_TRANSFORM_2PTS_H

/** \file
 * LPE "Transform through 2 points" implementation
 */

/*
 * Authors:
 *   
 *
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include "live_effects/effect.h"
#include "live_effects/lpegroupbbox.h"
#include "live_effects/parameter/parameter.h"
#include "live_effects/parameter/togglebutton.h"
#include "live_effects/parameter/pointreseteable.h"

namespace Inkscape {
namespace LivePathEffect {

class LPETransform2Pts : public Effect, GroupBBoxEffect {
public:
    LPETransform2Pts(LivePathEffectObject *lpeobject);
    virtual ~LPETransform2Pts();

    virtual void doOnApply (SPLPEItem const* lpeitem);

    virtual Geom::Piecewise<Geom::D2<Geom::SBasis> > doEffect_pwd2 (Geom::Piecewise<Geom::D2<Geom::SBasis> > const & pwd2_in);

    virtual void doBeforeEffect (SPLPEItem const* lpeitem);

    void updateIndex();

    virtual Gtk::Widget *newWidget();

    void reset();

protected:
    virtual void addCanvasIndicators(SPLPEItem const *lpeitem, std::vector<Geom::PathVector> &hp_vec);

private:
    ToggleButtonParam fromOriginalWidth;
    PointReseteableParam start;
    PointReseteableParam end;
    ScalarParam firstKnot;
    ScalarParam lastKnot;
    bool fromOriginalWidthToogler;
    Geom::Point A;
    Geom::Point B;
    SPCurve * c;
    bool appandedPath;
    LPETransform2Pts(const LPETransform2Pts&);
    LPETransform2Pts& operator=(const LPETransform2Pts&);
};

} //namespace LivePathEffect
} //namespace Inkscape

#endif

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4 :
