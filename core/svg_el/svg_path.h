#ifndef __LZ_SVG_PATH__
#define __LZ_SVG_PATH__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <anything>:path SVG element is the generic element to define a shape. All the basic shapes can be created with a path element.
    */
    class SVGPath: public virtual SVGElement {
    public:
        /**
        * Constructor of path.
        */
        SVGPath();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_d() const override;
        /**
        * This attribute defines the shape of the path. 
        * Value type: <string> ; Default value: ''; Animatable: yes
        *
        * @param  the d
        */
        virtual void set_d(const std::string &d) override;
        /**
        * This attribute lets authors specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * This attribute lets authors specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        virtual void set_path_length(const std::string &path_length);

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
        const std::string attribute_differ(const SVGPath &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPath
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGPath
        */
        std::shared_ptr<SVGPath> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPath
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGPath
        */
        virtual SVGPath &operator=(const SVGPath &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif