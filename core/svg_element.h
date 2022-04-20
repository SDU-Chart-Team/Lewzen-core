#ifndef __LZ_SVG_ELEMENT__
#define __LZ_SVG_ELEMENT__
#include <string>
#include <vector>
#include <memory>
#include "utils.h"

namespace Lewzen {
    /**
    * An SVG element.
    */
    class SVGElement: public std::enable_shared_from_this<SVGElement> {
    public:
        /**
        * Constructor of SVG element.
        */
        SVGElement();
        /**
        * Deep copy of SVG element.
        */
        SVGElement(const SVGElement &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Element
    private:
        std::string _id;
    private:
        std::string _lang;
    private:
        std::string _tabindex;
    private:
        std::string _xmlZbase;
    private:
        std::string _xmlZlang;
    private:
        std::string _xmlZspace;
    private:
        std::string _class;
    private:
        std::string _style;
    private:
        std::string _onbegin;
    private:
        std::string _onend;
    private:
        std::string _onrepeat;
    private:
        std::string _onabort;
    private:
        std::string _onerror;
    private:
        std::string _onresize;
    private:
        std::string _onscroll;
    private:
        std::string _onunload;
    private:
        std::string _oncopy;
    private:
        std::string _oncut;
    private:
        std::string _onpaste;
    private:
        std::string _oncancel;
    private:
        std::string _oncanplay;
    private:
        std::string _oncanplaythrough;
    private:
        std::string _onchange;
    private:
        std::string _onclick;
    private:
        std::string _onclose;
    private:
        std::string _oncuechange;
    private:
        std::string _ondblclick;
    private:
        std::string _ondrag;
    private:
        std::string _ondragend;
    private:
        std::string _ondragenter;
    private:
        std::string _ondragleave;
    private:
        std::string _ondragover;
    private:
        std::string _ondragstart;
    private:
        std::string _ondrop;
    private:
        std::string _ondurationchange;
    private:
        std::string _onemptied;
    private:
        std::string _onended;
    private:
        std::string _onfocus;
    private:
        std::string _oninput;
    private:
        std::string _oninvalid;
    private:
        std::string _onkeydown;
    private:
        std::string _onkeypress;
    private:
        std::string _onkeyup;
    private:
        std::string _onload;
    private:
        std::string _onloadeddata;
    private:
        std::string _onloadedmetadata;
    private:
        std::string _onloadstart;
    private:
        std::string _onmousedown;
    private:
        std::string _onmouseenter;
    private:
        std::string _onmouseleave;
    private:
        std::string _onmousemove;
    private:
        std::string _onmouseout;
    private:
        std::string _onmouseover;
    private:
        std::string _onmouseup;
    private:
        std::string _onmousewheel;
    private:
        std::string _onpause;
    private:
        std::string _onplay;
    private:
        std::string _onplaying;
    private:
        std::string _onprogress;
    private:
        std::string _onratechange;
    private:
        std::string _onreset;
    private:
        std::string _onseeked;
    private:
        std::string _onseeking;
    private:
        std::string _onselect;
    private:
        std::string _onshow;
    private:
        std::string _onstalled;
    private:
        std::string _onsubmit;
    private:
        std::string _onsuspend;
    private:
        std::string _ontimeupdate;
    private:
        std::string _ontoggle;
    private:
        std::string _onvolumechange;
    private:
        std::string _onwaiting;
    private:
        std::string _onactivate;
    private:
        std::string _onfocusin;
    private:
        std::string _onfocusout;
    private:
        std::string _alignment_baseline;
    private:
        std::string _baseline_shift;
    private:
        std::string _clip;
    private:
        std::string _clip_path;
    private:
        std::string _clip_rule;
    private:
        std::string _color;
    private:
        std::string _color_interpolation;
    private:
        std::string _color_interpolation_filters;
    private:
        std::string _color_profile;
    private:
        std::string _color_rendering;
    private:
        std::string _cursor;
    private:
        std::string _d;
    private:
        std::string _direction;
    private:
        std::string _display;
    private:
        std::string _dominant_baseline;
    private:
        std::string _enable_background;
    private:
        std::string _fill;
    private:
        std::string _fill_opacity;
    private:
        std::string _fill_rule;
    private:
        std::string _filter;
    private:
        std::string _flood_color;
    private:
        std::string _flood_opacity;
    private:
        std::string _font_family;
    private:
        std::string _font_size;
    private:
        std::string _font_size_adjust;
    private:
        std::string _font_stretch;
    private:
        std::string _font_style;
    private:
        std::string _font_variant;
    private:
        std::string _font_weight;
    private:
        std::string _glyph_orientation_horizontal;
    private:
        std::string _glyph_orientation_vertical;
    private:
        std::string _image_rendering;
    private:
        std::string _kerning;
    private:
        std::string _letter_spacing;
    private:
        std::string _lighting_color;
    private:
        std::string _marker_end;
    private:
        std::string _marker_mid;
    private:
        std::string _marker_start;
    private:
        std::string _mask;
    private:
        std::string _opacity;
    private:
        std::string _overflow;
    private:
        std::string _pointer_events;
    private:
        std::string _shape_rendering;
    private:
        std::string _solid_color;
    private:
        std::string _solid_opacity;
    private:
        std::string _stop_color;
    private:
        std::string _stop_opacity;
    private:
        std::string _stroke;
    private:
        std::string _stroke_dasharray;
    private:
        std::string _stroke_dashoffset;
    private:
        std::string _stroke_linecap;
    private:
        std::string _stroke_linejoin;
    private:
        std::string _stroke_miterlimit;
    private:
        std::string _stroke_opacity;
    private:
        std::string _stroke_width;
    private:
        std::string _text_anchor;
    private:
        std::string _text_decoration;
    private:
        std::string _text_rendering;
    private:
        std::string _transform;
    private:
        std::string _unicode_bidi;
    private:
        std::string _vector_effect;
    private:
        std::string _visibility;
    private:
        std::string _word_spacing;
    private:
        std::string _writing_mode;
    public:
        /**
        * Get Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        *
        * @return Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        */
        const std::string get_id() const;
        /**
        * Set Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        *
        * @param id Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        */
        void set_id(const std::string &id);
        /**
        * Get Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        *
        * @return Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        */
        const std::string get_lang() const;
        /**
        * Set Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        *
        * @param lang Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        */
        void set_lang(const std::string &lang);
        /**
        * Get The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
Value type: <integer>; Animatable: No
        *
        * @return The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
Value type: <integer>; Animatable: No
        */
        const std::string get_tabindex() const;
        /**
        * Set The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
Value type: <integer>; Animatable: No
        *
        * @param tabindex The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
Value type: <integer>; Animatable: No
        */
        void set_tabindex(const std::string &tabindex);
        /**
        * Get Specifies a base IRI other than the base IRI of the document. 
Value type: <IRI>; Animatable: No
        *
        * @return Specifies a base IRI other than the base IRI of the document. 
Value type: <IRI>; Animatable: No
        */
        const std::string get_xmlZbase() const;
        /**
        * Set Specifies a base IRI other than the base IRI of the document. 
Value type: <IRI>; Animatable: No
        *
        * @param xmlZbase Specifies a base IRI other than the base IRI of the document. 
Value type: <IRI>; Animatable: No
        */
        void set_xmlZbase(const std::string &xmlZbase);
        /**
        * Get It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        *
        * @return It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        */
        const std::string get_xmlZlang() const;
        /**
        * Set It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        *
        * @param xmlZlang It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        */
        void set_xmlZlang(const std::string &xmlZlang);
        /**
        * Get SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        *
        * @return SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        */
        const std::string get_xmlZspace() const;
        /**
        * Set SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        *
        * @param xmlZspace SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        */
        void set_xmlZspace(const std::string &xmlZspace);
        /**
        * Get Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        *
        * @return Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        */
        const std::string get_class() const;
        /**
        * Set Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        *
        * @param class Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        */
        void set_class(const std::string &_class_);
        /**
        * Get It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        *
        * @return It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        */
        const std::string get_style() const;
        /**
        * Set It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        *
        * @param style It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        */
        void set_style(const std::string &style);
        /**
        * Get Event of onbegin.
        *
        * @return Event of onbegin.
        */
        const std::string get_onbegin() const;
        /**
        * Set Event of onbegin.
        *
        * @param onbegin Event of onbegin.
        */
        void set_onbegin(const std::string &onbegin);
        /**
        * Get Event of onend.
        *
        * @return Event of onend.
        */
        const std::string get_onend() const;
        /**
        * Set Event of onend.
        *
        * @param onend Event of onend.
        */
        void set_onend(const std::string &onend);
        /**
        * Get Event of onrepeat.
        *
        * @return Event of onrepeat.
        */
        const std::string get_onrepeat() const;
        /**
        * Set Event of onrepeat.
        *
        * @param onrepeat Event of onrepeat.
        */
        void set_onrepeat(const std::string &onrepeat);
        /**
        * Get Event of onabort.
        *
        * @return Event of onabort.
        */
        const std::string get_onabort() const;
        /**
        * Set Event of onabort.
        *
        * @param onabort Event of onabort.
        */
        void set_onabort(const std::string &onabort);
        /**
        * Get Event of onerror.
        *
        * @return Event of onerror.
        */
        const std::string get_onerror() const;
        /**
        * Set Event of onerror.
        *
        * @param onerror Event of onerror.
        */
        void set_onerror(const std::string &onerror);
        /**
        * Get Event of onresize.
        *
        * @return Event of onresize.
        */
        const std::string get_onresize() const;
        /**
        * Set Event of onresize.
        *
        * @param onresize Event of onresize.
        */
        void set_onresize(const std::string &onresize);
        /**
        * Get Event of onscroll.
        *
        * @return Event of onscroll.
        */
        const std::string get_onscroll() const;
        /**
        * Set Event of onscroll.
        *
        * @param onscroll Event of onscroll.
        */
        void set_onscroll(const std::string &onscroll);
        /**
        * Get Event of onunload.
        *
        * @return Event of onunload.
        */
        const std::string get_onunload() const;
        /**
        * Set Event of onunload.
        *
        * @param onunload Event of onunload.
        */
        void set_onunload(const std::string &onunload);
        /**
        * Get Event of oncopy.
        *
        * @return Event of oncopy.
        */
        const std::string get_oncopy() const;
        /**
        * Set Event of oncopy.
        *
        * @param oncopy Event of oncopy.
        */
        void set_oncopy(const std::string &oncopy);
        /**
        * Get Event of oncut.
        *
        * @return Event of oncut.
        */
        const std::string get_oncut() const;
        /**
        * Set Event of oncut.
        *
        * @param oncut Event of oncut.
        */
        void set_oncut(const std::string &oncut);
        /**
        * Get Event of onpaste.
        *
        * @return Event of onpaste.
        */
        const std::string get_onpaste() const;
        /**
        * Set Event of onpaste.
        *
        * @param onpaste Event of onpaste.
        */
        void set_onpaste(const std::string &onpaste);
        /**
        * Get Event of oncancel.
        *
        * @return Event of oncancel.
        */
        const std::string get_oncancel() const;
        /**
        * Set Event of oncancel.
        *
        * @param oncancel Event of oncancel.
        */
        void set_oncancel(const std::string &oncancel);
        /**
        * Get Event of oncanplay.
        *
        * @return Event of oncanplay.
        */
        const std::string get_oncanplay() const;
        /**
        * Set Event of oncanplay.
        *
        * @param oncanplay Event of oncanplay.
        */
        void set_oncanplay(const std::string &oncanplay);
        /**
        * Get Event of oncanplaythrough.
        *
        * @return Event of oncanplaythrough.
        */
        const std::string get_oncanplaythrough() const;
        /**
        * Set Event of oncanplaythrough.
        *
        * @param oncanplaythrough Event of oncanplaythrough.
        */
        void set_oncanplaythrough(const std::string &oncanplaythrough);
        /**
        * Get Event of onchange.
        *
        * @return Event of onchange.
        */
        const std::string get_onchange() const;
        /**
        * Set Event of onchange.
        *
        * @param onchange Event of onchange.
        */
        void set_onchange(const std::string &onchange);
        /**
        * Get Event of onclick.
        *
        * @return Event of onclick.
        */
        const std::string get_onclick() const;
        /**
        * Set Event of onclick.
        *
        * @param onclick Event of onclick.
        */
        void set_onclick(const std::string &onclick);
        /**
        * Get Event of onclose.
        *
        * @return Event of onclose.
        */
        const std::string get_onclose() const;
        /**
        * Set Event of onclose.
        *
        * @param onclose Event of onclose.
        */
        void set_onclose(const std::string &onclose);
        /**
        * Get Event of oncuechange.
        *
        * @return Event of oncuechange.
        */
        const std::string get_oncuechange() const;
        /**
        * Set Event of oncuechange.
        *
        * @param oncuechange Event of oncuechange.
        */
        void set_oncuechange(const std::string &oncuechange);
        /**
        * Get Event of ondblclick.
        *
        * @return Event of ondblclick.
        */
        const std::string get_ondblclick() const;
        /**
        * Set Event of ondblclick.
        *
        * @param ondblclick Event of ondblclick.
        */
        void set_ondblclick(const std::string &ondblclick);
        /**
        * Get Event of ondrag.
        *
        * @return Event of ondrag.
        */
        const std::string get_ondrag() const;
        /**
        * Set Event of ondrag.
        *
        * @param ondrag Event of ondrag.
        */
        void set_ondrag(const std::string &ondrag);
        /**
        * Get Event of ondragend.
        *
        * @return Event of ondragend.
        */
        const std::string get_ondragend() const;
        /**
        * Set Event of ondragend.
        *
        * @param ondragend Event of ondragend.
        */
        void set_ondragend(const std::string &ondragend);
        /**
        * Get Event of ondragenter.
        *
        * @return Event of ondragenter.
        */
        const std::string get_ondragenter() const;
        /**
        * Set Event of ondragenter.
        *
        * @param ondragenter Event of ondragenter.
        */
        void set_ondragenter(const std::string &ondragenter);
        /**
        * Get Event of ondragleave.
        *
        * @return Event of ondragleave.
        */
        const std::string get_ondragleave() const;
        /**
        * Set Event of ondragleave.
        *
        * @param ondragleave Event of ondragleave.
        */
        void set_ondragleave(const std::string &ondragleave);
        /**
        * Get Event of ondragover.
        *
        * @return Event of ondragover.
        */
        const std::string get_ondragover() const;
        /**
        * Set Event of ondragover.
        *
        * @param ondragover Event of ondragover.
        */
        void set_ondragover(const std::string &ondragover);
        /**
        * Get Event of ondragstart.
        *
        * @return Event of ondragstart.
        */
        const std::string get_ondragstart() const;
        /**
        * Set Event of ondragstart.
        *
        * @param ondragstart Event of ondragstart.
        */
        void set_ondragstart(const std::string &ondragstart);
        /**
        * Get Event of ondrop.
        *
        * @return Event of ondrop.
        */
        const std::string get_ondrop() const;
        /**
        * Set Event of ondrop.
        *
        * @param ondrop Event of ondrop.
        */
        void set_ondrop(const std::string &ondrop);
        /**
        * Get Event of ondurationchange.
        *
        * @return Event of ondurationchange.
        */
        const std::string get_ondurationchange() const;
        /**
        * Set Event of ondurationchange.
        *
        * @param ondurationchange Event of ondurationchange.
        */
        void set_ondurationchange(const std::string &ondurationchange);
        /**
        * Get Event of onemptied.
        *
        * @return Event of onemptied.
        */
        const std::string get_onemptied() const;
        /**
        * Set Event of onemptied.
        *
        * @param onemptied Event of onemptied.
        */
        void set_onemptied(const std::string &onemptied);
        /**
        * Get Event of onended.
        *
        * @return Event of onended.
        */
        const std::string get_onended() const;
        /**
        * Set Event of onended.
        *
        * @param onended Event of onended.
        */
        void set_onended(const std::string &onended);
        /**
        * Get Event of onfocus.
        *
        * @return Event of onfocus.
        */
        const std::string get_onfocus() const;
        /**
        * Set Event of onfocus.
        *
        * @param onfocus Event of onfocus.
        */
        void set_onfocus(const std::string &onfocus);
        /**
        * Get Event of oninput.
        *
        * @return Event of oninput.
        */
        const std::string get_oninput() const;
        /**
        * Set Event of oninput.
        *
        * @param oninput Event of oninput.
        */
        void set_oninput(const std::string &oninput);
        /**
        * Get Event of oninvalid.
        *
        * @return Event of oninvalid.
        */
        const std::string get_oninvalid() const;
        /**
        * Set Event of oninvalid.
        *
        * @param oninvalid Event of oninvalid.
        */
        void set_oninvalid(const std::string &oninvalid);
        /**
        * Get Event of onkeydown.
        *
        * @return Event of onkeydown.
        */
        const std::string get_onkeydown() const;
        /**
        * Set Event of onkeydown.
        *
        * @param onkeydown Event of onkeydown.
        */
        void set_onkeydown(const std::string &onkeydown);
        /**
        * Get Event of onkeypress.
        *
        * @return Event of onkeypress.
        */
        const std::string get_onkeypress() const;
        /**
        * Set Event of onkeypress.
        *
        * @param onkeypress Event of onkeypress.
        */
        void set_onkeypress(const std::string &onkeypress);
        /**
        * Get Event of onkeyup.
        *
        * @return Event of onkeyup.
        */
        const std::string get_onkeyup() const;
        /**
        * Set Event of onkeyup.
        *
        * @param onkeyup Event of onkeyup.
        */
        void set_onkeyup(const std::string &onkeyup);
        /**
        * Get Event of onload.
        *
        * @return Event of onload.
        */
        const std::string get_onload() const;
        /**
        * Set Event of onload.
        *
        * @param onload Event of onload.
        */
        void set_onload(const std::string &onload);
        /**
        * Get Event of onloadeddata.
        *
        * @return Event of onloadeddata.
        */
        const std::string get_onloadeddata() const;
        /**
        * Set Event of onloadeddata.
        *
        * @param onloadeddata Event of onloadeddata.
        */
        void set_onloadeddata(const std::string &onloadeddata);
        /**
        * Get Event of onloadedmetadata.
        *
        * @return Event of onloadedmetadata.
        */
        const std::string get_onloadedmetadata() const;
        /**
        * Set Event of onloadedmetadata.
        *
        * @param onloadedmetadata Event of onloadedmetadata.
        */
        void set_onloadedmetadata(const std::string &onloadedmetadata);
        /**
        * Get Event of onloadstart.
        *
        * @return Event of onloadstart.
        */
        const std::string get_onloadstart() const;
        /**
        * Set Event of onloadstart.
        *
        * @param onloadstart Event of onloadstart.
        */
        void set_onloadstart(const std::string &onloadstart);
        /**
        * Get Event of onmousedown.
        *
        * @return Event of onmousedown.
        */
        const std::string get_onmousedown() const;
        /**
        * Set Event of onmousedown.
        *
        * @param onmousedown Event of onmousedown.
        */
        void set_onmousedown(const std::string &onmousedown);
        /**
        * Get Event of onmouseenter.
        *
        * @return Event of onmouseenter.
        */
        const std::string get_onmouseenter() const;
        /**
        * Set Event of onmouseenter.
        *
        * @param onmouseenter Event of onmouseenter.
        */
        void set_onmouseenter(const std::string &onmouseenter);
        /**
        * Get Event of onmouseleave.
        *
        * @return Event of onmouseleave.
        */
        const std::string get_onmouseleave() const;
        /**
        * Set Event of onmouseleave.
        *
        * @param onmouseleave Event of onmouseleave.
        */
        void set_onmouseleave(const std::string &onmouseleave);
        /**
        * Get Event of onmousemove.
        *
        * @return Event of onmousemove.
        */
        const std::string get_onmousemove() const;
        /**
        * Set Event of onmousemove.
        *
        * @param onmousemove Event of onmousemove.
        */
        void set_onmousemove(const std::string &onmousemove);
        /**
        * Get Event of onmouseout.
        *
        * @return Event of onmouseout.
        */
        const std::string get_onmouseout() const;
        /**
        * Set Event of onmouseout.
        *
        * @param onmouseout Event of onmouseout.
        */
        void set_onmouseout(const std::string &onmouseout);
        /**
        * Get Event of onmouseover.
        *
        * @return Event of onmouseover.
        */
        const std::string get_onmouseover() const;
        /**
        * Set Event of onmouseover.
        *
        * @param onmouseover Event of onmouseover.
        */
        void set_onmouseover(const std::string &onmouseover);
        /**
        * Get Event of onmouseup.
        *
        * @return Event of onmouseup.
        */
        const std::string get_onmouseup() const;
        /**
        * Set Event of onmouseup.
        *
        * @param onmouseup Event of onmouseup.
        */
        void set_onmouseup(const std::string &onmouseup);
        /**
        * Get Event of onmousewheel.
        *
        * @return Event of onmousewheel.
        */
        const std::string get_onmousewheel() const;
        /**
        * Set Event of onmousewheel.
        *
        * @param onmousewheel Event of onmousewheel.
        */
        void set_onmousewheel(const std::string &onmousewheel);
        /**
        * Get Event of onpause.
        *
        * @return Event of onpause.
        */
        const std::string get_onpause() const;
        /**
        * Set Event of onpause.
        *
        * @param onpause Event of onpause.
        */
        void set_onpause(const std::string &onpause);
        /**
        * Get Event of onplay.
        *
        * @return Event of onplay.
        */
        const std::string get_onplay() const;
        /**
        * Set Event of onplay.
        *
        * @param onplay Event of onplay.
        */
        void set_onplay(const std::string &onplay);
        /**
        * Get Event of onplaying.
        *
        * @return Event of onplaying.
        */
        const std::string get_onplaying() const;
        /**
        * Set Event of onplaying.
        *
        * @param onplaying Event of onplaying.
        */
        void set_onplaying(const std::string &onplaying);
        /**
        * Get Event of onprogress.
        *
        * @return Event of onprogress.
        */
        const std::string get_onprogress() const;
        /**
        * Set Event of onprogress.
        *
        * @param onprogress Event of onprogress.
        */
        void set_onprogress(const std::string &onprogress);
        /**
        * Get Event of onratechange.
        *
        * @return Event of onratechange.
        */
        const std::string get_onratechange() const;
        /**
        * Set Event of onratechange.
        *
        * @param onratechange Event of onratechange.
        */
        void set_onratechange(const std::string &onratechange);
        /**
        * Get Event of onreset.
        *
        * @return Event of onreset.
        */
        const std::string get_onreset() const;
        /**
        * Set Event of onreset.
        *
        * @param onreset Event of onreset.
        */
        void set_onreset(const std::string &onreset);
        /**
        * Get Event of onseeked.
        *
        * @return Event of onseeked.
        */
        const std::string get_onseeked() const;
        /**
        * Set Event of onseeked.
        *
        * @param onseeked Event of onseeked.
        */
        void set_onseeked(const std::string &onseeked);
        /**
        * Get Event of onseeking.
        *
        * @return Event of onseeking.
        */
        const std::string get_onseeking() const;
        /**
        * Set Event of onseeking.
        *
        * @param onseeking Event of onseeking.
        */
        void set_onseeking(const std::string &onseeking);
        /**
        * Get Event of onselect.
        *
        * @return Event of onselect.
        */
        const std::string get_onselect() const;
        /**
        * Set Event of onselect.
        *
        * @param onselect Event of onselect.
        */
        void set_onselect(const std::string &onselect);
        /**
        * Get Event of onshow.
        *
        * @return Event of onshow.
        */
        const std::string get_onshow() const;
        /**
        * Set Event of onshow.
        *
        * @param onshow Event of onshow.
        */
        void set_onshow(const std::string &onshow);
        /**
        * Get Event of onstalled.
        *
        * @return Event of onstalled.
        */
        const std::string get_onstalled() const;
        /**
        * Set Event of onstalled.
        *
        * @param onstalled Event of onstalled.
        */
        void set_onstalled(const std::string &onstalled);
        /**
        * Get Event of onsubmit.
        *
        * @return Event of onsubmit.
        */
        const std::string get_onsubmit() const;
        /**
        * Set Event of onsubmit.
        *
        * @param onsubmit Event of onsubmit.
        */
        void set_onsubmit(const std::string &onsubmit);
        /**
        * Get Event of onsuspend.
        *
        * @return Event of onsuspend.
        */
        const std::string get_onsuspend() const;
        /**
        * Set Event of onsuspend.
        *
        * @param onsuspend Event of onsuspend.
        */
        void set_onsuspend(const std::string &onsuspend);
        /**
        * Get Event of ontimeupdate.
        *
        * @return Event of ontimeupdate.
        */
        const std::string get_ontimeupdate() const;
        /**
        * Set Event of ontimeupdate.
        *
        * @param ontimeupdate Event of ontimeupdate.
        */
        void set_ontimeupdate(const std::string &ontimeupdate);
        /**
        * Get Event of ontoggle.
        *
        * @return Event of ontoggle.
        */
        const std::string get_ontoggle() const;
        /**
        * Set Event of ontoggle.
        *
        * @param ontoggle Event of ontoggle.
        */
        void set_ontoggle(const std::string &ontoggle);
        /**
        * Get Event of onvolumechange.
        *
        * @return Event of onvolumechange.
        */
        const std::string get_onvolumechange() const;
        /**
        * Set Event of onvolumechange.
        *
        * @param onvolumechange Event of onvolumechange.
        */
        void set_onvolumechange(const std::string &onvolumechange);
        /**
        * Get Event of onwaiting.
        *
        * @return Event of onwaiting.
        */
        const std::string get_onwaiting() const;
        /**
        * Set Event of onwaiting.
        *
        * @param onwaiting Event of onwaiting.
        */
        void set_onwaiting(const std::string &onwaiting);
        /**
        * Get Event of onactivate.
        *
        * @return Event of onactivate.
        */
        const std::string get_onactivate() const;
        /**
        * Set Event of onactivate.
        *
        * @param onactivate Event of onactivate.
        */
        void set_onactivate(const std::string &onactivate);
        /**
        * Get Event of onfocusin.
        *
        * @return Event of onfocusin.
        */
        const std::string get_onfocusin() const;
        /**
        * Set Event of onfocusin.
        *
        * @param onfocusin Event of onfocusin.
        */
        void set_onfocusin(const std::string &onfocusin);
        /**
        * Get Event of onfocusout.
        *
        * @return Event of onfocusout.
        */
        const std::string get_onfocusout() const;
        /**
        * Set Event of onfocusout.
        *
        * @param onfocusout Event of onfocusout.
        */
        void set_onfocusout(const std::string &onfocusout);
        /**
        * Get It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        *
        * @return It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        */
        const std::string get_alignment_baseline() const;
        /**
        * Set It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        *
        * @param alignment_baseline It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        */
        void set_alignment_baseline(const std::string &alignment_baseline);
        /**
        * Get It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        *
        * @return It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        */
        const std::string get_baseline_shift() const;
        /**
        * Set It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        *
        * @param baseline_shift It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        */
        void set_baseline_shift(const std::string &baseline_shift);
        /**
        * Get It defines what portion of an element is visible. 
        * Value: auto|<shape()>|inherit; Animatable: Yes
        *
        * @return It defines what portion of an element is visible. 
        * Value: auto|<shape()>|inherit; Animatable: Yes
        */
        const std::string get_clip() const;
        /**
        * Set It defines what portion of an element is visible. 
        * Value: auto|<shape()>|inherit; Animatable: Yes
        *
        * @param clip It defines what portion of an element is visible. 
        * Value: auto|<shape()>|inherit; Animatable: Yes
        */
        void set_clip(const std::string &clip);
        /**
        * Get It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        *
        * @return It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        */
        const std::string get_clip_path() const;
        /**
        * Set It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        *
        * @param clip_path It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        */
        void set_clip_path(const std::string &clip_path);
        /**
        * Get It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        *
        * @return It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        */
        const std::string get_clip_rule() const;
        /**
        * Set It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        *
        * @param clip_rule It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        */
        void set_clip_rule(const std::string &clip_rule);
        /**
        * Get It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        *
        * @return It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        */
        const std::string get_color() const;
        /**
        * Set It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        *
        * @param color It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        */
        void set_color(const std::string &color);
        /**
        * Get It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @return It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        const std::string get_color_interpolation() const;
        /**
        * Set It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @param color_interpolation It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        void set_color_interpolation(const std::string &color_interpolation);
        /**
        * Get It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @return It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        const std::string get_color_interpolation_filters() const;
        /**
        * Set It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @param color_interpolation_filters It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        */
        void set_color_interpolation_filters(const std::string &color_interpolation_filters);
        /**
        * Get It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        *
        * @return It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        */
        const std::string get_color_profile() const;
        /**
        * Set It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        *
        * @param color_profile It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        */
        void set_color_profile(const std::string &color_profile);
        /**
        * Get It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        *
        * @return It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        */
        const std::string get_color_rendering() const;
        /**
        * Set It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        *
        * @param color_rendering It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        */
        void set_color_rendering(const std::string &color_rendering);
        /**
        * Get It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<keywords>|inherit; Animatable: Yes
        *
        * @return It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<keywords>|inherit; Animatable: Yes
        */
        const std::string get_cursor() const;
        /**
        * Set It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<keywords>|inherit; Animatable: Yes
        *
        * @param cursor It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<keywords>|inherit; Animatable: Yes
        */
        void set_cursor(const std::string &cursor);
        /**
        * Get It defines a path to be drawn. 
        * Value: path()|none
        *
        * @return It defines a path to be drawn. 
        * Value: path()|none
        */
        const std::string get_d() const;
        /**
        * Set It defines a path to be drawn. 
        * Value: path()|none
        *
        * @param d It defines a path to be drawn. 
        * Value: path()|none
        */
        void set_d(const std::string &d);
        /**
        * Get It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        *
        * @return It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        */
        const std::string get_direction() const;
        /**
        * Set It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        *
        * @param direction It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        */
        void set_direction(const std::string &direction);
        /**
        * Get It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        *
        * @return It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        */
        const std::string get_display() const;
        /**
        * Set It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        *
        * @param display It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        */
        void set_display(const std::string &display);
        /**
        * Get It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        *
        * @return It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        */
        const std::string get_dominant_baseline() const;
        /**
        * Set It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        *
        * @param dominant_baseline It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        */
        void set_dominant_baseline(const std::string &dominant_baseline);
        /**
        * Get It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        *
        * @return It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        */
        const std::string get_enable_background() const;
        /**
        * Set It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        *
        * @param enable_background It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        */
        void set_enable_background(const std::string &enable_background);
        /**
        * Get It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        *
        * @return It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        */
        const std::string get_fill() const;
        /**
        * Set It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        *
        * @param fill It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        */
        void set_fill(const std::string &fill);
        /**
        * Get It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @return It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        const std::string get_fill_opacity() const;
        /**
        * Set It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @param fill_opacity It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        void set_fill_opacity(const std::string &fill_opacity);
        /**
        * Get It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        *
        * @return It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        */
        const std::string get_fill_rule() const;
        /**
        * Set It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        *
        * @param fill_rule It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        */
        void set_fill_rule(const std::string &fill_rule);
        /**
        * Get It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        const std::string get_filter() const;
        /**
        * Set It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param filter It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        void set_filter(const std::string &filter);
        /**
        * Get It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        *
        * @return It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        */
        const std::string get_flood_color() const;
        /**
        * Set It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        *
        * @param flood_color It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        */
        void set_flood_color(const std::string &flood_color);
        /**
        * Get It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @return It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        const std::string get_flood_opacity() const;
        /**
        * Set It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @param flood_opacity It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        */
        void set_flood_opacity(const std::string &flood_opacity);
        /**
        * Get It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        *
        * @return It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        */
        const std::string get_font_family() const;
        /**
        * Set It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        *
        * @param font_family It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        */
        void set_font_family(const std::string &font_family);
        /**
        * Get It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        *
        * @return It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        */
        const std::string get_font_size() const;
        /**
        * Set It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        *
        * @param font_size It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        */
        void set_font_size(const std::string &font_size);
        /**
        * Get It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        *
        * @return It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        */
        const std::string get_font_size_adjust() const;
        /**
        * Set It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        *
        * @param font_size_adjust It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        */
        void set_font_size_adjust(const std::string &font_size_adjust);
        /**
        * Get It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        *
        * @return It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        */
        const std::string get_font_stretch() const;
        /**
        * Set It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        *
        * @param font_stretch It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        */
        void set_font_stretch(const std::string &font_stretch);
        /**
        * Get It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        *
        * @return It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        */
        const std::string get_font_style() const;
        /**
        * Set It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        *
        * @param font_style It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        */
        void set_font_style(const std::string &font_style);
        /**
        * Get It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        *
        * @return It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        */
        const std::string get_font_variant() const;
        /**
        * Set It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        *
        * @param font_variant It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        */
        void set_font_variant(const std::string &font_variant);
        /**
        * Get It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        *
        * @return It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        */
        const std::string get_font_weight() const;
        /**
        * Set It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        *
        * @param font_weight It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        */
        void set_font_weight(const std::string &font_weight);
        /**
        * Get It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        *
        * @return It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        */
        const std::string get_glyph_orientation_horizontal() const;
        /**
        * Set It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        *
        * @param glyph_orientation_horizontal It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        */
        void set_glyph_orientation_horizontal(const std::string &glyph_orientation_horizontal);
        /**
        * Get It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        *
        * @return It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        */
        const std::string get_glyph_orientation_vertical() const;
        /**
        * Set It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        *
        * @param glyph_orientation_vertical It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        */
        void set_glyph_orientation_vertical(const std::string &glyph_orientation_vertical);
        /**
        * Get It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        *
        * @return It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        */
        const std::string get_image_rendering() const;
        /**
        * Set It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        *
        * @param image_rendering It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        */
        void set_image_rendering(const std::string &image_rendering);
        /**
        * Get It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        *
        * @return It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        */
        const std::string get_kerning() const;
        /**
        * Set It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        *
        * @param kerning It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        */
        void set_kerning(const std::string &kerning);
        /**
        * Get It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        *
        * @return It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        */
        const std::string get_letter_spacing() const;
        /**
        * Set It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        *
        * @param letter_spacing It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        */
        void set_letter_spacing(const std::string &letter_spacing);
        /**
        * Get It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        *
        * @return It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        */
        const std::string get_lighting_color() const;
        /**
        * Set It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        *
        * @param lighting_color It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        */
        void set_lighting_color(const std::string &lighting_color);
        /**
        * Get It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        const std::string get_marker_end() const;
        /**
        * Set It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param marker_end It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        void set_marker_end(const std::string &marker_end);
        /**
        * Get It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        const std::string get_marker_mid() const;
        /**
        * Set It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param marker_mid It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        void set_marker_mid(const std::string &marker_mid);
        /**
        * Get It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        const std::string get_marker_start() const;
        /**
        * Set It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param marker_start It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <path> element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        */
        void set_marker_start(const std::string &marker_start);
        /**
        * Get It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        *
        * @return It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        */
        const std::string get_mask() const;
        /**
        * Set It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        *
        * @param mask It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        */
        void set_mask(const std::string &mask);
        /**
        * Get It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        *
        * @return It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        */
        const std::string get_opacity() const;
        /**
        * Set It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        *
        * @param opacity It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        */
        void set_opacity(const std::string &opacity);
        /**
        * Get Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        *
        * @return Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        */
        const std::string get_overflow() const;
        /**
        * Set Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        *
        * @param overflow Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        */
        void set_overflow(const std::string &overflow);
        /**
        * Get Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        *
        * @return Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        */
        const std::string get_pointer_events() const;
        /**
        * Set Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        *
        * @param pointer_events Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        */
        void set_pointer_events(const std::string &pointer_events);
        /**
        * Get Hints about what tradeoffs to make as the browser renders <path> element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        *
        * @return Hints about what tradeoffs to make as the browser renders <path> element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        */
        const std::string get_shape_rendering() const;
        /**
        * Set Hints about what tradeoffs to make as the browser renders <path> element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        *
        * @param shape_rendering Hints about what tradeoffs to make as the browser renders <path> element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        */
        void set_shape_rendering(const std::string &shape_rendering);
        /**
        * Get - 
        * Value:; Animatable: -
        *
        * @return - 
        * Value:; Animatable: -
        */
        const std::string get_solid_color() const;
        /**
        * Set - 
        * Value:; Animatable: -
        *
        * @param solid_color - 
        * Value:; Animatable: -
        */
        void set_solid_color(const std::string &solid_color);
        /**
        * Get - 
        * Value:; Animatable: -
        *
        * @return - 
        * Value:; Animatable: -
        */
        const std::string get_solid_opacity() const;
        /**
        * Set - 
        * Value:; Animatable: -
        *
        * @param solid_opacity - 
        * Value:; Animatable: -
        */
        void set_solid_opacity(const std::string &solid_opacity);
        /**
        * Get Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<icccolor>|inherit; Animatable: Yes
        *
        * @return Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<icccolor>|inherit; Animatable: Yes
        */
        const std::string get_stop_color() const;
        /**
        * Set Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<icccolor>|inherit; Animatable: Yes
        *
        * @param stop_color Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<icccolor>|inherit; Animatable: Yes
        */
        void set_stop_color(const std::string &stop_color);
        /**
        * Get Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        *
        * @return Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        */
        const std::string get_stop_opacity() const;
        /**
        * Set Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        *
        * @param stop_opacity Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        */
        void set_stop_opacity(const std::string &stop_opacity);
        /**
        * Get Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        *
        * @return Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        */
        const std::string get_stroke() const;
        /**
        * Set Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        *
        * @param stroke Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        */
        void set_stroke(const std::string &stroke);
        /**
        * Get Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<dasharray>; Animatable: Yes
        *
        * @return Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<dasharray>; Animatable: Yes
        */
        const std::string get_stroke_dasharray() const;
        /**
        * Set Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<dasharray>; Animatable: Yes
        *
        * @param stroke_dasharray Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<dasharray>; Animatable: Yes
        */
        void set_stroke_dasharray(const std::string &stroke_dasharray);
        /**
        * Get Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        *
        * @return Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        */
        const std::string get_stroke_dashoffset() const;
        /**
        * Set Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        *
        * @param stroke_dashoffset Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        */
        void set_stroke_dashoffset(const std::string &stroke_dashoffset);
        /**
        * Get Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        *
        * @return Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        */
        const std::string get_stroke_linecap() const;
        /**
        * Set Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        *
        * @param stroke_linecap Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        */
        void set_stroke_linecap(const std::string &stroke_linecap);
        /**
        * Get Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        *
        * @return Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        */
        const std::string get_stroke_linejoin() const;
        /**
        * Set Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        *
        * @param stroke_linejoin Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        */
        void set_stroke_linejoin(const std::string &stroke_linejoin);
        /**
        * Get Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        *
        * @return Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        */
        const std::string get_stroke_miterlimit() const;
        /**
        * Set Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        *
        * @param stroke_miterlimit Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        */
        void set_stroke_miterlimit(const std::string &stroke_miterlimit);
        /**
        * Get Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        *
        * @return Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        */
        const std::string get_stroke_opacity() const;
        /**
        * Set Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        *
        * @param stroke_opacity Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        */
        void set_stroke_opacity(const std::string &stroke_opacity);
        /**
        * Get Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        *
        * @return Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        */
        const std::string get_stroke_width() const;
        /**
        * Set Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        *
        * @param stroke_width Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        */
        void set_stroke_width(const std::string &stroke_width);
        /**
        * Get Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        *
        * @return Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        */
        const std::string get_text_anchor() const;
        /**
        * Set Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        *
        * @param text_anchor Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        */
        void set_text_anchor(const std::string &text_anchor);
        /**
        * Get Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        *
        * @return Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        */
        const std::string get_text_decoration() const;
        /**
        * Set Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        *
        * @param text_decoration Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        */
        void set_text_decoration(const std::string &text_decoration);
        /**
        * Get Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        *
        * @return Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        */
        const std::string get_text_rendering() const;
        /**
        * Set Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        *
        * @param text_rendering Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        */
        void set_text_rendering(const std::string &text_rendering);
        /**
        * Get Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        *
        * @return Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        */
        const std::string get_transform() const;
        /**
        * Set Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        *
        * @param transform Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        */
        void set_transform(const std::string &transform);
        /**
        * Get - 
        * Value:; Animatable: -
        *
        * @return - 
        * Value:; Animatable: -
        */
        const std::string get_unicode_bidi() const;
        /**
        * Set - 
        * Value:; Animatable: -
        *
        * @param unicode_bidi - 
        * Value:; Animatable: -
        */
        void set_unicode_bidi(const std::string &unicode_bidi);
        /**
        * Get Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<uri>; Animatable: Yes
        *
        * @return Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<uri>; Animatable: Yes
        */
        const std::string get_vector_effect() const;
        /**
        * Set Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<uri>; Animatable: Yes
        *
        * @param vector_effect Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<uri>; Animatable: Yes
        */
        void set_vector_effect(const std::string &vector_effect);
        /**
        * Get Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        *
        * @return Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        */
        const std::string get_visibility() const;
        /**
        * Set Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        *
        * @param visibility Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        */
        void set_visibility(const std::string &visibility);
        /**
        * Get Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        *
        * @return Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        */
        const std::string get_word_spacing() const;
        /**
        * Set Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        *
        * @param word_spacing Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        */
        void set_word_spacing(const std::string &word_spacing);
        /**
        * Get Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        *
        * @return Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        */
        const std::string get_writing_mode() const;
        /**
        * Set Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        *
        * @param writing_mode Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        */
        void set_writing_mode(const std::string &writing_mode);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string get_attributes() const;
        
        /// Inner SVG
    private:
        std::string _inner_text;
        std::vector<std::shared_ptr<SVGElement>> _inner_elements;
        std::vector<std::weak_ptr<SVGElement>> _parent_elements;
    public:
        /**
        * Get inner SVG of this SVG element.
        *
        * @return inner SVG.
        */
        const std::string inner_SVG() const;
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        void set_inner_text(const std::string &text);
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        const std::string get_inner_text() const;
        /**
        * Add a sub element to this SVG element.
        *
        * @param element an inner element.
        */
        void add_inner_element(const std::shared_ptr<SVGElement> &element);
        /**
        * Remove a sub element from this SVG element.
        *
        * @param element an inner element.
        */
        void remove_inner_element(const std::shared_ptr<SVGElement> &element);
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner elements, readonly.
        */
        const std::vector<std::shared_ptr<SVGElement>> get_inner_elements() const;
        /**
        * Set inner SVG elements list in this SVG element.
        *
        * @param inner_elements inner elements list.
        */
        void set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements);

        /// Outer SVG
    public:
        /**
        * Get SVG of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string outer_SVG() const;

        /// Hash
    private:
        HASH_CODE _attribute_hash;
        HASH_CODE _inner_hash;
        HASH_CODE _outer_hash;
    protected:
        /**
        * Update outer hash by inner hash and attribtue hash.
        *
        * @return hash code.
        */
        void update_outer_hash();
        /**
        * Update attribute hash and outer hash of this element.
        *
        * @return hash code.
        */
        void update_attribute_hash();
        /**
        * Update inner hash and outer hash of this element.
        *
        * @return hash code.
        */
        void update_inner_hash();
    public:
        /**
        * Get hash of attributes of this element.
        *
        * @return hash code.
        */
        const HASH_CODE get_attribute_hash() const;
        /**
        * Get hash of inner content of this element.
        *
        * @return inner hash code.
        */
        const HASH_CODE get_inner_hash() const;
        /**
        * Get hash of this element, including tag, attributes and inner content.
        *
        * @return outer hash code.
        */
        const HASH_CODE get_outer_hash() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        virtual std::shared_ptr<SVGElement> clone() const;
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGElement
        */
        bool operator==(const SVGElement &element) const;
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGElement
        */
        bool operator!=(const SVGElement &element) const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const;
    };
}

#include "svg_el/svg_radial_gradient.h"
#include "svg_el/svg_circle.h"
#include "svg_el/svg_ellipse.h"
#include "svg_el/svg_path.h"
#include "svg_el/svg_line.h"
#include "svg_el/svg_g.h"
#include "svg_el/svg_mask.h"
#include "svg_el/svg_rect.h"
#include "svg_el/svg_image.h"
#include "svg_el/svg_text.h"
#include "svg_el/svg_pattern.h"
#include "svg_el/svg_polyline.h"
#include "svg_el/svg_marker.h"
#include "svg_el/svg_polygon.h"
#include "svg_el/svg_defs.h"
#include "svg_el/svg_foreign_object.h"
#include "svg_el/svg_linear_gradient.h"
#include "svg_el/svg_stop.h"
#include "svg_el/svg_use.h"
#endif