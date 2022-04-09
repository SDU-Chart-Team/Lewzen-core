#ifndef __LZ_SVG_MASK__
#define __LZ_SVG_MASK__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <mask> element defines an alpha mask for compositing the current object into the background. A mask is used/referenced using the mask property.
    */
    class SVGMask: public XMLElement {
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
        double _width;
    private:
        double _height;
    private:
        double _x;
    private:
        double _y;
    public:
        enum class MaskContentUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        MaskContentUnits _mask_content_units;
    public:
        enum class MaskUnits { USER_SPACE_ON_USE, OBJECT_BOUNDING_BOX };
    private:
        MaskUnits _mask_units;
    public:
        /**
        * Get width of masking area.
        *
        * @return width of masking area.
        */
        double get_width() const;
        /**
        * Set width of masking area.
        *
        * @param width width of masking area.
        */
        void set_width(const double &width);
        /**
        * Get height of masking area.
        *
        * @return height of masking area.
        */
        double get_height() const;
        /**
        * Set height of masking area.
        *
        * @param height height of masking area.
        */
        void set_height(const double &height);
        /**
        * Get x of the top-left corner of masking area.
        *
        * @return x of the top-left corner of masking area.
        */
        double get_x() const;
        /**
        * Set x of the top-left corner of masking area.
        *
        * @param x x of the top-left corner of masking area.
        */
        void set_x(const double &x);
        /**
        * Get y of the top-left corner of masking area.
        *
        * @return y of the top-left corner of masking area.
        */
        double get_y() const;
        /**
        * Set y of the top-left corner of masking area.
        *
        * @param y y of the top-left corner of masking area.
        */
        void set_y(const double &y);
        /**
        * Get the mask content units.
        *
        * @return the mask content units.
        */
        const MaskContentUnits get_mask_content_units() const;
        /**
        * Set the mask content units.
        *
        * @param mask_content_units the mask content units.
        */
        void set_mask_content_units(const MaskContentUnits &mask_content_units);
        /**
        * Get the mask units.
        *
        * @return the mask units.
        */
        const MaskUnits get_mask_units() const;
        /**
        * Set the mask units.
        *
        * @param mask_units the mask units.
        */
        void set_mask_units(const MaskUnits &mask_units);

        /// Attributes
    protected:
        /**
        * Get attribute string of this XML element.
        *
        * @return outer XML.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this XML element.
        *
        * @relatesalso XMLElement
        */
        std::shared_ptr<XMLElement> clone() const;
        /**
        * XML substraction, returning differences.
        *
        * @relatesalso XMLElement
        */
        const std::string operator-(const XMLElement &element) const;
    };
}
#endif