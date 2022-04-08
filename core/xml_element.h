#ifndef __LZ_XML_ELEMENT__
#define __LZ_XML_ELEMENT__
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "utils.h"

namespace Lewzen {
    /**
    * An XML element.
    */
    class XMLElement {
    public:
        /**
        * Constructor of XML element.
        */
        XMLElement();
        /**
        * Deep copy of XML element.
        */
        XMLElement(XMLElement &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const;

        /// Class
    public:
        std::set<std::string> _classes;
        /**
        * Add a class to this XML element.
        *
        * @param cls a class.
        */
        void add_class(const std::string &cls);
        /**
        * Remove a class from this XML element.
        *
        * @param cls a class.
        */
        void remove_class(const std::string &cls);
        /**
        * Get all classes from this XML element, readonly.
        *
        * @return classes, readonly.
        */
        const std::set<std::string> get_classes() const;
        /**
        * Set classes list in this XML element.
        *
        * @param cls_list classes list.
        */
        void set_inner_elements(const std::set<std::string> &cls_list);
        /**
        * Get classes list in this XML element.
        *
        * @return class attributes.
        */
        const std::string get_class_attributes() const;

        /// Fill Style
    public:
        enum class FillRule { NONEZERO, EVENODD };
    private:
        // fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        std::string _fill;
        // fill opacity
        double _fill_opacity;
        // fill rule
        FillRule _fill_rule;
    public:
        /**
        * Get the fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @return the fill content.
        */
        const std::string get_fill() const;
        /**
        * Set the fill content, eg: 'red', '#FFFFFF', 'url(#my_define)'.
        *
        * @param fill the fill content.
        */
        void set_fill(const std::string &fill);
        /**
        * Get the fill opacity.
        *
        * @return the fill opacity.
        */
        double get_fill_opacity() const;
        /**
        * Set the fill opacity.
        *
        * @param fill_opacity the fill opacity.
        */
        void set_fill_opacity(const double &fill_opacity);
        /**
        * Get the fill rule.
        *
        * @return the fill rule.
        */
        const FillRule get_fill_rule() const;
        /**
        * Set the fill rule.
        *
        * @param fill_rule the fill rule.
        */
        void set_fill_rule(const FillRule &fill_rule);
        /**
        * Parse this fill style to XML attributes.
        *
        * @return fill style attributes
        */
        const std::string get_fill_attributes() const;
        
        /// Stroke Style
    public:
        enum class StrokeLinecap { BUTT, SQUARE, ROUND };
        enum class StrokeLinejoin { MITER, ROUND, BEVEL };
    private:
        // stroke content, eg: 'red', '#FFFFFF'.
        std::string _stroke;
        // stroke width
        double _stroke_width;
        // stroke opacity
        double _stroke_opacity;
        // stroke linecap
        StrokeLinecap _stroke_linecap;
        // stroke linejoin
        StrokeLinejoin _stroke_linejoin;
        // stroke miterlimit
        double _stroke_miterlimit;
        // string of stroke dasharray, eg: '2', '2.2 1.6'.
        std::string _stroke_dasharray;
        // stroke dashoffset
        double _stroke_dashoffset;
    public:
        /**
        * Get the stroke content, eg: 'red', '#FFFFFF'.
        *
        * @return the stroke content.
        */
        const std::string get_stroke() const;
        /**
        * Set the stroke content, eg: 'red', '#FFFFFF'.
        *
        * @param stroke the stroke content.
        */
        void set_stroke(const std::string &stroke);
        /**
        * Get the stroke width.
        *
        * @return the stroke width.
        */
        double get_stroke_width() const;
        /**
        * Set the stroke width.
        *
        * @param stroke_width the stroke width.
        */
        void set_stroke_width(const double &stroke_width);
        /**
        * Get the stroke opacity.
        *
        * @return the stroke opacity.
        */
        double get_stroke_opacity() const;
        /**
        * Set the stroke opacity.
        *
        * @param stroke_opacity the stroke opacity.
        */
        void set_stroke_opacity(const double &stroke_opacity);
        /**
        * Get the stroke linecap.
        *
        * @return the stroke linecap.
        */
        const StrokeLinecap get_stroke_linecap() const;
        /**
        * Set the stroke linecap.
        *
        * @param stroke_linecap the stroke linecap.
        */
        void set_stroke_linecap(const StrokeLinecap &stroke_linecap);
        /**
        * Get the stroke linejoin.
        *
        * @return the stroke linejoin.
        */
        const StrokeLinejoin get_stroke_linejoin() const;
        /**
        * Set the stroke linejoin.
        *
        * @param stroke_linejoin the stroke linejoin.
        */
        void set_stroke_linejoin(const StrokeLinejoin &stroke_linejoin);
        /**
        * Get the stroke miterlimit.
        *
        * @return the stroke miterlimit.
        */
        double get_stroke_miterlimit() const;
        /**
        * Set the stroke miterlimit.
        *
        * @param stroke_miterlimit the stroke miterlimit.
        */
        void set_stroke_miterlimit(const double &stroke_miterlimit);
        /**
        * Get string of stroke dasharray, eg: '2', '2.2 1.6'.
        *
        * @return string of stroke dasharray.
        */
        const std::string get_stroke_dasharray() const;
        /**
        * Set string of stroke dasharray, eg: '2', '2.2 1.6'.
        *
        * @param stroke string of stroke dasharray.
        */
        void set_stroke_dasharray(const std::string &stroke_dasharray);
        /**
        * Get the stroke dashoffset.
        *
        * @return the stroke dashoffset.
        */
        double get_stroke_dashoffset() const;
        /**
        * Set the stroke dashoffset.
        *
        * @param stroke_dashoffset the stroke dashoffset.
        */
        void set_stroke_dashoffset(const double &stroke_dashoffset);
        /**
       * Parse this stroke style to XML attributes.
        *
        * @return stroke style attributes
        */
        const std::string get_stroke_attributes() const;
        
        /// Inner XML
    private:
        std::string _inner_text;
        std::vector<std::shared_ptr<XMLElement>> _inner_elements;
    public:
        /**
        * Get inner XML of this XML element.
        *
        * @return inner XML.
        */
        const std::string inner_XML() const;
        /**
        * Set inner string of this XML element. XML string or text.
        *
        * @param element an inner string.
        */
        void set_inner_text(const std::string &text);
        /**
        * Set inner string of this XML element. XML string or text.
        *
        * @param element an inner string.
        */
        const std::string get_inner_text() const;
        /**
        * Add a class to this XML element.
        *
        * @param element an inner element.
        */
        void add_inner_element(const std::shared_ptr<XMLElement> &element);
        /**
        * Remove a class from this XML element.
        *
        * @param element an inner element.
        */
        void remove_inner_element(const std::shared_ptr<XMLElement> &element);
        /**
        * Get inner XML elements list in this XML element.
        *
        * @return inner elements, readonly.
        */
        const std::vector<std::shared_ptr<XMLElement>> get_inner_elements() const;
        /**
        * Set inner XML elements list in this XML element.
        *
        * @param inner_elements inner elements list.
        */
        void set_inner_elements(const std::vector<std::shared_ptr<XMLElement>> &inner_elements);

        /// Outer XML
    protected:
        /**
        * Get attribute string of this XML element.
        *
        * @return outer XML.
        */
        virtual const std::string get_attributes() const;
    public:
        /**
        * Get XML of this XML element.
        *
        * @return outer XML.
        */
        const std::string outer_XML() const;

        /// Hash
    private:
        HASH_CODE _hash;
        HASH_CODE _inner_hash;
        HASH_CODE _outer_hash;
    protected:
        /**
        * Update hash of this element.
        *
        * @return hash code.
        */
        void update_hash();
    public:
        /**
        * Get hash of this element, excluding inner content.
        *
        * @return hash code.
        */
        const HASH_CODE get_hash() const;
        /**
        * Get hash of this element, only inner content
        *
        * @return inner hash code.
        */
        const HASH_CODE get_inner_hash() const;
        /**
        * Get hash of this element.
        *
        * @return outer hash code.
        */
        const HASH_CODE get_outer_hash() const;

        /// Operators
    public:
        /**
        * Deep copy this XML element.
        *
        * @relatesalso XMLElement
        */
        virtual std::shared_ptr<XMLElement> clone() const;
        /**
        * Compare two XML elements.
        *
        * @relatesalso XMLElement
        */
        virtual bool operator==(const XMLElement &element) const;
        /**
        * XML substraction, returning differences.
        *
        * @relatesalso XMLElement
        */
        virtual const std::string operator-(const XMLElement &element) const;
    };
}
#endif