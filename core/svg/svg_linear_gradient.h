#ifndef __LZ_SVG_LINEAR_GRADIENT__
#define __LZ_SVG_LINEAR_GRADIENT__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <linearGradient> element lets authors define linear gradients to apply to other SVG elements.
    */
    class SVGLinearGradient: public XMLElement {
    public:
        /**
        * Constructor of linearGradient.
        */
        SVGLinearGradient();
        /**
        * Deep copy of linearGradient.
        */
        SVGLinearGradient(const SVGLinearGradient &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// LinearGradient
    private:
        double _xQ;
    private:
        double _yQ;
    private:
        double _xR;
    private:
        double _yR;
    public:
        /**
        * Get x1 of gradient line.
        *
        * @return x1 of gradient line.
        */
        double get_xQ() const;
        /**
        * Set x1 of gradient line.
        *
        * @param xQ x1 of gradient line.
        */
        void set_xQ(const double &xQ);
        /**
        * Get y1 of gradient line.
        *
        * @return y1 of gradient line.
        */
        double get_yQ() const;
        /**
        * Set y1 of gradient line.
        *
        * @param yQ y1 of gradient line.
        */
        void set_yQ(const double &yQ);
        /**
        * Get x2 of gradient line.
        *
        * @return x2 of gradient line.
        */
        double get_xR() const;
        /**
        * Set x2 of gradient line.
        *
        * @param xR x2 of gradient line.
        */
        void set_xR(const double &xR);
        /**
        * Get y2 of gradient line.
        *
        * @return y2 of gradient line.
        */
        double get_yR() const;
        /**
        * Set y2 of gradient line.
        *
        * @param yR y2 of gradient line.
        */
        void set_yR(const double &yR);

        /// Attributes
    protected:
        /**
        * Get attribute string of this XML element.
        *
        * @return outer XML.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this XML element.
        *
        * @relatesalso XMLElement
        */
        std::shared_ptr<XMLElement> clone() const;
        /**
        * XML substraction, returning differences.
        *
        * @relatesalso XMLElement
        */
        const std::string operator-(const XMLElement &element) const;
    };
}
#endif