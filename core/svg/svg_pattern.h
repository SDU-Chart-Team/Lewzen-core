#ifndef __LZ_SVG_PATTERN__
#define __LZ_SVG_PATTERN__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <pattern> element defines a graphics object which can be redrawn at repeated x- and y-coordinate intervals ("tiled") to cover an area.
    */
    class SVGPattern: public XMLElement {
    public:
        /**
        * Constructor of pattern.
        */
        SVGPattern();
        /**
        * Deep copy of pattern.
        */
        SVGPattern(const SVGPattern &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Pattern
    private:
        double _x;
    private:
        double _y;
    private:
        double _width;
    private:
        double _height;
    public:
        enum class PatternContentUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        PatternContentUnits _pattern_content_units;
    public:
        enum class PatternUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        PatternUnits _pattern_units;
    public:
        /**
        * Get x of offset.
        *
        * @return x of offset.
        */
        double get_x() const;
        /**
        * Set x of offset.
        *
        * @param x x of offset.
        */
        void set_x(const double &x);
        /**
        * Get y of offset.
        *
        * @return y of offset.
        */
        double get_y() const;
        /**
        * Set y of offset.
        *
        * @param y y of offset.
        */
        void set_y(const double &y);
        /**
        * Get the width.
        *
        * @return the width.
        */
        double get_width() const;
        /**
        * Set the width.
        *
        * @param width the width.
        */
        void set_width(const double &width);
        /**
        * Get the height.
        *
        * @return the height.
        */
        double get_height() const;
        /**
        * Set the height.
        *
        * @param height the height.
        */
        void set_height(const double &height);
        /**
        * Get the pattern content units.
        *
        * @return the pattern content units.
        */
        const PatternContentUnits get_pattern_content_units() const;
        /**
        * Set the pattern content units.
        *
        * @param pattern_content_units the pattern content units.
        */
        void set_pattern_content_units(const PatternContentUnits &pattern_content_units);
        /**
        * Get the pattern units.
        *
        * @return the pattern units.
        */
        const PatternUnits get_pattern_units() const;
        /**
        * Set the pattern units.
        *
        * @param pattern_units the pattern units.
        */
        void set_pattern_units(const PatternUnits &pattern_units);

        /// Attributes
    protected:
        /**
        * Get attribute string of this XML element.
        *
        * @return outer XML.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this XML element.
        *
        * @relatesalso XMLElement
        */
        std::shared_ptr<XMLElement> clone() const;
        /**
        * XML substraction, returning differences.
        *
        * @relatesalso XMLElement
        */
        const std::string operator-(const XMLElement &element) const;
    };
}
#endif