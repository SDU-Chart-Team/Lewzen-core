#ifndef __LZ_SVG_LINE__
#define __LZ_SVG_LINE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <line> element is an SVG basic shape used to create a line connecting two points.
    */
    class SVGLine: public virtual SVGElement {
    public:
        /**
        * Constructor of line.
        */
        SVGLine();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Line
    private:
        std::string _xQ;
    private:
        std::string _xR;
    private:
        std::string _yQ;
    private:
        std::string _yR;
    private:
        std::string _path_length;
    public:
        /**
        * Defines the x-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the x1
        */
        virtual const std::string get_xQ() const;
        /**
        * Defines the x-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the x1
        */
        virtual void set_xQ(const std::string &xQ);
        /**
        * Defines the x-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the x2
        */
        virtual const std::string get_xR() const;
        /**
        * Defines the x-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the x2
        */
        virtual void set_xR(const std::string &xR);
        /**
        * Defines the y-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the y1
        */
        virtual const std::string get_yQ() const;
        /**
        * Defines the y-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the y1
        */
        virtual void set_yQ(const std::string &yQ);
        /**
        * Defines the y-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the y2
        */
        virtual const std::string get_yR() const;
        /**
        * Defines the y-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the y2
        */
        virtual void set_yR(const std::string &yR);
        /**
        * Defines the total path length in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * Defines the total path length in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        virtual void set_path_length(const std::string &path_length);

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
        const std::string attribute_differ(const SVGLine &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGLine
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGLine
        */
        std::shared_ptr<SVGLine> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGLine
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGLine
        */
        virtual SVGLine &operator=(const SVGLine &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif