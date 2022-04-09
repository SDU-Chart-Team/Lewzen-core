#include "svg_gradient.h"
#include <sstream>
#include <utility>

namespace Lewzen {
    SVGGradient::SVGGradient() {
    }
    const std::vector<SVGStop> &SVGGradient::get_stops() {
        return _stops;
    }
    void SVGGradient::add_stop(SVGStop stop) {
        _stops->push_back(stop);
    }
    bool SVGGradient::remove_stop(SVGStop stop) {
        for (auto it = _stops->begin(); it != _stops->end();) {
            if (*it == stop) it = _stops->erase(it);
            else it++;
        }
    }
    bool SVGGradient::remove_stop(const int &index) {
        if (index >= _stop->size()) return false;
        _stops->erase(_stop->begin() + index);
        return true;
    }
    std::string SVGGradient::to_XML() const {
        std::stringstream ss;
        for (auto &stop : *_stops) {
            ss << stop.to_XML() << std::endl;
        }
        return ss.str();
    }
}