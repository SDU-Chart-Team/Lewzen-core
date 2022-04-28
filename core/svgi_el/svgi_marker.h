#ifndef __LZ_SVGI_MARKER__
#define __LZ_SVGI_MARKER__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <marker> element defines the graphic that is to be used for drawing arrowheads or polymarkers on a given <anything>:path, <line>, <polyline> or <polygon> element.
    */
    class SVGIMarker : public virtual SVGIElement, public virtual SVGMarker {
    public:
        /**
        * Constructor of circle.
        */
        SVGIMarker();
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

        /// Marker
    public:
        /**
        * This attribute defines the height of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        */
        AttrLength MarkerHeight;
    public:
        /**
        * This attribute defines the coordinate system for the attributes markerWidth, markerHeight and the contents of the <marker>. 
        * Value type: userSpaceOnUse|strokeWidth ; Default value: strokeWidth; Animatable: yes
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstStrokeWidth> MarkerUnits;
    public:
        /**
        * This attribute defines the width of the marker viewport. 
        * Value type: <length> ; Default value: 3; Animatable: yes
        */
        AttrLength MarkerWidth;
    public:
        /**
        * This attribute defines the orientation of the marker relative to the shape it is attached to. 
        * Value type: auto|auto-start-reverse|<angle> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrConstAutoStartReverse, AttrAngle> Orient;
    public:
        /**
        * how the svg fragment must be deformed if it is embedded in a container with a different aspect ratio. eg: (none| xMinYMin| xMidYMin| xMaxYMin| xMinYMid| xMidYMid| xMaxYMid| xMinYMax| xMidYMax| xMaxYMax) (meet|slice)
        */
        AttrTuple<AttrEnumerate<AttrConstNone, AttrConstXMinYMin, AttrConstXMidYMin, AttrConstXMaxYMin, AttrConstXMinYMid, AttrConstXMidYMid, AttrConstXMaxYMid, AttrConstXMinYMax, AttrConstXMidYMax, AttrConstXMaxYMax>, AttrEnumerate<AttrConstMeet, AttrConstSlice>> PreserveAspectRatio;
    public:
        /**
        * This attribute defines the x coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrConstLeft, AttrConstCenter, AttrConstRight, AttrCoordinate> RefX;
    public:
        /**
        * This attribute defines the y coordinate for the reference point of the marker. 
        * Value type: left|center|right|<coordinate> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrConstLeft, AttrConstCenter, AttrConstRight, AttrCoordinate> RefY;
    public:
        /**
        * This attribute defines the bound of the SVG viewport for the current SVG fragment. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        */
        AttrListOfNumbers ViewBox;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 8> _attr_on_assign = {
            [this](const std::string &last){
                if (MarkerHeight.get() == MarkerHeight.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (MarkerUnits.get() == MarkerUnits.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (MarkerWidth.get() == MarkerWidth.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Orient.get() == Orient.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (PreserveAspectRatio.get() == PreserveAspectRatio.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (RefX.get() == RefX.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (RefY.get() == RefY.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (ViewBox.get() == ViewBox.get_commit()) modified.erase(7);
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
                MarkerHeight.commit();
                if (MarkerHeight.get() == STR_NULL) return std::string("reset MarkerHeight");
                else return std::string("modify MarkerHeight \"" + MarkerHeight.get() + "\"");
            },
            [this](){
                MarkerUnits.commit();
                if (MarkerUnits.get() == STR_NULL) return std::string("reset MarkerUnits");
                else return std::string("modify MarkerUnits \"" + MarkerUnits.get() + "\"");
            },
            [this](){
                MarkerWidth.commit();
                if (MarkerWidth.get() == STR_NULL) return std::string("reset MarkerWidth");
                else return std::string("modify MarkerWidth \"" + MarkerWidth.get() + "\"");
            },
            [this](){
                Orient.commit();
                if (Orient.get() == STR_NULL) return std::string("reset Orient");
                else return std::string("modify Orient \"" + Orient.get() + "\"");
            },
            [this](){
                PreserveAspectRatio.commit();
                if (PreserveAspectRatio.get() == STR_NULL) return std::string("reset PreserveAspectRatio");
                else return std::string("modify PreserveAspectRatio \"" + PreserveAspectRatio.get() + "\"");
            },
            [this](){
                RefX.commit();
                if (RefX.get() == STR_NULL) return std::string("reset RefX");
                else return std::string("modify RefX \"" + RefX.get() + "\"");
            },
            [this](){
                RefY.commit();
                if (RefY.get() == STR_NULL) return std::string("reset RefY");
                else return std::string("modify RefY \"" + RefY.get() + "\"");
            },
            [this](){
                ViewBox.commit();
                if (ViewBox.get() == STR_NULL) return std::string("reset ViewBox");
                else return std::string("modify ViewBox \"" + ViewBox.get() + "\"");
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
        std::shared_ptr<SVGIMarker> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIMarker &operator=(const SVGIMarker &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
