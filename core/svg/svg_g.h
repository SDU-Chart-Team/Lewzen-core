#ifndef __LZ_SVG_G__
#define __LZ_SVG_G__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <g> SVG element is a container used to group other SVG elements.
    */
    class SVGG: public XMLElement {
    public:
        /**
        * Constructor of g.
        */
        SVGG();
        /**
        * Deep copy of g.
        */
        SVGG(const SVGG &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// G
    public:

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