#include "coordinate.h"

namespace Lewzen {
    Coordinate::Coordinate() {
        new (this)Coordinate("NULL");
    }
    Coordinate::Coordinate(const std::string &coordinate_type): _coordinate_type(coordinate_type) {}
    const std::string &Coordinate::get_type() const {
        return _coordinate_type;
    }
    virtual bool Coordinate::operator== (const Coordinate &coordianate) {
        return _coordinate_type == coordianate.get_type();
    }
    virtual bool Coordinate::operator!= (const Coordinate &coordianate) {
        return _coordinate_type != coordianate.get_type();
    }

    CanvasCoordinate::CanvasCoordinate(): {
        new (this)Coordinate("CAN");
    }
    bool CanvasCoordinate::operator== (const Coordinate &coordianate) {
        return A::operator==(coordianate)
    }
    bool CanvasCoordinate::operator!= (const Coordinate &coordianate) {
        return !A::operator==(coordianate)
    }

    ComponentCoordinate::ComponentCoordinate(const std::shared_ptr<Component> &component): _component(component) {
        new (this)Coordinate("COM");
    }
    const std::shared_ptr<Component> &ComponentCoordinate::get_component() const {
        return _component;
    }
    bool ComponentCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const ComponentCoordinate &>(coordianate).get_component();
    }
    bool ComponentCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const ComponentCoordinate &>(coordianate).get_component();
    }

    ComponentRelativeCoordinate::ComponentRelativeCoordinate(const std::shared_ptr<Component> &component): _component(component) {
        new (this)Coordinate("COMR");
    }
    const std::shared_ptr<Component> &ComponentRelativeCoordinate::get_component() const {
        return _component;
    }
    bool ComponentRelativeCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const ComponentRelativeCoordinate &>(coordianate).get_component();
    }
    bool ComponentRelativeCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const ComponentRelativeCoordinate &>(coordianate).get_component();
    }

    PointCoordinate::PointCoordinate(const std::shared_ptr<Point2D> &origin): _origin(origin) {
        new (this)Coordinate("POI");
    }
    const std::shared_ptr<Point2D> &PointCoordinate::get_origin() const {
        return _origin;
    }
    bool PointCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const PointCoordinate &>(coordianate).get_origin();
    }
    bool PointCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const PointCoordinate &>(coordianate).get_origin();
    }

    PointRelativeCoordinate::PointRelativeCoordinate(const std::shared_ptr<Point2D> &origin, const std::shared_ptr<Point2D> &vertex): _origin(origin), _vertex(vertex) {
        new (this)Coordinate("POIR");
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinate::get_origin() const {
        return _origin;
    }
    const std::shared_ptr<Point2D> &PointRelativeCoordinate::get_vertex() const {
        return _vertex;
    }
    bool PointRelativeCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const PointRelativeCoordinate &>(coordianate).get_origin()
               && _component == static_cast<const PointRelativeCoordinate &>(coordianate).get_vertex();
    }
    bool PointRelativeCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const PointRelativeCoordinate &>(coordianate).get_origin()
                   || !_component == static_cast<const PointRelativeCoordinate &>(coordianate).get_vertex();
    }

    VectorCoordinate::VectorCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B): _A(A), _B(B) {
        new (this)Coordinate("VEC");
    }
    const std::shared_ptr<Point2D> &VectorCoordinate::get_A() const {
        return _A;
    }
    const std::shared_ptr<Point2D> &VectorCoordinate::get_B() const {
        return _B;
    }
    bool VectorCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const VectorCoordinate &>(coordianate).get_A()
               && _component == static_cast<const VectorCoordinate &>(coordianate).get_B();
    }
    bool VectorCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const VectorCoordinate &>(coordianate).get_A()
                   || !_component == static_cast<const VectorCoordinate &>(coordianate).get_B();
    }

    VectorRelativeCoordinate::VectorRelativeCoordinate(const std::shared_ptr<Point2D> &A, const std::shared_ptr<Point2D> &B): _A(A), _B(B) {
        new (this)Coordinate("VECR");
    }
    const std::shared_ptr<Point2D> &VectorRelativeCoordinate::get_A() const {
        return _A;
    }
    const std::shared_ptr<Point2D> &VectorRelativeCoordinate::get_B() const {
        return _B;
    }
    bool VectorRelativeCoordinate::operator== (const Coordinate &coordianate) {
        if (!A::operator==(coordianate)) return false;
        return _component == static_cast<const VectorRelativeCoordinate &>(coordianate).get_A()
               && _component == static_cast<const VectorRelativeCoordinate &>(coordianate).get_B();
    }
    bool VectorRelativeCoordinate::operator!= (const Coordinate &coordianate) {
        if (A::operator==(coordianate)) return false;
        return !_component == static_cast<const VectorRelativeCoordinate &>(coordianate).get_A()
                   || !_component == static_cast<const VectorRelativeCoordinate &>(coordianate).get_B();
    }
}