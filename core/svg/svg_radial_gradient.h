#ifndef __LZ_SVG_RADIAL_GRADIENT__
#define __LZ_SVG_RADIAL_GRADIENT__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <radialGradient> element lets authors define radial gradients that can be applied to fill or stroke of graphical elements.
    */
    class SVGRadialGradient: public XMLElement {
    public:
        /**
        * Constructor of radialGradient.
        */
        SVGRadialGradient();
        /**
        * Deep copy of radialGradient.
        */
        SVGRadialGradient(const SVGRadialGradient &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// RadialGradient
    private:
        double _cx;
    private:
        double _cy;
    private:
        double _r;
    private:
        double _fx;
    private:
        double _fy;
    public:
        enum class SpreadMethod { PAD, REFLECT, REPEAT };
    private:
        SpreadMethod _spread_method;
    public:
        enum class GradientUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        GradientUnits _gradient_units;
    public:
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
        * Get radius of radiation.
        *
        * @return radius of radiation.
        */
        double get_r() const;
        /**
        * Set radius of radiation.
        *
        * @param r radius of radiation.
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
        const SpreadMethod get_spread_method() const;
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
        const GradientUnits get_gradient_units() const;
        /**
        * Set the gradient units.
        *
        * @param gradient_units the gradient units.
        */
        void set_gradient_units(const GradientUnits &gradient_units);

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