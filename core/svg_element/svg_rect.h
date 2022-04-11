#ifndef __LZ_SVG_RECT__
#define __LZ_SVG_RECT__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <rect> element is a basic SVG shape that draws rectangles, defined by their position, width, and height. The rectangles may have their corners rounded.
    */
    class SVGRect: public SVGElement {
    public:
        /**
        * Constructor of rect.
        */
        SVGRect();
        /**
        * Deep copy of rect.
        */
        SVGRect(const SVGRect &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Rect
    private:
        double _x;
    private:
        double _y;
    private:
        double _width;
    private:
        double _height;
    private:
        double _rx;
    private:
        double _ry;
    private:
        double _path_length;
    public:
        /**
        * Get x position of the rect.
        *
        * @return x position of the rect.
        */
        double get_x() const;
        /**
        * Set x position of the rect.
        *
        * @param x x position of the rect.
        */
        void set_x(const double &x);
        /**
        * Get y position of the rect.
        *
        * @return y position of the rect.
        */
        double get_y() const;
        /**
        * Set y position of the rect.
        *
        * @param y y position of the rect.
        */
        void set_y(const double &y);
        /**
        * Get the width of the rect.
        *
        * @return the width of the rect.
        */
        double get_width() const;
        /**
        * Set the width of the rect.
        *
        * @param width the width of the rect.
        */
        void set_width(const double &width);
        /**
        * Get the height of the rect.
        *
        * @return the height of the rect.
        */
        double get_height() const;
        /**
        * Set the height of the rect.
        *
        * @param height the height of the rect.
        */
        void set_height(const double &height);
        /**
        * Get the horizontal corner radius of the rect.
        *
        * @return the horizontal corner radius of the rect.
        */
        double get_rx() const;
        /**
        * Set the horizontal corner radius of the rect.
        *
        * @param rx the horizontal corner radius of the rect.
        */
        void set_rx(const double &rx);
        /**
        * Get the vertical corner radius of the rect.
        *
        * @return the vertical corner radius of the rect.
        */
        double get_ry() const;
        /**
        * Set the vertical corner radius of the rect.
        *
        * @param ry the vertical corner radius of the rect.
        */
        void set_ry(const double &ry);
        /**
        * Get the total length for the circle's circumference, in user units.
        *
        * @return the total length for the circle's circumference, in user units.
        */
        double get_path_length() const;
        /**
        * Set the total length for the circle's circumference, in user units.
        *
        * @param path_length the total length for the circle's circumference, in user units.
        */
        void set_path_length(const double &path_length);

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