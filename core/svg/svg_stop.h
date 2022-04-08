#include <string>
#include "../xml_element.h"
#ifndef __LZ_SVG_STOP__
#define __LZ_SVG_STOP__

namespace Lewzen {
    /**
    * A gradient stop define in SVG context.
    */
    class SVGStop: public XMLElement {
    private:
        double _offset;
        std::string _stop_color;
        double _stop_opacity;
    public:
        /**
        * Constructor of stop.
        */
        SVGStop();

        /// Properties
        /**
        * Get the offset of stop point.
        *
        * @return the offset of stop point.
        */
        double get_offset() const;
        /**
        * Set the offset of stop point.
        *
        * @param offset the offset of stop point.
        */
        void set_offset(const double &offset);
        /**
        * Get the color of stop point, eg: 'red', '#FFFFFF'.
        *
        * @return the color of stop point.
        */
        const std::string get_stop_color() const;
        /**
        * Set the color of stop point, eg: 'red', '#FFFFFF'.
        *
        * @param stop_color the color of stop point.
        */
        void set_stop_color(const std::string &stop_color);
        /**
        * Get the opacity of stop point.
        *
        * @return the opacity of stop point.
        */
        double get_stop_opacity() const;
        /**
        * Set the opacityof stop point.
        *
        * @param stop_opacity the opacity of stop point.
        */
        void set_stop_opacity(const double &stop_opacity);
        

        /// Functional
        /**
        * Parse this stop to XML.
        */
        const std::string outer_XML() const override;
    }
}
#endif