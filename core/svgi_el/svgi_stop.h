#ifndef __LZ_SVGI_STOP__
#define __LZ_SVGI_STOP__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The SVG <stop> element defines a color and its position to use on a gradient. This element is always a child of a <linearGradient> or <radialGradient> element.
    */
    class SVGIStop : public virtual SVGIElement, public virtual SVGStop {
    public:
        /**
        * Constructor of circle.
        */
        SVGIStop();
    protected:
        virtual void _bind_getter_setter() override;

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

    private:
        void add_inner_element(const std::shared_ptr<SVGElement> &element) = delete;
        void remove_inner_element(const std::shared_ptr<SVGElement> &element, bool remove_all = false) = delete;
        using SVGStop::get_offset;
        using SVGStop::set_offset;
        using SVGStop::get_stop_color;
        using SVGStop::set_stop_color;
        using SVGStop::get_stop_opacity;
        using SVGStop::set_stop_opacity;
        using SVGElement::get_id;
        using SVGElement::set_id;
        using SVGElement::get_lang;
        using SVGElement::set_lang;
        using SVGElement::get_tabindex;
        using SVGElement::set_tabindex;
        using SVGElement::get_xmlZbase;
        using SVGElement::set_xmlZbase;
        using SVGElement::get_xmlZlang;
        using SVGElement::set_xmlZlang;
        using SVGElement::get_xmlZspace;
        using SVGElement::set_xmlZspace;
        using SVGElement::get_class;
        using SVGElement::set_class;
        using SVGElement::get_style;
        using SVGElement::set_style;
        using SVGElement::get_onbegin;
        using SVGElement::set_onbegin;
        using SVGElement::get_onend;
        using SVGElement::set_onend;
        using SVGElement::get_onrepeat;
        using SVGElement::set_onrepeat;
        using SVGElement::get_onabort;
        using SVGElement::set_onabort;
        using SVGElement::get_onerror;
        using SVGElement::set_onerror;
        using SVGElement::get_onresize;
        using SVGElement::set_onresize;
        using SVGElement::get_onscroll;
        using SVGElement::set_onscroll;
        using SVGElement::get_onunload;
        using SVGElement::set_onunload;
        using SVGElement::get_oncopy;
        using SVGElement::set_oncopy;
        using SVGElement::get_oncut;
        using SVGElement::set_oncut;
        using SVGElement::get_onpaste;
        using SVGElement::set_onpaste;
        using SVGElement::get_oncancel;
        using SVGElement::set_oncancel;
        using SVGElement::get_oncanplay;
        using SVGElement::set_oncanplay;
        using SVGElement::get_oncanplaythrough;
        using SVGElement::set_oncanplaythrough;
        using SVGElement::get_onchange;
        using SVGElement::set_onchange;
        using SVGElement::get_onclick;
        using SVGElement::set_onclick;
        using SVGElement::get_onclose;
        using SVGElement::set_onclose;
        using SVGElement::get_oncuechange;
        using SVGElement::set_oncuechange;
        using SVGElement::get_ondblclick;
        using SVGElement::set_ondblclick;
        using SVGElement::get_ondrag;
        using SVGElement::set_ondrag;
        using SVGElement::get_ondragend;
        using SVGElement::set_ondragend;
        using SVGElement::get_ondragenter;
        using SVGElement::set_ondragenter;
        using SVGElement::get_ondragleave;
        using SVGElement::set_ondragleave;
        using SVGElement::get_ondragover;
        using SVGElement::set_ondragover;
        using SVGElement::get_ondragstart;
        using SVGElement::set_ondragstart;
        using SVGElement::get_ondrop;
        using SVGElement::set_ondrop;
        using SVGElement::get_ondurationchange;
        using SVGElement::set_ondurationchange;
        using SVGElement::get_onemptied;
        using SVGElement::set_onemptied;
        using SVGElement::get_onended;
        using SVGElement::set_onended;
        using SVGElement::get_onfocus;
        using SVGElement::set_onfocus;
        using SVGElement::get_oninput;
        using SVGElement::set_oninput;
        using SVGElement::get_oninvalid;
        using SVGElement::set_oninvalid;
        using SVGElement::get_onkeydown;
        using SVGElement::set_onkeydown;
        using SVGElement::get_onkeypress;
        using SVGElement::set_onkeypress;
        using SVGElement::get_onkeyup;
        using SVGElement::set_onkeyup;
        using SVGElement::get_onload;
        using SVGElement::set_onload;
        using SVGElement::get_onloadeddata;
        using SVGElement::set_onloadeddata;
        using SVGElement::get_onloadedmetadata;
        using SVGElement::set_onloadedmetadata;
        using SVGElement::get_onloadstart;
        using SVGElement::set_onloadstart;
        using SVGElement::get_onmousedown;
        using SVGElement::set_onmousedown;
        using SVGElement::get_onmouseenter;
        using SVGElement::set_onmouseenter;
        using SVGElement::get_onmouseleave;
        using SVGElement::set_onmouseleave;
        using SVGElement::get_onmousemove;
        using SVGElement::set_onmousemove;
        using SVGElement::get_onmouseout;
        using SVGElement::set_onmouseout;
        using SVGElement::get_onmouseover;
        using SVGElement::set_onmouseover;
        using SVGElement::get_onmouseup;
        using SVGElement::set_onmouseup;
        using SVGElement::get_onmousewheel;
        using SVGElement::set_onmousewheel;
        using SVGElement::get_onpause;
        using SVGElement::set_onpause;
        using SVGElement::get_onplay;
        using SVGElement::set_onplay;
        using SVGElement::get_onplaying;
        using SVGElement::set_onplaying;
        using SVGElement::get_onprogress;
        using SVGElement::set_onprogress;
        using SVGElement::get_onratechange;
        using SVGElement::set_onratechange;
        using SVGElement::get_onreset;
        using SVGElement::set_onreset;
        using SVGElement::get_onseeked;
        using SVGElement::set_onseeked;
        using SVGElement::get_onseeking;
        using SVGElement::set_onseeking;
        using SVGElement::get_onselect;
        using SVGElement::set_onselect;
        using SVGElement::get_onshow;
        using SVGElement::set_onshow;
        using SVGElement::get_onstalled;
        using SVGElement::set_onstalled;
        using SVGElement::get_onsubmit;
        using SVGElement::set_onsubmit;
        using SVGElement::get_onsuspend;
        using SVGElement::set_onsuspend;
        using SVGElement::get_ontimeupdate;
        using SVGElement::set_ontimeupdate;
        using SVGElement::get_ontoggle;
        using SVGElement::set_ontoggle;
        using SVGElement::get_onvolumechange;
        using SVGElement::set_onvolumechange;
        using SVGElement::get_onwaiting;
        using SVGElement::set_onwaiting;
        using SVGElement::get_onactivate;
        using SVGElement::set_onactivate;
        using SVGElement::get_onfocusin;
        using SVGElement::set_onfocusin;
        using SVGElement::get_onfocusout;
        using SVGElement::set_onfocusout;
        using SVGElement::get_alignment_baseline;
        using SVGElement::set_alignment_baseline;
        using SVGElement::get_baseline_shift;
        using SVGElement::set_baseline_shift;
        using SVGElement::get_clip_path;
        using SVGElement::set_clip_path;
        using SVGElement::get_clip_rule;
        using SVGElement::set_clip_rule;
        using SVGElement::get_color;
        using SVGElement::set_color;
        using SVGElement::get_color_interpolation;
        using SVGElement::set_color_interpolation;
        using SVGElement::get_color_interpolation_filters;
        using SVGElement::set_color_interpolation_filters;
        using SVGElement::get_color_profile;
        using SVGElement::set_color_profile;
        using SVGElement::get_color_rendering;
        using SVGElement::set_color_rendering;
        using SVGElement::get_cursor;
        using SVGElement::set_cursor;
        using SVGElement::get_d;
        using SVGElement::set_d;
        using SVGElement::get_direction;
        using SVGElement::set_direction;
        using SVGElement::get_display;
        using SVGElement::set_display;
        using SVGElement::get_dominant_baseline;
        using SVGElement::set_dominant_baseline;
        using SVGElement::get_enable_background;
        using SVGElement::set_enable_background;
        using SVGElement::get_fill;
        using SVGElement::set_fill;
        using SVGElement::get_fill_opacity;
        using SVGElement::set_fill_opacity;
        using SVGElement::get_fill_rule;
        using SVGElement::set_fill_rule;
        using SVGElement::get_filter;
        using SVGElement::set_filter;
        using SVGElement::get_flood_color;
        using SVGElement::set_flood_color;
        using SVGElement::get_flood_opacity;
        using SVGElement::set_flood_opacity;
        using SVGElement::get_font_family;
        using SVGElement::set_font_family;
        using SVGElement::get_font_size;
        using SVGElement::set_font_size;
        using SVGElement::get_font_size_adjust;
        using SVGElement::set_font_size_adjust;
        using SVGElement::get_font_stretch;
        using SVGElement::set_font_stretch;
        using SVGElement::get_font_style;
        using SVGElement::set_font_style;
        using SVGElement::get_font_variant;
        using SVGElement::set_font_variant;
        using SVGElement::get_font_weight;
        using SVGElement::set_font_weight;
        using SVGElement::get_glyph_orientation_horizontal;
        using SVGElement::set_glyph_orientation_horizontal;
        using SVGElement::get_glyph_orientation_vertical;
        using SVGElement::set_glyph_orientation_vertical;
        using SVGElement::get_image_rendering;
        using SVGElement::set_image_rendering;
        using SVGElement::get_kerning;
        using SVGElement::set_kerning;
        using SVGElement::get_letter_spacing;
        using SVGElement::set_letter_spacing;
        using SVGElement::get_lighting_color;
        using SVGElement::set_lighting_color;
        using SVGElement::get_marker_end;
        using SVGElement::set_marker_end;
        using SVGElement::get_marker_mid;
        using SVGElement::set_marker_mid;
        using SVGElement::get_marker_start;
        using SVGElement::set_marker_start;
        using SVGElement::get_mask;
        using SVGElement::set_mask;
        using SVGElement::get_opacity;
        using SVGElement::set_opacity;
        using SVGElement::get_overflow;
        using SVGElement::set_overflow;
        using SVGElement::get_pointer_events;
        using SVGElement::set_pointer_events;
        using SVGElement::get_shape_rendering;
        using SVGElement::set_shape_rendering;
        using SVGElement::get_solid_color;
        using SVGElement::set_solid_color;
        using SVGElement::get_solid_opacity;
        using SVGElement::set_solid_opacity;
        using SVGElement::get_stop_color;
        using SVGElement::set_stop_color;
        using SVGElement::get_stop_opacity;
        using SVGElement::set_stop_opacity;
        using SVGElement::get_stroke;
        using SVGElement::set_stroke;
        using SVGElement::get_stroke_dasharray;
        using SVGElement::set_stroke_dasharray;
        using SVGElement::get_stroke_dashoffset;
        using SVGElement::set_stroke_dashoffset;
        using SVGElement::get_stroke_linecap;
        using SVGElement::set_stroke_linecap;
        using SVGElement::get_stroke_linejoin;
        using SVGElement::set_stroke_linejoin;
        using SVGElement::get_stroke_miterlimit;
        using SVGElement::set_stroke_miterlimit;
        using SVGElement::get_stroke_opacity;
        using SVGElement::set_stroke_opacity;
        using SVGElement::get_stroke_width;
        using SVGElement::set_stroke_width;
        using SVGElement::get_text_anchor;
        using SVGElement::set_text_anchor;
        using SVGElement::get_text_decoration;
        using SVGElement::set_text_decoration;
        using SVGElement::get_text_rendering;
        using SVGElement::set_text_rendering;
        using SVGElement::get_transform;
        using SVGElement::set_transform;
        using SVGElement::get_unicode_bidi;
        using SVGElement::set_unicode_bidi;
        using SVGElement::get_vector_effect;
        using SVGElement::set_vector_effect;
        using SVGElement::get_visibility;
        using SVGElement::set_visibility;
        using SVGElement::get_word_spacing;
        using SVGElement::set_word_spacing;
        using SVGElement::get_writing_mode;
        using SVGElement::set_writing_mode;

        /// Outer SVG
    public:
        /**
        * Get SVG of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string outer_SVG() const;

        /// Stop
    public:
        /**
        * This attribute defines where the gradient stop is placed along the gradient vector. 
        * Value type: <number>|<percentage>; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrNumber, AttrPercentage> Offset;
    public:
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<color>:icccolor; Default value: black; Animatable: yes
        */
        AttrEnumerate<AttrConstCurrentcolor, AttrColor, AttrColor> StopColor;
    public:
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity-value>; Default value: 1; Animatable: yes
        */
        AttrOpacityValue StopOpacity;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 3> _attr_on_assign = {
            [this](const std::string &last){
                if (Offset.get() == Offset.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (StopColor.get() == StopColor.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (StopOpacity.get() == StopOpacity.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
        };
        const std::array<std::function<void()>, 3> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
            std::bind([this](){
                modified.erase(1);
                bound.insert(1);
            }),
            std::bind([this](){
                modified.erase(2);
                bound.insert(2);
            }),
        };
        const std::array<std::function<const std::string()>, 3> _attr_commit = {
            [this](){
                if (SVGStop::get_offset() == Offset.get_commit()) return std::string("");
                Offset.commit();
                if (Offset.get() == STR_NULL) return std::string("reset offset");
                else return std::string("modify offset \"" + Offset.get() + "\"");
            },
            [this](){
                if (SVGStop::get_stop_color() == StopColor.get_commit()) return std::string("");
                StopColor.commit();
                if (StopColor.get() == STR_NULL) return std::string("reset stop-color");
                else return std::string("modify stop-color \"" + StopColor.get() + "\"");
            },
            [this](){
                if (SVGStop::get_stop_opacity() == StopOpacity.get_commit()) return std::string("");
                StopOpacity.commit();
                if (StopOpacity.get() == STR_NULL) return std::string("reset stop-opacity");
                else return std::string("modify stop-opacity \"" + StopOpacity.get() + "\"");
            },
        };

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string commit() override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        std::shared_ptr<SVGIStop> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIStop &operator=(const SVGIStop &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
