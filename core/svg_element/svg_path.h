#ifndef __LZ_SVG_PATH__
#define __LZ_SVG_PATH__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <path> SVG element is the generic element to define a shape. All the basic shapes can be created with a path element.
    */
    class SVGPath: public SVGElement {
    public:
        /**
        * Constructor of path.
        */
        SVGPath();
        /**
        * Deep copy of path.
        */
        SVGPath(const SVGPath &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Path
    private:
        std::string _d;
    private:
        double _path_length;
    public:
        /**
        * Get defines the shape of the path.
        *
        * @return defines the shape of the path.
        */
        const std::string get_d() const;
        /**
        * Set defines the shape of the path.
        *
        * @param d defines the shape of the path.
        */
        void set_d(const std::string &d);
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