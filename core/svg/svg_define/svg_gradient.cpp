#include "svg_gradient.h"
#include <sstream>
#include <utility>

namespace Lewzen {
    SVGGradient::SVGGradient() {
    }
    const std::vector<std::shared_ptr<SVGStop>> &SVGGradient::get_stops() {
        return _stops;
    }
    void SVGGradient::add_stop(std::shared_ptr<SVGStop> stop) {
        _stops->push_back(stop);
    }
    bool SVGGradient::remove_stop(std::shared_ptr<SVGStop> stop) {
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
    std::string SVGGradient::to_XML() const override {
        std::stringstream ss;
        for (auto &stop : *_stops) {
            ss << stop.to_XML() << std::endl;
        }
        return ss.str();
    }
}