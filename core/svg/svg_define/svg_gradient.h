#include <string>
#include <vector>
#include <memory>
#include "../svg_define.h"
#include "svg_stop.h"
#ifndef __LZ_SVG_GRADIENT__
#define __LZ_SVG_GRADIENT__

namespace Lewzen {
    // Define for gradients: https://developer.mozilla.org/en-US/docs/Web/SVG/Tutorial/Gradients
    /**
    * A gradient define in SVG context.
    */
    class SVGGradient: public SVGDefine {
    private:
        std::vector<SVGStop> _stops;
    public:
        /**
        * Constructor of gradient.
        */
        SVGGradient();

        /// Stops
        /**
        * Get all stop points in gradient.
        *
        * @return the list of the stop points.
        */
        const std::vector<SVGStop> &get_stops() const;
        /**
        * Add a new stop point.
        *
        * @param stop a stop point of gradient.
        */
        void add_stop(SVGStop stop);
        /**
        * Remove a stop point by its content.
        *
        * @param stop a stop point of gradient.
        * @return true for successful removal.
        */
        bool remove_stop(SVGStop stop);
        /**
        * Remove a stop point by index.
        *
        * @param index index of stop point.
        * @return true for successful removal.
        */
        bool remove_stop(const int &index);

        /// Functional
        /**
        * Parse this gradient to XML.
        */
        virtual std::string to_XML() const;
    }
}
#endif