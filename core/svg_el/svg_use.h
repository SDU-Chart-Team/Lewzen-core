#ifndef __LZ_SVG_USE__
#define __LZ_SVG_USE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <use> element takes nodes from within the SVG document, and duplicates them somewhere else.
    */
    class SVGUse: public virtual SVGElement {
    public:
        /**
        * Constructor of use.
        */
        SVGUse();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Use
    private:
        std::string _href;
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _width;
    private:
        std::string _height;
    public:
        /**
        * The URL to an element/fragment that needs to be duplicated. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @return the href
        */
        virtual const std::string get_href() const;
        /**
        * The URL to an element/fragment that needs to be duplicated. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        *
        * @param  the href
        */
        virtual void set_href(const std::string &href);
        /**
        * The x coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * The x coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * The y coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * The y coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);

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
        const std::string attribute_differ(const SVGUse &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGUse
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGUse
        */
        std::shared_ptr<SVGUse> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGUse
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGUse
        */
        virtual SVGUse &operator=(const SVGUse &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif