#include <vector>
#include <memory>
#include "coordinate.h"
#include "point.h"
#ifndef __LZ_POINT_FUNC__
#define __LZ_POINT_FUNC__

namespace Lewzen {
    /// Transformations
    /**
    * Do linear transformation on 2D point.
    *
    * @param m0 mat[0][0].
    * @param m1 mat[0][1].
    * @param m2 mat[1][0].
    * @param m3 mat[1][1].
    * @param p the point.
    * @return [[m0, m1], [m2, m3]]·p
    */
    Point2D linear_transform(const double &m0, const double &m1, const double &m2, const double &m3, const Point &p);
    /**
    * Do linear transformation on 2D point.
    *
    * @param mat the transformation matrix.
    * @param p the point.
    * @return mat·p
    */
    Point2D linear_transform(const int *mat, const Point &p);

    /**
    * Do line symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param a a point in line, in the same coordinate with point p. 
    * @param b another point in line, in the same coordinate with point p. 
    * 
    * @return line symmetric point of p.
    */
    Point2D line_symmetric(const Point &p, const Point &a, const Point &b);
    /**
    * Do line symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param a a point in line, in the same coordinate with point p. 
    * @param dx x rate of line.
    * @param dy y rate of line.
    * 
    * @return line symmetric point of p.
    */
    Point2D line_symmetric(const Point &p, const Point &a, double dx, double dy);

    /**
    * Do center symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param c symmetric center, in the same coordinate with point p.
    * 
    * @return center symmetric point of p.
    */
    Point2D center_symmetric(const Point &p, const Point &c);

    /**
    * Do center zoom transformation on 2D point.
    *
    * @param p the point.
    * @param c zoom center, in the same coordinate with point p.
    * @param lambda zoom rate.
    * 
    * @return center zoom point of p.
    */
    Point2D center_zoom(const Point &p, const Point &c, double lambda);

    /**
    * Do rotate transformation on 2D point.
    *
    * @param p the point.
    * @param c rotate center, in the same coordinate with point p.
    * @param theta rotate radian in clockwise direction.
    * 
    * @return center zoom point of p.
    */
    Point2D center_rotate(const Point &p, const Point &c, double theta);

    /// Centroids
    /**
    * Get geometry centroid of a set of 2D points.
    *
    * @param p_list the list of 2D points' pointers, in the same coordinate.
    * 
    * @return geometry centroid.
    */
    Point2D geometry_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list) {
        Point2D d = linear_transform(cos(theta), -sin(theta), sin(theta), cos(theta), p - c);
        return d + c;
    }

    /**
    * Get polygon centroid of a set of vertices. The vertices should be inputted in order and the polygon should be closed.
    *
    * @param p_list the list of vertices' pointers, in the same coordinate.
    * 
    * @return polygon centroid.
    */
    Point2D polygon_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list);

    /**
    * Get weight balance point of a set of 2D points and corresponding weight.
    *
    * @param p_list the list of 2D points' pointers, in the same coordinate.
    * @param weights the list of weights.
    * 
    * @return weight balance point.
    */
    Point2D weight_balance(const std::vector<std::shared_ptr<Point2D>> &p_list, const std::vector<double> &weights);

    /// Coordinate Conversion
    Point2D coordinate_convert(const Point &p, const Coordinate &coordinate);
}