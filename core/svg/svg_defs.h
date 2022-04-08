#include <string>
#include "../xml_element.h"
#ifndef __LZ_SVG_DEFINE__
#define __LZ_SVG_DEFINE__

namespace Lewzen {
    /**
    * A SVG define in SVG context.
    */
    class SVGDefs: public XMLElement {
    private:
        // id
        std::string _id;
    public:
        /**
        * Constructor of stroke style.
        */
        SVGDefs();

        /// ID
        /**
        * Get element's id.
        *
        * @return element's id.
        */
        const std::string get_id() const;
        /**
        * Set element's id.
        *
        * @param id element's id.
        */
        void set_id(const std::string &id);
        
        /// Functional
        /**
        * Parse this SVG object to XML. (Unimplemented)
        */
        virtual const std::string outer_XML();
    }
}
#endif