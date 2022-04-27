#ifndef __LZ_COMPR__
#define __LZ_COMPR__
#include <string>
#include <memory>
#include "../geometry.h"
#include "../svgi_el.h"

namespace Lewzen {
    class ComponentRotatable: public std::enable_shared_from_this<ComponentRotatable>{
    private:
        double _theta;
        std::weak_ptr<Point2D> _rotate_center;
        std::weak_ptr<SVGIElement> _svg_element_interface;
        std::string _rotate_trans;
    protected:
        virtual std::weak_ptr<ComponentRotatable> get_parent() = 0;
        const std::string get_rotate();
    public:
        ComponentRotatable();
        ComponentRotatable(const std::weak_ptr<SVGIElement> &svg_element_interface, const std::weak_ptr<Point2D> &rotate_center);

        double get_theta() const;
        void set_theta(double theta);
        const std::weak_ptr<Point2D> get_rotate_center() const;
        void set_rotate_center(const std::weak_ptr<Point2D> &rotate_center);
        const std::weak_ptr<SVGIElement> get_svg_element_interface() const;
        void set_svg_element_interface(const std::weak_ptr<SVGIElement> &svg_element_interface);

        void update_transform();
    };
}
#endif