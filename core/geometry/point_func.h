#ifndef __LZ_POINT_FUNC__
#define __LZ_POINT_FUNC__
#include <vector>
#include <memory>
#include "point.h"

namespace Lewzen {
    /**
    * Create point in CanvasCoordinateSystem.
    */
    Point2D canvas_point(const double &x, const double &y);

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
    Point2D linear_transform(const double &m0, const double &m1, const double &m2, const double &m3, const Point2D &p);
    /**
    * Do linear transformation on 2D point.
    *
    * @param mat the transformation matrix.
    * @param p the point.
    * @return mat·p
    */
    Point2D linear_transform(const int *mat, const Point2D &p);

    /**
    * Do line symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param a a point in line, in the same coordinate system with point p. 
    * @param b another point in line, in the same coordinate system with point p. 
    * 
    * @return line symmetric point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if three points are not in the same coordinate system.
    * @throws logic_error: if a equals to b, which can not define a straight line.
    */
    Point2D line_symmetric(const Point2D &p, const Point2D &a, const Point2D &b);
    /**
    * Do line symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param a a point in line, in the same coordinate system with point p. 
    * @param dx x rate of line.
    * @param dy y rate of line.
    * 
    * @return line symmetric point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if three points are not in the same coordinate system.
    * @throws logic_error: if a equals to b, which can not define a straight line.
    */
    Point2D line_symmetric(const Point2D &p, const Point2D &a, double dx, double dy);

    /**
    * Do center symmetric transformation on 2D point.
    *
    * @param p the point.
    * @param c symmetric center, in the same coordinate system with point p.
    * 
    * @return center symmetric point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if two points are not in the same coordinate system.
    */
    Point2D center_symmetric(const Point2D &p, const Point2D &c);

    /**
    * Do center zoom transformation on 2D point.
    *
    * @param p the point.
    * @param c zoom center, in the same coordinate system with point p.
    * @param lambda zoom rate.
    * 
    * @return center zoom point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if two points are not in the same coordinate system.
    */
    Point2D center_zoom(const Point2D &p, const Point2D &c, double lambda);
    /**
    * Do center zoom transformation on 2D point.
    *
    * @param p the point.
    * @param c zoom center, in the same coordinate system with point p.
    * @param dx x-axis zoom rate.
    * @param dy y-axis zoom rate.
    * 
    * @return center zoom point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if two points are not in the same coordinate system.
    */
    Point2D center_zoom(const Point2D &p, const Point2D &c, double dx, double dy);

    /**
    * Do rotate transformation on 2D point.
    *
    * @param p the point.
    * @param c rotate center, in the same coordinate system with point p.
    * @param theta rotate radian in clockwise direction.
    * 
    * @return center zoom point of p.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if two points are not in the same coordinate system.
    */
    Point2D center_rotate(const Point2D &p, const Point2D &c, double theta);

    /// Centroids
    /**
    * Get geometry centroid of a set of 2D points.
    *
    * @param p_list the list of 2D points' pointers, in the same coordinate system.
    * 
    * @return geometry centroid.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if points are not in the same coordinate system.
    */
    Point2D geometry_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list);

    /**
    * Get polygon centroid of a set of vertices. The vertices should be inputted in order and the polygon should be closed.
    *
    * @param p_list the list of vertices' pointers, in the same coordinate system.
    * 
    * @return polygon centroid.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if points are not in the same coordinate system.
    */
    Point2D polygon_centroid(const std::vector<std::shared_ptr<Point2D>> &p_list);

    /**
    * Get weight balance point of a set of 2D points and corresponding weight.
    *
    * @param p_list the list of 2D points' pointers, in the same coordinate system.
    * @param weights the list of weights.
    * 
    * @return weight balance point.
    *
    * @throws Lewzen::coordinate_system_mismatch: thrown if points are not in the same coordinate system.
    */
    Point2D weight_balance(const std::vector<std::shared_ptr<Point2D>> &p_list, const std::vector<double> &weights);

    /// Coordinate System Conversion
    /**
    * Convert point p to another coordinate sysytem.
    *
    * @param p.the point.
    * @param coordinate_system  the target coordinate system.
    * 
    * @return weight balance point.
    */
    Point2D coordinate_system_convert(const Point2D &p, const std::shared_ptr<CoordinateSystem> &coordinate_system);
}
#endif