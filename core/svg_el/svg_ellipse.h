#ifndef __LZ_SVG_ELLIPSE__
#define __LZ_SVG_ELLIPSE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <ellipse> element is an SVG basic shape, used to create ellipses based on a center coordinate, and both their x and y radius.
    */
    class SVGEllipse: public virtual SVGElement {
    public:
        /**
        * Constructor of ellipse.
        */
        SVGEllipse();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Ellipse
    private:
        std::string _cx;
    private:
        std::string _cy;
    private:
        std::string _rx;
    private:
        std::string _ry;
    private:
        std::string _path_length;
    public:
        /**
        * The x position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the cx
        */
        virtual const std::string get_cx() const;
        /**
        * The x position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cx
        */
        virtual void set_cx(const std::string &cx);
        /**
        * The y position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @return the cy
        */
        virtual const std::string get_cy() const;
        /**
        * The y position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        *
        * @param  the cy
        */
        virtual void set_cy(const std::string &cy);
        /**
        * The radius of the ellipse on the x axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the rx
        */
        virtual const std::string get_rx() const;
        /**
        * The radius of the ellipse on the x axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the rx
        */
        virtual void set_rx(const std::string &rx);
        /**
        * The radius of the ellipse on the y axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @return the ry
        */
        virtual const std::string get_ry() const;
        /**
        * The radius of the ellipse on the y axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        *
        * @param  the ry
        */
        virtual void set_ry(const std::string &ry);
        /**
        * This attribute lets specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        virtual const std::string get_path_length() const;
        /**
        * This attribute lets specify the total length for the path, in user units. 
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
        const std::string attribute_differ(const SVGEllipse &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGEllipse
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGEllipse
        */
        std::shared_ptr<SVGEllipse> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGEllipse
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGEllipse
        */
        virtual SVGEllipse &operator=(const SVGEllipse &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif