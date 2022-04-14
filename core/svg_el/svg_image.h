#ifndef __LZ_SVG_IMAGE__
#define __LZ_SVG_IMAGE__
#include <string>
#include <sstream>
#include "../svg_element.h"

namespace Lewzen {
    /**
    * The <image> SVG element includes images inside SVG documents. It can display raster image files or other SVG files.
        * The only image formats SVG software must support are JPEG, PNG, and other SVG files. Animated GIF behavior is undefined.
        * SVG files displayed with <image> are treated as an image: external resources aren't loaded, :visited styles aren't applied, and they cannot be interactive. To include dynamic SVG elements, try <use> with an external URL. To include SVG files and run scripts inside them, try <object> inside of <foreignObject>.
    */
    class SVGImage: public SVGElement {
    public:
        /**
        * Constructor of image.
        */
        SVGImage();
        /**
        * Deep copy of image.
        */
        SVGImage(const SVGImage &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

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
        const std::string get_width() const;
        /**
        * The width the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @param  the width
        */
        void set_width(const std::string &width);
        /**
        * The height the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @return the height
        */
        const std::string get_height() const;
        /**
        * The height the image renders at. Unlike HTML's <img>, this attribute is required.
        *
        * @param  the height
        */
        void set_height(const std::string &height);
        /**
        * Positions the image horizontally from the origin.
        *
        * @return the x
        */
        const std::string get_x() const;
        /**
        * Positions the image horizontally from the origin.
        *
        * @param  the x
        */
        void set_x(const std::string &x);
        /**
        * Positions the image vertically from the origin.
        *
        * @return the y
        */
        const std::string get_y() const;
        /**
        * Positions the image vertically from the origin.
        *
        * @param  the y
        */
        void set_y(const std::string &y);
        /**
        * Points at a URL for the image file.
        *
        * @return the href
        */
        const std::string get_href() const;
        /**
        * Points at a URL for the image file.
        *
        * @param  the href
        */
        void set_href(const std::string &href);
        /**
        * Points at a URL for the image file.
        *
        * @return the xlink:href
        */
        const std::string get_xlinkZhref() const;
        /**
        * Points at a URL for the image file.
        *
        * @param  the xlink:href
        */
        void set_xlinkZhref(const std::string &xlinkZhref);
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @return the preserveAspectRatio
        */
        const std::string get_preserve_aspect_ratio() const;
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @param  the preserveAspectRatio
        */
        void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * the value of the credentials flag for CORS requests.
        *
        * @return the crossorigin
        */
        const std::string get_crossorigin() const;
        /**
        * the value of the credentials flag for CORS requests.
        *
        * @param  the crossorigin
        */
        void set_crossorigin(const std::string &crossorigin);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        std::shared_ptr<SVGElement> clone() const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        const std::string operator-(const SVGElement &element) const;
    };
}
#endif