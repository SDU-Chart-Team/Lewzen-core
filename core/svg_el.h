#ifndef __LZ_SVG_ELEMENT__
#define __LZ_SVG_ELEMENT__
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <utility>
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

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const;

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
        * Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        *
        * @return the id
        */
        virtual const std::string get_id() const;
        /**
        * Defines a unique identifier (ID) which must be unique in the whole document. Its purpose is to identify the element when linking (using a fragment identifier), scripting, or styling (with CSS). 
        * Value: Any valid ID string; Animatable: No
        *
        * @param  the id
        */
        virtual void set_id(const std::string &id);
        /**
        * Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        *
        * @return the lang
        */
        virtual const std::string get_lang() const;
        /**
        * Participates in defining the language of the element, the language that non-editable elements are written in or the language that editable elements should be written in. The tag contains one single entry value in the format defined in RFC 5646: Tags for Identifying Languages (also known as BCP 47). 
        * Value: Any valid language ID; Animatable: No
        *
        * @param  the lang
        */
        virtual void set_lang(const std::string &lang);
        /**
        * The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
        * Value type: <integer>; Animatable: No
        *
        * @return the tabindex
        */
        virtual const std::string get_tabindex() const;
        /**
        * The tabindex SVG attribute allows you to control whether an element is focusable and to define the relative order of the element for the purposes of sequential focus navigation. 
        * Value type: <integer>; Animatable: No
        *
        * @param  the tabindex
        */
        virtual void set_tabindex(const std::string &tabindex);
        /**
        * Specifies a base IRI other than the base IRI of the document. 
        * Value type: <IRI>; Animatable: No
        *
        * @return the xml:base
        */
        virtual const std::string get_xmlZbase() const;
        /**
        * Specifies a base IRI other than the base IRI of the document. 
        * Value type: <IRI>; Animatable: No
        *
        * @param  the xml:base
        */
        virtual void set_xmlZbase(const std::string &xmlZbase);
        /**
        * It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        *
        * @return the xml:lang
        */
        virtual const std::string get_xmlZlang() const;
        /**
        * It is a universal attribute allowed in all XML dialects to mark up the natural human language that an element contains. It's almost identical in usage to HTML's lang, but in conforming XML 1.0 documents, it does not allow the use of a null attribute value (xml:lang="") to indicate an unknown language. Instead, use xml:lang="und". 
        * Value: Any valid language ID; Animatable: No
        *
        * @param  the xml:lang
        */
        virtual void set_xmlZlang(const std::string &xmlZlang);
        /**
        * SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        *
        * @return the xml:space
        */
        virtual const std::string get_xmlZspace() const;
        /**
        * SVG supports the standard XML attribute xml:space to specify the handling of white space characters within a given <text> element's character data. 
        * Value: default | preserve; Animatable: No
        *
        * @param  the xml:space
        */
        virtual void set_xmlZspace(const std::string &xmlZspace);
        /**
        * Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        *
        * @return the class
        */
        virtual const std::string get_class() const;
        /**
        * Assigns a class name or set of class names to an element. It functions identically to the class attribute in HTML. 
        * Value: Any valid ID string; Animatable: Yes
        *
        * @param  the class
        */
        virtual void set_class(const std::string &cls);
        /**
        * It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        *
        * @return the style
        */
        virtual const std::string get_style() const;
        /**
        * It specifies style information for its element. It functions identically to the style attribute in HTML. 
        * Value: Any valid style string; Animatable: No
        *
        * @param  the style
        */
        virtual void set_style(const std::string &style);
        /**
        * Event of onbegin.
        *
        * @return the onbegin
        */
        virtual const std::string get_onbegin() const;
        /**
        * Event of onbegin.
        *
        * @param  the onbegin
        */
        virtual void set_onbegin(const std::string &onbegin);
        /**
        * Event of onend.
        *
        * @return the onend
        */
        virtual const std::string get_onend() const;
        /**
        * Event of onend.
        *
        * @param  the onend
        */
        virtual void set_onend(const std::string &onend);
        /**
        * Event of onrepeat.
        *
        * @return the onrepeat
        */
        virtual const std::string get_onrepeat() const;
        /**
        * Event of onrepeat.
        *
        * @param  the onrepeat
        */
        virtual void set_onrepeat(const std::string &onrepeat);
        /**
        * Event of onabort.
        *
        * @return the onabort
        */
        virtual const std::string get_onabort() const;
        /**
        * Event of onabort.
        *
        * @param  the onabort
        */
        virtual void set_onabort(const std::string &onabort);
        /**
        * Event of onerror.
        *
        * @return the onerror
        */
        virtual const std::string get_onerror() const;
        /**
        * Event of onerror.
        *
        * @param  the onerror
        */
        virtual void set_onerror(const std::string &onerror);
        /**
        * Event of onresize.
        *
        * @return the onresize
        */
        virtual const std::string get_onresize() const;
        /**
        * Event of onresize.
        *
        * @param  the onresize
        */
        virtual void set_onresize(const std::string &onresize);
        /**
        * Event of onscroll.
        *
        * @return the onscroll
        */
        virtual const std::string get_onscroll() const;
        /**
        * Event of onscroll.
        *
        * @param  the onscroll
        */
        virtual void set_onscroll(const std::string &onscroll);
        /**
        * Event of onunload.
        *
        * @return the onunload
        */
        virtual const std::string get_onunload() const;
        /**
        * Event of onunload.
        *
        * @param  the onunload
        */
        virtual void set_onunload(const std::string &onunload);
        /**
        * Event of oncopy.
        *
        * @return the oncopy
        */
        virtual const std::string get_oncopy() const;
        /**
        * Event of oncopy.
        *
        * @param  the oncopy
        */
        virtual void set_oncopy(const std::string &oncopy);
        /**
        * Event of oncut.
        *
        * @return the oncut
        */
        virtual const std::string get_oncut() const;
        /**
        * Event of oncut.
        *
        * @param  the oncut
        */
        virtual void set_oncut(const std::string &oncut);
        /**
        * Event of onpaste.
        *
        * @return the onpaste
        */
        virtual const std::string get_onpaste() const;
        /**
        * Event of onpaste.
        *
        * @param  the onpaste
        */
        virtual void set_onpaste(const std::string &onpaste);
        /**
        * Event of oncancel.
        *
        * @return the oncancel
        */
        virtual const std::string get_oncancel() const;
        /**
        * Event of oncancel.
        *
        * @param  the oncancel
        */
        virtual void set_oncancel(const std::string &oncancel);
        /**
        * Event of oncanplay.
        *
        * @return the oncanplay
        */
        virtual const std::string get_oncanplay() const;
        /**
        * Event of oncanplay.
        *
        * @param  the oncanplay
        */
        virtual void set_oncanplay(const std::string &oncanplay);
        /**
        * Event of oncanplaythrough.
        *
        * @return the oncanplaythrough
        */
        virtual const std::string get_oncanplaythrough() const;
        /**
        * Event of oncanplaythrough.
        *
        * @param  the oncanplaythrough
        */
        virtual void set_oncanplaythrough(const std::string &oncanplaythrough);
        /**
        * Event of onchange.
        *
        * @return the onchange
        */
        virtual const std::string get_onchange() const;
        /**
        * Event of onchange.
        *
        * @param  the onchange
        */
        virtual void set_onchange(const std::string &onchange);
        /**
        * Event of onclick.
        *
        * @return the onclick
        */
        virtual const std::string get_onclick() const;
        /**
        * Event of onclick.
        *
        * @param  the onclick
        */
        virtual void set_onclick(const std::string &onclick);
        /**
        * Event of onclose.
        *
        * @return the onclose
        */
        virtual const std::string get_onclose() const;
        /**
        * Event of onclose.
        *
        * @param  the onclose
        */
        virtual void set_onclose(const std::string &onclose);
        /**
        * Event of oncuechange.
        *
        * @return the oncuechange
        */
        virtual const std::string get_oncuechange() const;
        /**
        * Event of oncuechange.
        *
        * @param  the oncuechange
        */
        virtual void set_oncuechange(const std::string &oncuechange);
        /**
        * Event of ondblclick.
        *
        * @return the ondblclick
        */
        virtual const std::string get_ondblclick() const;
        /**
        * Event of ondblclick.
        *
        * @param  the ondblclick
        */
        virtual void set_ondblclick(const std::string &ondblclick);
        /**
        * Event of ondrag.
        *
        * @return the ondrag
        */
        virtual const std::string get_ondrag() const;
        /**
        * Event of ondrag.
        *
        * @param  the ondrag
        */
        virtual void set_ondrag(const std::string &ondrag);
        /**
        * Event of ondragend.
        *
        * @return the ondragend
        */
        virtual const std::string get_ondragend() const;
        /**
        * Event of ondragend.
        *
        * @param  the ondragend
        */
        virtual void set_ondragend(const std::string &ondragend);
        /**
        * Event of ondragenter.
        *
        * @return the ondragenter
        */
        virtual const std::string get_ondragenter() const;
        /**
        * Event of ondragenter.
        *
        * @param  the ondragenter
        */
        virtual void set_ondragenter(const std::string &ondragenter);
        /**
        * Event of ondragleave.
        *
        * @return the ondragleave
        */
        virtual const std::string get_ondragleave() const;
        /**
        * Event of ondragleave.
        *
        * @param  the ondragleave
        */
        virtual void set_ondragleave(const std::string &ondragleave);
        /**
        * Event of ondragover.
        *
        * @return the ondragover
        */
        virtual const std::string get_ondragover() const;
        /**
        * Event of ondragover.
        *
        * @param  the ondragover
        */
        virtual void set_ondragover(const std::string &ondragover);
        /**
        * Event of ondragstart.
        *
        * @return the ondragstart
        */
        virtual const std::string get_ondragstart() const;
        /**
        * Event of ondragstart.
        *
        * @param  the ondragstart
        */
        virtual void set_ondragstart(const std::string &ondragstart);
        /**
        * Event of ondrop.
        *
        * @return the ondrop
        */
        virtual const std::string get_ondrop() const;
        /**
        * Event of ondrop.
        *
        * @param  the ondrop
        */
        virtual void set_ondrop(const std::string &ondrop);
        /**
        * Event of ondurationchange.
        *
        * @return the ondurationchange
        */
        virtual const std::string get_ondurationchange() const;
        /**
        * Event of ondurationchange.
        *
        * @param  the ondurationchange
        */
        virtual void set_ondurationchange(const std::string &ondurationchange);
        /**
        * Event of onemptied.
        *
        * @return the onemptied
        */
        virtual const std::string get_onemptied() const;
        /**
        * Event of onemptied.
        *
        * @param  the onemptied
        */
        virtual void set_onemptied(const std::string &onemptied);
        /**
        * Event of onended.
        *
        * @return the onended
        */
        virtual const std::string get_onended() const;
        /**
        * Event of onended.
        *
        * @param  the onended
        */
        virtual void set_onended(const std::string &onended);
        /**
        * Event of onfocus.
        *
        * @return the onfocus
        */
        virtual const std::string get_onfocus() const;
        /**
        * Event of onfocus.
        *
        * @param  the onfocus
        */
        virtual void set_onfocus(const std::string &onfocus);
        /**
        * Event of oninput.
        *
        * @return the oninput
        */
        virtual const std::string get_oninput() const;
        /**
        * Event of oninput.
        *
        * @param  the oninput
        */
        virtual void set_oninput(const std::string &oninput);
        /**
        * Event of oninvalid.
        *
        * @return the oninvalid
        */
        virtual const std::string get_oninvalid() const;
        /**
        * Event of oninvalid.
        *
        * @param  the oninvalid
        */
        virtual void set_oninvalid(const std::string &oninvalid);
        /**
        * Event of onkeydown.
        *
        * @return the onkeydown
        */
        virtual const std::string get_onkeydown() const;
        /**
        * Event of onkeydown.
        *
        * @param  the onkeydown
        */
        virtual void set_onkeydown(const std::string &onkeydown);
        /**
        * Event of onkeypress.
        *
        * @return the onkeypress
        */
        virtual const std::string get_onkeypress() const;
        /**
        * Event of onkeypress.
        *
        * @param  the onkeypress
        */
        virtual void set_onkeypress(const std::string &onkeypress);
        /**
        * Event of onkeyup.
        *
        * @return the onkeyup
        */
        virtual const std::string get_onkeyup() const;
        /**
        * Event of onkeyup.
        *
        * @param  the onkeyup
        */
        virtual void set_onkeyup(const std::string &onkeyup);
        /**
        * Event of onload.
        *
        * @return the onload
        */
        virtual const std::string get_onload() const;
        /**
        * Event of onload.
        *
        * @param  the onload
        */
        virtual void set_onload(const std::string &onload);
        /**
        * Event of onloadeddata.
        *
        * @return the onloadeddata
        */
        virtual const std::string get_onloadeddata() const;
        /**
        * Event of onloadeddata.
        *
        * @param  the onloadeddata
        */
        virtual void set_onloadeddata(const std::string &onloadeddata);
        /**
        * Event of onloadedmetadata.
        *
        * @return the onloadedmetadata
        */
        virtual const std::string get_onloadedmetadata() const;
        /**
        * Event of onloadedmetadata.
        *
        * @param  the onloadedmetadata
        */
        virtual void set_onloadedmetadata(const std::string &onloadedmetadata);
        /**
        * Event of onloadstart.
        *
        * @return the onloadstart
        */
        virtual const std::string get_onloadstart() const;
        /**
        * Event of onloadstart.
        *
        * @param  the onloadstart
        */
        virtual void set_onloadstart(const std::string &onloadstart);
        /**
        * Event of onmousedown.
        *
        * @return the onmousedown
        */
        virtual const std::string get_onmousedown() const;
        /**
        * Event of onmousedown.
        *
        * @param  the onmousedown
        */
        virtual void set_onmousedown(const std::string &onmousedown);
        /**
        * Event of onmouseenter.
        *
        * @return the onmouseenter
        */
        virtual const std::string get_onmouseenter() const;
        /**
        * Event of onmouseenter.
        *
        * @param  the onmouseenter
        */
        virtual void set_onmouseenter(const std::string &onmouseenter);
        /**
        * Event of onmouseleave.
        *
        * @return the onmouseleave
        */
        virtual const std::string get_onmouseleave() const;
        /**
        * Event of onmouseleave.
        *
        * @param  the onmouseleave
        */
        virtual void set_onmouseleave(const std::string &onmouseleave);
        /**
        * Event of onmousemove.
        *
        * @return the onmousemove
        */
        virtual const std::string get_onmousemove() const;
        /**
        * Event of onmousemove.
        *
        * @param  the onmousemove
        */
        virtual void set_onmousemove(const std::string &onmousemove);
        /**
        * Event of onmouseout.
        *
        * @return the onmouseout
        */
        virtual const std::string get_onmouseout() const;
        /**
        * Event of onmouseout.
        *
        * @param  the onmouseout
        */
        virtual void set_onmouseout(const std::string &onmouseout);
        /**
        * Event of onmouseover.
        *
        * @return the onmouseover
        */
        virtual const std::string get_onmouseover() const;
        /**
        * Event of onmouseover.
        *
        * @param  the onmouseover
        */
        virtual void set_onmouseover(const std::string &onmouseover);
        /**
        * Event of onmouseup.
        *
        * @return the onmouseup
        */
        virtual const std::string get_onmouseup() const;
        /**
        * Event of onmouseup.
        *
        * @param  the onmouseup
        */
        virtual void set_onmouseup(const std::string &onmouseup);
        /**
        * Event of onmousewheel.
        *
        * @return the onmousewheel
        */
        virtual const std::string get_onmousewheel() const;
        /**
        * Event of onmousewheel.
        *
        * @param  the onmousewheel
        */
        virtual void set_onmousewheel(const std::string &onmousewheel);
        /**
        * Event of onpause.
        *
        * @return the onpause
        */
        virtual const std::string get_onpause() const;
        /**
        * Event of onpause.
        *
        * @param  the onpause
        */
        virtual void set_onpause(const std::string &onpause);
        /**
        * Event of onplay.
        *
        * @return the onplay
        */
        virtual const std::string get_onplay() const;
        /**
        * Event of onplay.
        *
        * @param  the onplay
        */
        virtual void set_onplay(const std::string &onplay);
        /**
        * Event of onplaying.
        *
        * @return the onplaying
        */
        virtual const std::string get_onplaying() const;
        /**
        * Event of onplaying.
        *
        * @param  the onplaying
        */
        virtual void set_onplaying(const std::string &onplaying);
        /**
        * Event of onprogress.
        *
        * @return the onprogress
        */
        virtual const std::string get_onprogress() const;
        /**
        * Event of onprogress.
        *
        * @param  the onprogress
        */
        virtual void set_onprogress(const std::string &onprogress);
        /**
        * Event of onratechange.
        *
        * @return the onratechange
        */
        virtual const std::string get_onratechange() const;
        /**
        * Event of onratechange.
        *
        * @param  the onratechange
        */
        virtual void set_onratechange(const std::string &onratechange);
        /**
        * Event of onreset.
        *
        * @return the onreset
        */
        virtual const std::string get_onreset() const;
        /**
        * Event of onreset.
        *
        * @param  the onreset
        */
        virtual void set_onreset(const std::string &onreset);
        /**
        * Event of onseeked.
        *
        * @return the onseeked
        */
        virtual const std::string get_onseeked() const;
        /**
        * Event of onseeked.
        *
        * @param  the onseeked
        */
        virtual void set_onseeked(const std::string &onseeked);
        /**
        * Event of onseeking.
        *
        * @return the onseeking
        */
        virtual const std::string get_onseeking() const;
        /**
        * Event of onseeking.
        *
        * @param  the onseeking
        */
        virtual void set_onseeking(const std::string &onseeking);
        /**
        * Event of onselect.
        *
        * @return the onselect
        */
        virtual const std::string get_onselect() const;
        /**
        * Event of onselect.
        *
        * @param  the onselect
        */
        virtual void set_onselect(const std::string &onselect);
        /**
        * Event of onshow.
        *
        * @return the onshow
        */
        virtual const std::string get_onshow() const;
        /**
        * Event of onshow.
        *
        * @param  the onshow
        */
        virtual void set_onshow(const std::string &onshow);
        /**
        * Event of onstalled.
        *
        * @return the onstalled
        */
        virtual const std::string get_onstalled() const;
        /**
        * Event of onstalled.
        *
        * @param  the onstalled
        */
        virtual void set_onstalled(const std::string &onstalled);
        /**
        * Event of onsubmit.
        *
        * @return the onsubmit
        */
        virtual const std::string get_onsubmit() const;
        /**
        * Event of onsubmit.
        *
        * @param  the onsubmit
        */
        virtual void set_onsubmit(const std::string &onsubmit);
        /**
        * Event of onsuspend.
        *
        * @return the onsuspend
        */
        virtual const std::string get_onsuspend() const;
        /**
        * Event of onsuspend.
        *
        * @param  the onsuspend
        */
        virtual void set_onsuspend(const std::string &onsuspend);
        /**
        * Event of ontimeupdate.
        *
        * @return the ontimeupdate
        */
        virtual const std::string get_ontimeupdate() const;
        /**
        * Event of ontimeupdate.
        *
        * @param  the ontimeupdate
        */
        virtual void set_ontimeupdate(const std::string &ontimeupdate);
        /**
        * Event of ontoggle.
        *
        * @return the ontoggle
        */
        virtual const std::string get_ontoggle() const;
        /**
        * Event of ontoggle.
        *
        * @param  the ontoggle
        */
        virtual void set_ontoggle(const std::string &ontoggle);
        /**
        * Event of onvolumechange.
        *
        * @return the onvolumechange
        */
        virtual const std::string get_onvolumechange() const;
        /**
        * Event of onvolumechange.
        *
        * @param  the onvolumechange
        */
        virtual void set_onvolumechange(const std::string &onvolumechange);
        /**
        * Event of onwaiting.
        *
        * @return the onwaiting
        */
        virtual const std::string get_onwaiting() const;
        /**
        * Event of onwaiting.
        *
        * @param  the onwaiting
        */
        virtual void set_onwaiting(const std::string &onwaiting);
        /**
        * Event of onactivate.
        *
        * @return the onactivate
        */
        virtual const std::string get_onactivate() const;
        /**
        * Event of onactivate.
        *
        * @param  the onactivate
        */
        virtual void set_onactivate(const std::string &onactivate);
        /**
        * Event of onfocusin.
        *
        * @return the onfocusin
        */
        virtual const std::string get_onfocusin() const;
        /**
        * Event of onfocusin.
        *
        * @param  the onfocusin
        */
        virtual void set_onfocusin(const std::string &onfocusin);
        /**
        * Event of onfocusout.
        *
        * @return the onfocusout
        */
        virtual const std::string get_onfocusout() const;
        /**
        * Event of onfocusout.
        *
        * @param  the onfocusout
        */
        virtual void set_onfocusout(const std::string &onfocusout);
        /**
        * It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        *
        * @return the alignment-baseline
        */
        virtual const std::string get_alignment_baseline() const;
        /**
        * It specifies how an object is aligned along the font baseline with respect to its parent. 
        * Value: auto|baseline|before-edge|text-before-edge|middle|central|after-edge|text-after-edge|ideographic|alphabetic|hanging|mathematical|inherit; Animatable: Yes
        *
        * @param  the alignment-baseline
        */
        virtual void set_alignment_baseline(const std::string &alignment_baseline);
        /**
        * It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        *
        * @return the baseline-shift
        */
        virtual const std::string get_baseline_shift() const;
        /**
        * It allows repositioning of the dominant-baseline relative to the dominant-baseline of the parent text content element. 
        * Value: auto|baseline|super|sub|<percentage>|<length>|inherit; Animatable: Yes
        *
        * @param  the baseline-shift
        */
        virtual void set_baseline_shift(const std::string &baseline_shift);
        /**
        * It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        *
        * @return the clip-path
        */
        virtual const std::string get_clip_path() const;
        /**
        * It binds the element it is applied to with a given <clipPath> element. 
        * Value: none|<FuncIRI>|inherit; Animatable: Yes
        *
        * @param  the clip-path
        */
        virtual void set_clip_path(const std::string &clip_path);
        /**
        * It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        *
        * @return the clip-rule
        */
        virtual const std::string get_clip_rule() const;
        /**
        * It indicates how to determine what side of a path is inside a shape in order to know how a <clipPath> should clip its target. 
        * Value: nonezero|evenodd|inherit; Animatable: Yes
        *
        * @param  the clip-rule
        */
        virtual void set_clip_rule(const std::string &clip_rule);
        /**
        * It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        *
        * @return the color
        */
        virtual const std::string get_color() const;
        /**
        * It provides a potential indirect value (currentcolor) for the fill, stroke, stop-color, flood-color and lighting-color presentation attributes. 
        * Value: <color>|inherit; Animatable: Yes
        *
        * @param  the color
        */
        virtual void set_color(const std::string &color);
        /**
        * It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @return the color-interpolation
        */
        virtual const std::string get_color_interpolation() const;
        /**
        * It specifies the color space for gradient interpolations, color animations, and alpha compositing. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @param  the color-interpolation
        */
        virtual void set_color_interpolation(const std::string &color_interpolation);
        /**
        * It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @return the color-interpolation-filters
        */
        virtual const std::string get_color_interpolation_filters() const;
        /**
        * It specifies the color space for imaging operations performed via filter effects. 
        * Value: auto|sRGB|linearRGB|inherit; Animatable: Yes
        *
        * @param  the color-interpolation-filters
        */
        virtual void set_color_interpolation_filters(const std::string &color_interpolation_filters);
        /**
        * It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        *
        * @return the color-profile
        */
        virtual const std::string get_color_profile() const;
        /**
        * It defines which color profile a raster image included through the <image> element should use. 
        * Value: auto|sRGB|linearRGB|<name>|<IRI>|inherit; Animatable: Yes
        *
        * @param  the color-profile
        */
        virtual void set_color_profile(const std::string &color_profile);
        /**
        * It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        *
        * @return the color-rendering
        */
        virtual const std::string get_color_rendering() const;
        /**
        * It provides a hint to the browser about how to optimize its color interpolation and compositing operations. 
        * Value: auto|optimizeSpeed|optimizeQuality|inherit; Animatable: Yes
        *
        * @param  the color-rendering
        */
        virtual void set_color_rendering(const std::string &color_rendering);
        /**
        * It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<anything>:cursorKeywords|inherit; Animatable: Yes
        *
        * @return the cursor
        */
        virtual const std::string get_cursor() const;
        /**
        * It specifies the mouse cursor displayed when the mouse pointer is over an element. 
        * Value: <FuncIRI>|<anything>:cursorKeywords|inherit; Animatable: Yes
        *
        * @param  the cursor
        */
        virtual void set_cursor(const std::string &cursor);
        /**
        * It defines a path to be drawn. 
        * Value: path()|none
        *
        * @return the d
        */
        virtual const std::string get_d() const;
        /**
        * It defines a path to be drawn. 
        * Value: path()|none
        *
        * @param  the d
        */
        virtual void set_d(const std::string &d);
        /**
        * It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        *
        * @return the direction
        */
        virtual const std::string get_direction() const;
        /**
        * It specifies the base writing direction of text. 
        * Value: ltr|rtl|inherit; Animatable: Yes
        *
        * @param  the direction
        */
        virtual void set_direction(const std::string &direction);
        /**
        * It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        *
        * @return the display
        */
        virtual const std::string get_display() const;
        /**
        * It allows to control the rendering of graphical or container elements. 
        * Value: see css display; Animatable: Yes
        *
        * @param  the display
        */
        virtual void set_display(const std::string &display);
        /**
        * It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        *
        * @return the dominant-baseline
        */
        virtual const std::string get_dominant_baseline() const;
        /**
        * It defines the baseline used to align the box's text and inline-level contents. 
        * Value: auto|text-bottom|alphabetic|ideographic|middle|central| mathematical|hanging|text-top; Animatable: Yes
        *
        * @param  the dominant-baseline
        */
        virtual void set_dominant_baseline(const std::string &dominant_baseline);
        /**
        * It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        *
        * @return the enable-background
        */
        virtual const std::string get_enable_background() const;
        /**
        * It tells the browser how to manage the accumulation of the background image. 
        * Value: accumulate|new|inherit; Animatable: No
        *
        * @param  the enable-background
        */
        virtual void set_enable_background(const std::string &enable_background);
        /**
        * It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        *
        * @return the fill
        */
        virtual const std::string get_fill() const;
        /**
        * It defines the color of the inside of the graphical element it applies to. 
        * Value: <paint>; Animatable: Yes
        *
        * @param  the fill
        */
        virtual void set_fill(const std::string &fill);
        /**
        * It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @return the fill-opacity
        */
        virtual const std::string get_fill_opacity() const;
        /**
        * It specifies the opacity of the color or the content the current object is filled with. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @param  the fill-opacity
        */
        virtual void set_fill_opacity(const std::string &fill_opacity);
        /**
        * It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        *
        * @return the fill-rule
        */
        virtual const std::string get_fill_rule() const;
        /**
        * It indicates how to determine what side of a path is inside a shape. 
        * Value: nonzero|evenodd|inherit; Animatable: Yes
        *
        * @param  the fill-rule
        */
        virtual void set_fill_rule(const std::string &fill_rule);
        /**
        * It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return the filter
        */
        virtual const std::string get_filter() const;
        /**
        * It defines the filter effects defined by the <filter> element that shall be applied to its element. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param  the filter
        */
        virtual void set_filter(const std::string &filter);
        /**
        * It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        *
        * @return the flood-color
        */
        virtual const std::string get_flood_color() const;
        /**
        * It indicates what color to use to flood the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <color>; Animatable: Yes
        *
        * @param  the flood-color
        */
        virtual void set_flood_color(const std::string &flood_color);
        /**
        * It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @return the flood-opacity
        */
        virtual const std::string get_flood_opacity() const;
        /**
        * It indicates the opacity value to use across the current filter primitive subregion defined through the <feFlood> or <feDropShadow> element. 
        * Value: <number>|<percentage>; Animatable: Yes
        *
        * @param  the flood-opacity
        */
        virtual void set_flood_opacity(const std::string &flood_opacity);
        /**
        * It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        *
        * @return the font-family
        */
        virtual const std::string get_font_family() const;
        /**
        * It indicates which font family will be used to render the text of the element. 
        * Value: see css font-family; Animatable: Yes
        *
        * @param  the font-family
        */
        virtual void set_font_family(const std::string &font_family);
        /**
        * It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        *
        * @return the font-size
        */
        virtual const std::string get_font_size() const;
        /**
        * It specifies the size of the font. 
        * Value: see css font-size; Animatable: Yes
        *
        * @param  the font-size
        */
        virtual void set_font_size(const std::string &font_size);
        /**
        * It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        *
        * @return the font-size-adjust
        */
        virtual const std::string get_font_size_adjust() const;
        /**
        * It specifies that the font size should be chosen based on the height of lowercase letters rather than the height of capital letters. 
        * Value: <number>|none|inherit; Animatable: Yes
        *
        * @param  the font-size-adjust
        */
        virtual void set_font_size_adjust(const std::string &font_size_adjust);
        /**
        * It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        *
        * @return the font-stretch
        */
        virtual const std::string get_font_stretch() const;
        /**
        * It selects a normal, condensed, or expanded face from a font. 
        * Value: see css font-stretch; Animatable: Yes
        *
        * @param  the font-stretch
        */
        virtual void set_font_stretch(const std::string &font_stretch);
        /**
        * It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        *
        * @return the font-style
        */
        virtual const std::string get_font_style() const;
        /**
        * It specifies whether a font should be styled with a normal, italic, or oblique face from its font-family. 
        * Value: normal|italic|oblique; Animatable: Yes
        *
        * @param  the font-style
        */
        virtual void set_font_style(const std::string &font_style);
        /**
        * It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        *
        * @return the font-variant
        */
        virtual const std::string get_font_variant() const;
        /**
        * It specifies whether a font should be used with some of their variation such as small caps or ligatures. 
        * Value: see css font-variant; Animatable: Yes
        *
        * @param  the font-variant
        */
        virtual void set_font_variant(const std::string &font_variant);
        /**
        * It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        *
        * @return the font-weight
        */
        virtual const std::string get_font_weight() const;
        /**
        * It specifies the weight (or boldness) of the font. 
        * Value: normal|bold|lighter|bolder|100|200|300|400|500|600|700|800|900; Animatable: Yes
        *
        * @param  the font-weight
        */
        virtual void set_font_weight(const std::string &font_weight);
        /**
        * It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        *
        * @return the glyph-orientation-horizontal
        */
        virtual const std::string get_glyph_orientation_horizontal() const;
        /**
        * It controls glyph orientation when the inline-progression-direction is horizontal. 
        * Value: <angle>|inherit; Animatable: No
        *
        * @param  the glyph-orientation-horizontal
        */
        virtual void set_glyph_orientation_horizontal(const std::string &glyph_orientation_horizontal);
        /**
        * It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        *
        * @return the glyph-orientation-vertical
        */
        virtual const std::string get_glyph_orientation_vertical() const;
        /**
        * It controls glyph orientation when the inline-progression-direction is vertical. 
        * Value: auto|<angle>|inherit; Animatable: No
        *
        * @param  the glyph-orientation-vertical
        */
        virtual void set_glyph_orientation_vertical(const std::string &glyph_orientation_vertical);
        /**
        * It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        *
        * @return the image-rendering
        */
        virtual const std::string get_image_rendering() const;
        /**
        * It provides a hint to the browser about how to make speed vs. quality tradeoffs as it performs image processing. 
        * Value: auto|optimizeQuality|optimizeSpeed; Animatable: Yes
        *
        * @param  the image-rendering
        */
        virtual void set_image_rendering(const std::string &image_rendering);
        /**
        * It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        *
        * @return the kerning
        */
        virtual const std::string get_kerning() const;
        /**
        * It indicates whether the browser should adjust inter-glyph spacing. 
        * Value: auto|<length>|inherit; Animatable: Yes
        *
        * @param  the kerning
        */
        virtual void set_kerning(const std::string &kerning);
        /**
        * It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        *
        * @return the letter-spacing
        */
        virtual const std::string get_letter_spacing() const;
        /**
        * It controls spacing between text characters. 
        * Value: normal|<length>|inherit; Animatable: Yes
        *
        * @param  the letter-spacing
        */
        virtual void set_letter_spacing(const std::string &letter_spacing);
        /**
        * It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        *
        * @return the lighting-color
        */
        virtual const std::string get_lighting_color() const;
        /**
        * It defines the color of the light source for filter primitives elements <feDiffuseLighting> and <feSpecularLighting>. 
        * Value: <color>; Animatable: Yes
        *
        * @param  the lighting-color
        */
        virtual void set_lighting_color(const std::string &lighting_color);
        /**
        * It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return the marker-end
        */
        virtual const std::string get_marker_end() const;
        /**
        * It defines the arrowhead or polymarker that will be drawn at the final vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param  the marker-end
        */
        virtual void set_marker_end(const std::string &marker_end);
        /**
        * It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return the marker-mid
        */
        virtual const std::string get_marker_mid() const;
        /**
        * It defines the arrowhead or polymarker that will be drawn at every vertex other than the first and last vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param  the marker-mid
        */
        virtual void set_marker_mid(const std::string &marker_mid);
        /**
        * It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @return the marker-start
        */
        virtual const std::string get_marker_start() const;
        /**
        * It defines the arrowhead or polymarker that will be drawn at the first vertex of the given <anything>:path element or basic shape. 
        * Value: <FuncIRI>|none|inherit; Animatable: Yes
        *
        * @param  the marker-start
        */
        virtual void set_marker_start(const std::string &marker_start);
        /**
        * It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        *
        * @return the mask
        */
        virtual const std::string get_mask() const;
        /**
        * It alters the visibility of an element by either masking or clipping the image at specific points. 
        * Value: see css mask; Animatable: Yes
        *
        * @param  the mask
        */
        virtual void set_mask(const std::string &mask);
        /**
        * It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        *
        * @return the opacity
        */
        virtual const std::string get_opacity() const;
        /**
        * It specifies the transparency of an object or a group of objects. 
        * Value: <opacity-value>; Animatable: Yes
        *
        * @param  the opacity
        */
        virtual void set_opacity(const std::string &opacity);
        /**
        * Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        *
        * @return the overflow
        */
        virtual const std::string get_overflow() const;
        /**
        * Specifies whether the content of a block-level element is clipped when it overflows the element's box. 
        * Value: visible|hidden|scroll|auto|inherit; Animatable: Yes
        *
        * @param  the overflow
        */
        virtual void set_overflow(const std::string &overflow);
        /**
        * Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        *
        * @return the pointer-events
        */
        virtual const std::string get_pointer_events() const;
        /**
        * Defines whether or when an element may be the target of a mouse event. 
        * Value: bounding-box|visiblePainted|visibleFil|visibleStroke|visible |painted|fill|stroke|all|none; Animatable: Yes
        *
        * @param  the pointer-events
        */
        virtual void set_pointer_events(const std::string &pointer_events);
        /**
        * Hints about what tradeoffs to make as the browser renders <anything>:path element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        *
        * @return the shape-rendering
        */
        virtual const std::string get_shape_rendering() const;
        /**
        * Hints about what tradeoffs to make as the browser renders <anything>:path element or basic shapes. 
        * Value: auto|optimizeSpeed|crispEdges|geometricPrecision |inherit; Animatable: Yes
        *
        * @param  the shape-rendering
        */
        virtual void set_shape_rendering(const std::string &shape_rendering);
        /**
        * - 
        * Value:; Animatable: -
        *
        * @return the solid-color
        */
        virtual const std::string get_solid_color() const;
        /**
        * - 
        * Value:; Animatable: -
        *
        * @param  the solid-color
        */
        virtual void set_solid_color(const std::string &solid_color);
        /**
        * - 
        * Value:; Animatable: -
        *
        * @return the solid-opacity
        */
        virtual const std::string get_solid_opacity() const;
        /**
        * - 
        * Value:; Animatable: -
        *
        * @param  the solid-opacity
        */
        virtual void set_solid_opacity(const std::string &solid_opacity);
        /**
        * Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<color>:icccolor|inherit; Animatable: Yes
        *
        * @return the stop-color
        */
        virtual const std::string get_stop_color() const;
        /**
        * Indicates what color to use at that gradient stop. 
        * Value: currentcolor|<color>|<color>:icccolor|inherit; Animatable: Yes
        *
        * @param  the stop-color
        */
        virtual void set_stop_color(const std::string &stop_color);
        /**
        * Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        *
        * @return the stop-opacity
        */
        virtual const std::string get_stop_opacity() const;
        /**
        * Defines the opacity of a given gradient stop. 
        * Value: <opacity-value>|inherit; Animatable: Yes
        *
        * @param  the stop-opacity
        */
        virtual void set_stop_opacity(const std::string &stop_opacity);
        /**
        * Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        *
        * @return the stroke
        */
        virtual const std::string get_stroke() const;
        /**
        * Defines the color used to paint the outline of the shape. 
        * Value: <paint>; Animatable: Yes
        *
        * @param  the stroke
        */
        virtual void set_stroke(const std::string &stroke);
        /**
        * Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<list-of-numbers>:dasharray; Animatable: Yes
        *
        * @return the stroke-dasharray
        */
        virtual const std::string get_stroke_dasharray() const;
        /**
        * Defines the pattern of dashes and gaps used to paint the outline of the shape. 
        * Value: none|<list-of-numbers>:dasharray; Animatable: Yes
        *
        * @param  the stroke-dasharray
        */
        virtual void set_stroke_dasharray(const std::string &stroke_dasharray);
        /**
        * Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        *
        * @return the stroke-dashoffset
        */
        virtual const std::string get_stroke_dashoffset() const;
        /**
        * Defines an offset on the rendering of the associated dash array. 
        * Value: <percentage>|<length>; Animatable: Yes
        *
        * @param  the stroke-dashoffset
        */
        virtual void set_stroke_dashoffset(const std::string &stroke_dashoffset);
        /**
        * Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        *
        * @return the stroke-linecap
        */
        virtual const std::string get_stroke_linecap() const;
        /**
        * Defines the shape to be used at the end of open subpaths when they are stroked. 
        * Value: butt|round|square; Animatable: Yes
        *
        * @param  the stroke-linecap
        */
        virtual void set_stroke_linecap(const std::string &stroke_linecap);
        /**
        * Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        *
        * @return the stroke-linejoin
        */
        virtual const std::string get_stroke_linejoin() const;
        /**
        * Defines the shape to be used at the corners of paths when they are stroked. 
        * Value: arcs|bevel|miter|miter-clip|round; Animatable: Yes
        *
        * @param  the stroke-linejoin
        */
        virtual void set_stroke_linejoin(const std::string &stroke_linejoin);
        /**
        * Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        *
        * @return the stroke-miterlimit
        */
        virtual const std::string get_stroke_miterlimit() const;
        /**
        * Defines a limit on the ratio of the miter length to the stroke-width used to draw a miter join. 
        * Value: <number>; Animatable: Yes
        *
        * @param  the stroke-miterlimit
        */
        virtual void set_stroke_miterlimit(const std::string &stroke_miterlimit);
        /**
        * Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        *
        * @return the stroke-opacity
        */
        virtual const std::string get_stroke_opacity() const;
        /**
        * Defines the opacity of the stroke of a shape. 
        * Value: <opacity-value>|<percentage>; Animatable: Yes
        *
        * @param  the stroke-opacity
        */
        virtual void set_stroke_opacity(const std::string &stroke_opacity);
        /**
        * Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        *
        * @return the stroke-width
        */
        virtual const std::string get_stroke_width() const;
        /**
        * Defines the width of the stroke to be applied to the shape. 
        * Value: <length>|<percentage>; Animatable: Yes
        *
        * @param  the stroke-width
        */
        virtual void set_stroke_width(const std::string &stroke_width);
        /**
        * Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        *
        * @return the text-anchor
        */
        virtual const std::string get_text_anchor() const;
        /**
        * Defines the vertical alignment a string of text. 
        * Value: start|middle|end|inherit; Animatable: Yes
        *
        * @param  the text-anchor
        */
        virtual void set_text_anchor(const std::string &text_anchor);
        /**
        * Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        *
        * @return the text-decoration
        */
        virtual const std::string get_text_decoration() const;
        /**
        * Sets the appearance of decorative lines on text. 
        * Value: none|underline|overline|line-through|blink|inherit; Animatable: Yes
        *
        * @param  the text-decoration
        */
        virtual void set_text_decoration(const std::string &text_decoration);
        /**
        * Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        *
        * @return the text-rendering
        */
        virtual const std::string get_text_rendering() const;
        /**
        * Hints about what tradeoffs to make as the browser renders text. 
        * Value: auto|optimizeSpeed|optimizeLegibility|geometricPrecision|inherit; Animatable: Yes
        *
        * @param  the text-rendering
        */
        virtual void set_text_rendering(const std::string &text_rendering);
        /**
        * Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        *
        * @return the transform
        */
        virtual const std::string get_transform() const;
        /**
        * Defines a list of transform definitions that are applied to an element and the element's children. 
        * Value: <transform-list>; Animatable: Yes
        *
        * @param  the transform
        */
        virtual void set_transform(const std::string &transform);
        /**
        * - 
        * Value:; Animatable: -
        *
        * @return the unicode-bidi
        */
        virtual const std::string get_unicode_bidi() const;
        /**
        * - 
        * Value:; Animatable: -
        *
        * @param  the unicode-bidi
        */
        virtual void set_unicode_bidi(const std::string &unicode_bidi);
        /**
        * Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<IRI>:uri; Animatable: Yes
        *
        * @return the vector-effect
        */
        virtual const std::string get_vector_effect() const;
        /**
        * Specifies the vector effect to use when drawing an object. 
        * Value: default|non-scaling-stroke|inherit|<IRI>:uri; Animatable: Yes
        *
        * @param  the vector-effect
        */
        virtual void set_vector_effect(const std::string &vector_effect);
        /**
        * Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        *
        * @return the visibility
        */
        virtual const std::string get_visibility() const;
        /**
        * Lets you control the visibility of graphical elements. 
        * Value: visible|hidden|collapse|inherit; Animatable: Yes
        *
        * @param  the visibility
        */
        virtual void set_visibility(const std::string &visibility);
        /**
        * Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        *
        * @return the word-spacing
        */
        virtual const std::string get_word_spacing() const;
        /**
        * Specifies spacing behavior between words. 
        * Value: <length>|inherit; Animatable: Yes
        *
        * @param  the word-spacing
        */
        virtual void set_word_spacing(const std::string &word_spacing);
        /**
        * Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        *
        * @return the writing-mode
        */
        virtual const std::string get_writing_mode() const;
        /**
        * Specifies whether the initial inline-progression-direction for a <text> element shall be left-to-right, right-to-left, or top-to-bottom. 
        * Value: lr-tb|rl-tb|tb-rl|lr|rl|tb|inherit; Animatable: Yes
        *
        * @param  the writing-mode
        */
        virtual void set_writing_mode(const std::string &writing_mode);
        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        virtual const std::string get_attributes() const;
        /**
        * Returning differences on attributes.
        *
        * @return DOM Commands.
        */
        const std::string attribute_differ(const SVGElement &element) const;
        
        /// Inner SVG
    protected:
        std::string _raw_HTML;
        std::vector<std::shared_ptr<SVGElement>> _inner_elements;
        std::weak_ptr<SVGElement> _parent_element;
    protected:
        struct _el_idx {
            std::shared_ptr<SVGElement> ptr;
            int idx;
            bool operator<(const _el_idx &b) const {
                if (ptr == b.ptr) return idx < b.idx;
                return ptr < b.ptr;
            }
        };
        /**
        * Returning differences on inner elements.
        *
        * @return DOM Commands.
        */
        void inner_differ(const SVGElement &element,
            std::vector<_el_idx> &removal,
            std::vector<_el_idx> &addition,
            std::vector<std::pair<_el_idx, _el_idx>> &unchanged,
            std::vector<std::pair<_el_idx, _el_idx>> &changed) const;
    public:
        /**
        * Get inner SVG of this SVG element.
        *
        * @return inner SVG.
        */
        const std::string inner_SVG() const;
        /**
        * Set raw HTML of this SVG element. SVG string or text.
        *
        * @param element an raw HTML.
        */
        void set_raw_HTML(const std::string &text);
        /**
        * Set raw HTML of this SVG element. SVG string or text.
        *
        * @param element an raw HTML.
        */
        const std::string get_raw_HTML() const;
        /**
        * Add a sub element to this SVG element.
        *
        * @param element an inner element.
        * @param index the index to be insert. default -1 means tail.
        */
        void add_inner_element(const std::shared_ptr<SVGElement> &element, int index = -1);
        /**
        * Remove a child element or child elements from this SVG element, based on content.
        *
        * @param element an inner element.
        * @param remove_all if to remove all occurances.
        */
        void remove_inner_element(const std::shared_ptr<SVGElement> &element, bool remove_all = false);
        /**
        * Remove a child element or child elements from this SVG element, by index.
        *
        * @param index the index of inner element.
        */
        void remove_inner_element(int index);
        /**
        * Get inner SVG element in this SVG element, by index.
        *
        * @return inner element.
        */
        std::shared_ptr<SVGElement> get_inner_element(int index) const;
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner element list, readonly.
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
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGElement
        */
        virtual SVGElement &operator=(const SVGElement &element);
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
#include "svg_el/svg_svg.h"
#include "svg_el/svg_stop.h"
#include "svg_el/svg_use.h"
#endif
