#ifndef __LZ_SVGI_STOP__
#define __LZ_SVGI_STOP__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The SVG <stop> element defines a color and its position to use on a gradient. This element is always a child of a <linearGradient> or <radialGradient> element.
    */
    class SVGIStop : public virtual SVGIElement, public virtual SVGStop {
    public:
        /**
        * Constructor of circle.
        */
        SVGIStop();
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

        /// Stop
    public:
        /**
        * This attribute defines where the gradient stop is placed along the gradient vector. 
        * Value type: <number>|<percentage>; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrNumber, AttrPercentage> Offset;
    public:
        /**
        * This attribute defines the color of the gradient stop. It can be used as a CSS property. 
        * Value type: currentcolor|<color>|<color>:icccolor; Default value: black; Animatable: yes
        */
        AttrEnumerate<AttrConstCurrentcolor, AttrColor, AttrColor> StopColor;
    public:
        /**
        * This attribute defines the opacity of the gradient stop. It can be used as a CSS property. 
        * Value type: <opacity-value>; Default value: 1; Animatable: yes
        */
        AttrOpacityValue StopOpacity;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 3> _attr_on_assign = {
            [this](const std::string &last){
                if (Offset.get() == Offset.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (StopColor.get() == StopColor.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (StopOpacity.get() == StopOpacity.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
        };
        const std::array<std::function<void()>, 3> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 3> _attr_commit = {
            [this](){
                Offset.commit();
                if (Offset.get() == STR_NULL) return std::string("reset Offset");
                else return std::string("modify Offset \"" + Offset.get() + "\"");
            },
            [this](){
                StopColor.commit();
                if (StopColor.get() == STR_NULL) return std::string("reset StopColor");
                else return std::string("modify StopColor \"" + StopColor.get() + "\"");
            },
            [this](){
                StopOpacity.commit();
                if (StopOpacity.get() == STR_NULL) return std::string("reset StopOpacity");
                else return std::string("modify StopOpacity \"" + StopOpacity.get() + "\"");
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
        std::shared_ptr<SVGIStop> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIStop &operator=(const SVGIStop &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
