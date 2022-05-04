#ifndef __LZ_SVG_FOREIGN_OBJECT__
#define __LZ_SVG_FOREIGN_OBJECT__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <foreignObject> SVG element includes elements from a different XML namespace. In the context of a browser, it is most likely (X)HTML.
    */
    class SVGForeignObject: public virtual SVGElement {
    public:
        /**
        * Constructor of foreignObject.
        */
        SVGForeignObject();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_width() const;
        /**
        * The height of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * The width of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * The width of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * The x coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * The x coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * The y coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * The y coordinate of the foreignObject. 
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
        const std::string attribute_differ(const SVGForeignObject &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGForeignObject
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGForeignObject
        */
        std::shared_ptr<SVGForeignObject> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGForeignObject
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGForeignObject
        */
        virtual SVGForeignObject &operator=(const SVGForeignObject &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif