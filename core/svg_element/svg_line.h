#ifndef __LZ_SVG_LINE__
#define __LZ_SVG_LINE__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <line> element is an SVG basic shape used to create a line connecting two points.
    */
    class SVGLine: public SVGElement {
    public:
        /**
        * Constructor of line.
        */
        SVGLine();
        /**
        * Deep copy of line.
        */
        SVGLine(const SVGLine &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Line
    private:
        double _xQ;
    private:
        double _yQ;
    private:
        double _xR;
    private:
        double _yR;
    private:
        double _path_length;
    public:
        /**
        * Get x position of the line starting point.
        *
        * @return x position of the line starting point.
        */
        double get_xQ() const;
        /**
        * Set x position of the line starting point.
        *
        * @param xQ x position of the line starting point.
        */
        void set_xQ(const double &xQ);
        /**
        * Get y position of the line starting point.
        *
        * @return y position of the line starting point.
        */
        double get_yQ() const;
        /**
        * Set y position of the line starting point.
        *
        * @param yQ y position of the line starting point.
        */
        void set_yQ(const double &yQ);
        /**
        * Get x position of the line ending point.
        *
        * @return x position of the line ending point.
        */
        double get_xR() const;
        /**
        * Set x position of the line ending point.
        *
        * @param xR x position of the line ending point.
        */
        void set_xR(const double &xR);
        /**
        * Get y position of the line ending point.
        *
        * @return y position of the line ending point.
        */
        double get_yR() const;
        /**
        * Set y position of the line ending point.
        *
        * @param yR y position of the line ending point.
        */
        void set_yR(const double &yR);
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