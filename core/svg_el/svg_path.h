#ifndef __LZ_SVG_PATH__
#define __LZ_SVG_PATH__
#include <string>
#include <sstream>
#include "../svg_el.h"

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
        std::string _path_length;
    public:
        /**
        * This attribute defines the shape of the path. 
        * Value type: <string> ; Default value: ''; Animatable: yes
        *
        * @return the d
        */
        const std::string get_d() const;
        /**
        * This attribute defines the shape of the path. 
        * Value type: <string> ; Default value: ''; Animatable: yes
        *
        * @param  the d
        */
        void set_d(const std::string &d);
        /**
        * This attribute lets authors specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        const std::string get_path_length() const;
        /**
        * This attribute lets authors specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        void set_path_length(const std::string &path_length);

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