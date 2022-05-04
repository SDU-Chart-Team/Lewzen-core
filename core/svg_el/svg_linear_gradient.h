#ifndef __LZ_SVG_LINEAR_GRADIENT__
#define __LZ_SVG_LINEAR_GRADIENT__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <linearGradient> element lets authors define linear gradients to apply to other SVG elements.
    */
    class SVGLinearGradient: public virtual SVGElement {
    public:
        /**
        * Constructor of linearGradient.
        */
        SVGLinearGradient();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// LinearGradient
    private:
        std::string _gradient_units;
    private:
        std::string _gradient_transform;
    private:
        std::string _href;
    private:
        std::string _spread_method;
    private:
        std::string _xQ;
    private:
        std::string _xR;
    private:
        std::string _yQ;
    private:
        std::string _yR;
    public:
        /**
        * This attribute defines the coordinate system for attributes x1, x2, y1, y2 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @return the gradientUnits
        */
        virtual const std::string get_gradient_units() const;
        /**
        * This attribute defines the coordinate system for attributes x1, x2, y1, y2 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @param  the gradientUnits
        */
        virtual void set_gradient_units(const std::string &gradient_units);
        /**
        * This attribute provides additional transformation to the gradient coordinate system. 
        * Value type: <transform-list> ; Default value: identity transform; Animatable: yes
        *
        * @return the gradientTransform
        */
        virtual const std::string get_gradient_transform() const;
        /**
        * This attribute provides additional transformation to the gradient coordinate system. 
        * Value type: <transform-list> ; Default value: identity transform; Animatable: yes
        *
        * @param  the gradientTransform
        */
        virtual void set_gradient_transform(const std::string &gradient_transform);
        /**
        * This attribute defines a reference to another <linearGradient> element that will be used as a template. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @return the href
        */
        virtual const std::string get_href() const;
        /**
        * This attribute defines a reference to another <linearGradient> element that will be used as a template. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @param  the href
        */
        virtual void set_href(const std::string &href);
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        *
        * @return the spreadMethod
        */
        virtual const std::string get_spread_method() const;
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        *
        * @param  the spreadMethod
        */
        virtual void set_spread_method(const std::string &spread_method);
        /**
        * This attribute defines the x coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @return the x1
        */
        virtual const std::string get_xQ() const;
        /**
        * This attribute defines the x coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @param  the x1
        */
        virtual void set_xQ(const std::string &xQ);
        /**
        * This attribute defines the x coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 100%; Animatable: yes
        *
        * @return the x2
        */
        virtual const std::string get_xR() const;
        /**
        * This attribute defines the x coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 100%; Animatable: yes
        *
        * @param  the x2
        */
        virtual void set_xR(const std::string &xR);
        /**
        * This attribute defines the y coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @return the y1
        */
        virtual const std::string get_yQ() const;
        /**
        * This attribute defines the y coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @param  the y1
        */
        virtual void set_yQ(const std::string &yQ);
        /**
        * This attribute defines the y coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @return the y2
        */
        virtual const std::string get_yR() const;
        /**
        * This attribute defines the y coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        *
        * @param  the y2
        */
        virtual void set_yR(const std::string &yR);

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
        const std::string attribute_differ(const SVGLinearGradient &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGLinearGradient
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGLinearGradient
        */
        std::shared_ptr<SVGLinearGradient> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGLinearGradient
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGLinearGradient
        */
        virtual SVGLinearGradient &operator=(const SVGLinearGradient &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif