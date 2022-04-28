#ifndef __LZ_SVGI_IMAGE__
#define __LZ_SVGI_IMAGE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <image> SVG element includes images inside SVG documents. It can display raster image files or other SVG files.
        * The only image formats SVG software must support are JPEG, PNG, and other SVG files. Animated GIF behavior is undefined.
        * SVG files displayed with <image> are treated as an image: external resources aren't loaded, :visited styles aren't applied, and they cannot be interactive. To include dynamic SVG elements, try <use> with an external URL. To include SVG files and run scripts inside them, try <object> inside of <foreignObject>.
    */
    class SVGIImage : public virtual SVGIElement, public virtual SVGImage {
    public:
        /**
        * Constructor of circle.
        */
        SVGIImage();
    protected:
        virtual void _bind_getter_setter() override;

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Image
    public:
        /**
        * The width the image renders at. Unlike HTML's <img>, this attribute is required.
        */
        AttrEnumerate<AttrLength, AttrPercentage> Width;
    public:
        /**
        * The height the image renders at. Unlike HTML's <img>, this attribute is required.
        */
        AttrEnumerate<AttrLength, AttrPercentage> Height;
    public:
        /**
        * Positions the image horizontally from the origin.
        */
        AttrEnumerate<AttrLength, AttrPercentage> X;
    public:
        /**
        * Positions the image vertically from the origin.
        */
        AttrEnumerate<AttrLength, AttrPercentage> Y;
    public:
        /**
        * Points at a URL for the image file.
        */
        AttrURL Href;
    public:
        /**
        * Points at a URL for the image file.
        */
        AttrURL XlinkHref;
    public:
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        AttrAnything PreserveAspectRatio;
    public:
        /**
        * the value of the credentials flag for CORS requests.
        */
        AttrAnything Crossorigin;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 8> _attr_on_assign = {
            [this](const std::string &last){
                if (Width.get() == Width.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Height.get() == Height.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Href.get() == Href.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (XlinkHref.get() == XlinkHref.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (PreserveAspectRatio.get() == PreserveAspectRatio.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (Crossorigin.get() == Crossorigin.get_commit()) modified.erase(7);
                else modified.insert(7);
                bound.erase(7);
            },
        };
        const std::array<std::function<void()>, 8> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
            std::bind([this](){
                modified.erase(1);
                bound.insert(1);
            }),
            std::bind([this](){
                modified.erase(2);
                bound.insert(2);
            }),
            std::bind([this](){
                modified.erase(3);
                bound.insert(3);
            }),
            std::bind([this](){
                modified.erase(4);
                bound.insert(4);
            }),
            std::bind([this](){
                modified.erase(5);
                bound.insert(5);
            }),
            std::bind([this](){
                modified.erase(6);
                bound.insert(6);
            }),
            std::bind([this](){
                modified.erase(7);
                bound.insert(7);
            }),
        };
        const std::array<std::function<const std::string()>, 8> _attr_commit = {
            [this](){
                Width.commit();
                if (Width.get() == STR_NULL) return std::string("reset Width");
                else return std::string("modify Width \"" + Width.get() + "\"");
            },
            [this](){
                Height.commit();
                if (Height.get() == STR_NULL) return std::string("reset Height");
                else return std::string("modify Height \"" + Height.get() + "\"");
            },
            [this](){
                X.commit();
                if (X.get() == STR_NULL) return std::string("reset X");
                else return std::string("modify X \"" + X.get() + "\"");
            },
            [this](){
                Y.commit();
                if (Y.get() == STR_NULL) return std::string("reset Y");
                else return std::string("modify Y \"" + Y.get() + "\"");
            },
            [this](){
                Href.commit();
                if (Href.get() == STR_NULL) return std::string("reset Href");
                else return std::string("modify Href \"" + Href.get() + "\"");
            },
            [this](){
                XlinkHref.commit();
                if (XlinkHref.get() == STR_NULL) return std::string("reset XlinkHref");
                else return std::string("modify XlinkHref \"" + XlinkHref.get() + "\"");
            },
            [this](){
                PreserveAspectRatio.commit();
                if (PreserveAspectRatio.get() == STR_NULL) return std::string("reset PreserveAspectRatio");
                else return std::string("modify PreserveAspectRatio \"" + PreserveAspectRatio.get() + "\"");
            },
            [this](){
                Crossorigin.commit();
                if (Crossorigin.get() == STR_NULL) return std::string("reset Crossorigin");
                else return std::string("modify Crossorigin \"" + Crossorigin.get() + "\"");
            },
        };

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string commit() override;
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
        std::shared_ptr<SVGIImage> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIImage &operator=(const SVGIImage &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
