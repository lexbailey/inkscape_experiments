/*
 * Filter effect selection selection widget
 *
 * Author:
 *   Nicholas Bishop <nicholasbishop@gmail.com>
 *
 * Copyright (C) 2007 Authors
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include "filter-effect-chooser.h"
#include <glibmm/i18n.h>

#include "desktop.h"
#include "desktop-handles.h"
#include "document.h"
#include "inkscape.h"

namespace Inkscape {
namespace UI {
namespace Widget {

SimpleFilterModifier::SimpleFilterModifier(int flags)
    : _hb_blur(false, 0),
      _lb_blend(_("Blend mode:")),
      _lb_blur(_("_Blur:")),
      _blend(BlendModeConverter, SP_ATTR_INVALID, false),
      _blur(0, 0, 100, 1, 0.01, 1)
{
    _flags = flags;

    if (flags & BLEND) {
        add(_hb_blend);
        _hb_blend.pack_start(_lb_blend);
        _hb_blend.pack_start(_blend);
    }
    if (flags & BLUR) {
        add(_hb_blur);
        /*
         * Hack to get a min size of label, but still be able to expand if needed
         * Should match ObjectCompositeSettings::_opacity_label
         */
        if (_lb_blur.get_text().length() < 7) {
            _lb_blur.set_width_chars(7);
        }
        #if WITH_GTKMM_2_22
            _lb_blur.set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
        #else
            _lb_blur.set_alignment(Gtk::ALIGN_RIGHT, Gtk::ALIGN_CENTER);
        #endif
        _hb_blur.pack_start(_lb_blur, false, false, 0);
        _hb_blur.pack_start(_blur, true, true, 0);
    }

    show_all_children();

    _hb_blend.set_spacing(12);
    _lb_blend.set_use_underline();
    _lb_blend.set_mnemonic_widget(_blend);
    _lb_blur.set_use_underline();
    _lb_blur.set_mnemonic_widget(_blur.get_scale());
    _blend.signal_changed().connect(signal_blend_blur_changed());
    _blur.signal_value_changed().connect(signal_blend_blur_changed());
}

sigc::signal<void>& SimpleFilterModifier::signal_blend_blur_changed()
{
    return _signal_blend_blur_changed;
}

const Glib::ustring SimpleFilterModifier::get_blend_mode()
{
    if (!(_flags & BLEND)) {
        return "normal";
    }
    if (_blend.get_active_row_number() == 5) {
        return "normal";
    } else {
        const Util::EnumData<Inkscape::Filters::FilterBlendMode> *d = _blend.get_active_data();
        if (d) {
            return _blend.get_active_data()->key;
        } else
            return "normal";
    }
}

void SimpleFilterModifier::set_blend_mode(const int val)
{
    _blend.set_active(val);
}

double SimpleFilterModifier::get_blur_value() const
{
    return _blur.get_value();
}

void SimpleFilterModifier::set_blur_value(const double val)
{
    _blur.set_value(val);
}

void SimpleFilterModifier::set_blur_sensitive(const bool s)
{
    _blur.set_sensitive(s);
}

}
}
}

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
