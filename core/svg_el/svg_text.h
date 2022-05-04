#ifndef __LZ_SVG_TEXT__
#define __LZ_SVG_TEXT__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The SVG <text> element draws a graphics element consisting of text. It's possible to apply a gradient, pattern, clipping path, mask, or filter to <text>, like any other SVG graphics element.
    */
    class SVGText: public virtual SVGElement {
    public:
        /**
        * Constructor of text.
        */
        SVGText();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_x() const;
        /**
        * The x coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * The y coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * The y coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * Shifts the text position horizontally from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the dx
        */
        virtual const std::string get_dx() const;
        /**
        * Shifts the text position horizontally from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the dx
        */
        virtual void set_dx(const std::string &dx);
        /**
        * Shifts the text position vertically from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the dy
        */
        virtual const std::string get_dy() const;
        /**
        * Shifts the text position vertically from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the dy
        */
        virtual void set_dy(const std::string &dy);
        /**
        * Rotates orientation of each individual glyph. Can rotate glyphs individually. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @return the rotate
        */
        virtual const std::string get_rotate() const;
        /**
        * Rotates orientation of each individual glyph. Can rotate glyphs individually. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @param  the rotate
        */
        virtual void set_rotate(const std::string &rotate);
        /**
        * How the text is stretched or compressed to fit the width defined by the textLength attribute. 
        * Value type: spacing|spacingAndGlyphs; Default value: spacing; Animatable: yes
        *
        * @return the lengthAdjust
        */
        virtual const std::string get_length_adjust() const;
        /**
        * How the text is stretched or compressed to fit the width defined by the textLength attribute. 
        * Value type: spacing|spacingAndGlyphs; Default value: spacing; Animatable: yes
        *
        * @param  the lengthAdjust
        */
        virtual void set_length_adjust(const std::string &length_adjust);
        /**
        * A width that the text should be scaled to fit. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @return the textLength
        */
        virtual const std::string get_text_length() const;
        /**
        * A width that the text should be scaled to fit. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        *
        * @param  the textLength
        */
        virtual void set_text_length(const std::string &text_length);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        virtual const std::string get_attributes() const override;
        /**
        * Returning differences on attributes.
        *
        * @return DOM Commands.
        */
        const std::string attribute_differ(const SVGText &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGText
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGText
        */
        std::shared_ptr<SVGText> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGText
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGText
        */
        virtual SVGText &operator=(const SVGText &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif