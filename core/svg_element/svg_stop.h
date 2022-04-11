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
        double _offset;
    private:
        std::string _stop_color;
    private:
        double _stop_opacity;
    public:
        /**
        * Get the offset of stop.
        *
        * @return the offset of stop.
        */
        double get_offset() const;
        /**
        * Set the offset of stop.
        *
        * @param offset the offset of stop.
        */
        void set_offset(const double &offset);
        /**
        * Get the color of stop, eg: 'red', '#FFFFFF'.
        *
        * @return the color of stop, eg: 'red', '#FFFFFF'.
        */
        const std::string get_stop_color() const;
        /**
        * Set the color of stop, eg: 'red', '#FFFFFF'.
        *
        * @param stop_color the color of stop, eg: 'red', '#FFFFFF'.
        */
        void set_stop_color(const std::string &stop_color);
        /**
        * Get the opacity of stop.
        *
        * @return the opacity of stop.
        */
        double get_stop_opacity() const;
        /**
        * Set the opacity of stop.
        *
        * @param stop_opacity the opacity of stop.
        */
        void set_stop_opacity(const double &stop_opacity);

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