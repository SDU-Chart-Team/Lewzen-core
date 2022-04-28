#ifndef __LZ_SVGI_PATTERN__
#define __LZ_SVGI_PATTERN__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <pattern> element defines a graphics object which can be redrawn at repeated x- and y-coordinate intervals ("tiled") to cover an area.
    */
    class SVGIPattern : public virtual SVGIElement, public virtual SVGPattern {
    public:
        /**
        * Constructor of circle.
        */
        SVGIPattern();
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

        /// Pattern
    public:
        /**
        * This attribute determines the height of the pattern tile. 
        * Value type: <length>|<percentage>; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Height;
    public:
        /**
        * This attribute reference a template pattern that provides default values for the <pattern> attributes. 
        * Value type: <URL>; Default value: none; Animatable: yes
        */
        AttrURL Href;
    public:
        /**
        * This attribute defines the coordinate system for the contents of the <pattern>. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: userSpaceOnUse; Animatable: yes
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstObjectBoundingBox> PatternContentUnits;
    public:
        /**
        * This attribute contains the definition of an optional additional transformation from the pattern coordinate system onto the target coordinate system. 
        * Value type: <transform-list>; Default value: none; Animatable: yes
        */
        AttrTransformList PatternTransform;
    public:
        /**
        * This attribute defines the coordinate system for attributes x, y, width , and height. 
        * Value type: userSpaceOnUse|objectBoundingBox; Default value: objectBoundingBox; Animatable: yes
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstObjectBoundingBox> PatternUnits;
    public:
        /**
        * This attribute defines how the SVG fragment must be deformed if it is embedded in a container with a different aspect ratio. 
        * Value type: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)? ; Default value: xMidYMid meet; Animatable: yes
        */
        AttrTuple<AttrEnumerate<AttrConstNone, AttrConstXMinYMin, AttrConstXMidYMin, AttrConstXMaxYMin, AttrConstXMinYMid, AttrConstXMidYMid, AttrConstXMaxYMid, AttrConstXMinYMax, AttrConstXMidYMax, AttrConstXMaxYMax>, AttrEnumerate<AttrConstMeet, AttrConstSlice>> PreserveAspectRatio;
    public:
        /**
        * This attribute defines the bound of the SVG viewport for the pattern fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        */
        AttrListOfNumbers ViewBox;
    public:
        /**
        * This attribute determines the width of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Width;
    public:
        /**
        * This attribute determines the x coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> X;
    public:
        /**
        * This attribute determines the y coordinate shift of the pattern tile. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Y;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 10> _attr_on_assign = {
            [this](const std::string &last){
                if (Height.get() == Height.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Href.get() == Href.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (PatternContentUnits.get() == PatternContentUnits.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (PatternTransform.get() == PatternTransform.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (PatternUnits.get() == PatternUnits.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (PreserveAspectRatio.get() == PreserveAspectRatio.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (ViewBox.get() == ViewBox.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (Width.get() == Width.get_commit()) modified.erase(7);
                else modified.insert(7);
                bound.erase(7);
            },
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(8);
                else modified.insert(8);
                bound.erase(8);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(9);
                else modified.insert(9);
                bound.erase(9);
            },
        };
        const std::array<std::function<void()>, 10> _attr_on_bind = {
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
            std::bind([this](){
                modified.erase(8);
                bound.insert(8);
            }),
            std::bind([this](){
                modified.erase(9);
                bound.insert(9);
            }),
        };
        const std::array<std::function<const std::string()>, 10> _attr_commit = {
            [this](){
                Height.commit();
                if (Height.get() == STR_NULL) return std::string("reset Height");
                else return std::string("modify Height \"" + Height.get() + "\"");
            },
            [this](){
                Href.commit();
                if (Href.get() == STR_NULL) return std::string("reset Href");
                else return std::string("modify Href \"" + Href.get() + "\"");
            },
            [this](){
                PatternContentUnits.commit();
                if (PatternContentUnits.get() == STR_NULL) return std::string("reset PatternContentUnits");
                else return std::string("modify PatternContentUnits \"" + PatternContentUnits.get() + "\"");
            },
            [this](){
                PatternTransform.commit();
                if (PatternTransform.get() == STR_NULL) return std::string("reset PatternTransform");
                else return std::string("modify PatternTransform \"" + PatternTransform.get() + "\"");
            },
            [this](){
                PatternUnits.commit();
                if (PatternUnits.get() == STR_NULL) return std::string("reset PatternUnits");
                else return std::string("modify PatternUnits \"" + PatternUnits.get() + "\"");
            },
            [this](){
                PreserveAspectRatio.commit();
                if (PreserveAspectRatio.get() == STR_NULL) return std::string("reset PreserveAspectRatio");
                else return std::string("modify PreserveAspectRatio \"" + PreserveAspectRatio.get() + "\"");
            },
            [this](){
                ViewBox.commit();
                if (ViewBox.get() == STR_NULL) return std::string("reset ViewBox");
                else return std::string("modify ViewBox \"" + ViewBox.get() + "\"");
            },
            [this](){
                Width.commit();
                if (Width.get() == STR_NULL) return std::string("reset Width");
                else return std::string("modify Width \"" + Width.get() + "\"");
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
        std::shared_ptr<SVGIPattern> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIPattern &operator=(const SVGIPattern &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
