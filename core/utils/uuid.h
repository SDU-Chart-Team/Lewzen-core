#ifndef __LZ_UTILS_UUID__
#define __LZ_UTILS_UUID__
#include <string>

namespace Lewzen {
        /**
        * Get a random UUID;
        *
        * @return a random UUID.
        */
    const std::string generate_uuid_v4();
}
#endif