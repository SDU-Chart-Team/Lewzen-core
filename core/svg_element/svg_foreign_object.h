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
        double _width;
    private:
        double _height;
    private:
        double _x;
    private:
        double _y;
    public:
        /**
        * Get height of the foreign object.
        *
        * @return height of the foreign object.
        */
        double get_width() const;
        /**
        * Set height of the foreign object.
        *
        * @param width height of the foreign object.
        */
        void set_width(const double &width);
        /**
        * Get width of the foreign object.
        *
        * @return width of the foreign object.
        */
        double get_height() const;
        /**
        * Set width of the foreign object.
        *
        * @param height width of the foreign object.
        */
        void set_height(const double &height);
        /**
        * Get x of the foreign object.
        *
        * @return x of the foreign object.
        */
        double get_x() const;
        /**
        * Set x of the foreign object.
        *
        * @param x x of the foreign object.
        */
        void set_x(const double &x);
        /**
        * Get y of the foreign object.
        *
        * @return y of the foreign object.
        */
        double get_y() const;
        /**
        * Set y of the foreign object.
        *
        * @param y y of the foreign object.
        */
        void set_y(const double &y);

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