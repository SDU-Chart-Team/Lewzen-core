#ifndef __LZ_SVG_USE__
#define __LZ_SVG_USE__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <use> element takes nodes from within the SVG document, and duplicates them somewhere else.
    */
    class SVGUse: public SVGElement {
    public:
        /**
        * Constructor of use.
        */
        SVGUse();
        /**
        * Deep copy of use.
        */
        SVGUse(const SVGUse &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Use
    private:
        double _width;
    private:
        double _height;
    private:
        double _x;
    private:
        double _y;
    private:
        std::string _href;
    public:
        /**
        * Get the width of the use element.
        *
        * @return the width of the use element.
        */
        double get_width() const;
        /**
        * Set the width of the use element.
        *
        * @param width the width of the use element.
        */
        void set_width(const double &width);
        /**
        * Get the height of the use element.
        *
        * @return the height of the use element.
        */
        double get_height() const;
        /**
        * Set the height of the use element.
        *
        * @param height the height of the use element.
        */
        void set_height(const double &height);
        /**
        * Get x of the use element.
        *
        * @return x of the use element.
        */
        double get_x() const;
        /**
        * Set x of the use element.
        *
        * @param x x of the use element.
        */
        void set_x(const double &x);
        /**
        * Get y of the use element.
        *
        * @return y of the use element.
        */
        double get_y() const;
        /**
        * Set y of the use element.
        *
        * @param y y of the use element.
        */
        void set_y(const double &y);
        /**
        * Get The URL to an element/fragment that needs to be duplicated.
        *
        * @return The URL to an element/fragment that needs to be duplicated.
        */
        const std::string get_href() const;
        /**
        * Set The URL to an element/fragment that needs to be duplicated.
        *
        * @param href The URL to an element/fragment that needs to be duplicated.
        */
        void set_href(const std::string &href);

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