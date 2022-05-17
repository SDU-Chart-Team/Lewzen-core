#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include "point_func.h"

namespace Lewzen {
    Point2D canvas_point(const double &x, const double &y) {
        return Point2D(x, y, CanvasCoordinateSystem::canvas_coordinate_system);
    }

    /// Transformations
    Point2D linear_transform(const double &m0, const double &m1, const double &m2, const double &m3, const Point2D &p) {
        return Point2D(m0 * p.get_x() + m1 * p.get_y(), m2 * p.get_x() + m3 * p.get_y(), p.get_coordinate_system()); 
    }
    Point2D linear_transform(const int *mat, const Point2D &p) {
        return Point2D(mat[0] * p.get_x() + mat[1] * p.get_y(), mat[2] * p.get_x() + mat[3] * p.get_y(), p.get_coordinate_system());
    }

    Point2D line_symmetric(const Point2D &p, const Point2D &a, const Point2D &b) {
        if (a == b) {
            throw std::logic_error("Two points cannot define a straight line");
        } else if (a.get_coordinate_system() != b.get_coordinate_system() || a.get_coordinate_system() != p.get_coordinate_system()) {
            throw coordinate_system_mismatch("Three points are not in the same coordinate system");
        }
                
        double dx = (a.get_x() - b.get_x()), dy = (a.get_y() - b.get_y());
        if (dx < 0) dx = -dx, dy = -dy;

        if (dx == 0) return Point2D(2 * a.get_x() - p.get_x(), p.get_y());
        else if (dy == 0) return Point2D(p.get_x(), 2 * a.get_y() - p.get_y());

        double A = dy, B = -dx, C = a.get_y() * dx - a.get_x() * dy;
        double D = dx * dx + dy * dy, E = A * p.get_x() + B * p.get_y() + C;
        dx = -2 * E * A / D, dy = -2 * E * B / D;
        return Point2D(p.get_x() + dx, p.get_y() + dy);
    }
    Point2D line_symmetric(const Point2D &p, const Point2D &a, double dx, double dy) {
        return line_symmetric(p, a, Point2D(a.get_x() + dx, a.get_y() + dy));
    }

    Point2D center_symmetric(const Point2D &p, const Point2D &c) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(2 * c.get_x() - p.get_x(), 2 * c.get_y() - p.get_y(), p.get_coordinate_system());
    }

    Point2D center_zoom(const Point2D &p, const Point2D &c, double lambda) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(c.get_x() + lambda * (p.get_x() - c.get_x()), c.get_y() + lambda * (p.get_y() - c.get_y()), p.get_coordinate_system());
    }
    Point2D center_zoom(const Point2D &p, const Point2D &c, double dx, double dy) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        return Point2D(c.get_x() + dx * (p.get_x() - c.get_x()), c.get_y() + dy * (p.get_y() - c.get_y()), p.get_coordinate_system());
    }

    Point2D center_rotate(const Point2D &p, const Point2D &c, double theta) {
        if (p.get_coordinate_system() != c.get_coordinate_system()) {
            throw coordinate_system_mismatch("Two points are not in the same coordinate system");
        }
        Point2D d = linear_transform(std::cos(theta), std::sin(theta), -std::sin(theta), std::cos(theta), p - c); // p + (p - c) * mat^{-1}
        return d + c;
    }

    /// Centroids
    void _check_coords(const std::vector<std::shared_ptr<Point2D>> &p_list) {
        for (int i = 0; i < p_list.size(); i++) {
            const std::shared_ptr<Point2D> p = p_list[i];
            if (p->get_coordinate_system() != p_list[0]->get_coordinate_system()) {
                throw coordinate_system_mismatch("Points are not in the same coordinate system");
            }
        }
    }
    Point2D geometry_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list) {
        _check_coords(p_list);
        double SX, SY;
        for (int i = 0; i < p_list.size(); i++) {
            const std::shared_ptr<Point2D> p = p_list[i];
            SX += p->get_x();
            SY += p->get_y();
        }
        return Point2D(SX / p_list.size(), SY / p_list.size(), p_list[0]->get_coordinate_system());
    }

    Point2D polygon_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list) {
        _check_coords(p_list);
        double SX, SY, S, A;
        for (int i = 0; i < p_list.size() - 1; i++) {
            const std::shared_ptr<Point2D> p0 = p_list[i];
            const std::shared_ptr<Point2D> p1 = p_list[i + 1];
            S = p0->get_x() * p1->get_y() - p1->get_x() * p0->get_y();
            SX += (p0->get_x() + p1->get_x()) * S;
            SY += (p0->get_y() + p1->get_y()) * S;
            A += S;
        }
        A /= 2;
        return Point2D(SX / A / 6, SY / A / 6, p_list[0]->get_coordinate_system());
    }

    const int MOVE_LOSS_RATE = 0.618;
    Point2D weight_balance(const std::vector<std::shared_ptr<Point2D>> &p_list, const std::vector<double> &weights) {
        if (p_list.size() != weights.size()) {
            throw std::logic_error("The numbers of elements in the two lists are not equal");
        }
        double l, sx, sy, g, x, y;
        const Point2D &c = geometry_centroid(p_list);
        for (int i = 0; i < p_list.size(); i++) {
            const std::shared_ptr<Point2D> p = p_list[i];
            l = std::max(l, std::sqrt((p->get_x() - c.get_x()) * (p->get_x() - c.get_x()) + (p->get_y() - c.get_y()) * (p->get_y() - c.get_y())));
        }
        l *= 2; // max radius
        while (l > 1e-4) { // iterations
            sx = 0, sy = 0;
            for (int i = 0; i < p_list.size(); i++) {
                const std::shared_ptr<Point2D> p = p_list[i];
                g = std::sqrt((p->get_x() - x) * (p->get_x() - x) + (p->get_y() - y) * (p->get_y() - y));
                if (g == 0) continue;
                sx += weights[i] / g * (p->get_x() - x);
                sy += weights[i] / g * (p->get_y() - y);
            }
            g = sqrt(sx * sx + sy * sy);
            x += l / g * sx, y = l / g * sy;
            l *= MOVE_LOSS_RATE;
        }
        return Point2D(x, y, p_list[0]->get_coordinate_system());
    }

    /// Coordinate System Conversion
    Point2D coordinate_system_convert(const Point2D &p, const std::shared_ptr<CoordinateSystem> &coordinate_system) {
        return coordinate_system->from_canvas(p.get_coordinate_system()->to_canvas(p));
    }
}