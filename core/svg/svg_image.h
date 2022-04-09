#ifndef __LZ_SVG_IMAGE__
#define __LZ_SVG_IMAGE__
#include <string>
#include <sstream>
#include "../xml_element.h"

namespace Lewzen {
    /**
    * The <image> SVG element includes images inside SVG documents. It can display raster image files or other SVG files.
    */
    class SVGImage: public XMLElement {
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
        double _width;
    private:
        double _height;
    private:
        double _x;
    private:
        double _y;
    private:
        std::string _href;
    private:
        std::string _preserve_aspect_ratio;
    private:
        std::string _crossorigin;
    public:
        /**
        * Get the width the image renders at. (required)
        *
        * @return the width the image renders at. (required)
        */
        double get_width() const;
        /**
        * Set the width the image renders at. (required)
        *
        * @param width the width the image renders at. (required)
        */
        void set_width(const double &width);
        /**
        * Get the height the image renders at. (required)
        *
        * @return the height the image renders at. (required)
        */
        double get_height() const;
        /**
        * Set the height the image renders at. (required)
        *
        * @param height the height the image renders at. (required)
        */
        void set_height(const double &height);
        /**
        * Get positions the image horizontally from the origin.
        *
        * @return positions the image horizontally from the origin.
        */
        double get_x() const;
        /**
        * Set positions the image horizontally from the origin.
        *
        * @param x positions the image horizontally from the origin.
        */
        void set_x(const double &x);
        /**
        * Get positions the image vertically from the origin.
        *
        * @return positions the image vertically from the origin.
        */
        double get_y() const;
        /**
        * Set positions the image vertically from the origin.
        *
        * @param y positions the image vertically from the origin.
        */
        void set_y(const double &y);
        /**
        * Get points at a URL for the image file.
        *
        * @return points at a URL for the image file.
        */
        const std::string get_href() const;
        /**
        * Set points at a URL for the image file.
        *
        * @param href points at a URL for the image file.
        */
        void set_href(const std::string &href);
        /**
        * Get how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @return how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        const std::string get_preserve_aspect_ratio() const;
        /**
        * Set how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        *
        * @param preserve_aspect_ratio how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        void set_preserve_aspect_ratio(const std::string &preserve_aspect_ratio);
        /**
        * Get the value of the credentials flag for CORS requests.
        *
        * @return the value of the credentials flag for CORS requests.
        */
        const std::string get_crossorigin() const;
        /**
        * Set the value of the credentials flag for CORS requests.
        *
        * @param crossorigin the value of the credentials flag for CORS requests.
        */
        void set_crossorigin(const std::string &crossorigin);

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