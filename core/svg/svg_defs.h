#ifndef __LZ_SVG_DEFS__
#define __LZ_SVG_DEFS__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <defs> element is used to store graphical objects that will be used at a later time. Objects created inside a <defs> element are not rendered directly. To display them you have to reference them (with a <use> element for example).
    */
    class SVGDefs: public XMLElement {
    public:
        /**
        * Constructor of defs.
        */
        SVGDefs();
        /**
        * Deep copy of defs.
        */
        SVGDefs(const SVGDefs &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Defs
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