#ifndef __LZ_SVGI_G__
#define __LZ_SVGI_G__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <g> SVG element is a container used to group other SVG elements.
    */
    class SVGIG : public virtual SVGIElement, public virtual SVGG {
    public:
        /**
        * Constructor of circle.
        */
        SVGIG();
    protected:
        virtual void _bind_getter_setter() override;

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// G
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 0> _attr_on_assign = {
        };
        const std::array<std::function<void()>, 0> _attr_on_bind = {
        };
        const std::array<std::function<const std::string()>, 0> _attr_commit = {
        };

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string commit() override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        std::shared_ptr<SVGIG> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIG &operator=(const SVGIG &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
