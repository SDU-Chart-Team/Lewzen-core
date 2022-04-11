#include "binded_path.h"

namespace Lewzen {
    const std::vector<std::shared_ptr<Point2D>> BindedPath::get_way_points() const {
        std::vector<std::shared_ptr<Point2D>> vec;
        for (auto &kv: _way_points) vec.push_back(kv.second);
        return std::move(vec);
    }
    double BindedPath::rank_to_num(const int &rank) const {
        return _way_points.find_by_order(rank)->first;
    }
    int BindedPath::num_to_rank(const double &num) const {
       return _way_points.order_of_key(num);
    }
    std::shared_ptr<Point2D> BindedPath::get_way_point(const int &rank) const {
        return _way_points.find_by_order(rank)->second;
    }
    std::shared_ptr<Point2D> BindedPath::get_way_point(const double &num) const {
        return _way_points[num];
    }
    void BindedPath::add_way_point(const double &num, std::shared_ptr<Point2D> way_point) {
        _way_points[num] = way_point;
    }
    bool BindedPath::remove_way_point(const double &num) {
        _way_points.erase(num);
    }
}