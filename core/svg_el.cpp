#include <sstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdio>
#include "svg_el.h"

namespace Lewzen {
    SVGElement::SVGElement() {
        _id = STR_NULL;
        _lang = STR_NULL;
        _tabindex = STR_NULL;
        _xmlZbase = STR_NULL;
        _xmlZlang = STR_NULL;
        _xmlZspace = STR_NULL;
        _class = STR_NULL;
        _style = STR_NULL;
        _onbegin = STR_NULL;
        _onend = STR_NULL;
        _onrepeat = STR_NULL;
        _onabort = STR_NULL;
        _onerror = STR_NULL;
        _onresize = STR_NULL;
        _onscroll = STR_NULL;
        _onunload = STR_NULL;
        _oncopy = STR_NULL;
        _oncut = STR_NULL;
        _onpaste = STR_NULL;
        _oncancel = STR_NULL;
        _oncanplay = STR_NULL;
        _oncanplaythrough = STR_NULL;
        _onchange = STR_NULL;
        _onclick = STR_NULL;
        _onclose = STR_NULL;
        _oncuechange = STR_NULL;
        _ondblclick = STR_NULL;
        _ondrag = STR_NULL;
        _ondragend = STR_NULL;
        _ondragenter = STR_NULL;
        _ondragleave = STR_NULL;
        _ondragover = STR_NULL;
        _ondragstart = STR_NULL;
        _ondrop = STR_NULL;
        _ondurationchange = STR_NULL;
        _onemptied = STR_NULL;
        _onended = STR_NULL;
        _onfocus = STR_NULL;
        _oninput = STR_NULL;
        _oninvalid = STR_NULL;
        _onkeydown = STR_NULL;
        _onkeypress = STR_NULL;
        _onkeyup = STR_NULL;
        _onload = STR_NULL;
        _onloadeddata = STR_NULL;
        _onloadedmetadata = STR_NULL;
        _onloadstart = STR_NULL;
        _onmousedown = STR_NULL;
        _onmouseenter = STR_NULL;
        _onmouseleave = STR_NULL;
        _onmousemove = STR_NULL;
        _onmouseout = STR_NULL;
        _onmouseover = STR_NULL;
        _onmouseup = STR_NULL;
        _onmousewheel = STR_NULL;
        _onpause = STR_NULL;
        _onplay = STR_NULL;
        _onplaying = STR_NULL;
        _onprogress = STR_NULL;
        _onratechange = STR_NULL;
        _onreset = STR_NULL;
        _onseeked = STR_NULL;
        _onseeking = STR_NULL;
        _onselect = STR_NULL;
        _onshow = STR_NULL;
        _onstalled = STR_NULL;
        _onsubmit = STR_NULL;
        _onsuspend = STR_NULL;
        _ontimeupdate = STR_NULL;
        _ontoggle = STR_NULL;
        _onvolumechange = STR_NULL;
        _onwaiting = STR_NULL;
        _onactivate = STR_NULL;
        _onfocusin = STR_NULL;
        _onfocusout = STR_NULL;
        _alignment_baseline = STR_NULL;
        _baseline_shift = STR_NULL;
        _clip_path = STR_NULL;
        _clip_rule = STR_NULL;
        _color = STR_NULL;
        _color_interpolation = STR_NULL;
        _color_interpolation_filters = STR_NULL;
        _color_profile = STR_NULL;
        _color_rendering = STR_NULL;
        _cursor = STR_NULL;
        _d = STR_NULL;
        _direction = STR_NULL;
        _display = STR_NULL;
        _dominant_baseline = STR_NULL;
        _enable_background = STR_NULL;
        _fill = STR_NULL;
        _fill_opacity = STR_NULL;
        _fill_rule = STR_NULL;
        _filter = STR_NULL;
        _flood_color = STR_NULL;
        _flood_opacity = STR_NULL;
        _font_family = STR_NULL;
        _font_size = STR_NULL;
        _font_size_adjust = STR_NULL;
        _font_stretch = STR_NULL;
        _font_style = STR_NULL;
        _font_variant = STR_NULL;
        _font_weight = STR_NULL;
        _glyph_orientation_horizontal = STR_NULL;
        _glyph_orientation_vertical = STR_NULL;
        _image_rendering = STR_NULL;
        _kerning = STR_NULL;
        _letter_spacing = STR_NULL;
        _lighting_color = STR_NULL;
        _marker_end = STR_NULL;
        _marker_mid = STR_NULL;
        _marker_start = STR_NULL;
        _mask = STR_NULL;
        _opacity = STR_NULL;
        _overflow = STR_NULL;
        _pointer_events = STR_NULL;
        _shape_rendering = STR_NULL;
        _solid_color = STR_NULL;
        _solid_opacity = STR_NULL;
        _stop_color = STR_NULL;
        _stop_opacity = STR_NULL;
        _stroke = STR_NULL;
        _stroke_dasharray = STR_NULL;
        _stroke_dashoffset = STR_NULL;
        _stroke_linecap = STR_NULL;
        _stroke_linejoin = STR_NULL;
        _stroke_miterlimit = STR_NULL;
        _stroke_opacity = STR_NULL;
        _stroke_width = STR_NULL;
        _text_anchor = STR_NULL;
        _text_decoration = STR_NULL;
        _text_rendering = STR_NULL;
        _transform = STR_NULL;
        _unicode_bidi = STR_NULL;
        _vector_effect = STR_NULL;
        _visibility = STR_NULL;
        _word_spacing = STR_NULL;
        _writing_mode = STR_NULL;
        _raw_HTML = STR_NULL;

        _attribute_hash = 0;
        _inner_hash = 0;
        _outer_hash = rand();
    }

    const std::string SVGElement::get_tag() const {
        return "?";
    }
    const std::string SVGElement::get_id() const {
        return _id;
    }
    void SVGElement::set_id(const std::string &id) {
        _id = id;
        update_attribute_hash();
    }
    const std::string SVGElement::get_lang() const {
        return _lang;
    }
    void SVGElement::set_lang(const std::string &lang) {
        _lang = lang;
        update_attribute_hash();
    }
    const std::string SVGElement::get_tabindex() const {
        return _tabindex;
    }
    void SVGElement::set_tabindex(const std::string &tabindex) {
        _tabindex = tabindex;
        update_attribute_hash();
    }
    const std::string SVGElement::get_xmlZbase() const {
        return _xmlZbase;
    }
    void SVGElement::set_xmlZbase(const std::string &xmlZbase) {
        _xmlZbase = xmlZbase;
        update_attribute_hash();
    }
    const std::string SVGElement::get_xmlZlang() const {
        return _xmlZlang;
    }
    void SVGElement::set_xmlZlang(const std::string &xmlZlang) {
        _xmlZlang = xmlZlang;
        update_attribute_hash();
    }
    const std::string SVGElement::get_xmlZspace() const {
        return _xmlZspace;
    }
    void SVGElement::set_xmlZspace(const std::string &xmlZspace) {
        _xmlZspace = xmlZspace;
        update_attribute_hash();
    }
    const std::string SVGElement::get_class() const {
        return _class;
    }
    void SVGElement::set_class(const std::string &cls) {
        _class = cls;
        update_attribute_hash();
    }
    const std::string SVGElement::get_style() const {
        return _style;
    }
    void SVGElement::set_style(const std::string &style) {
        _style = style;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onbegin() const {
        return _onbegin;
    }
    void SVGElement::set_onbegin(const std::string &onbegin) {
        _onbegin = onbegin;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onend() const {
        return _onend;
    }
    void SVGElement::set_onend(const std::string &onend) {
        _onend = onend;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onrepeat() const {
        return _onrepeat;
    }
    void SVGElement::set_onrepeat(const std::string &onrepeat) {
        _onrepeat = onrepeat;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onabort() const {
        return _onabort;
    }
    void SVGElement::set_onabort(const std::string &onabort) {
        _onabort = onabort;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onerror() const {
        return _onerror;
    }
    void SVGElement::set_onerror(const std::string &onerror) {
        _onerror = onerror;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onresize() const {
        return _onresize;
    }
    void SVGElement::set_onresize(const std::string &onresize) {
        _onresize = onresize;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onscroll() const {
        return _onscroll;
    }
    void SVGElement::set_onscroll(const std::string &onscroll) {
        _onscroll = onscroll;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onunload() const {
        return _onunload;
    }
    void SVGElement::set_onunload(const std::string &onunload) {
        _onunload = onunload;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncopy() const {
        return _oncopy;
    }
    void SVGElement::set_oncopy(const std::string &oncopy) {
        _oncopy = oncopy;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncut() const {
        return _oncut;
    }
    void SVGElement::set_oncut(const std::string &oncut) {
        _oncut = oncut;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onpaste() const {
        return _onpaste;
    }
    void SVGElement::set_onpaste(const std::string &onpaste) {
        _onpaste = onpaste;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncancel() const {
        return _oncancel;
    }
    void SVGElement::set_oncancel(const std::string &oncancel) {
        _oncancel = oncancel;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncanplay() const {
        return _oncanplay;
    }
    void SVGElement::set_oncanplay(const std::string &oncanplay) {
        _oncanplay = oncanplay;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncanplaythrough() const {
        return _oncanplaythrough;
    }
    void SVGElement::set_oncanplaythrough(const std::string &oncanplaythrough) {
        _oncanplaythrough = oncanplaythrough;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onchange() const {
        return _onchange;
    }
    void SVGElement::set_onchange(const std::string &onchange) {
        _onchange = onchange;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onclick() const {
        return _onclick;
    }
    void SVGElement::set_onclick(const std::string &onclick) {
        _onclick = onclick;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onclose() const {
        return _onclose;
    }
    void SVGElement::set_onclose(const std::string &onclose) {
        _onclose = onclose;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oncuechange() const {
        return _oncuechange;
    }
    void SVGElement::set_oncuechange(const std::string &oncuechange) {
        _oncuechange = oncuechange;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondblclick() const {
        return _ondblclick;
    }
    void SVGElement::set_ondblclick(const std::string &ondblclick) {
        _ondblclick = ondblclick;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondrag() const {
        return _ondrag;
    }
    void SVGElement::set_ondrag(const std::string &ondrag) {
        _ondrag = ondrag;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondragend() const {
        return _ondragend;
    }
    void SVGElement::set_ondragend(const std::string &ondragend) {
        _ondragend = ondragend;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondragenter() const {
        return _ondragenter;
    }
    void SVGElement::set_ondragenter(const std::string &ondragenter) {
        _ondragenter = ondragenter;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondragleave() const {
        return _ondragleave;
    }
    void SVGElement::set_ondragleave(const std::string &ondragleave) {
        _ondragleave = ondragleave;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondragover() const {
        return _ondragover;
    }
    void SVGElement::set_ondragover(const std::string &ondragover) {
        _ondragover = ondragover;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondragstart() const {
        return _ondragstart;
    }
    void SVGElement::set_ondragstart(const std::string &ondragstart) {
        _ondragstart = ondragstart;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondrop() const {
        return _ondrop;
    }
    void SVGElement::set_ondrop(const std::string &ondrop) {
        _ondrop = ondrop;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ondurationchange() const {
        return _ondurationchange;
    }
    void SVGElement::set_ondurationchange(const std::string &ondurationchange) {
        _ondurationchange = ondurationchange;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onemptied() const {
        return _onemptied;
    }
    void SVGElement::set_onemptied(const std::string &onemptied) {
        _onemptied = onemptied;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onended() const {
        return _onended;
    }
    void SVGElement::set_onended(const std::string &onended) {
        _onended = onended;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onfocus() const {
        return _onfocus;
    }
    void SVGElement::set_onfocus(const std::string &onfocus) {
        _onfocus = onfocus;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oninput() const {
        return _oninput;
    }
    void SVGElement::set_oninput(const std::string &oninput) {
        _oninput = oninput;
        update_attribute_hash();
    }
    const std::string SVGElement::get_oninvalid() const {
        return _oninvalid;
    }
    void SVGElement::set_oninvalid(const std::string &oninvalid) {
        _oninvalid = oninvalid;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onkeydown() const {
        return _onkeydown;
    }
    void SVGElement::set_onkeydown(const std::string &onkeydown) {
        _onkeydown = onkeydown;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onkeypress() const {
        return _onkeypress;
    }
    void SVGElement::set_onkeypress(const std::string &onkeypress) {
        _onkeypress = onkeypress;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onkeyup() const {
        return _onkeyup;
    }
    void SVGElement::set_onkeyup(const std::string &onkeyup) {
        _onkeyup = onkeyup;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onload() const {
        return _onload;
    }
    void SVGElement::set_onload(const std::string &onload) {
        _onload = onload;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onloadeddata() const {
        return _onloadeddata;
    }
    void SVGElement::set_onloadeddata(const std::string &onloadeddata) {
        _onloadeddata = onloadeddata;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onloadedmetadata() const {
        return _onloadedmetadata;
    }
    void SVGElement::set_onloadedmetadata(const std::string &onloadedmetadata) {
        _onloadedmetadata = onloadedmetadata;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onloadstart() const {
        return _onloadstart;
    }
    void SVGElement::set_onloadstart(const std::string &onloadstart) {
        _onloadstart = onloadstart;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmousedown() const {
        return _onmousedown;
    }
    void SVGElement::set_onmousedown(const std::string &onmousedown) {
        _onmousedown = onmousedown;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmouseenter() const {
        return _onmouseenter;
    }
    void SVGElement::set_onmouseenter(const std::string &onmouseenter) {
        _onmouseenter = onmouseenter;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmouseleave() const {
        return _onmouseleave;
    }
    void SVGElement::set_onmouseleave(const std::string &onmouseleave) {
        _onmouseleave = onmouseleave;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmousemove() const {
        return _onmousemove;
    }
    void SVGElement::set_onmousemove(const std::string &onmousemove) {
        _onmousemove = onmousemove;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmouseout() const {
        return _onmouseout;
    }
    void SVGElement::set_onmouseout(const std::string &onmouseout) {
        _onmouseout = onmouseout;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmouseover() const {
        return _onmouseover;
    }
    void SVGElement::set_onmouseover(const std::string &onmouseover) {
        _onmouseover = onmouseover;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmouseup() const {
        return _onmouseup;
    }
    void SVGElement::set_onmouseup(const std::string &onmouseup) {
        _onmouseup = onmouseup;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onmousewheel() const {
        return _onmousewheel;
    }
    void SVGElement::set_onmousewheel(const std::string &onmousewheel) {
        _onmousewheel = onmousewheel;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onpause() const {
        return _onpause;
    }
    void SVGElement::set_onpause(const std::string &onpause) {
        _onpause = onpause;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onplay() const {
        return _onplay;
    }
    void SVGElement::set_onplay(const std::string &onplay) {
        _onplay = onplay;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onplaying() const {
        return _onplaying;
    }
    void SVGElement::set_onplaying(const std::string &onplaying) {
        _onplaying = onplaying;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onprogress() const {
        return _onprogress;
    }
    void SVGElement::set_onprogress(const std::string &onprogress) {
        _onprogress = onprogress;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onratechange() const {
        return _onratechange;
    }
    void SVGElement::set_onratechange(const std::string &onratechange) {
        _onratechange = onratechange;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onreset() const {
        return _onreset;
    }
    void SVGElement::set_onreset(const std::string &onreset) {
        _onreset = onreset;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onseeked() const {
        return _onseeked;
    }
    void SVGElement::set_onseeked(const std::string &onseeked) {
        _onseeked = onseeked;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onseeking() const {
        return _onseeking;
    }
    void SVGElement::set_onseeking(const std::string &onseeking) {
        _onseeking = onseeking;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onselect() const {
        return _onselect;
    }
    void SVGElement::set_onselect(const std::string &onselect) {
        _onselect = onselect;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onshow() const {
        return _onshow;
    }
    void SVGElement::set_onshow(const std::string &onshow) {
        _onshow = onshow;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onstalled() const {
        return _onstalled;
    }
    void SVGElement::set_onstalled(const std::string &onstalled) {
        _onstalled = onstalled;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onsubmit() const {
        return _onsubmit;
    }
    void SVGElement::set_onsubmit(const std::string &onsubmit) {
        _onsubmit = onsubmit;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onsuspend() const {
        return _onsuspend;
    }
    void SVGElement::set_onsuspend(const std::string &onsuspend) {
        _onsuspend = onsuspend;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ontimeupdate() const {
        return _ontimeupdate;
    }
    void SVGElement::set_ontimeupdate(const std::string &ontimeupdate) {
        _ontimeupdate = ontimeupdate;
        update_attribute_hash();
    }
    const std::string SVGElement::get_ontoggle() const {
        return _ontoggle;
    }
    void SVGElement::set_ontoggle(const std::string &ontoggle) {
        _ontoggle = ontoggle;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onvolumechange() const {
        return _onvolumechange;
    }
    void SVGElement::set_onvolumechange(const std::string &onvolumechange) {
        _onvolumechange = onvolumechange;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onwaiting() const {
        return _onwaiting;
    }
    void SVGElement::set_onwaiting(const std::string &onwaiting) {
        _onwaiting = onwaiting;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onactivate() const {
        return _onactivate;
    }
    void SVGElement::set_onactivate(const std::string &onactivate) {
        _onactivate = onactivate;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onfocusin() const {
        return _onfocusin;
    }
    void SVGElement::set_onfocusin(const std::string &onfocusin) {
        _onfocusin = onfocusin;
        update_attribute_hash();
    }
    const std::string SVGElement::get_onfocusout() const {
        return _onfocusout;
    }
    void SVGElement::set_onfocusout(const std::string &onfocusout) {
        _onfocusout = onfocusout;
        update_attribute_hash();
    }
    const std::string SVGElement::get_alignment_baseline() const {
        return _alignment_baseline;
    }
    void SVGElement::set_alignment_baseline(const std::string &alignment_baseline) {
        _alignment_baseline = alignment_baseline;
        update_attribute_hash();
    }
    const std::string SVGElement::get_baseline_shift() const {
        return _baseline_shift;
    }
    void SVGElement::set_baseline_shift(const std::string &baseline_shift) {
        _baseline_shift = baseline_shift;
        update_attribute_hash();
    }
    const std::string SVGElement::get_clip_path() const {
        return _clip_path;
    }
    void SVGElement::set_clip_path(const std::string &clip_path) {
        _clip_path = clip_path;
        update_attribute_hash();
    }
    const std::string SVGElement::get_clip_rule() const {
        return _clip_rule;
    }
    void SVGElement::set_clip_rule(const std::string &clip_rule) {
        _clip_rule = clip_rule;
        update_attribute_hash();
    }
    const std::string SVGElement::get_color() const {
        return _color;
    }
    void SVGElement::set_color(const std::string &color) {
        _color = color;
        update_attribute_hash();
    }
    const std::string SVGElement::get_color_interpolation() const {
        return _color_interpolation;
    }
    void SVGElement::set_color_interpolation(const std::string &color_interpolation) {
        _color_interpolation = color_interpolation;
        update_attribute_hash();
    }
    const std::string SVGElement::get_color_interpolation_filters() const {
        return _color_interpolation_filters;
    }
    void SVGElement::set_color_interpolation_filters(const std::string &color_interpolation_filters) {
        _color_interpolation_filters = color_interpolation_filters;
        update_attribute_hash();
    }
    const std::string SVGElement::get_color_profile() const {
        return _color_profile;
    }
    void SVGElement::set_color_profile(const std::string &color_profile) {
        _color_profile = color_profile;
        update_attribute_hash();
    }
    const std::string SVGElement::get_color_rendering() const {
        return _color_rendering;
    }
    void SVGElement::set_color_rendering(const std::string &color_rendering) {
        _color_rendering = color_rendering;
        update_attribute_hash();
    }
    const std::string SVGElement::get_cursor() const {
        return _cursor;
    }
    void SVGElement::set_cursor(const std::string &cursor) {
        _cursor = cursor;
        update_attribute_hash();
    }
    const std::string SVGElement::get_d() const {
        return _d;
    }
    void SVGElement::set_d(const std::string &d) {
        _d = d;
        update_attribute_hash();
    }
    const std::string SVGElement::get_direction() const {
        return _direction;
    }
    void SVGElement::set_direction(const std::string &direction) {
        _direction = direction;
        update_attribute_hash();
    }
    const std::string SVGElement::get_display() const {
        return _display;
    }
    void SVGElement::set_display(const std::string &display) {
        _display = display;
        update_attribute_hash();
    }
    const std::string SVGElement::get_dominant_baseline() const {
        return _dominant_baseline;
    }
    void SVGElement::set_dominant_baseline(const std::string &dominant_baseline) {
        _dominant_baseline = dominant_baseline;
        update_attribute_hash();
    }
    const std::string SVGElement::get_enable_background() const {
        return _enable_background;
    }
    void SVGElement::set_enable_background(const std::string &enable_background) {
        _enable_background = enable_background;
        update_attribute_hash();
    }
    const std::string SVGElement::get_fill() const {
        return _fill;
    }
    void SVGElement::set_fill(const std::string &fill) {
        _fill = fill;
        update_attribute_hash();
    }
    const std::string SVGElement::get_fill_opacity() const {
        return _fill_opacity;
    }
    void SVGElement::set_fill_opacity(const std::string &fill_opacity) {
        _fill_opacity = fill_opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_fill_rule() const {
        return _fill_rule;
    }
    void SVGElement::set_fill_rule(const std::string &fill_rule) {
        _fill_rule = fill_rule;
        update_attribute_hash();
    }
    const std::string SVGElement::get_filter() const {
        return _filter;
    }
    void SVGElement::set_filter(const std::string &filter) {
        _filter = filter;
        update_attribute_hash();
    }
    const std::string SVGElement::get_flood_color() const {
        return _flood_color;
    }
    void SVGElement::set_flood_color(const std::string &flood_color) {
        _flood_color = flood_color;
        update_attribute_hash();
    }
    const std::string SVGElement::get_flood_opacity() const {
        return _flood_opacity;
    }
    void SVGElement::set_flood_opacity(const std::string &flood_opacity) {
        _flood_opacity = flood_opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_family() const {
        return _font_family;
    }
    void SVGElement::set_font_family(const std::string &font_family) {
        _font_family = font_family;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_size() const {
        return _font_size;
    }
    void SVGElement::set_font_size(const std::string &font_size) {
        _font_size = font_size;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_size_adjust() const {
        return _font_size_adjust;
    }
    void SVGElement::set_font_size_adjust(const std::string &font_size_adjust) {
        _font_size_adjust = font_size_adjust;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_stretch() const {
        return _font_stretch;
    }
    void SVGElement::set_font_stretch(const std::string &font_stretch) {
        _font_stretch = font_stretch;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_style() const {
        return _font_style;
    }
    void SVGElement::set_font_style(const std::string &font_style) {
        _font_style = font_style;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_variant() const {
        return _font_variant;
    }
    void SVGElement::set_font_variant(const std::string &font_variant) {
        _font_variant = font_variant;
        update_attribute_hash();
    }
    const std::string SVGElement::get_font_weight() const {
        return _font_weight;
    }
    void SVGElement::set_font_weight(const std::string &font_weight) {
        _font_weight = font_weight;
        update_attribute_hash();
    }
    const std::string SVGElement::get_glyph_orientation_horizontal() const {
        return _glyph_orientation_horizontal;
    }
    void SVGElement::set_glyph_orientation_horizontal(const std::string &glyph_orientation_horizontal) {
        _glyph_orientation_horizontal = glyph_orientation_horizontal;
        update_attribute_hash();
    }
    const std::string SVGElement::get_glyph_orientation_vertical() const {
        return _glyph_orientation_vertical;
    }
    void SVGElement::set_glyph_orientation_vertical(const std::string &glyph_orientation_vertical) {
        _glyph_orientation_vertical = glyph_orientation_vertical;
        update_attribute_hash();
    }
    const std::string SVGElement::get_image_rendering() const {
        return _image_rendering;
    }
    void SVGElement::set_image_rendering(const std::string &image_rendering) {
        _image_rendering = image_rendering;
        update_attribute_hash();
    }
    const std::string SVGElement::get_kerning() const {
        return _kerning;
    }
    void SVGElement::set_kerning(const std::string &kerning) {
        _kerning = kerning;
        update_attribute_hash();
    }
    const std::string SVGElement::get_letter_spacing() const {
        return _letter_spacing;
    }
    void SVGElement::set_letter_spacing(const std::string &letter_spacing) {
        _letter_spacing = letter_spacing;
        update_attribute_hash();
    }
    const std::string SVGElement::get_lighting_color() const {
        return _lighting_color;
    }
    void SVGElement::set_lighting_color(const std::string &lighting_color) {
        _lighting_color = lighting_color;
        update_attribute_hash();
    }
    const std::string SVGElement::get_marker_end() const {
        return _marker_end;
    }
    void SVGElement::set_marker_end(const std::string &marker_end) {
        _marker_end = marker_end;
        update_attribute_hash();
    }
    const std::string SVGElement::get_marker_mid() const {
        return _marker_mid;
    }
    void SVGElement::set_marker_mid(const std::string &marker_mid) {
        _marker_mid = marker_mid;
        update_attribute_hash();
    }
    const std::string SVGElement::get_marker_start() const {
        return _marker_start;
    }
    void SVGElement::set_marker_start(const std::string &marker_start) {
        _marker_start = marker_start;
        update_attribute_hash();
    }
    const std::string SVGElement::get_mask() const {
        return _mask;
    }
    void SVGElement::set_mask(const std::string &mask) {
        _mask = mask;
        update_attribute_hash();
    }
    const std::string SVGElement::get_opacity() const {
        return _opacity;
    }
    void SVGElement::set_opacity(const std::string &opacity) {
        _opacity = opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_overflow() const {
        return _overflow;
    }
    void SVGElement::set_overflow(const std::string &overflow) {
        _overflow = overflow;
        update_attribute_hash();
    }
    const std::string SVGElement::get_pointer_events() const {
        return _pointer_events;
    }
    void SVGElement::set_pointer_events(const std::string &pointer_events) {
        _pointer_events = pointer_events;
        update_attribute_hash();
    }
    const std::string SVGElement::get_shape_rendering() const {
        return _shape_rendering;
    }
    void SVGElement::set_shape_rendering(const std::string &shape_rendering) {
        _shape_rendering = shape_rendering;
        update_attribute_hash();
    }
    const std::string SVGElement::get_solid_color() const {
        return _solid_color;
    }
    void SVGElement::set_solid_color(const std::string &solid_color) {
        _solid_color = solid_color;
        update_attribute_hash();
    }
    const std::string SVGElement::get_solid_opacity() const {
        return _solid_opacity;
    }
    void SVGElement::set_solid_opacity(const std::string &solid_opacity) {
        _solid_opacity = solid_opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stop_color() const {
        return _stop_color;
    }
    void SVGElement::set_stop_color(const std::string &stop_color) {
        _stop_color = stop_color;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stop_opacity() const {
        return _stop_opacity;
    }
    void SVGElement::set_stop_opacity(const std::string &stop_opacity) {
        _stop_opacity = stop_opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke() const {
        return _stroke;
    }
    void SVGElement::set_stroke(const std::string &stroke) {
        _stroke = stroke;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_dasharray() const {
        return _stroke_dasharray;
    }
    void SVGElement::set_stroke_dasharray(const std::string &stroke_dasharray) {
        _stroke_dasharray = stroke_dasharray;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_dashoffset() const {
        return _stroke_dashoffset;
    }
    void SVGElement::set_stroke_dashoffset(const std::string &stroke_dashoffset) {
        _stroke_dashoffset = stroke_dashoffset;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_linecap() const {
        return _stroke_linecap;
    }
    void SVGElement::set_stroke_linecap(const std::string &stroke_linecap) {
        _stroke_linecap = stroke_linecap;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_linejoin() const {
        return _stroke_linejoin;
    }
    void SVGElement::set_stroke_linejoin(const std::string &stroke_linejoin) {
        _stroke_linejoin = stroke_linejoin;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_miterlimit() const {
        return _stroke_miterlimit;
    }
    void SVGElement::set_stroke_miterlimit(const std::string &stroke_miterlimit) {
        _stroke_miterlimit = stroke_miterlimit;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_opacity() const {
        return _stroke_opacity;
    }
    void SVGElement::set_stroke_opacity(const std::string &stroke_opacity) {
        _stroke_opacity = stroke_opacity;
        update_attribute_hash();
    }
    const std::string SVGElement::get_stroke_width() const {
        return _stroke_width;
    }
    void SVGElement::set_stroke_width(const std::string &stroke_width) {
        _stroke_width = stroke_width;
        update_attribute_hash();
    }
    const std::string SVGElement::get_text_anchor() const {
        return _text_anchor;
    }
    void SVGElement::set_text_anchor(const std::string &text_anchor) {
        _text_anchor = text_anchor;
        update_attribute_hash();
    }
    const std::string SVGElement::get_text_decoration() const {
        return _text_decoration;
    }
    void SVGElement::set_text_decoration(const std::string &text_decoration) {
        _text_decoration = text_decoration;
        update_attribute_hash();
    }
    const std::string SVGElement::get_text_rendering() const {
        return _text_rendering;
    }
    void SVGElement::set_text_rendering(const std::string &text_rendering) {
        _text_rendering = text_rendering;
        update_attribute_hash();
    }
    const std::string SVGElement::get_transform() const {
        return _transform;
    }
    void SVGElement::set_transform(const std::string &transform) {
        _transform = transform;
        update_attribute_hash();
    }
    const std::string SVGElement::get_unicode_bidi() const {
        return _unicode_bidi;
    }
    void SVGElement::set_unicode_bidi(const std::string &unicode_bidi) {
        _unicode_bidi = unicode_bidi;
        update_attribute_hash();
    }
    const std::string SVGElement::get_vector_effect() const {
        return _vector_effect;
    }
    void SVGElement::set_vector_effect(const std::string &vector_effect) {
        _vector_effect = vector_effect;
        update_attribute_hash();
    }
    const std::string SVGElement::get_visibility() const {
        return _visibility;
    }
    void SVGElement::set_visibility(const std::string &visibility) {
        _visibility = visibility;
        update_attribute_hash();
    }
    const std::string SVGElement::get_word_spacing() const {
        return _word_spacing;
    }
    void SVGElement::set_word_spacing(const std::string &word_spacing) {
        _word_spacing = word_spacing;
        update_attribute_hash();
    }
    const std::string SVGElement::get_writing_mode() const {
        return _writing_mode;
    }
    void SVGElement::set_writing_mode(const std::string &writing_mode) {
        _writing_mode = writing_mode;
        update_attribute_hash();
    }

        const std::string SVGElement::inner_SVG() const {
        std::stringstream ss;
        if (_raw_HTML != STR_NULL) ss << _raw_HTML;
        for (auto &p : _inner_elements) ss << p->outer_SVG();
        return ss.str();
    }
    void SVGElement::set_raw_HTML(const std::string &text) {
        _raw_HTML = text;
        update_inner_hash();
    }
    const std::string SVGElement::get_raw_HTML() const {
        return _raw_HTML;
    }
    void SVGElement::add_inner_element(const std::shared_ptr<SVGElement> &inner_element, int index) {
        if (auto sp = inner_element->_parent_element.lock()) {
            auto &els = sp->_inner_elements;
            els.erase(std::remove(els.begin(), els.end(), inner_element), els.end());
        }
        inner_element->_parent_element = shared_from_this();
        if (index == -1) _inner_elements.push_back(inner_element);
        else _inner_elements.insert(_inner_elements.begin() + index, inner_element);
        update_inner_hash();
    }
    void SVGElement::remove_inner_element(const std::shared_ptr<SVGElement> &inner_element, bool remove_all) {
        bool success;
        std::vector<std::shared_ptr<SVGElement>> removed;
        _inner_elements.erase(std::remove_if(_inner_elements.begin(), _inner_elements.end(),
                                [&](const std::shared_ptr<SVGElement>& _inner_element) { 
                                    if (success && !remove_all) return false;
                                    if (_inner_element->get_outer_hash() == inner_element->get_outer_hash()) {
                                        success = true;
                                        removed.push_back(_inner_element);
                                        return true;
                                    }
                                    return false;
                                }), _inner_elements.end());
        success = false;
        for (auto &p : removed) p->_parent_element = std::weak_ptr<SVGElement>();
        update_inner_hash();
    }
    void SVGElement::remove_inner_element(int index) {
        _inner_elements[index]->_parent_element = std::weak_ptr<SVGElement>();
        _inner_elements.erase(_inner_elements.begin() + index);
        update_inner_hash();
    }
    std::shared_ptr<SVGElement> SVGElement::get_inner_element(int index) const {
        return _inner_elements[index];
    }
    const std::vector<std::shared_ptr<SVGElement>> SVGElement::get_inner_elements() const {
        return _inner_elements;
    }
    void SVGElement::set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements) {
        while (_inner_elements.size() > 0) remove_inner_element(0);
        for (auto p : inner_elements) add_inner_element(p);
        update_inner_hash();
    }

    const std::string SVGElement::get_attributes() const {
        std::stringstream ss;

        if (_id != STR_NULL) ss << " id=\"" << _id << "\"";
        if (_lang != STR_NULL) ss << " lang=\"" << _lang << "\"";
        if (_tabindex != STR_NULL) ss << " tabindex=\"" << _tabindex << "\"";
        if (_xmlZbase != STR_NULL) ss << " xml:base=\"" << _xmlZbase << "\"";
        if (_xmlZlang != STR_NULL) ss << " xml:lang=\"" << _xmlZlang << "\"";
        if (_xmlZspace != STR_NULL) ss << " xml:space=\"" << _xmlZspace << "\"";
        if (_class != STR_NULL) ss << " class=\"" << _class << "\"";
        if (_style != STR_NULL) ss << " style=\"" << _style << "\"";
        if (_onbegin != STR_NULL) ss << " onbegin=\"" << _onbegin << "\"";
        if (_onend != STR_NULL) ss << " onend=\"" << _onend << "\"";
        if (_onrepeat != STR_NULL) ss << " onrepeat=\"" << _onrepeat << "\"";
        if (_onabort != STR_NULL) ss << " onabort=\"" << _onabort << "\"";
        if (_onerror != STR_NULL) ss << " onerror=\"" << _onerror << "\"";
        if (_onresize != STR_NULL) ss << " onresize=\"" << _onresize << "\"";
        if (_onscroll != STR_NULL) ss << " onscroll=\"" << _onscroll << "\"";
        if (_onunload != STR_NULL) ss << " onunload=\"" << _onunload << "\"";
        if (_oncopy != STR_NULL) ss << " oncopy=\"" << _oncopy << "\"";
        if (_oncut != STR_NULL) ss << " oncut=\"" << _oncut << "\"";
        if (_onpaste != STR_NULL) ss << " onpaste=\"" << _onpaste << "\"";
        if (_oncancel != STR_NULL) ss << " oncancel=\"" << _oncancel << "\"";
        if (_oncanplay != STR_NULL) ss << " oncanplay=\"" << _oncanplay << "\"";
        if (_oncanplaythrough != STR_NULL) ss << " oncanplaythrough=\"" << _oncanplaythrough << "\"";
        if (_onchange != STR_NULL) ss << " onchange=\"" << _onchange << "\"";
        if (_onclick != STR_NULL) ss << " onclick=\"" << _onclick << "\"";
        if (_onclose != STR_NULL) ss << " onclose=\"" << _onclose << "\"";
        if (_oncuechange != STR_NULL) ss << " oncuechange=\"" << _oncuechange << "\"";
        if (_ondblclick != STR_NULL) ss << " ondblclick=\"" << _ondblclick << "\"";
        if (_ondrag != STR_NULL) ss << " ondrag=\"" << _ondrag << "\"";
        if (_ondragend != STR_NULL) ss << " ondragend=\"" << _ondragend << "\"";
        if (_ondragenter != STR_NULL) ss << " ondragenter=\"" << _ondragenter << "\"";
        if (_ondragleave != STR_NULL) ss << " ondragleave=\"" << _ondragleave << "\"";
        if (_ondragover != STR_NULL) ss << " ondragover=\"" << _ondragover << "\"";
        if (_ondragstart != STR_NULL) ss << " ondragstart=\"" << _ondragstart << "\"";
        if (_ondrop != STR_NULL) ss << " ondrop=\"" << _ondrop << "\"";
        if (_ondurationchange != STR_NULL) ss << " ondurationchange=\"" << _ondurationchange << "\"";
        if (_onemptied != STR_NULL) ss << " onemptied=\"" << _onemptied << "\"";
        if (_onended != STR_NULL) ss << " onended=\"" << _onended << "\"";
        if (_onfocus != STR_NULL) ss << " onfocus=\"" << _onfocus << "\"";
        if (_oninput != STR_NULL) ss << " oninput=\"" << _oninput << "\"";
        if (_oninvalid != STR_NULL) ss << " oninvalid=\"" << _oninvalid << "\"";
        if (_onkeydown != STR_NULL) ss << " onkeydown=\"" << _onkeydown << "\"";
        if (_onkeypress != STR_NULL) ss << " onkeypress=\"" << _onkeypress << "\"";
        if (_onkeyup != STR_NULL) ss << " onkeyup=\"" << _onkeyup << "\"";
        if (_onload != STR_NULL) ss << " onload=\"" << _onload << "\"";
        if (_onloadeddata != STR_NULL) ss << " onloadeddata=\"" << _onloadeddata << "\"";
        if (_onloadedmetadata != STR_NULL) ss << " onloadedmetadata=\"" << _onloadedmetadata << "\"";
        if (_onloadstart != STR_NULL) ss << " onloadstart=\"" << _onloadstart << "\"";
        if (_onmousedown != STR_NULL) ss << " onmousedown=\"" << _onmousedown << "\"";
        if (_onmouseenter != STR_NULL) ss << " onmouseenter=\"" << _onmouseenter << "\"";
        if (_onmouseleave != STR_NULL) ss << " onmouseleave=\"" << _onmouseleave << "\"";
        if (_onmousemove != STR_NULL) ss << " onmousemove=\"" << _onmousemove << "\"";
        if (_onmouseout != STR_NULL) ss << " onmouseout=\"" << _onmouseout << "\"";
        if (_onmouseover != STR_NULL) ss << " onmouseover=\"" << _onmouseover << "\"";
        if (_onmouseup != STR_NULL) ss << " onmouseup=\"" << _onmouseup << "\"";
        if (_onmousewheel != STR_NULL) ss << " onmousewheel=\"" << _onmousewheel << "\"";
        if (_onpause != STR_NULL) ss << " onpause=\"" << _onpause << "\"";
        if (_onplay != STR_NULL) ss << " onplay=\"" << _onplay << "\"";
        if (_onplaying != STR_NULL) ss << " onplaying=\"" << _onplaying << "\"";
        if (_onprogress != STR_NULL) ss << " onprogress=\"" << _onprogress << "\"";
        if (_onratechange != STR_NULL) ss << " onratechange=\"" << _onratechange << "\"";
        if (_onreset != STR_NULL) ss << " onreset=\"" << _onreset << "\"";
        if (_onseeked != STR_NULL) ss << " onseeked=\"" << _onseeked << "\"";
        if (_onseeking != STR_NULL) ss << " onseeking=\"" << _onseeking << "\"";
        if (_onselect != STR_NULL) ss << " onselect=\"" << _onselect << "\"";
        if (_onshow != STR_NULL) ss << " onshow=\"" << _onshow << "\"";
        if (_onstalled != STR_NULL) ss << " onstalled=\"" << _onstalled << "\"";
        if (_onsubmit != STR_NULL) ss << " onsubmit=\"" << _onsubmit << "\"";
        if (_onsuspend != STR_NULL) ss << " onsuspend=\"" << _onsuspend << "\"";
        if (_ontimeupdate != STR_NULL) ss << " ontimeupdate=\"" << _ontimeupdate << "\"";
        if (_ontoggle != STR_NULL) ss << " ontoggle=\"" << _ontoggle << "\"";
        if (_onvolumechange != STR_NULL) ss << " onvolumechange=\"" << _onvolumechange << "\"";
        if (_onwaiting != STR_NULL) ss << " onwaiting=\"" << _onwaiting << "\"";
        if (_onactivate != STR_NULL) ss << " onactivate=\"" << _onactivate << "\"";
        if (_onfocusin != STR_NULL) ss << " onfocusin=\"" << _onfocusin << "\"";
        if (_onfocusout != STR_NULL) ss << " onfocusout=\"" << _onfocusout << "\"";
        if (_alignment_baseline != STR_NULL) ss << " alignment-baseline=\"" << _alignment_baseline << "\"";
        if (_baseline_shift != STR_NULL) ss << " baseline-shift=\"" << _baseline_shift << "\"";
        if (_clip_path != STR_NULL) ss << " clip-path=\"" << _clip_path << "\"";
        if (_clip_rule != STR_NULL) ss << " clip-rule=\"" << _clip_rule << "\"";
        if (_color != STR_NULL) ss << " color=\"" << _color << "\"";
        if (_color_interpolation != STR_NULL) ss << " color-interpolation=\"" << _color_interpolation << "\"";
        if (_color_interpolation_filters != STR_NULL) ss << " color-interpolation-filters=\"" << _color_interpolation_filters << "\"";
        if (_color_profile != STR_NULL) ss << " color-profile=\"" << _color_profile << "\"";
        if (_color_rendering != STR_NULL) ss << " color-rendering=\"" << _color_rendering << "\"";
        if (_cursor != STR_NULL) ss << " cursor=\"" << _cursor << "\"";
        if (_d != STR_NULL) ss << " d=\"" << _d << "\"";
        if (_direction != STR_NULL) ss << " direction=\"" << _direction << "\"";
        if (_display != STR_NULL) ss << " display=\"" << _display << "\"";
        if (_dominant_baseline != STR_NULL) ss << " dominant-baseline=\"" << _dominant_baseline << "\"";
        if (_enable_background != STR_NULL) ss << " enable-background=\"" << _enable_background << "\"";
        if (_fill != STR_NULL) ss << " fill=\"" << _fill << "\"";
        if (_fill_opacity != STR_NULL) ss << " fill-opacity=\"" << _fill_opacity << "\"";
        if (_fill_rule != STR_NULL) ss << " fill-rule=\"" << _fill_rule << "\"";
        if (_filter != STR_NULL) ss << " filter=\"" << _filter << "\"";
        if (_flood_color != STR_NULL) ss << " flood-color=\"" << _flood_color << "\"";
        if (_flood_opacity != STR_NULL) ss << " flood-opacity=\"" << _flood_opacity << "\"";
        if (_font_family != STR_NULL) ss << " font-family=\"" << _font_family << "\"";
        if (_font_size != STR_NULL) ss << " font-size=\"" << _font_size << "\"";
        if (_font_size_adjust != STR_NULL) ss << " font-size-adjust=\"" << _font_size_adjust << "\"";
        if (_font_stretch != STR_NULL) ss << " font-stretch=\"" << _font_stretch << "\"";
        if (_font_style != STR_NULL) ss << " font-style=\"" << _font_style << "\"";
        if (_font_variant != STR_NULL) ss << " font-variant=\"" << _font_variant << "\"";
        if (_font_weight != STR_NULL) ss << " font-weight=\"" << _font_weight << "\"";
        if (_glyph_orientation_horizontal != STR_NULL) ss << " glyph-orientation-horizontal=\"" << _glyph_orientation_horizontal << "\"";
        if (_glyph_orientation_vertical != STR_NULL) ss << " glyph-orientation-vertical=\"" << _glyph_orientation_vertical << "\"";
        if (_image_rendering != STR_NULL) ss << " image-rendering=\"" << _image_rendering << "\"";
        if (_kerning != STR_NULL) ss << " kerning=\"" << _kerning << "\"";
        if (_letter_spacing != STR_NULL) ss << " letter-spacing=\"" << _letter_spacing << "\"";
        if (_lighting_color != STR_NULL) ss << " lighting-color=\"" << _lighting_color << "\"";
        if (_marker_end != STR_NULL) ss << " marker-end=\"" << _marker_end << "\"";
        if (_marker_mid != STR_NULL) ss << " marker-mid=\"" << _marker_mid << "\"";
        if (_marker_start != STR_NULL) ss << " marker-start=\"" << _marker_start << "\"";
        if (_mask != STR_NULL) ss << " mask=\"" << _mask << "\"";
        if (_opacity != STR_NULL) ss << " opacity=\"" << _opacity << "\"";
        if (_overflow != STR_NULL) ss << " overflow=\"" << _overflow << "\"";
        if (_pointer_events != STR_NULL) ss << " pointer-events=\"" << _pointer_events << "\"";
        if (_shape_rendering != STR_NULL) ss << " shape-rendering=\"" << _shape_rendering << "\"";
        if (_solid_color != STR_NULL) ss << " solid-color=\"" << _solid_color << "\"";
        if (_solid_opacity != STR_NULL) ss << " solid-opacity=\"" << _solid_opacity << "\"";
        if (_stop_color != STR_NULL) ss << " stop-color=\"" << _stop_color << "\"";
        if (_stop_opacity != STR_NULL) ss << " stop-opacity=\"" << _stop_opacity << "\"";
        if (_stroke != STR_NULL) ss << " stroke=\"" << _stroke << "\"";
        if (_stroke_dasharray != STR_NULL) ss << " stroke-dasharray=\"" << _stroke_dasharray << "\"";
        if (_stroke_dashoffset != STR_NULL) ss << " stroke-dashoffset=\"" << _stroke_dashoffset << "\"";
        if (_stroke_linecap != STR_NULL) ss << " stroke-linecap=\"" << _stroke_linecap << "\"";
        if (_stroke_linejoin != STR_NULL) ss << " stroke-linejoin=\"" << _stroke_linejoin << "\"";
        if (_stroke_miterlimit != STR_NULL) ss << " stroke-miterlimit=\"" << _stroke_miterlimit << "\"";
        if (_stroke_opacity != STR_NULL) ss << " stroke-opacity=\"" << _stroke_opacity << "\"";
        if (_stroke_width != STR_NULL) ss << " stroke-width=\"" << _stroke_width << "\"";
        if (_text_anchor != STR_NULL) ss << " text-anchor=\"" << _text_anchor << "\"";
        if (_text_decoration != STR_NULL) ss << " text-decoration=\"" << _text_decoration << "\"";
        if (_text_rendering != STR_NULL) ss << " text-rendering=\"" << _text_rendering << "\"";
        if (_transform != STR_NULL) ss << " transform=\"" << _transform << "\"";
        if (_unicode_bidi != STR_NULL) ss << " unicode-bidi=\"" << _unicode_bidi << "\"";
        if (_vector_effect != STR_NULL) ss << " vector-effect=\"" << _vector_effect << "\"";
        if (_visibility != STR_NULL) ss << " visibility=\"" << _visibility << "\"";
        if (_word_spacing != STR_NULL) ss << " word-spacing=\"" << _word_spacing << "\"";
        if (_writing_mode != STR_NULL) ss << " writing-mode=\"" << _writing_mode << "\"";
        
        return ss.str();
    }

    const std::string SVGElement::outer_SVG() const {
        if (_raw_HTML != STR_NULL) return _raw_HTML;

        std::stringstream ss;

        ss << "<" << get_tag();

        const std::string _attributes = get_attributes();
        if (_attributes != "") ss << _attributes;

        auto _inner_svg = inner_SVG();
        ss << ">" << _inner_svg << "</" << get_tag() << ">";

        return ss.str();
    }

    void SVGElement::update_outer_hash() {
        // has raw html
        if (_raw_HTML != STR_NULL) {
            _attribute_hash = _inner_hash = 0;
            _outer_hash = str_hash(_raw_HTML);
        }
        // update outer hash by attribute hash and inner hash
        else {
            std::stringstream ss;
            ss << get_tag() << ",";
            ss << _attribute_hash << ",";
            ss << _inner_hash;
            _outer_hash = str_hash(ss.str());
        }

        // update parent element
        if (auto sp = _parent_element.lock()) {
            sp->update_inner_hash();
        }
    }
    void SVGElement::update_attribute_hash() {
        // update attribute hash
        if (_raw_HTML == STR_NULL) {
            _attribute_hash = str_hash(get_attributes());
        }

        // update outer hash
        update_outer_hash();
    }
    void SVGElement::update_inner_hash() {
        // inner string + (inner elements)
        if (_raw_HTML == STR_NULL) {
            std::stringstream ss;
            ss << get_raw_HTML() << ",";
            for (auto p : _inner_elements) ss << p->get_outer_hash() << ",";
            _inner_hash = str_hash(ss.str());
        }

        // update outer hash
        update_outer_hash();
    }
    const HASH_CODE SVGElement::get_attribute_hash() const {
        return _attribute_hash;
    }
    const HASH_CODE SVGElement::get_inner_hash() const {
        return _inner_hash;
    }
    const HASH_CODE SVGElement::get_outer_hash() const {
        return _outer_hash;
    }

    std::shared_ptr<SVGElement> SVGElement::clone() const {
        auto cloned =  std::make_shared<SVGElement>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGElement::operator=(const SVGElement &element) {
        _id = element.get_id();
        _lang = element.get_lang();
        _tabindex = element.get_tabindex();
        _xmlZbase = element.get_xmlZbase();
        _xmlZlang = element.get_xmlZlang();
        _xmlZspace = element.get_xmlZspace();
        _class = element.get_class();
        _style = element.get_style();
        _onbegin = element.get_onbegin();
        _onend = element.get_onend();
        _onrepeat = element.get_onrepeat();
        _onabort = element.get_onabort();
        _onerror = element.get_onerror();
        _onresize = element.get_onresize();
        _onscroll = element.get_onscroll();
        _onunload = element.get_onunload();
        _oncopy = element.get_oncopy();
        _oncut = element.get_oncut();
        _onpaste = element.get_onpaste();
        _oncancel = element.get_oncancel();
        _oncanplay = element.get_oncanplay();
        _oncanplaythrough = element.get_oncanplaythrough();
        _onchange = element.get_onchange();
        _onclick = element.get_onclick();
        _onclose = element.get_onclose();
        _oncuechange = element.get_oncuechange();
        _ondblclick = element.get_ondblclick();
        _ondrag = element.get_ondrag();
        _ondragend = element.get_ondragend();
        _ondragenter = element.get_ondragenter();
        _ondragleave = element.get_ondragleave();
        _ondragover = element.get_ondragover();
        _ondragstart = element.get_ondragstart();
        _ondrop = element.get_ondrop();
        _ondurationchange = element.get_ondurationchange();
        _onemptied = element.get_onemptied();
        _onended = element.get_onended();
        _onfocus = element.get_onfocus();
        _oninput = element.get_oninput();
        _oninvalid = element.get_oninvalid();
        _onkeydown = element.get_onkeydown();
        _onkeypress = element.get_onkeypress();
        _onkeyup = element.get_onkeyup();
        _onload = element.get_onload();
        _onloadeddata = element.get_onloadeddata();
        _onloadedmetadata = element.get_onloadedmetadata();
        _onloadstart = element.get_onloadstart();
        _onmousedown = element.get_onmousedown();
        _onmouseenter = element.get_onmouseenter();
        _onmouseleave = element.get_onmouseleave();
        _onmousemove = element.get_onmousemove();
        _onmouseout = element.get_onmouseout();
        _onmouseover = element.get_onmouseover();
        _onmouseup = element.get_onmouseup();
        _onmousewheel = element.get_onmousewheel();
        _onpause = element.get_onpause();
        _onplay = element.get_onplay();
        _onplaying = element.get_onplaying();
        _onprogress = element.get_onprogress();
        _onratechange = element.get_onratechange();
        _onreset = element.get_onreset();
        _onseeked = element.get_onseeked();
        _onseeking = element.get_onseeking();
        _onselect = element.get_onselect();
        _onshow = element.get_onshow();
        _onstalled = element.get_onstalled();
        _onsubmit = element.get_onsubmit();
        _onsuspend = element.get_onsuspend();
        _ontimeupdate = element.get_ontimeupdate();
        _ontoggle = element.get_ontoggle();
        _onvolumechange = element.get_onvolumechange();
        _onwaiting = element.get_onwaiting();
        _onactivate = element.get_onactivate();
        _onfocusin = element.get_onfocusin();
        _onfocusout = element.get_onfocusout();
        _alignment_baseline = element.get_alignment_baseline();
        _baseline_shift = element.get_baseline_shift();
        _clip_path = element.get_clip_path();
        _clip_rule = element.get_clip_rule();
        _color = element.get_color();
        _color_interpolation = element.get_color_interpolation();
        _color_interpolation_filters = element.get_color_interpolation_filters();
        _color_profile = element.get_color_profile();
        _color_rendering = element.get_color_rendering();
        _cursor = element.get_cursor();
        _d = element.get_d();
        _direction = element.get_direction();
        _display = element.get_display();
        _dominant_baseline = element.get_dominant_baseline();
        _enable_background = element.get_enable_background();
        _fill = element.get_fill();
        _fill_opacity = element.get_fill_opacity();
        _fill_rule = element.get_fill_rule();
        _filter = element.get_filter();
        _flood_color = element.get_flood_color();
        _flood_opacity = element.get_flood_opacity();
        _font_family = element.get_font_family();
        _font_size = element.get_font_size();
        _font_size_adjust = element.get_font_size_adjust();
        _font_stretch = element.get_font_stretch();
        _font_style = element.get_font_style();
        _font_variant = element.get_font_variant();
        _font_weight = element.get_font_weight();
        _glyph_orientation_horizontal = element.get_glyph_orientation_horizontal();
        _glyph_orientation_vertical = element.get_glyph_orientation_vertical();
        _image_rendering = element.get_image_rendering();
        _kerning = element.get_kerning();
        _letter_spacing = element.get_letter_spacing();
        _lighting_color = element.get_lighting_color();
        _marker_end = element.get_marker_end();
        _marker_mid = element.get_marker_mid();
        _marker_start = element.get_marker_start();
        _mask = element.get_mask();
        _opacity = element.get_opacity();
        _overflow = element.get_overflow();
        _pointer_events = element.get_pointer_events();
        _shape_rendering = element.get_shape_rendering();
        _solid_color = element.get_solid_color();
        _solid_opacity = element.get_solid_opacity();
        _stop_color = element.get_stop_color();
        _stop_opacity = element.get_stop_opacity();
        _stroke = element.get_stroke();
        _stroke_dasharray = element.get_stroke_dasharray();
        _stroke_dashoffset = element.get_stroke_dashoffset();
        _stroke_linecap = element.get_stroke_linecap();
        _stroke_linejoin = element.get_stroke_linejoin();
        _stroke_miterlimit = element.get_stroke_miterlimit();
        _stroke_opacity = element.get_stroke_opacity();
        _stroke_width = element.get_stroke_width();
        _text_anchor = element.get_text_anchor();
        _text_decoration = element.get_text_decoration();
        _text_rendering = element.get_text_rendering();
        _transform = element.get_transform();
        _unicode_bidi = element.get_unicode_bidi();
        _vector_effect = element.get_vector_effect();
        _visibility = element.get_visibility();
        _word_spacing = element.get_word_spacing();
        _writing_mode = element.get_writing_mode();

        _raw_HTML = element.get_raw_HTML();
        for (auto p : element.get_inner_elements()) {
            auto cloned = p->clone();
            _inner_elements.push_back(cloned);
            p->_parent_element = cloned;
        }

        _attribute_hash = element.get_attribute_hash();
        _inner_hash = element.get_inner_hash();
        _outer_hash = element.get_outer_hash();
        return *this;
    }
    bool SVGElement::operator==(const SVGElement &element) const {
        return element.get_outer_hash() == get_outer_hash();
    }
    bool SVGElement::operator!=(const SVGElement &element) const {
        return !operator==(element);
    }
    const std::string SVGElement::operator-(const SVGElement &element) const {
        std::stringstream ss;

        // tag differ
        if (get_tag() != element.get_tag()) {
            auto svg = outer_SVG();
            ss << "replace " << svg.size() << std::endl << svg << std::endl;
            return ss.str();
        }

        // cast
        auto _element = static_cast<const SVGElement &>(element);

        // attribute differ
        if (element.get_attribute_hash() != get_attribute_hash()) ss << attribute_differ(_element);

        // inner differ
        if (element.get_inner_hash() == get_inner_hash()) return ss.str();

        // extract change relation
        std::vector<_el_idx> removal;
        std::vector<_el_idx> addition;
        std::vector<std::pair<_el_idx, _el_idx>> unchanged;
        std::vector<std::pair<_el_idx, _el_idx>> changed;
        inner_differ(element, removal, addition, unchanged, changed);
        // remove
        int m = _inner_elements.size(), n = element.get_inner_elements().size();
        int *indices = new int[m], *removed = new int[n];
        std::fill(indices, indices + m, 0); std::fill(removed, removed + n, 0);
        for (auto &r : removal) removed[r.idx] = 1;
        for (int i = 1; i < n; i++) removed[i] += removed[i - 1];
        for (auto &r : removal) ss << "remove " << r.idx - (r.idx > 0 ? removed[r.idx - 1] : 0) << std::endl;
        // append
        for (auto &a : addition) {
            auto svg = a.ptr->outer_SVG();
            ss << "append " << svg.size() << std::endl << svg << std::endl;
        }
        // change recursively
        for (auto &c : changed) {
            auto &a = c.first; auto &b = c.second;
            ss << "child " << b.idx - removed[b.idx] << std::endl;
            ss << (*a.ptr - *b.ptr);
            ss << "parent" << std::endl;
        }
        // sort
        for (auto &c : unchanged) {
            auto &a = c.first; auto &b = c.second;
            indices[b.idx - removed[b.idx]] = a.idx;
        }
        for (auto &c : changed) {
            auto &a = c.first; auto &b = c.second;
            indices[b.idx - removed[b.idx]] =  a.idx;
        }
        for (int i = 0; i < addition.size(); i++) {
            auto &a = addition[i];
            indices[unchanged.size() + changed.size() + i] = a.idx;
        }
        bool ordered = true;
        for (int i = 0; i < m && ordered; i++) if (indices[i] != i) ordered = false;
        if (!ordered) {
            ss << "sort \"";
            for (int i = 0; i < m; i++) {
                ss << indices[i];
                if (i < m - 1) ss << ",";
            }
            ss << "\"" << std::endl;
        }
        delete[] removed; delete[] indices;

        return ss.str();
    }
    const std::string SVGElement::attribute_differ(const SVGElement &element) const {
        std::stringstream ss;

        if (_id != element.get_id()) {
            if (_id == STR_NULL) ss << "reset id" << std::endl;
            else ss << "modify id \"" << _id << "\"" << std::endl;
        }
        if (_lang != element.get_lang()) {
            if (_lang == STR_NULL) ss << "reset lang" << std::endl;
            else ss << "modify lang \"" << _lang << "\"" << std::endl;
        }
        if (_tabindex != element.get_tabindex()) {
            if (_tabindex == STR_NULL) ss << "reset tabindex" << std::endl;
            else ss << "modify tabindex \"" << _tabindex << "\"" << std::endl;
        }
        if (_xmlZbase != element.get_xmlZbase()) {
            if (_xmlZbase == STR_NULL) ss << "reset xml:base" << std::endl;
            else ss << "modify xml:base \"" << _xmlZbase << "\"" << std::endl;
        }
        if (_xmlZlang != element.get_xmlZlang()) {
            if (_xmlZlang == STR_NULL) ss << "reset xml:lang" << std::endl;
            else ss << "modify xml:lang \"" << _xmlZlang << "\"" << std::endl;
        }
        if (_xmlZspace != element.get_xmlZspace()) {
            if (_xmlZspace == STR_NULL) ss << "reset xml:space" << std::endl;
            else ss << "modify xml:space \"" << _xmlZspace << "\"" << std::endl;
        }
        if (_class != element.get_class()) {
            if (_class == STR_NULL) ss << "reset class" << std::endl;
            else ss << "modify class \"" << _class << "\"" << std::endl;
        }
        if (_style != element.get_style()) {
            if (_style == STR_NULL) ss << "reset style" << std::endl;
            else ss << "modify style \"" << _style << "\"" << std::endl;
        }
        if (_onbegin != element.get_onbegin()) {
            if (_onbegin == STR_NULL) ss << "reset onbegin" << std::endl;
            else ss << "modify onbegin \"" << _onbegin << "\"" << std::endl;
        }
        if (_onend != element.get_onend()) {
            if (_onend == STR_NULL) ss << "reset onend" << std::endl;
            else ss << "modify onend \"" << _onend << "\"" << std::endl;
        }
        if (_onrepeat != element.get_onrepeat()) {
            if (_onrepeat == STR_NULL) ss << "reset onrepeat" << std::endl;
            else ss << "modify onrepeat \"" << _onrepeat << "\"" << std::endl;
        }
        if (_onabort != element.get_onabort()) {
            if (_onabort == STR_NULL) ss << "reset onabort" << std::endl;
            else ss << "modify onabort \"" << _onabort << "\"" << std::endl;
        }
        if (_onerror != element.get_onerror()) {
            if (_onerror == STR_NULL) ss << "reset onerror" << std::endl;
            else ss << "modify onerror \"" << _onerror << "\"" << std::endl;
        }
        if (_onresize != element.get_onresize()) {
            if (_onresize == STR_NULL) ss << "reset onresize" << std::endl;
            else ss << "modify onresize \"" << _onresize << "\"" << std::endl;
        }
        if (_onscroll != element.get_onscroll()) {
            if (_onscroll == STR_NULL) ss << "reset onscroll" << std::endl;
            else ss << "modify onscroll \"" << _onscroll << "\"" << std::endl;
        }
        if (_onunload != element.get_onunload()) {
            if (_onunload == STR_NULL) ss << "reset onunload" << std::endl;
            else ss << "modify onunload \"" << _onunload << "\"" << std::endl;
        }
        if (_oncopy != element.get_oncopy()) {
            if (_oncopy == STR_NULL) ss << "reset oncopy" << std::endl;
            else ss << "modify oncopy \"" << _oncopy << "\"" << std::endl;
        }
        if (_oncut != element.get_oncut()) {
            if (_oncut == STR_NULL) ss << "reset oncut" << std::endl;
            else ss << "modify oncut \"" << _oncut << "\"" << std::endl;
        }
        if (_onpaste != element.get_onpaste()) {
            if (_onpaste == STR_NULL) ss << "reset onpaste" << std::endl;
            else ss << "modify onpaste \"" << _onpaste << "\"" << std::endl;
        }
        if (_oncancel != element.get_oncancel()) {
            if (_oncancel == STR_NULL) ss << "reset oncancel" << std::endl;
            else ss << "modify oncancel \"" << _oncancel << "\"" << std::endl;
        }
        if (_oncanplay != element.get_oncanplay()) {
            if (_oncanplay == STR_NULL) ss << "reset oncanplay" << std::endl;
            else ss << "modify oncanplay \"" << _oncanplay << "\"" << std::endl;
        }
        if (_oncanplaythrough != element.get_oncanplaythrough()) {
            if (_oncanplaythrough == STR_NULL) ss << "reset oncanplaythrough" << std::endl;
            else ss << "modify oncanplaythrough \"" << _oncanplaythrough << "\"" << std::endl;
        }
        if (_onchange != element.get_onchange()) {
            if (_onchange == STR_NULL) ss << "reset onchange" << std::endl;
            else ss << "modify onchange \"" << _onchange << "\"" << std::endl;
        }
        if (_onclick != element.get_onclick()) {
            if (_onclick == STR_NULL) ss << "reset onclick" << std::endl;
            else ss << "modify onclick \"" << _onclick << "\"" << std::endl;
        }
        if (_onclose != element.get_onclose()) {
            if (_onclose == STR_NULL) ss << "reset onclose" << std::endl;
            else ss << "modify onclose \"" << _onclose << "\"" << std::endl;
        }
        if (_oncuechange != element.get_oncuechange()) {
            if (_oncuechange == STR_NULL) ss << "reset oncuechange" << std::endl;
            else ss << "modify oncuechange \"" << _oncuechange << "\"" << std::endl;
        }
        if (_ondblclick != element.get_ondblclick()) {
            if (_ondblclick == STR_NULL) ss << "reset ondblclick" << std::endl;
            else ss << "modify ondblclick \"" << _ondblclick << "\"" << std::endl;
        }
        if (_ondrag != element.get_ondrag()) {
            if (_ondrag == STR_NULL) ss << "reset ondrag" << std::endl;
            else ss << "modify ondrag \"" << _ondrag << "\"" << std::endl;
        }
        if (_ondragend != element.get_ondragend()) {
            if (_ondragend == STR_NULL) ss << "reset ondragend" << std::endl;
            else ss << "modify ondragend \"" << _ondragend << "\"" << std::endl;
        }
        if (_ondragenter != element.get_ondragenter()) {
            if (_ondragenter == STR_NULL) ss << "reset ondragenter" << std::endl;
            else ss << "modify ondragenter \"" << _ondragenter << "\"" << std::endl;
        }
        if (_ondragleave != element.get_ondragleave()) {
            if (_ondragleave == STR_NULL) ss << "reset ondragleave" << std::endl;
            else ss << "modify ondragleave \"" << _ondragleave << "\"" << std::endl;
        }
        if (_ondragover != element.get_ondragover()) {
            if (_ondragover == STR_NULL) ss << "reset ondragover" << std::endl;
            else ss << "modify ondragover \"" << _ondragover << "\"" << std::endl;
        }
        if (_ondragstart != element.get_ondragstart()) {
            if (_ondragstart == STR_NULL) ss << "reset ondragstart" << std::endl;
            else ss << "modify ondragstart \"" << _ondragstart << "\"" << std::endl;
        }
        if (_ondrop != element.get_ondrop()) {
            if (_ondrop == STR_NULL) ss << "reset ondrop" << std::endl;
            else ss << "modify ondrop \"" << _ondrop << "\"" << std::endl;
        }
        if (_ondurationchange != element.get_ondurationchange()) {
            if (_ondurationchange == STR_NULL) ss << "reset ondurationchange" << std::endl;
            else ss << "modify ondurationchange \"" << _ondurationchange << "\"" << std::endl;
        }
        if (_onemptied != element.get_onemptied()) {
            if (_onemptied == STR_NULL) ss << "reset onemptied" << std::endl;
            else ss << "modify onemptied \"" << _onemptied << "\"" << std::endl;
        }
        if (_onended != element.get_onended()) {
            if (_onended == STR_NULL) ss << "reset onended" << std::endl;
            else ss << "modify onended \"" << _onended << "\"" << std::endl;
        }
        if (_onfocus != element.get_onfocus()) {
            if (_onfocus == STR_NULL) ss << "reset onfocus" << std::endl;
            else ss << "modify onfocus \"" << _onfocus << "\"" << std::endl;
        }
        if (_oninput != element.get_oninput()) {
            if (_oninput == STR_NULL) ss << "reset oninput" << std::endl;
            else ss << "modify oninput \"" << _oninput << "\"" << std::endl;
        }
        if (_oninvalid != element.get_oninvalid()) {
            if (_oninvalid == STR_NULL) ss << "reset oninvalid" << std::endl;
            else ss << "modify oninvalid \"" << _oninvalid << "\"" << std::endl;
        }
        if (_onkeydown != element.get_onkeydown()) {
            if (_onkeydown == STR_NULL) ss << "reset onkeydown" << std::endl;
            else ss << "modify onkeydown \"" << _onkeydown << "\"" << std::endl;
        }
        if (_onkeypress != element.get_onkeypress()) {
            if (_onkeypress == STR_NULL) ss << "reset onkeypress" << std::endl;
            else ss << "modify onkeypress \"" << _onkeypress << "\"" << std::endl;
        }
        if (_onkeyup != element.get_onkeyup()) {
            if (_onkeyup == STR_NULL) ss << "reset onkeyup" << std::endl;
            else ss << "modify onkeyup \"" << _onkeyup << "\"" << std::endl;
        }
        if (_onload != element.get_onload()) {
            if (_onload == STR_NULL) ss << "reset onload" << std::endl;
            else ss << "modify onload \"" << _onload << "\"" << std::endl;
        }
        if (_onloadeddata != element.get_onloadeddata()) {
            if (_onloadeddata == STR_NULL) ss << "reset onloadeddata" << std::endl;
            else ss << "modify onloadeddata \"" << _onloadeddata << "\"" << std::endl;
        }
        if (_onloadedmetadata != element.get_onloadedmetadata()) {
            if (_onloadedmetadata == STR_NULL) ss << "reset onloadedmetadata" << std::endl;
            else ss << "modify onloadedmetadata \"" << _onloadedmetadata << "\"" << std::endl;
        }
        if (_onloadstart != element.get_onloadstart()) {
            if (_onloadstart == STR_NULL) ss << "reset onloadstart" << std::endl;
            else ss << "modify onloadstart \"" << _onloadstart << "\"" << std::endl;
        }
        if (_onmousedown != element.get_onmousedown()) {
            if (_onmousedown == STR_NULL) ss << "reset onmousedown" << std::endl;
            else ss << "modify onmousedown \"" << _onmousedown << "\"" << std::endl;
        }
        if (_onmouseenter != element.get_onmouseenter()) {
            if (_onmouseenter == STR_NULL) ss << "reset onmouseenter" << std::endl;
            else ss << "modify onmouseenter \"" << _onmouseenter << "\"" << std::endl;
        }
        if (_onmouseleave != element.get_onmouseleave()) {
            if (_onmouseleave == STR_NULL) ss << "reset onmouseleave" << std::endl;
            else ss << "modify onmouseleave \"" << _onmouseleave << "\"" << std::endl;
        }
        if (_onmousemove != element.get_onmousemove()) {
            if (_onmousemove == STR_NULL) ss << "reset onmousemove" << std::endl;
            else ss << "modify onmousemove \"" << _onmousemove << "\"" << std::endl;
        }
        if (_onmouseout != element.get_onmouseout()) {
            if (_onmouseout == STR_NULL) ss << "reset onmouseout" << std::endl;
            else ss << "modify onmouseout \"" << _onmouseout << "\"" << std::endl;
        }
        if (_onmouseover != element.get_onmouseover()) {
            if (_onmouseover == STR_NULL) ss << "reset onmouseover" << std::endl;
            else ss << "modify onmouseover \"" << _onmouseover << "\"" << std::endl;
        }
        if (_onmouseup != element.get_onmouseup()) {
            if (_onmouseup == STR_NULL) ss << "reset onmouseup" << std::endl;
            else ss << "modify onmouseup \"" << _onmouseup << "\"" << std::endl;
        }
        if (_onmousewheel != element.get_onmousewheel()) {
            if (_onmousewheel == STR_NULL) ss << "reset onmousewheel" << std::endl;
            else ss << "modify onmousewheel \"" << _onmousewheel << "\"" << std::endl;
        }
        if (_onpause != element.get_onpause()) {
            if (_onpause == STR_NULL) ss << "reset onpause" << std::endl;
            else ss << "modify onpause \"" << _onpause << "\"" << std::endl;
        }
        if (_onplay != element.get_onplay()) {
            if (_onplay == STR_NULL) ss << "reset onplay" << std::endl;
            else ss << "modify onplay \"" << _onplay << "\"" << std::endl;
        }
        if (_onplaying != element.get_onplaying()) {
            if (_onplaying == STR_NULL) ss << "reset onplaying" << std::endl;
            else ss << "modify onplaying \"" << _onplaying << "\"" << std::endl;
        }
        if (_onprogress != element.get_onprogress()) {
            if (_onprogress == STR_NULL) ss << "reset onprogress" << std::endl;
            else ss << "modify onprogress \"" << _onprogress << "\"" << std::endl;
        }
        if (_onratechange != element.get_onratechange()) {
            if (_onratechange == STR_NULL) ss << "reset onratechange" << std::endl;
            else ss << "modify onratechange \"" << _onratechange << "\"" << std::endl;
        }
        if (_onreset != element.get_onreset()) {
            if (_onreset == STR_NULL) ss << "reset onreset" << std::endl;
            else ss << "modify onreset \"" << _onreset << "\"" << std::endl;
        }
        if (_onseeked != element.get_onseeked()) {
            if (_onseeked == STR_NULL) ss << "reset onseeked" << std::endl;
            else ss << "modify onseeked \"" << _onseeked << "\"" << std::endl;
        }
        if (_onseeking != element.get_onseeking()) {
            if (_onseeking == STR_NULL) ss << "reset onseeking" << std::endl;
            else ss << "modify onseeking \"" << _onseeking << "\"" << std::endl;
        }
        if (_onselect != element.get_onselect()) {
            if (_onselect == STR_NULL) ss << "reset onselect" << std::endl;
            else ss << "modify onselect \"" << _onselect << "\"" << std::endl;
        }
        if (_onshow != element.get_onshow()) {
            if (_onshow == STR_NULL) ss << "reset onshow" << std::endl;
            else ss << "modify onshow \"" << _onshow << "\"" << std::endl;
        }
        if (_onstalled != element.get_onstalled()) {
            if (_onstalled == STR_NULL) ss << "reset onstalled" << std::endl;
            else ss << "modify onstalled \"" << _onstalled << "\"" << std::endl;
        }
        if (_onsubmit != element.get_onsubmit()) {
            if (_onsubmit == STR_NULL) ss << "reset onsubmit" << std::endl;
            else ss << "modify onsubmit \"" << _onsubmit << "\"" << std::endl;
        }
        if (_onsuspend != element.get_onsuspend()) {
            if (_onsuspend == STR_NULL) ss << "reset onsuspend" << std::endl;
            else ss << "modify onsuspend \"" << _onsuspend << "\"" << std::endl;
        }
        if (_ontimeupdate != element.get_ontimeupdate()) {
            if (_ontimeupdate == STR_NULL) ss << "reset ontimeupdate" << std::endl;
            else ss << "modify ontimeupdate \"" << _ontimeupdate << "\"" << std::endl;
        }
        if (_ontoggle != element.get_ontoggle()) {
            if (_ontoggle == STR_NULL) ss << "reset ontoggle" << std::endl;
            else ss << "modify ontoggle \"" << _ontoggle << "\"" << std::endl;
        }
        if (_onvolumechange != element.get_onvolumechange()) {
            if (_onvolumechange == STR_NULL) ss << "reset onvolumechange" << std::endl;
            else ss << "modify onvolumechange \"" << _onvolumechange << "\"" << std::endl;
        }
        if (_onwaiting != element.get_onwaiting()) {
            if (_onwaiting == STR_NULL) ss << "reset onwaiting" << std::endl;
            else ss << "modify onwaiting \"" << _onwaiting << "\"" << std::endl;
        }
        if (_onactivate != element.get_onactivate()) {
            if (_onactivate == STR_NULL) ss << "reset onactivate" << std::endl;
            else ss << "modify onactivate \"" << _onactivate << "\"" << std::endl;
        }
        if (_onfocusin != element.get_onfocusin()) {
            if (_onfocusin == STR_NULL) ss << "reset onfocusin" << std::endl;
            else ss << "modify onfocusin \"" << _onfocusin << "\"" << std::endl;
        }
        if (_onfocusout != element.get_onfocusout()) {
            if (_onfocusout == STR_NULL) ss << "reset onfocusout" << std::endl;
            else ss << "modify onfocusout \"" << _onfocusout << "\"" << std::endl;
        }
        if (_alignment_baseline != element.get_alignment_baseline()) {
            if (_alignment_baseline == STR_NULL) ss << "reset alignment-baseline" << std::endl;
            else ss << "modify alignment-baseline \"" << _alignment_baseline << "\"" << std::endl;
        }
        if (_baseline_shift != element.get_baseline_shift()) {
            if (_baseline_shift == STR_NULL) ss << "reset baseline-shift" << std::endl;
            else ss << "modify baseline-shift \"" << _baseline_shift << "\"" << std::endl;
        }
        if (_clip_path != element.get_clip_path()) {
            if (_clip_path == STR_NULL) ss << "reset clip-path" << std::endl;
            else ss << "modify clip-path \"" << _clip_path << "\"" << std::endl;
        }
        if (_clip_rule != element.get_clip_rule()) {
            if (_clip_rule == STR_NULL) ss << "reset clip-rule" << std::endl;
            else ss << "modify clip-rule \"" << _clip_rule << "\"" << std::endl;
        }
        if (_color != element.get_color()) {
            if (_color == STR_NULL) ss << "reset color" << std::endl;
            else ss << "modify color \"" << _color << "\"" << std::endl;
        }
        if (_color_interpolation != element.get_color_interpolation()) {
            if (_color_interpolation == STR_NULL) ss << "reset color-interpolation" << std::endl;
            else ss << "modify color-interpolation \"" << _color_interpolation << "\"" << std::endl;
        }
        if (_color_interpolation_filters != element.get_color_interpolation_filters()) {
            if (_color_interpolation_filters == STR_NULL) ss << "reset color-interpolation-filters" << std::endl;
            else ss << "modify color-interpolation-filters \"" << _color_interpolation_filters << "\"" << std::endl;
        }
        if (_color_profile != element.get_color_profile()) {
            if (_color_profile == STR_NULL) ss << "reset color-profile" << std::endl;
            else ss << "modify color-profile \"" << _color_profile << "\"" << std::endl;
        }
        if (_color_rendering != element.get_color_rendering()) {
            if (_color_rendering == STR_NULL) ss << "reset color-rendering" << std::endl;
            else ss << "modify color-rendering \"" << _color_rendering << "\"" << std::endl;
        }
        if (_cursor != element.get_cursor()) {
            if (_cursor == STR_NULL) ss << "reset cursor" << std::endl;
            else ss << "modify cursor \"" << _cursor << "\"" << std::endl;
        }
        if (_d != element.get_d()) {
            if (_d == STR_NULL) ss << "reset d" << std::endl;
            else ss << "modify d \"" << _d << "\"" << std::endl;
        }
        if (_direction != element.get_direction()) {
            if (_direction == STR_NULL) ss << "reset direction" << std::endl;
            else ss << "modify direction \"" << _direction << "\"" << std::endl;
        }
        if (_display != element.get_display()) {
            if (_display == STR_NULL) ss << "reset display" << std::endl;
            else ss << "modify display \"" << _display << "\"" << std::endl;
        }
        if (_dominant_baseline != element.get_dominant_baseline()) {
            if (_dominant_baseline == STR_NULL) ss << "reset dominant-baseline" << std::endl;
            else ss << "modify dominant-baseline \"" << _dominant_baseline << "\"" << std::endl;
        }
        if (_enable_background != element.get_enable_background()) {
            if (_enable_background == STR_NULL) ss << "reset enable-background" << std::endl;
            else ss << "modify enable-background \"" << _enable_background << "\"" << std::endl;
        }
        if (_fill != element.get_fill()) {
            if (_fill == STR_NULL) ss << "reset fill" << std::endl;
            else ss << "modify fill \"" << _fill << "\"" << std::endl;
        }
        if (_fill_opacity != element.get_fill_opacity()) {
            if (_fill_opacity == STR_NULL) ss << "reset fill-opacity" << std::endl;
            else ss << "modify fill-opacity \"" << _fill_opacity << "\"" << std::endl;
        }
        if (_fill_rule != element.get_fill_rule()) {
            if (_fill_rule == STR_NULL) ss << "reset fill-rule" << std::endl;
            else ss << "modify fill-rule \"" << _fill_rule << "\"" << std::endl;
        }
        if (_filter != element.get_filter()) {
            if (_filter == STR_NULL) ss << "reset filter" << std::endl;
            else ss << "modify filter \"" << _filter << "\"" << std::endl;
        }
        if (_flood_color != element.get_flood_color()) {
            if (_flood_color == STR_NULL) ss << "reset flood-color" << std::endl;
            else ss << "modify flood-color \"" << _flood_color << "\"" << std::endl;
        }
        if (_flood_opacity != element.get_flood_opacity()) {
            if (_flood_opacity == STR_NULL) ss << "reset flood-opacity" << std::endl;
            else ss << "modify flood-opacity \"" << _flood_opacity << "\"" << std::endl;
        }
        if (_font_family != element.get_font_family()) {
            if (_font_family == STR_NULL) ss << "reset font-family" << std::endl;
            else ss << "modify font-family \"" << _font_family << "\"" << std::endl;
        }
        if (_font_size != element.get_font_size()) {
            if (_font_size == STR_NULL) ss << "reset font-size" << std::endl;
            else ss << "modify font-size \"" << _font_size << "\"" << std::endl;
        }
        if (_font_size_adjust != element.get_font_size_adjust()) {
            if (_font_size_adjust == STR_NULL) ss << "reset font-size-adjust" << std::endl;
            else ss << "modify font-size-adjust \"" << _font_size_adjust << "\"" << std::endl;
        }
        if (_font_stretch != element.get_font_stretch()) {
            if (_font_stretch == STR_NULL) ss << "reset font-stretch" << std::endl;
            else ss << "modify font-stretch \"" << _font_stretch << "\"" << std::endl;
        }
        if (_font_style != element.get_font_style()) {
            if (_font_style == STR_NULL) ss << "reset font-style" << std::endl;
            else ss << "modify font-style \"" << _font_style << "\"" << std::endl;
        }
        if (_font_variant != element.get_font_variant()) {
            if (_font_variant == STR_NULL) ss << "reset font-variant" << std::endl;
            else ss << "modify font-variant \"" << _font_variant << "\"" << std::endl;
        }
        if (_font_weight != element.get_font_weight()) {
            if (_font_weight == STR_NULL) ss << "reset font-weight" << std::endl;
            else ss << "modify font-weight \"" << _font_weight << "\"" << std::endl;
        }
        if (_glyph_orientation_horizontal != element.get_glyph_orientation_horizontal()) {
            if (_glyph_orientation_horizontal == STR_NULL) ss << "reset glyph-orientation-horizontal" << std::endl;
            else ss << "modify glyph-orientation-horizontal \"" << _glyph_orientation_horizontal << "\"" << std::endl;
        }
        if (_glyph_orientation_vertical != element.get_glyph_orientation_vertical()) {
            if (_glyph_orientation_vertical == STR_NULL) ss << "reset glyph-orientation-vertical" << std::endl;
            else ss << "modify glyph-orientation-vertical \"" << _glyph_orientation_vertical << "\"" << std::endl;
        }
        if (_image_rendering != element.get_image_rendering()) {
            if (_image_rendering == STR_NULL) ss << "reset image-rendering" << std::endl;
            else ss << "modify image-rendering \"" << _image_rendering << "\"" << std::endl;
        }
        if (_kerning != element.get_kerning()) {
            if (_kerning == STR_NULL) ss << "reset kerning" << std::endl;
            else ss << "modify kerning \"" << _kerning << "\"" << std::endl;
        }
        if (_letter_spacing != element.get_letter_spacing()) {
            if (_letter_spacing == STR_NULL) ss << "reset letter-spacing" << std::endl;
            else ss << "modify letter-spacing \"" << _letter_spacing << "\"" << std::endl;
        }
        if (_lighting_color != element.get_lighting_color()) {
            if (_lighting_color == STR_NULL) ss << "reset lighting-color" << std::endl;
            else ss << "modify lighting-color \"" << _lighting_color << "\"" << std::endl;
        }
        if (_marker_end != element.get_marker_end()) {
            if (_marker_end == STR_NULL) ss << "reset marker-end" << std::endl;
            else ss << "modify marker-end \"" << _marker_end << "\"" << std::endl;
        }
        if (_marker_mid != element.get_marker_mid()) {
            if (_marker_mid == STR_NULL) ss << "reset marker-mid" << std::endl;
            else ss << "modify marker-mid \"" << _marker_mid << "\"" << std::endl;
        }
        if (_marker_start != element.get_marker_start()) {
            if (_marker_start == STR_NULL) ss << "reset marker-start" << std::endl;
            else ss << "modify marker-start \"" << _marker_start << "\"" << std::endl;
        }
        if (_mask != element.get_mask()) {
            if (_mask == STR_NULL) ss << "reset mask" << std::endl;
            else ss << "modify mask \"" << _mask << "\"" << std::endl;
        }
        if (_opacity != element.get_opacity()) {
            if (_opacity == STR_NULL) ss << "reset opacity" << std::endl;
            else ss << "modify opacity \"" << _opacity << "\"" << std::endl;
        }
        if (_overflow != element.get_overflow()) {
            if (_overflow == STR_NULL) ss << "reset overflow" << std::endl;
            else ss << "modify overflow \"" << _overflow << "\"" << std::endl;
        }
        if (_pointer_events != element.get_pointer_events()) {
            if (_pointer_events == STR_NULL) ss << "reset pointer-events" << std::endl;
            else ss << "modify pointer-events \"" << _pointer_events << "\"" << std::endl;
        }
        if (_shape_rendering != element.get_shape_rendering()) {
            if (_shape_rendering == STR_NULL) ss << "reset shape-rendering" << std::endl;
            else ss << "modify shape-rendering \"" << _shape_rendering << "\"" << std::endl;
        }
        if (_solid_color != element.get_solid_color()) {
            if (_solid_color == STR_NULL) ss << "reset solid-color" << std::endl;
            else ss << "modify solid-color \"" << _solid_color << "\"" << std::endl;
        }
        if (_solid_opacity != element.get_solid_opacity()) {
            if (_solid_opacity == STR_NULL) ss << "reset solid-opacity" << std::endl;
            else ss << "modify solid-opacity \"" << _solid_opacity << "\"" << std::endl;
        }
        if (_stop_color != element.get_stop_color()) {
            if (_stop_color == STR_NULL) ss << "reset stop-color" << std::endl;
            else ss << "modify stop-color \"" << _stop_color << "\"" << std::endl;
        }
        if (_stop_opacity != element.get_stop_opacity()) {
            if (_stop_opacity == STR_NULL) ss << "reset stop-opacity" << std::endl;
            else ss << "modify stop-opacity \"" << _stop_opacity << "\"" << std::endl;
        }
        if (_stroke != element.get_stroke()) {
            if (_stroke == STR_NULL) ss << "reset stroke" << std::endl;
            else ss << "modify stroke \"" << _stroke << "\"" << std::endl;
        }
        if (_stroke_dasharray != element.get_stroke_dasharray()) {
            if (_stroke_dasharray == STR_NULL) ss << "reset stroke-dasharray" << std::endl;
            else ss << "modify stroke-dasharray \"" << _stroke_dasharray << "\"" << std::endl;
        }
        if (_stroke_dashoffset != element.get_stroke_dashoffset()) {
            if (_stroke_dashoffset == STR_NULL) ss << "reset stroke-dashoffset" << std::endl;
            else ss << "modify stroke-dashoffset \"" << _stroke_dashoffset << "\"" << std::endl;
        }
        if (_stroke_linecap != element.get_stroke_linecap()) {
            if (_stroke_linecap == STR_NULL) ss << "reset stroke-linecap" << std::endl;
            else ss << "modify stroke-linecap \"" << _stroke_linecap << "\"" << std::endl;
        }
        if (_stroke_linejoin != element.get_stroke_linejoin()) {
            if (_stroke_linejoin == STR_NULL) ss << "reset stroke-linejoin" << std::endl;
            else ss << "modify stroke-linejoin \"" << _stroke_linejoin << "\"" << std::endl;
        }
        if (_stroke_miterlimit != element.get_stroke_miterlimit()) {
            if (_stroke_miterlimit == STR_NULL) ss << "reset stroke-miterlimit" << std::endl;
            else ss << "modify stroke-miterlimit \"" << _stroke_miterlimit << "\"" << std::endl;
        }
        if (_stroke_opacity != element.get_stroke_opacity()) {
            if (_stroke_opacity == STR_NULL) ss << "reset stroke-opacity" << std::endl;
            else ss << "modify stroke-opacity \"" << _stroke_opacity << "\"" << std::endl;
        }
        if (_stroke_width != element.get_stroke_width()) {
            if (_stroke_width == STR_NULL) ss << "reset stroke-width" << std::endl;
            else ss << "modify stroke-width \"" << _stroke_width << "\"" << std::endl;
        }
        if (_text_anchor != element.get_text_anchor()) {
            if (_text_anchor == STR_NULL) ss << "reset text-anchor" << std::endl;
            else ss << "modify text-anchor \"" << _text_anchor << "\"" << std::endl;
        }
        if (_text_decoration != element.get_text_decoration()) {
            if (_text_decoration == STR_NULL) ss << "reset text-decoration" << std::endl;
            else ss << "modify text-decoration \"" << _text_decoration << "\"" << std::endl;
        }
        if (_text_rendering != element.get_text_rendering()) {
            if (_text_rendering == STR_NULL) ss << "reset text-rendering" << std::endl;
            else ss << "modify text-rendering \"" << _text_rendering << "\"" << std::endl;
        }
        if (_transform != element.get_transform()) {
            if (_transform == STR_NULL) ss << "reset transform" << std::endl;
            else ss << "modify transform \"" << _transform << "\"" << std::endl;
        }
        if (_unicode_bidi != element.get_unicode_bidi()) {
            if (_unicode_bidi == STR_NULL) ss << "reset unicode-bidi" << std::endl;
            else ss << "modify unicode-bidi \"" << _unicode_bidi << "\"" << std::endl;
        }
        if (_vector_effect != element.get_vector_effect()) {
            if (_vector_effect == STR_NULL) ss << "reset vector-effect" << std::endl;
            else ss << "modify vector-effect \"" << _vector_effect << "\"" << std::endl;
        }
        if (_visibility != element.get_visibility()) {
            if (_visibility == STR_NULL) ss << "reset visibility" << std::endl;
            else ss << "modify visibility \"" << _visibility << "\"" << std::endl;
        }
        if (_word_spacing != element.get_word_spacing()) {
            if (_word_spacing == STR_NULL) ss << "reset word-spacing" << std::endl;
            else ss << "modify word-spacing \"" << _word_spacing << "\"" << std::endl;
        }
        if (_writing_mode != element.get_writing_mode()) {
            if (_writing_mode == STR_NULL) ss << "reset writing-mode" << std::endl;
            else ss << "modify writing-mode \"" << _writing_mode << "\"" << std::endl;
        }

        return ss.str();
    }
    void SVGElement::inner_differ(const SVGElement &element,
            std::vector<_el_idx> &removal,
            std::vector<_el_idx> &addition,
            std::vector<std::pair<_el_idx, _el_idx>> &unchanged,
            std::vector<std::pair<_el_idx, _el_idx>> &changed) const {
        std::function<const std::string(const std::shared_ptr<SVGElement> &)> get_tag;
        get_tag = [](const std::shared_ptr<SVGElement> &x){
            if (x->get_raw_HTML() != STR_NULL) return std::string("#") + std::to_string(x->get_outer_hash());
            return std::string(x->get_tag());
        };
        std::unordered_map<std::string, std::set<_el_idx>> tags_map;
        std::set<_el_idx> A, B;
        int c = 0;
        for (auto &a : _inner_elements) A.insert({a, c++}); c = 0;
        for (auto &b : element.get_inner_elements()) tags_map[get_tag(b)].insert({b, c}), B.insert({b, c++});

        c = 0;
        for (auto &_a : _inner_elements) { // with outer hash equal
            auto &tag  = get_tag(_a);
            _el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_outer_hash() == a.ptr->get_outer_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                unchanged.push_back({a, match});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements) { // with inner hash equal
            auto &tag  = get_tag(_a);
            _el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_inner_hash() == a.ptr->get_inner_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                changed.push_back({a, match});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements) { // with attribute hash equal
            auto &tag  = get_tag(_a);
            _el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag)) continue;
            _el_idx match = { nullptr, -1 };
            for (auto &b : tags_map[tag]) {
                if (b.ptr->get_attribute_hash() == a.ptr->get_attribute_hash()) {
                    match = b;
                    break;
                }
            }
            if (match.idx >= 0) {
                tags_map[tag].erase(match);
                A.erase(a), B.erase(match);
                changed.push_back({a, match});
            }
        }
        c = 0;
        for (auto &_a : _inner_elements) { // with tag equal
            auto &tag  = get_tag(_a);
            _el_idx a = { _a, c++ };
            if (!A.count(a) || !tags_map.count(tag) || tags_map[tag].size() == 0) continue;
            _el_idx match = *tags_map[tag].begin();
            tags_map[tag].erase(match);
            A.erase(a), B.erase(match);
            changed.push_back({a, match});
        }
        for (auto &a : A) addition.push_back(a);
        for (auto &b : B) removal.push_back(b);
    }
}
