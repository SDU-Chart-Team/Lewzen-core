#include <string>
#include "../utils.h"
#ifndef __LZ_XML_ELEMENT__
#define __LZ_XML_ELEMENT__

namespace Lewzen {
    /**
    * An XML property or grouped properties.
    */
    class XMLProperty {
    public:
        /**
        * Get XML description of this XML property.
        */
        virtual const std::string &to_properties() const = 0;
    }
}
#endif