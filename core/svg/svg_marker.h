#ifndef __LZ_SVG_MARKER__
#define __LZ_SVG_MARKER__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <marker> element defines the graphic that is to be used for drawing arrowheads or polymarkers on a given <path>, <line>, <polyline> or <polygon> element.
    */
    class SVGMarker: public XMLElement {
    public:
        /**
        * Constructor of marker.
        */
        SVGMarker();
        /**
        * Deep copy of marker.
        */
        SVGMarker(const SVGMarker &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Marker
    private:
        double _marker_width;
    private:
        double _marker_height;
    private:
        double _ref_x;
    private:
        double _ref_y;
    private:
        std::string _orient;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _view_box;
    public:
        enum class MarkerUnits { USER_SPACE_ON_USE, STROKE_WIDTH };
    private:
        MarkerUnits _marker_units;
    public:
        /**
        * Get width of marker viewport.
        *
        * @return width of marker viewport.
        */
        double get_marker_width() const;
        /**
        * Set width of marker viewport.
        *
        * @param marker_width width of marker viewport.
        */
        void set_marker_width(const double &marker_width);
        /**
        * Get height of marker viewport.
        *
        * @return height of marker viewport.
        */
        double get_marker_height() const;
        /**
        * Set height of marker viewport.
        *
        * @param marker_height height of marker viewport.
        */
        void set_marker_height(const double &marker_height);
        /**
        * Get x of the reference point of the marker.
        *
        * @return x of the reference point of the marker.
        */
        double get_ref_x() const;
        /**
        * Set x of the reference point of the marker.
        *
        * @param ref_x x of the reference point of the marker.
        */
        void set_ref_x(const double &ref_x);
        /**
        * Get y of the reference point of the marker.
        *
        * @return y of the reference point of the marker.
        */
        double get_ref_y() const;
        /**
        * Set y of the reference point of the marker.
        *
        * @param ref_y y of the reference point of the marker.
        */
        void set_ref_y(const double &ref_y);
        /**
        * Get the orientation of the marker relative to the shape it is attached to. eg: 'auto', 'auto-start-reverse', '65deg'.
        *
        * @return the orientation of the marker relative to the shape it is attached to. eg: 'auto', 'auto-start-reverse', '65deg'.
        */
        const std::string get_orient() const;
        /**
        * Set the orientation of the marker relative to the shape it is attached to. eg: 'auto', 'auto-start-reverse', '65deg'.
        *
        * @param orient the orientation of the marker relative to the shape it is attached to. eg: 'auto', 'auto-start-reverse', '65deg'.
        */
        void set_orient(const std::string &orient);
        /**
        * Get how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @return how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        const std::string get_preserve_aspect_ratio() const;
        /**
        * Set how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @param preserve_aspect_ratio how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * Get the bound of the SVG viewport for the current SVG fragment. eg: '0 0 100 100'
        *
        * @return the bound of the SVG viewport for the current SVG fragment. eg: '0 0 100 100'
        */
        const std::string get_view_box() const;
        /**
        * Set the bound of the SVG viewport for the current SVG fragment. eg: '0 0 100 100'
        *
        * @param view_box the bound of the SVG viewport for the current SVG fragment. eg: '0 0 100 100'
        */
        void set_view_box(const std::string &view_box);
        /**
        * Get the marker units.
        *
        * @return the marker units.
        */
        const MarkerUnits get_marker_units() const;
        /**
        * Set the marker units.
        *
        * @param marker_units the marker units.
        */
        void set_marker_units(const MarkerUnits &marker_units);

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