#ifndef __LZ_SVG_PATTERN__
#define __LZ_SVG_PATTERN__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <pattern> element defines a graphics object which can be redrawn at repeated x- and y-coordinate intervals ("tiled") to cover an area.
    */
    class SVGPattern: public virtual SVGElement {
    public:
        /**
        * Constructor of pattern.
        */
        SVGPattern();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Pattern
    private:
        std::string _height;
    private:
        std::string _href;
    private:
        std::string _pattern_content_units;
    private:
        std::string _pattern_transform;
    private:
        std::string _pattern_units;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _view_box;
    private:
        std::string _width;
    private:
        std::string _x;
    private:
        std::string _y;
    public:
        /**
        * This attribute determines the height of the pattern tile. 
        * Value type: <length>|<percentage>; Default value: 0; Animatable: yes
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * This attribute determines the height of the pattern tile. 
        * Value type: <length>|<percentage>; Default value: 0; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * This attribute reference a template pattern that provides default values for the <pattern> attributes. 
        * Value type: <URL>; Default value: none; Animatable: yes
        *
        * @return the href
        */
        virtual const std::string get_href() const;
        /**
        * This attribute reference a template pattern that provides default values for the <pattern> attributes. 
        * Value type: <URL>; Default value: none; Animatable: yes
        *
        * @param  the href
        */
        virtual void set_href(const std::string &href);
        /**
        * This attribute defines the coordinate system for the contents of the <pattern>. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: userSpaceOnUse; Animatable: yes
        *
        * @return the patternContentUnits
        */
        virtual const std::string get_pattern_content_units() const;
        /**
        * This attribute defines the coordinate system for the contents of the <pattern>. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: userSpaceOnUse; Animatable: yes
        *
        * @param  the patternContentUnits
        */
        virtual void set_pattern_content_units(const std::string &pattern_content_units);
        /**
        * This attribute contains the definition of an optional additional transformation from the pattern coordinate system onto the target coordinate system. 
        * Value type: <transform-list>; Default value: none; Animatable: yes
        *
        * @return the patternTransform
        */
        virtual const std::string get_pattern_transform() const;
        /**
        * This attribute contains the definition of an optional additional transformation from the pattern coordinate system onto the target coordinate system. 
        * Value type: <transform-list>; Default value: none; Animatable: yes
        *
        * @param  the patternTransform
        */
        virtual void set_pattern_transform(const std::string &pattern_transform);
        /**
        * This attribute defines the coordinate system for attributes x, y, width , and height. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: objectBoundingBox; Animatable: yes
        *
        * @return the patternUnits
        */
        virtual const std::string get_pattern_units() const;
        /**
        * This attribute defines the coordinate system for attributes x, y, width , and height. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: objectBoundingBox; Animatable: yes
        *
        * @param  the patternUnits
        */
        virtual void set_pattern_units(const std::string &pattern_units);
        /**
        * This attribute defines how the SVG fragment must be deformed if it is embedded in a container with a different aspect ratio. 
        * Value type: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)? ; Default value: xMidYMid meet; Animatable: yes
        *
        * @return the preserveAspectRatio
        */
        virtual const std::string get_preserve_aspect_ratio() const;
        /**
        * This attribute defines how the SVG fragment must be deformed if it is embedded in a container with a different aspect ratio. 
        * Value type: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)? ; Default value: xMidYMid meet; Animatable: yes
        *
        * @param  the preserveAspectRatio
        */
        virtual void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * This attribute defines the bound of the SVG viewport for the pattern fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @return the viewBox
        */
        virtual const std::string get_view_box() const;
        /**
        * This attribute defines the bound of the SVG viewport for the pattern fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @param  the viewBox
        */
        virtual void set_view_box(const std::string &view_box);
        /**
        * This attribute determines the width of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * This attribute determines the width of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * This attribute determines the x coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * This attribute determines the x coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * This attribute determines the y coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * This attribute determines the y coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);

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
        const std::string attribute_differ(const SVGPattern &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPattern
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPattern
        */
        std::shared_ptr<SVGPattern> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPattern
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPattern
        */
        virtual SVGPattern &operator=(const SVGPattern &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif