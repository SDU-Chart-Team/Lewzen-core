#include <string>
#ifndef __LZ_UTILS_UUID__
#define __LZ_UTILS_UUID__

namespace uuid {
        /**
        * Get a random UUID;
        *
        * @return a random UUID.
        */
    const std::string &generate_uuid_v4();
}