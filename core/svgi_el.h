#ifndef __LZ_SVGI_ELEMENT__
#define __LZ_SVGI_ELEMENT__
#include "svg_el.h"

namespace Lewzen {
    /**
    * An SVG element interface.
    */
    class SVGIElement : protected virtual SVGElement {
    public:
        /**
        * Constructor of SVG element interface.
        */
        SVGIElement();

        /// Attributes
    public:
        Attr attr0;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const array<std::function<void(const std::string &)>, 1> _attr_on_assign = {
            std::bind([this](const std::string &last){
                if (attr0.get() == attr0.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            }),
        };
        const array<std::function<void()>, 1> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
        };
        const array<std::function<const std::string()>, 1> _attr_commit = {
            std::bind([this](){
                attr0.commit();
                if (attr0.get() == STR_NULL) return "reset attr0";
                else return "modify attr0 \"" + attr0.get() + "\"";
            }),
        };
    
        /// Inner SVG
    protected:
        std::vector<std::shared_ptr<SVGElement>> _inner_elements_commit;
    public:
        /**
        * Get inner SVG of this SVG element.
        *
        * @return inner SVG.
        */
        const std::string inner_SVG() const;
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        void set_inner_text(const std::string &text);
        /**
        * Set inner string of this SVG element. SVG string or text.
        *
        * @param element an inner string.
        */
        const std::string get_inner_text() const;
        /**
        * Add a sub element to this SVG element.
        *
        * @param element an inner element.
        */
        void add_inner_element(const std::shared_ptr<SVGElement> &element);
        /**
        * Remove a child element or child elements from this SVG element, based on content.
        *
        * @param element an inner element.
        * @param remove_all if to remove all occurances.
        */
        void remove_inner_element(const std::shared_ptr<SVGElement> &element, bool remove_all = false);
        /**
        * Get inner SVG elements list in this SVG element.
        *
        * @return inner elements, readonly.
        */
        const std::vector<std::shared_ptr<SVGElement>> get_inner_elements() const;
        /**
        * Set inner SVG elements list in this SVG element.
        *
        * @param inner_elements inner elements list.
        */
        void set_inner_elements(const std::vector<std::shared_ptr<SVGElement>> &inner_elements);

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        const std::string commit();
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
        virtual std::shared_ptr<SVGIElement> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIElement &operator=(const SVGIElement &element);
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGIElement
        */
        bool operator==(const SVGElement &element) const;
        /**
        * Compare two SVG elements.
        *
        * @relatesalso SVGIElement
        */
        bool operator!=(const SVGElement &element) const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const;
    };
}