#include <string>
#include "../component.h"
#ifndef __LZ_Coordinate__
#define __LZ_Coordinate__

namespace Lewzen {
    /**
    * Coordinate information.
    */
    class Coordinate {
    private:
        // coordinate type
        std::string _coordinate_type;
    public:
        /**
        * Empty constructor of coordinate.
        */
        Coordinate();
        /**
        * Constructor of coordinate.
        *
        * @param coordinate_type coordinate type.
        */
        Coordinate(const std::string &coordinate_type);
        /**
        * Get coordinate type.
        *
        * @return coordinate type.
        */
        const std::string &get_type() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        virtual bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        virtual bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Canvas coordinate information.
    */
    class CanvasCoordinate: public Coordinate {
    public:
        /**
        * Constructor of Canvas Coordinate.
        */
        CanvasCoordinate();
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Component coordinate information.
    */
    class ComponentCoordinate: public Coordinate {
    private:
        // component
        std::shared_ptr<Component> _component;
    public:
        /**
        * Constructor of Component Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param component the component of component coordinate.
        */
        ComponentCoordinate(const std::shared_ptr<Component> &component);
        /**
        * Get component of Component Coordinate.
        *
        * @return the component of component coordinate.
        */
        const std::shared_ptr<Component> &get_component() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Component relative coordinate information.
    */
    class ComponentRelativeCoordinate: public Coordinate {
    private:
        // component
        std::shared_ptr<Component> _component;
    public:
        /**
        * Constructor of Component Relative Coordinate. Top-left and bottom-right of component's box is (-1, -1) to (1, 1).
        *
        * @param component the component of component relative coordinate.
        */
        ComponentRelativeCoordinate(const std::shared_ptr<Component> &component);
        /**
        * Get component of Component Relative Coordinate.
        *
        * @return the component of component relative coordinate.
        */
        const std::shared_ptr<Component> &get_component() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Point coordinate information.
    */
    class PointCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
    public:
        /**
        * Constructor of Point Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param origin the origin of point coordinate. 
        */
        PointCoordinate(const std::shared_ptr<Point2D> &origin);
        /**
        * Get origin of Point Coordinate.
        *
        * @return the origin of point coordinate.
        */
        const std::shared_ptr<Point2D> &get_origin() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Point relative coordinate information.
    */
    class PointRelativeCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _origin;
        // vertex
        std::shared_ptr<Point2D> _vertex;
    public:
        /**
        * Constructor of Point Relative Coordinate.
        *
        * @param origin the origin of point relative coordinate.
        * @param vertex the (1, 1) of point relative coordinate.
        */
        PointRelativeCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex);
        /**
        * Get origin of Point Relative Coordinate.
        *
        * @return the origin of point relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_origin() const;
        /**
        * Get vertex of Point Relative Coordinate.
        *
        * @return the vertex of point relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_vertex() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Vector coordinate information.
    */
    class VectorCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _A;
        // vertex
        std::shared_ptr<Point2D> _B;
    public:
        /**
        * Constructor of Vector Coordinate. Unit is equal to Canvas Coordinate.
        *
        * @param A the origin of vector coordinate.
        * @param B vector AB means x-axis of point coordinate, .
        */
        VectorCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B);
        /**
        * Get Aof Vector Coordinate.
        *
        * @return A point of vector coordinate.
        */
        const std::shared_ptr<Point2D> &get_A() const;
        /**
        * Get B of Vector Coordinate.
        *
        * @return B point of vector coordinate.
        */
        const std::shared_ptr<Point2D> &get_B() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };

    /**
    * Vector relative coordinate information.
    */
    class VectorRelativeCoordinate: public Coordinate {
    private:
        // origin
        std::shared_ptr<Point2D> _A;
        // vertex
        std::shared_ptr<Point2D> _B;
    public:
        /**
        * Constructor of Vector Relative Coordinate.
        *
        * @param A the origin of vector relative coordinate.
        * @param B vector AB means x-axis of point relative coordinate, and B means (1, 0) in this coordinate.
        */
        VectorRelativeCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B);
        /**
        * Get origin of Vector Relative Coordinate.
        *
        * @return the origin of vector relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_A() const;
        /**
        * Get unit (1, 0) of Vector Relative Coordinate.
        *
        * @return the unit (1, 0) of vector relative coordinate.
        */
        const std::shared_ptr<Point2D> &get_B() const;
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator== (const Coordinate &coordianate);
        /**
        * Compare two coordinates.
        *
        * @relatesalso Coordinate
        */
        bool operator!= (const Coordinate &coordianate);
    };
}
#endif