#ifndef __LZ_SVG_FOREIGN_OBJECT__
#define __LZ_SVG_FOREIGN_OBJECT__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <foreignObject> SVG element includes elements from a different XML namespace. In the context of a browser, it is most likely (X)HTML.
    */
    class SVGForeignObject: public SVGElement {
    public:
        /**
        * Constructor of foreignObject.
        */
        SVGForeignObject();
        /**
        * Deep copy of foreignObject.
        */
        SVGForeignObject(const SVGForeignObject &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// ForeignObject
    private:
        std::string _width;
    private:
        std::string _height;
    private:
        std::string _x;
    private:
        std::string _y;
    public:
        /**
        * The height of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the width
        */
        const std::string get_width() const;
        /**
        * The height of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the width
        */
        void set_width(const std::string &width);
        /**
        * The width of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the height
        */
        const std::string get_height() const;
        /**
        * The width of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the height
        */
        void set_height(const std::string &height);
        /**
        * The x coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        const std::string get_x() const;
        /**
        * The x coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        void set_x(const std::string &x);
        /**
        * The y coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        const std::string get_y() const;
        /**
        * The y coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        void set_y(const std::string &y);

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