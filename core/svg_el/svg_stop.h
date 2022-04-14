#ifndef __LZ_SVG_STOP__
#define __LZ_SVG_STOP__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The SVG <stop> element defines a color and its position to use on a gradient. This element is always a child of a <linearGradient> or <radialGradient> element.
    */
    class SVGStop: public SVGElement {
    public:
        /**
        * Constructor of stop.
        */
        SVGStop();
        /**
        * Deep copy of stop.
        */
        SVGStop(const SVGStop &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

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
        const std::string get_offset() const;
        /**
        * This attribute defines where the gradient stop is placed along the gradient vector. 
        * Value type: <number>|<percentage>; Default value: 0; Animatable: yes
        *
        * @param  the offset
        */
        void set_offset(const std::string &offset);
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<icccolor>; Default value: black; Animatable: yes
        *
        * @return the stop-color
        */
        const std::string get_stop_color() const;
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<icccolor>; Default value: black; Animatable: yes
        *
        * @param  the stop-color
        */
        void set_stop_color(const std::string &stop_color);
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity>; Default value: 1; Animatable: yes
        *
        * @return the stop-opacity
        */
        const std::string get_stop_opacity() const;
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity>; Default value: 1; Animatable: yes
        *
        * @param  the stop-opacity
        */
        void set_stop_opacity(const std::string &stop_opacity);

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