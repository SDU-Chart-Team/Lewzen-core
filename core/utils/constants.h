#ifndef __LZ_UTILS_DEFS__
#define __LZ_UTILS_DEFS__
#include <string>
#include <limits>

namespace Lewzen {
    /**
    * The null number indicating default option.
    *
    * @hideinitializer
    */
    const double NUM_NULL = std::numeric_limits<double>::max();
    /**
    * The null string indicating default option.
    *
    * @hideinitializer
    */
    const std::string STR_NULL = "";
    /**
    * The hash code.
    *
    * @hideinitializer
    */
    typedef unsigned long long int HASH_CODE;
}
#endif