#include "svg_define.h"

namespace Lewzen {
    SVGDefine::SVGDefine() {
        _id = uuid::generate_uuid_v4();
    }
    const std::string &SVGDefine::get_id() const {
        return _id;
    }
    void SVGDefine::set_id(const std::string &id) {
        _id = id;
    }
}