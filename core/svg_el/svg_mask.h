#ifndef __LZ_SVG_MASK__
#define __LZ_SVG_MASK__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <mask> element defines an alpha mask for compositing the current object into the background. A mask is used/referenced using the mask property.
    */
    class SVGMask: public SVGElement {
    public:
        /**
        * Constructor of mask.
        */
        SVGMask();
        /**
        * Deep copy of mask.
        */
        SVGMask(const SVGMask &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Mask
    private:
        std::string _height;
    private:
        std::string _mask_content_units;
    private:
        std::string _mask_units;
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _width;
    public:
        /**
        * This attribute defines the height of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @return the height
        */
        const std::string get_height() const;
        /**
        * This attribute defines the height of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @param  the height
        */
        void set_height(const std::string &height);
        /**
        * This attribute defines the coordinate system for the contents of the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: userSpaceOnUse; Animatable: yes.
        *
        * @return the maskContentUnits
        */
        const std::string get_mask_content_units() const;
        /**
        * This attribute defines the coordinate system for the contents of the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: userSpaceOnUse; Animatable: yes.
        *
        * @param  the maskContentUnits
        */
        void set_mask_content_units(const std::string &mask_content_units);
        /**
        * This attribute defines the coordinate system for attributes x, y, width and height on the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @return the maskUnits
        */
        const std::string get_mask_units() const;
        /**
        * This attribute defines the coordinate system for attributes x, y, width and height on the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @param  the maskUnits
        */
        void set_mask_units(const std::string &mask_units);
        /**
        * This attribute defines the x-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @return the x
        */
        const std::string get_x() const;
        /**
        * This attribute defines the x-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @param  the x
        */
        void set_x(const std::string &x);
        /**
        * This attribute defines the y-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @return the y
        */
        const std::string get_y() const;
        /**
        * This attribute defines the y-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @param  the y
        */
        void set_y(const std::string &y);
        /**
        * This attribute defines the width of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @return the width
        */
        const std::string get_width() const;
        /**
        * This attribute defines the width of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @param  the width
        */
        void set_width(const std::string &width);

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