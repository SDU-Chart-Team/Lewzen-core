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
        double _x;
    private:
        double _y;
    private:
        double _dx;
    private:
        double _dy;
    private:
        std::string _rotate;
    public:
        enum class LengthAdjust { SPACING, SPACING_AND_GLYPHS };
    private:
        LengthAdjust _length_adjust;
    private:
        double _text_length;
    public:
        /**
        * Get x position of the starting point of the text baseline.
        *
        * @return x position of the starting point of the text baseline.
        */
        double get_x() const;
        /**
        * Set x position of the starting point of the text baseline.
        *
        * @param x x position of the starting point of the text baseline.
        */
        void set_x(const double &x);
        /**
        * Get y position of the starting point of the text baseline.
        *
        * @return y position of the starting point of the text baseline.
        */
        double get_y() const;
        /**
        * Set y position of the starting point of the text baseline.
        *
        * @param y y position of the starting point of the text baseline.
        */
        void set_y(const double &y);
        /**
        * Get shifts the text position horizontally from a previous text element.
        *
        * @return shifts the text position horizontally from a previous text element.
        */
        double get_dx() const;
        /**
        * Set shifts the text position horizontally from a previous text element.
        *
        * @param dx shifts the text position horizontally from a previous text element.
        */
        void set_dx(const double &dx);
        /**
        * Get shifts the text position vertically from a previous text element.
        *
        * @return shifts the text position vertically from a previous text element.
        */
        double get_dy() const;
        /**
        * Set shifts the text position vertically from a previous text element.
        *
        * @param dy shifts the text position vertically from a previous text element.
        */
        void set_dy(const double &dy);
        /**
        * Get rotates orientation of each individual glyph. can rotate glyphs individually.
        *
        * @return rotates orientation of each individual glyph. can rotate glyphs individually.
        */
        const std::string get_rotate() const;
        /**
        * Set rotates orientation of each individual glyph. can rotate glyphs individually.
        *
        * @param rotate rotates orientation of each individual glyph. can rotate glyphs individually.
        */
        void set_rotate(const std::string &rotate);
        /**
        * Get how the text is stretched or compressed to fit the width defined by the textLength attribute.
        *
        * @return how the text is stretched or compressed to fit the width defined by the textLength attribute.
        */
        const LengthAdjust get_length_adjust() const;
        /**
        * Set how the text is stretched or compressed to fit the width defined by the textLength attribute.
        *
        * @param length_adjust how the text is stretched or compressed to fit the width defined by the textLength attribute.
        */
        void set_length_adjust(const LengthAdjust &length_adjust);
        /**
        * Get a width that the text should be scaled to fit.
        *
        * @return a width that the text should be scaled to fit.
        */
        double get_text_length() const;
        /**
        * Set a width that the text should be scaled to fit.
        *
        * @param text_length a width that the text should be scaled to fit.
        */
        void set_text_length(const double &text_length);

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