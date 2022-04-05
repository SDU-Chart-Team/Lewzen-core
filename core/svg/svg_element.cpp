#include "svg_element.h"

namespace Lewzen {
SVGElement();
    const std::string &get_id() const {
        return _id;
    }
    void set_id(const std::string &id) {
        _id = id;
    }

    const std::vector<Point2D> get_way_points() const {
        std::vector<Point2D> vec;
        for (auto &kv: _way_points) vec.push_back(kv.second);
        return std::move(vec);
    }
    double rank_to_num(const int &rank) const {
        return _way_points.find_by_order(rank)->first;
    }
    int num_to_rank(const double &num) const {
       return _way_points.order_of_key(num);
    }
    const Point2D &get_way_point(const int &rank) const {
        return _way_points.find_by_order(rank)->second;
    }
    const Point2D &get_way_point(const double &num) const {
        return _way_points[num];
    }
    void add_way_point(const double &num, const Point2D & way_point) {
        _way_points[num] = way_point;
    }
    bool remove_way_point(const double &num) {
        _way_points.erase(num);
    }

    const SVGFillStyle &get_fill_style() const {
        return _fill_style;
    }
    void set_fill_style(const SVGFillStyle &fill_style) {
        _fill_style = fill_style;
    }
    const SVGStrokeStyle &get_stroke_style() const {
        return _stroke_style;
    }
    void set_stroke_style(const SVGStrokeStyle &stroke_style) {
        _stroke_style = stroke_style;
    }
}
#endif