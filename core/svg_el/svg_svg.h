#ifndef __LZ_SVG_SVG__
#define __LZ_SVG_SVG__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The svg element is a container that defines a new coordinate system and viewport. It is used as the outermost element of SVG documents, but it can also be used to embed an SVG fragment inside an SVG or HTML document.
    */
    class SVGSvg: public virtual SVGElement {
    public:
        /**
        * Constructor of svg.
        */
        SVGSvg();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Svg
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _width;
    private:
        std::string _height;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _view_box;
    public:
        /**
        * The displayed x coordinate of the svg container. No effect on outermost svg elements. Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * The displayed x coordinate of the svg container. No effect on outermost svg elements. Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * The displayed y coordinate of the svg container. No effect on outermost svg elements. Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * The displayed y coordinate of the svg container. No effect on outermost svg elements. Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * The displayed width of the rectangular viewport. (Not the width of its coordinate system.) Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * The displayed width of the rectangular viewport. (Not the width of its coordinate system.) Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * The displayed height of the rectangular viewport. (Not the height of its coordinate system.) Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * The displayed height of the rectangular viewport. (Not the height of its coordinate system.) Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * How the svg fragment must be deformed if it is displayed with a different aspect ratio. Value type: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)? ; Default value: xMidYMid meet; Animatable: yes
        *
        * @return the preserveAspectRatio
        */
        virtual const std::string get_preserve_aspect_ratio() const;
        /**
        * How the svg fragment must be deformed if it is displayed with a different aspect ratio. Value type: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)? ; Default value: xMidYMid meet; Animatable: yes
        *
        * @param  the preserveAspectRatio
        */
        virtual void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * The SVG viewport coordinates for the current SVG fragment. Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        *
        * @return the viewBox
        */
        virtual const std::string get_view_box() const;
        /**
        * The SVG viewport coordinates for the current SVG fragment. Value type: <list-of-numbers> ; Default value: none; Animatable: yes
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
        const std::string attribute_differ(const SVGSvg &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGSvg
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGSvg
        */
        std::shared_ptr<SVGSvg> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGSvg
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGSvg
        */
        virtual SVGSvg &operator=(const SVGSvg &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif