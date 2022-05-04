#ifndef __LZ_SVG_STOP__
#define __LZ_SVG_STOP__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The SVG <stop> element defines a color and its position to use on a gradient. This element is always a child of a <linearGradient> or <radialGradient> element.
    */
    class SVGStop: public virtual SVGElement {
    public:
        /**
        * Constructor of stop.
        */
        SVGStop();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Stop
    private:
        std::string _offset;
    private:
        std::string _stop_color;
    private:
        std::string _stop_opacity;
    public:
        /**
        * This attribute defines where the gradient stop is placed along the gradient vector. 
        * Value type: <number>|<percentage>; Default value: 0; Animatable: yes
        *
        * @return the offset
        */
        virtual const std::string get_offset() const;
        /**
        * This attribute defines where the gradient stop is placed along the gradient vector. 
        * Value type: <number>|<percentage>; Default value: 0; Animatable: yes
        *
        * @param  the offset
        */
        virtual void set_offset(const std::string &offset);
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<color>:icccolor; Default value: black; Animatable: yes
        *
        * @return the stop-color
        */
        virtual const std::string get_stop_color() const override;
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<color>:icccolor; Default value: black; Animatable: yes
        *
        * @param  the stop-color
        */
        virtual void set_stop_color(const std::string &stop_color) override;
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity-value>; Default value: 1; Animatable: yes
        *
        * @return the stop-opacity
        */
        virtual const std::string get_stop_opacity() const override;
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity-value>; Default value: 1; Animatable: yes
        *
        * @param  the stop-opacity
        */
        virtual void set_stop_opacity(const std::string &stop_opacity) override;

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
        const std::string attribute_differ(const SVGStop &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGStop
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGStop
        */
        std::shared_ptr<SVGStop> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGStop
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGStop
        */
        virtual SVGStop &operator=(const SVGStop &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif