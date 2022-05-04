#ifndef __LZ_SVG_MASK__
#define __LZ_SVG_MASK__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <mask> element defines an alpha mask for compositing the current object into the background. A mask is used/referenced using the mask property.
    */
    class SVGMask: public virtual SVGElement {
    public:
        /**
        * Constructor of mask.
        */
        SVGMask();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

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
        virtual const std::string get_height() const;
        /**
        * This attribute defines the height of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * This attribute defines the coordinate system for the contents of the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: userSpaceOnUse; Animatable: yes.
        *
        * @return the maskContentUnits
        */
        virtual const std::string get_mask_content_units() const;
        /**
        * This attribute defines the coordinate system for the contents of the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: userSpaceOnUse; Animatable: yes.
        *
        * @param  the maskContentUnits
        */
        virtual void set_mask_content_units(const std::string &mask_content_units);
        /**
        * This attribute defines the coordinate system for attributes x, y, width and height on the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @return the maskUnits
        */
        virtual const std::string get_mask_units() const;
        /**
        * This attribute defines the coordinate system for attributes x, y, width and height on the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        *
        * @param  the maskUnits
        */
        virtual void set_mask_units(const std::string &mask_units);
        /**
        * This attribute defines the x-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * This attribute defines the x-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * This attribute defines the y-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * This attribute defines the y-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * This attribute defines the width of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * This attribute defines the width of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);

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
        const std::string attribute_differ(const SVGMask &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGMask
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGMask
        */
        std::shared_ptr<SVGMask> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGMask
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGMask
        */
        virtual SVGMask &operator=(const SVGMask &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif