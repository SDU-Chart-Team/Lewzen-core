#include <string>
#ifndef __LZ_Coordinate__
#define __LZ_Coordinate__

namespace Lewzen {
    class Coordinate {
    private:
        std::string _coordinate_type;
    public:
        Coordinate();
        Coordinate(const std::string &coordinate_type);
        const std::string &get_type() const;
    };
}
#endif