#ifndef __LZ_SVG_G__
#define __LZ_SVG_G__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <g> SVG element is a container used to group other SVG elements.
    */
    class SVGG: public virtual SVGElement {
    public:
        /**
        * Constructor of g.
        */
        SVGG();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// G
    public:

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        virtual const std::string get_attributes() const override;
        /**
        * Returning differences on attributes.
        *
        * @return DOM Commands.
        */
        const std::string attribute_differ(const SVGG &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGG
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGG
        */
        std::shared_ptr<SVGG> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGG
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGG
        */
        virtual SVGG &operator=(const SVGG &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif