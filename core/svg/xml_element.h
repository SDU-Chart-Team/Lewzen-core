#include <string>
#include "../utils.h"
#ifndef __LZ_XML_ELEMENT__
#define __LZ_XML_ELEMENT__

namespace Lewzen {
    /**
    * An XML element.
    */
    class XMLElement {
    public:
        /**
        * Get XML of this XML element.
        */
        virtual const std::string &to_XML() const = 0;
    }
}
#endif