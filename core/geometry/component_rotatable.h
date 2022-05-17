#ifndef __LZ_COMPR__
#define __LZ_COMPR__
#include <string>
#include <memory>
#include "../geometry.h"
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * Rotatable Component part
    */
    class ComponentRotatable {
    private:
        std::shared_ptr<CoordinateSystem> _this_coordinate;
        double _theta;
        std::shared_ptr<Point2D> _rotate_center;
        std::shared_ptr<Point2D> _area_vertex;
        std::weak_ptr<SVGIElement> _svg_element_interface;
        std::string _rotate_trans;
    protected:
        virtual std::weak_ptr<ComponentRotatable> get_parent() const = 0;
        const std::string get_rotate() const;
    public:
        /**
        * Constructor of ComponentRotatable.
        */
        ComponentRotatable();
        /**
        * Constructor of ComponentRotatable.
        *
        * @param svg_element_interface svgi to be update.
        */
        ComponentRotatable(const std::weak_ptr<SVGIElement> &svg_element_interface);

        /**
        * Get the rotate radian.
        *
        * @return rotate radian.
        */
        double get_theta() const;
        /**
        * Set the rotate radian.
        *
        * @param theta rotate radian.
        */
        void set_theta(double theta);
        /**
        * Get the rotate center.
        *
        * @return weak pointer of rotate center.
        */
        const Point2D get_rotate_center() const;
        /**
        * Set the rotate center.
        *
        * @param rotate_center weak pointer of rotate center.
        */
        void set_rotate_center(const Point2D &rotate_center);
        /**
        * Set the rotate center.
        *
        * @param x x of rotate center.
        * @param y y of rotate center.
        */
        void set_rotate_center(const double &x, const double &y);
        /**
        * Get the area vertex.
        *
        * @return weak pointer of area vertex.
        */
        const Point2D get_area_vertex() const;
        /**
        * Set the area vertex.
        *
        * @param area_vertex weak pointer of area vertex.
        */
        void set_area_vertex(const Point2D &area_vertex);
        /**
        * Set the area vertex.
        *
        * @param x x of area vertex.
        * @param y y of area vertex.
        */
        void set_area_vertex(const double &x, const double &y);
        /**
        * Get the svgi.
        *
        * @return the svgi.
        */
        const std::weak_ptr<SVGIElement> get_svg_element_interface() const;
        /**
        * Set the svgi.
        *
        * @param svg_element_interface the svgi.
        */
        void set_svg_element_interface(const std::weak_ptr<SVGIElement> &svg_element_interface);

        /**
        * Update tranform of svgi.
        */
        void update_transform();

        /**
        * Convert a point in CanvasCoordinateSystem to this coordinate system.
        *
        * @param p a point in CanvasCoordinateSystem.
        * @return a point in this coordinate system.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in CanvasCoordinateSystem.
        */
        Point2D from_canvas(const Point2D &p) const;
        /**
        * Convert a point in this coordinate system to CanvasCoordinateSystem.
        *
        * @param p a point in this coordinate system.
        * @return a point in CanvasCoordinateSystem.
        * @throws Lewzen::coordinate_system_mismatch: thrown if point p is not in this coordinate system.
        */
        Point2D to_canvas(const Point2D &p) const;

        /**
        * Get corresponding coordinate system.
        *
        * @return corresponding coordinate system.
        */
        virtual const std::shared_ptr<CoordinateSystem> get_coordinate_system() const = 0;
        /**
        * Create a new point in this coordinate system.
        *
        * @return the new point in this coordinate system.
        */
        Point2D create_point() const;
        /**
        * Create a new point in this coordinate system.
        *
        * @param x x position of the point.
        * @param y y position of the point.
        * @return the new point in this coordinate system.
        */
        Point2D create_point(double x, double y) const;
    };
}
#endif