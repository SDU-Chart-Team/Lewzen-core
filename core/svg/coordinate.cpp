#include "coordinate.h"

namespace Lewzen {
    Coordinate::Coordinate() {
        new (this)Coordinate("NULL");
    }
    Coordinate::Coordinate(const std::string &coordinate_type): _coordinate_type(coordinate_type) {}
    const std::string &Coordinate::get_type() const {
        return _coordinate_type;
    }
}