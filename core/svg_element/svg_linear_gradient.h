#ifndef __LZ_SVG_LINEAR_GRADIENT__
#define __LZ_SVG_LINEAR_GRADIENT__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <linearGradient> element lets authors define linear gradients to apply to other SVG elements.
    */
    class SVGLinearGradient: public SVGElement {
    public:
        /**
        * Constructor of linearGradient.
        */
        SVGLinearGradient();
        /**
        * Deep copy of linearGradient.
        */
        SVGLinearGradient(const SVGLinearGradient &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// LinearGradient
    private:
        double _xQ;
    private:
        double _yQ;
    private:
        double _xR;
    private:
        double _yR;
    public:
        enum class SpreadMethod { PAD, REFLECT, REPEAT };
    private:
        SpreadMethod _spread_method;
    public:
        enum class GradientUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        GradientUnits _gradient_units;
    private:
        std::string _gradient_transform;
    private:
        std::string _href;
    public:
        /**
        * Get x1 of gradient line.
        *
        * @return x1 of gradient line.
        */
        double get_xQ() const;
        /**
        * Set x1 of gradient line.
        *
        * @param xQ x1 of gradient line.
        */
        void set_xQ(const double &xQ);
        /**
        * Get y1 of gradient line.
        *
        * @return y1 of gradient line.
        */
        double get_yQ() const;
        /**
        * Set y1 of gradient line.
        *
        * @param yQ y1 of gradient line.
        */
        void set_yQ(const double &yQ);
        /**
        * Get x2 of gradient line.
        *
        * @return x2 of gradient line.
        */
        double get_xR() const;
        /**
        * Set x2 of gradient line.
        *
        * @param xR x2 of gradient line.
        */
        void set_xR(const double &xR);
        /**
        * Get y2 of gradient line.
        *
        * @return y2 of gradient line.
        */
        double get_yR() const;
        /**
        * Set y2 of gradient line.
        *
        * @param yR y2 of gradient line.
        */
        void set_yR(const double &yR);
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
        /**
        * Get provides additional transformation to the gradient coordinate system.
        *
        * @return provides additional transformation to the gradient coordinate system.
        */
        const std::string get_gradient_transform() const;
        /**
        * Set provides additional transformation to the gradient coordinate system.
        *
        * @param gradient_transform provides additional transformation to the gradient coordinate system.
        */
        void set_gradient_transform(const std::string &gradient_transform);
        /**
        * Get defines a reference to another <linearGradient>.
        *
        * @return defines a reference to another <linearGradient>.
        */
        const std::string get_href() const;
        /**
        * Set defines a reference to another <linearGradient>.
        *
        * @param href defines a reference to another <linearGradient>.
        */
        void set_href(const std::string &href);

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