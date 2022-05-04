#ifndef __LZ_SVG_MARKER__
#define __LZ_SVG_MARKER__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <marker> element defines the graphic that is to be used for drawing arrowheads or polymarkers on a given <anything>:path, <line>, <polyline> or <polygon> element.
    */
    class SVGMarker: public virtual SVGElement {
    public:
        /**
        * Constructor of marker.
        */
        SVGMarker();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Marker
    private:
        std::string _marker_height;
    private:
        std::string _marker_units;
    private:
        std::string _marker_width;
    private:
        std::string _orient;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _ref_x;
    private:
        std::string _ref_y;
    private:
        std::string _view_box;
    public:
        /**
        * This attribute defines the height of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        *
        * @return the markerHeight
        */
        virtual const std::string get_marker_height() const;
        /**
        * This attribute defines the height of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        *
        * @param  the markerHeight
        */
        virtual void set_marker_height(const std::string &marker_height);
        /**
        * This attribute defines the coordinate system for the attributes markerWidth, markerHeight and the contents of the <marker>. 
        * Value type: userSpaceOnUse|strokeWidth ; Default value: strokeWidth; Animatable: yes
        *
        * @return the markerUnits
        */
        virtual const std::string get_marker_units() const;
        /**
        * This attribute defines the coordinate system for the attributes markerWidth, markerHeight and the contents of the <marker>. 
        * Value type: userSpaceOnUse|strokeWidth ; Default value: strokeWidth; Animatable: yes
        *
        * @param  the markerUnits
        */
        virtual void set_marker_units(const std::string &marker_units);
        /**
        * This attribute defines the width of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        *
        * @return the markerWidth
        */
        virtual const std::string get_marker_width() const;
        /**
        * This attribute defines the width of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        *
        * @param  the markerWidth
        */
        virtual void set_marker_width(const std::string &marker_width);
        /**
        * This attribute defines the orientation of the marker relative to the shape it is attached to. 
        * Value type: auto|auto-start-reverse|<angle> ; Default value: 0; Animatable: yes
        *
        * @return the orient
        */
        virtual const std::string get_orient() const;
        /**
        * This attribute defines the orientation of the marker relative to the shape it is attached to. 
        * Value type: auto|auto-start-reverse|<angle> ; Default value: 0; Animatable: yes
        *
        * @param  the orient
        */
        virtual void set_orient(const std::string &orient);
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @return the preserveAspectRatio
        */
        virtual const std::string get_preserve_aspect_ratio() const;
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @param  the preserveAspectRatio
        */
        virtual void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * This attribute defines the x coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        *
        * @return the refX
        */
        virtual const std::string get_ref_x() const;
        /**
        * This attribute defines the x coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        *
        * @param  the refX
        */
        virtual void set_ref_x(const std::string &ref_x);
        /**
        * This attribute defines the y coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        *
        * @return the refY
        */
        virtual const std::string get_ref_y() const;
        /**
        * This attribute defines the y coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        *
        * @param  the refY
        */
        virtual void set_ref_y(const std::string &ref_y);
        /**
        * This attribute defines the bound of the SVG viewport for the current SVG fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @return the viewBox
        */
        virtual const std::string get_view_box() const;
        /**
        * This attribute defines the bound of the SVG viewport for the current SVG fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @param  the viewBox
        */
        virtual void set_view_box(const std::string &view_box);

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
        const std::string attribute_differ(const SVGMarker &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGMarker
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGMarker
        */
        std::shared_ptr<SVGMarker> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGMarker
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGMarker
        */
        virtual SVGMarker &operator=(const SVGMarker &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif