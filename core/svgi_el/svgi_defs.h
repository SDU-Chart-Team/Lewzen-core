#ifndef __LZ_SVGI_DEFS__
#define __LZ_SVGI_DEFS__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <defs> element is used to store graphical objects that will be used at a later time. Objects created inside a <defs> element are not rendered directly. To display them you have to reference them (with a <use> element for example).
    */
    class SVGIDefs : public virtual SVGIElement, public virtual SVGDefs {
    public:
        /**
        * Constructor of circle.
        */
        SVGIDefs();
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

        /// Defs
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
        std::shared_ptr<SVGIDefs> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIDefs &operator=(const SVGIDefs &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
