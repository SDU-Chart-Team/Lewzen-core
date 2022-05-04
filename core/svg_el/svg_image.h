#ifndef __LZ_SVG_IMAGE__
#define __LZ_SVG_IMAGE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <image> SVG element includes images inside SVG documents. It can display raster image files or other SVG files.
        * The only image formats SVG software must support are JPEG, PNG, and other SVG files. Animated GIF behavior is undefined.
        * SVG files displayed with <image> are treated as an image: external resources aren't loaded, :visited styles aren't applied, and they cannot be interactive. To include dynamic SVG elements, try <use> with an external URL. To include SVG files and run scripts inside them, try <object> inside of <foreignObject>.
    */
    class SVGImage: public virtual SVGElement {
    public:
        /**
        * Constructor of image.
        */
        SVGImage();

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Image
    private:
        std::string _width;
    private:
        std::string _height;
    private:
        std::string _x;
    private:
        std::string _y;
    private:
        std::string _href;
    private:
        std::string _xlinkZhref;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _crossorigin;
    public:
        /**
        * The width the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @return the width
        */
        virtual const std::string get_width() const;
        /**
        * The width the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @param  the width
        */
        virtual void set_width(const std::string &width);
        /**
        * The height the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @return the height
        */
        virtual const std::string get_height() const;
        /**
        * The height the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @param  the height
        */
        virtual void set_height(const std::string &height);
        /**
        * Positions the image horizontally from the origin.
        *
        * @return the x
        */
        virtual const std::string get_x() const;
        /**
        * Positions the image horizontally from the origin.
        *
        * @param  the x
        */
        virtual void set_x(const std::string &x);
        /**
        * Positions the image vertically from the origin.
        *
        * @return the y
        */
        virtual const std::string get_y() const;
        /**
        * Positions the image vertically from the origin.
        *
        * @param  the y
        */
        virtual void set_y(const std::string &y);
        /**
        * Points at a URL for the image file.
        *
        * @return the href
        */
        virtual const std::string get_href() const;
        /**
        * Points at a URL for the image file.
        *
        * @param  the href
        */
        virtual void set_href(const std::string &href);
        /**
        * Points at a URL for the image file.
        *
        * @return the xlink:href
        */
        virtual const std::string get_xlinkZhref() const;
        /**
        * Points at a URL for the image file.
        *
        * @param  the xlink:href
        */
        virtual void set_xlinkZhref(const std::string &xlinkZhref);
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @return the preserveAspectRatio
        */
        virtual const std::string get_preserve_aspect_ratio() const;
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @param  the preserveAspectRatio
        */
        virtual void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * the value of the credentials flag for CORS requests.
        *
        * @return the crossorigin
        */
        virtual const std::string get_crossorigin() const;
        /**
        * the value of the credentials flag for CORS requests.
        *
        * @param  the crossorigin
        */
        virtual void set_crossorigin(const std::string &crossorigin);

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
        const std::string attribute_differ(const SVGImage &element) const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGImage
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGImage
        */
        std::shared_ptr<SVGImage> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGImage
        */
        virtual SVGElement &operator=(const SVGElement &element) override;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGImage
        */
        virtual SVGImage &operator=(const SVGImage &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif