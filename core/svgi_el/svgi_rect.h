#ifndef __LZ_SVGI_RECT__
#define __LZ_SVGI_RECT__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <rect> element is a basic SVG shape that draws rectangles, defined by their position, width, and height. The rectangles may have their corners rounded.
    */
    class SVGIRect : public virtual SVGIElement, public virtual SVGRect {
    public:
        /**
        * Constructor of circle.
        */
        SVGIRect();
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

        /// Rect
    public:
        /**
        * The x coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> X;
    public:
        /**
        * The y coordinate of the rect. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Y;
    public:
        /**
        * The width of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Width;
    public:
        /**
        * The height of the rect. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Height;
    public:
        /**
        * The horizontal corner radius of the rect. Defaults to ry if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Rx;
    public:
        /**
        * The vertical corner radius of the rect. Defaults to rx if it is specified. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Ry;
    public:
        /**
        * The total length of the rectangle's perimeter, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 7> _attr_on_assign = {
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Width.get() == Width.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Height.get() == Height.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Rx.get() == Rx.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (Ry.get() == Ry.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (PathLength.get() == PathLength.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
        };
        const std::array<std::function<void()>, 7> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 7> _attr_commit = {
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
                Rx.commit();
                if (Rx.get() == STR_NULL) return std::string("reset Rx");
                else return std::string("modify Rx \"" + Rx.get() + "\"");
            },
            [this](){
                Ry.commit();
                if (Ry.get() == STR_NULL) return std::string("reset Ry");
                else return std::string("modify Ry \"" + Ry.get() + "\"");
            },
            [this](){
                PathLength.commit();
                if (PathLength.get() == STR_NULL) return std::string("reset PathLength");
                else return std::string("modify PathLength \"" + PathLength.get() + "\"");
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
        std::shared_ptr<SVGIRect> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIRect &operator=(const SVGIRect &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
