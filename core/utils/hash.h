#ifndef __LZ_UTILS_HASH__
#define __LZ_UTILS_HASH__
#include <string>
#include "constants.h"

namespace Lewzen {
    /**
    * Get hash of a string;
    *
    * @param str the string.
    * @return hash.
    */
    const HASH_CODE str_hash(std::string str);
}
#endif