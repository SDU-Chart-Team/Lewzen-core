#include <string>
#include <vector>
#include "../svg_gradient.h"
#ifndef __LZ_SVG_LINEAR_GRADIENT__
#define __LZ_SVG_LINEAR_GRADIENT__

namespace Lewzen {
    /**
    * A linear gradient define in SVG context.
    */
    class SVGLinearGradient: public SVGGradient {
    private:
        double _x1;
        double _y1;
        double _x2;
        double _y2;
    public:
        /**
        * Constructor of linear gradient.
        */
        SVGLinearGradient();

        /// Properties
        /**
        * Get x1 of gradient line.
        *
        * @return x1 of gradient line.
        */
        double get_x1() const;
        /**
        * Set x1 of gradient line.
        *
        * @param x1
        */
        void set_x1(const double &x1);
        /**
        * Get y1 of gradient line.
        *
        * @return y1 of gradient line.
        */
        double get_y1() const;
        /**
        * Set y1 of gradient line.
        *
        * @param y1
        */
        void set_y1(const double &y1);
        /**
        * Get x2 of gradient line.
        *
        * @return x2 of gradient line.
        */
        double get_x2() const;
        /**
        * Set x2 of gradient line.
        *
        * @param x2
        */
        void set_x2(const double &x2);
        /**
        * Get y2 of gradient line.
        *
        * @return y2 of gradient line.
        */
        double get_y2() const;
        /**
        * Set y2 of gradient line.
        *
        * @param y2
        */
        void set_y2(const double &y2);

        /// Functional
        /**
        * Parse this gradient to XML.
        */
        std::string to_XML() const override;
    }
}
#endif