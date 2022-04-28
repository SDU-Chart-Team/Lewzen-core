#ifndef __LZ_SVGI_LINEAR_GRADIENT__
#define __LZ_SVGI_LINEAR_GRADIENT__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <linearGradient> element lets authors define linear gradients to apply to other SVG elements.
    */
    class SVGILinearGradient : public virtual SVGIElement, public virtual SVGLinearGradient {
    public:
        /**
        * Constructor of circle.
        */
        SVGILinearGradient();
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

        /// LinearGradient
    public:
        /**
        * This attribute defines the coordinate system for attributes x1, x2, y1, y2 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstObjectBoundingBox> GradientUnits;
    public:
        /**
        * This attribute provides additional transformation to the gradient coordinate system. 
        * Value type: <transform-list> ; Default value: identity transform; Animatable: yes
        */
        AttrTransformList GradientTransform;
    public:
        /**
        * This attribute defines a reference to another <linearGradient> element that will be used as a template. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        */
        AttrURL Href;
    public:
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        */
        AttrEnumerate<AttrConstPad, AttrConstReflect, AttrConstRepeat> SpreadMethod;
    public:
        /**
        * This attribute defines the x coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> X1;
    public:
        /**
        * This attribute defines the x coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 100%; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> X2;
    public:
        /**
        * This attribute defines the y coordinate of the starting point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> Y1;
    public:
        /**
        * This attribute defines the y coordinate of the ending point of the vector gradient along which the linear gradient is drawn. 
        * Value type: <length>|<percentage>|<number>; Default value: 0%; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> Y2;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 8> _attr_on_assign = {
            [this](const std::string &last){
                if (GradientUnits.get() == GradientUnits.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (GradientTransform.get() == GradientTransform.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Href.get() == Href.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (SpreadMethod.get() == SpreadMethod.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (X1.get() == X1.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (X2.get() == X2.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (Y1.get() == Y1.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (Y2.get() == Y2.get_commit()) modified.erase(7);
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
                GradientUnits.commit();
                if (GradientUnits.get() == STR_NULL) return std::string("reset GradientUnits");
                else return std::string("modify GradientUnits \"" + GradientUnits.get() + "\"");
            },
            [this](){
                GradientTransform.commit();
                if (GradientTransform.get() == STR_NULL) return std::string("reset GradientTransform");
                else return std::string("modify GradientTransform \"" + GradientTransform.get() + "\"");
            },
            [this](){
                Href.commit();
                if (Href.get() == STR_NULL) return std::string("reset Href");
                else return std::string("modify Href \"" + Href.get() + "\"");
            },
            [this](){
                SpreadMethod.commit();
                if (SpreadMethod.get() == STR_NULL) return std::string("reset SpreadMethod");
                else return std::string("modify SpreadMethod \"" + SpreadMethod.get() + "\"");
            },
            [this](){
                X1.commit();
                if (X1.get() == STR_NULL) return std::string("reset X1");
                else return std::string("modify X1 \"" + X1.get() + "\"");
            },
            [this](){
                X2.commit();
                if (X2.get() == STR_NULL) return std::string("reset X2");
                else return std::string("modify X2 \"" + X2.get() + "\"");
            },
            [this](){
                Y1.commit();
                if (Y1.get() == STR_NULL) return std::string("reset Y1");
                else return std::string("modify Y1 \"" + Y1.get() + "\"");
            },
            [this](){
                Y2.commit();
                if (Y2.get() == STR_NULL) return std::string("reset Y2");
                else return std::string("modify Y2 \"" + Y2.get() + "\"");
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
        std::shared_ptr<SVGILinearGradient> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGILinearGradient &operator=(const SVGILinearGradient &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
