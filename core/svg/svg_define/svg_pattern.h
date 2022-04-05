#include <string>
#include "../svg_define.h"
#ifndef __LZ_SVG_PATTERN__
#define __LZ_SVG_PATTERN__

namespace Lewzen {
    // Define for patterns: https://developer.mozilla.org/en-US/docs/Web/SVG/Tutorial/Patterns
    /**
    * A pattern define in SVG context.
    */
    class SVGPattern: public SVGDefine {
    public:
        enum class PatternContentUnits { OBJECT_BOUNDING_BOX, USER_SPACT_ON_USE };
        enum class PatternUnits { OBJECT_BOUNDING_BOX, USER_SPACT_ON_USE };
    private:
        double _x;
        double _y;
        double _width;
        double _height;
        PatternContentUnits _pattern_content_units;
        PatternUnits _pattern_units;
    public:
        /**
        * Constructor of pattern.
        */
        SVGPattern();

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
        const PatternContentUnits &get_pattern_content_units() const;
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
        const PatternUnits &get_pattern_units() const;
        /**
        * Set the pattern units.
        *
        * @param pattern_units the pattern units.
        */
        void set_pattern_units(const PatternUnits &pattern_units);
    }
}
#endif