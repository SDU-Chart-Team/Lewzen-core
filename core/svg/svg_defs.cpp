#include "../svg_defs.h"

namespace Lewzen {
    std::string SVGDefs::outer_XML() const override {
        std::stringstream ss;
        return outer_XML("defs");
    }
}