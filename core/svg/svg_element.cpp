#include "svg_element.h"

namespace Lewzen {
    SVGElement::SVGElement() {

    }
    const std::string &SVGElement::get_id() const {
        return _id;
    }
    void SVGElement::set_id(const std::string &id) {
        _id = id;
    }
    const std::vector<std::shared_ptr<Point2D>> SVGElement::get_way_points() const {
        std::vector<std::shared_ptr<Point2D>> vec;
        for (auto &kv: _way_points) vec.push_back(kv.second);
        return std::move(vec);
    }
    double SVGElement::rank_to_num(const int &rank) const {
        return _way_points.find_by_order(rank)->first;
    }
    int SVGElement::num_to_rank(const double &num) const {
       return _way_points.order_of_key(num);
    }
    std::shared_ptr<Point2D> SVGElement::get_way_point(const int &rank) const {
        return _way_points.find_by_order(rank)->second;
    }
    std::shared_ptr<Point2D> SVGElement::get_way_point(const double &num) const {
        return _way_points[num];
    }
    void SVGElement::add_way_point(const double &num, std::shared_ptr<Point2D> way_point) {
        _way_points[num] = way_point;
    }
    bool SVGElement::remove_way_point(const double &num) {
        _way_points.erase(num);
    }
    const SVGFillStyle &SVGElement::get_fill_style() const {
        return _fill_style;
    }
    void SVGElement::set_fill_style(const SVGFillStyle &fill_style) {
        _fill_style = fill_style;
    }
    const SVGStrokeStyle &SVGElement::get_stroke_style() const {
        return _stroke_style;
    }
    void SVGElement::set_stroke_style(const SVGStrokeStyle &stroke_style) {
        _stroke_style = stroke_style;
    }
}