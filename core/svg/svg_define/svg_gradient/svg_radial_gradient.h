#include <string>
#include <vector>
#include "../svg_gradient.h"
#ifndef __LZ_SVG_RADIAL_GRADIENT__
#define __LZ_SVG_RADIAL_GRADIENT__

namespace Lewzen {
    /**
    * A radial gradient define in SVG context.
    */
    class SVGRadialGradient: public SVGGradient {
    public:
        enum class SpreadMethod { PAD, REFLECT, REPEAT };
        enum class GradientUnits { OBJECT_BOUNDING_BOX, USER_SPACE_ON_USE };
    private:
        double _cx;
        double _cy;
        double _r;
        double _fx;
        double _fy;
        SpreadMethod _spread_method;
        GradientUnits _gradient_units;
    public:
        /**
        * Constructor of radial gradient.
        */
        SVGRadialGradient();

        /// Properties
        /**
        * Get x of center point.
        *
        * @return x of center point.
        */
        double get_cx() const;
        /**
        * Set x of center point.
        *
        * @param cx x of center point.
        */
        void set_cx(const double &cx);
        /**
        * Get y of center point.
        *
        * @return y of center point.
        */
        double get_cy() const;
        /**
        * Set y of center point.
        *
        * @param cy y of center point.
        */
        void set_cy(const double &cy);
        /**
        * Get the radius.
        *
        * @return the radius.
        */
        double get_r() const;
        /**
        * Set the radius.
        *
        * @param r the radius.
        */
        void set_r(const double &r);
        /**
        * Get x of focal point.
        *
        * @return x of focal point.
        */
        double get_fx() const;
        /**
        * Set x of focal point.
        *
        * @param fx x of focal point.
        */
        void set_fx(const double &fx);
        /**
        * Get y of focal point.
        *
        * @return y of focal point.
        */
        double get_fy() const;
        /**
        * Set y of focal point.
        *
        * @param fy y of focal point.
        */
        void set_fy(const double &fy);
        /**
        * Get the spread method.
        *
        * @return the spread method.
        */
        const SpreadMethod &get_spread_method() const;
        /**
        * Set the spread method.
        *
        * @param spread_method the spread method.
        */
        void set_spread_method(const SpreadMethod &spread_method);
        /**
        * Get the gradient units.
        *
        * @return the gradient units.
        */
        const GradientUnits &get_gradient_units() const;
        /**
        * Set the gradient units.
        *
        * @param gradient_units the gradient units.
        */
        void set_gradient_units(const GradientUnits &gradient_units);

        /// Functional
        /**
        * Parse this gradient to XML.
        */
        std::string to_XML() const override;
    }
}
#endif