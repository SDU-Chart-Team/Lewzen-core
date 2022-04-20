#ifndef __LZ_SVG_TEXT__
#define __LZ_SVG_TEXT__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The SVG <text> element draws a graphics element consisting of text. It's possible to apply a gradient, pattern, clipping path, mask, or filter to <text>, like any other SVG graphics element.
    */
    class SVGText: public SVGElement {
    public:
        /**
        * Constructor of text.
        */
        SVGText();
        /**
        * Deep copy of text.
        */
        SVGText(const SVGText &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Text
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _dx;
    private:
        std::string _dy;
    private:
        std::string _rotate;
    private:
        std::string _length_adjust;
    private:
        std::string _text_length;
    public:
        /**
        * The x coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        const std::string get_x() const;
        /**
        * The x coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        void set_x(const std::string &x);
        /**
        * The y coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        const std::string get_y() const;
        /**
        * The y coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        void set_y(const std::string &y);
        /**
        * Shifts the text position horizontally from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the dx
        */
        const std::string get_dx() const;
        /**
        * Shifts the text position horizontally from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the dx
        */
        void set_dx(const std::string &dx);
        /**
        * Shifts the text position vertically from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the dy
        */
        const std::string get_dy() const;
        /**
        * Shifts the text position vertically from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the dy
        */
        void set_dy(const std::string &dy);
        /**
        * Rotates orientation of each individual glyph. Can rotate glyphs individually. 
        * Value type: <list-of-number> ; Default value: none; Animatable: yes
        *
        * @return the rotate
        */
        const std::string get_rotate() const;
        /**
        * Rotates orientation of each individual glyph. Can rotate glyphs individually. 
        * Value type: <list-of-number> ; Default value: none; Animatable: yes
        *
        * @param  the rotate
        */
        void set_rotate(const std::string &rotate);
        /**
        * How the text is stretched or compressed to fit the width defined by the textLength attribute. 
        * Value type: spacing|spacingAndGlyphs; Default value: spacing; Animatable: yes
        *
        * @return the lengthAdjust
        */
        const std::string get_length_adjust() const;
        /**
        * How the text is stretched or compressed to fit the width defined by the textLength attribute. 
        * Value type: spacing|spacingAndGlyphs; Default value: spacing; Animatable: yes
        *
        * @param  the lengthAdjust
        */
        void set_length_adjust(const std::string &length_adjust);
        /**
        * A width that the text should be scaled to fit. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the textLength
        */
        const std::string get_text_length() const;
        /**
        * A width that the text should be scaled to fit. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the textLength
        */
        void set_text_length(const std::string &text_length);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        std::shared_ptr<SVGElement> clone() const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        const std::string operator-(const SVGElement &element) const;
    };
}
#endif