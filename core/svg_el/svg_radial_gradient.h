#ifndef __LZ_SVG_RADIAL_GRADIENT__
#define __LZ_SVG_RADIAL_GRADIENT__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <radialGradient> element lets authors define radial gradients that can be applied to fill or stroke of graphical elements.
    */
    class SVGRadialGradient: public SVGElement {
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
        std::string _cx;
    private:
        std::string _cy;
    private:
        std::string _fr;
    private:
        std::string _fx;
    private:
        std::string _fy;
    private:
        std::string _gradient_units;
    private:
        std::string _gradient_transform;
    private:
        std::string _href;
    private:
        std::string _r;
    private:
        std::string _spread_method;
    public:
        /**
        * This attribute defines the x coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @return the cx
        */
        const std::string get_cx() const;
        /**
        * This attribute defines the x coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @param  the cx
        */
        void set_cx(const std::string &cx);
        /**
        * This attribute defines the y coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @return the cy
        */
        const std::string get_cy() const;
        /**
        * This attribute defines the y coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @param  the cy
        */
        void set_cy(const std::string &cy);
        /**
        * This attribute defines the radius of the start circle of the radial gradient. The gradient will be drawn such that the 0% <stop> is mapped to the perimeter of the start circle. 
        * Value type: <length> ; Default value: 0%; Animatable: yes
        *
        * @return the fr
        */
        const std::string get_fr() const;
        /**
        * This attribute defines the radius of the start circle of the radial gradient. The gradient will be drawn such that the 0% <stop> is mapped to the perimeter of the start circle. 
        * Value type: <length> ; Default value: 0%; Animatable: yes
        *
        * @param  the fr
        */
        void set_fr(const std::string &fr);
        /**
        * This attribute defines the x coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        *
        * @return the fx
        */
        const std::string get_fx() const;
        /**
        * This attribute defines the x coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        *
        * @param  the fx
        */
        void set_fx(const std::string &fx);
        /**
        * This attribute defines the y coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        *
        * @return the fy
        */
        const std::string get_fy() const;
        /**
        * This attribute defines the y coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        *
        * @param  the fy
        */
        void set_fy(const std::string &fy);
        /**
        * This attribute defines the coordinate system for attributes cx, cy, r, fx, fy, fr 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @return the gradientUnits
        */
        const std::string get_gradient_units() const;
        /**
        * This attribute defines the coordinate system for attributes cx, cy, r, fx, fy, fr 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @param  the gradientUnits
        */
        void set_gradient_units(const std::string &gradient_units);
        /**
        * This attribute provides additional transformation to the gradient coordinate system. 
        * Value type: <transform-list> ; Default value: identity transform; Animatable: yes
        *
        * @return the gradientTransform
        */
        const std::string get_gradient_transform() const;
        /**
        * This attribute provides additional transformation to the gradient coordinate system. 
        * Value type: <transform-list> ; Default value: identity transform; Animatable: yes
        *
        * @param  the gradientTransform
        */
        void set_gradient_transform(const std::string &gradient_transform);
        /**
        * This attribute defines a reference to another <linearGradient> element that will be used as a template. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @return the href
        */
        const std::string get_href() const;
        /**
        * This attribute defines a reference to another <linearGradient> element that will be used as a template. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @param  the href
        */
        void set_href(const std::string &href);
        /**
        * This attribute defines the radius of the end circle of the radial gradient. The gradient will be drawn such that the 100% <stop> is mapped to the perimeter of the end circle. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @return the r
        */
        const std::string get_r() const;
        /**
        * This attribute defines the radius of the end circle of the radial gradient. The gradient will be drawn such that the 100% <stop> is mapped to the perimeter of the end circle. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        *
        * @param  the r
        */
        void set_r(const std::string &r);
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        *
        * @return the spreadMethod
        */
        const std::string get_spread_method() const;
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        *
        * @param  the spreadMethod
        */
        void set_spread_method(const std::string &spread_method);

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