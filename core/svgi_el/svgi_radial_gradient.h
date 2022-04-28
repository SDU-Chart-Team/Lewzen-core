#ifndef __LZ_SVGI_RADIAL_GRADIENT__
#define __LZ_SVGI_RADIAL_GRADIENT__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <radialGradient> element lets authors define radial gradients that can be applied to fill or stroke of graphical elements.
    */
    class SVGIRadialGradient : public virtual SVGIElement, public virtual SVGRadialGradient {
    public:
        /**
        * Constructor of circle.
        */
        SVGIRadialGradient();
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

        /// RadialGradient
    public:
        /**
        * This attribute defines the x coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        */
        AttrLength Cx;
    public:
        /**
        * This attribute defines the y coordinate of the end circle of the radial gradient. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        */
        AttrLength Cy;
    public:
        /**
        * This attribute defines the radius of the start circle of the radial gradient. The gradient will be drawn such that the 0% <stop> is mapped to the perimeter of the start circle. 
        * Value type: <length> ; Default value: 0%; Animatable: yes
        */
        AttrLength Fr;
    public:
        /**
        * This attribute defines the x coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        */
        AttrLength Fx;
    public:
        /**
        * This attribute defines the y coordinate of the start circle of the radial gradient. 
        * Value type: <length> ; Default value: Same as cx; Animatable: yes
        */
        AttrLength Fy;
    public:
        /**
        * This attribute defines the coordinate system for attributes cx, cy, r, fx, fy, fr 
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
        * This attribute defines the radius of the end circle of the radial gradient. The gradient will be drawn such that the 100% <stop> is mapped to the perimeter of the end circle. 
        * Value type: <length> ; Default value: 50%; Animatable: yes
        */
        AttrLength R;
    public:
        /**
        * This attribute indicates how the gradient behaves if it starts or ends inside the bounds of the shape containing the gradient. 
        * Value type: pad|reflect|repeat ; Default value: pad; Animatable: yes
        */
        AttrEnumerate<AttrConstPad, AttrConstReflect, AttrConstRepeat> SpreadMethod;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 10> _attr_on_assign = {
            [this](const std::string &last){
                if (Cx.get() == Cx.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Cy.get() == Cy.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Fr.get() == Fr.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Fx.get() == Fx.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Fy.get() == Fy.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (GradientUnits.get() == GradientUnits.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (GradientTransform.get() == GradientTransform.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
            [this](const std::string &last){
                if (Href.get() == Href.get_commit()) modified.erase(7);
                else modified.insert(7);
                bound.erase(7);
            },
            [this](const std::string &last){
                if (R.get() == R.get_commit()) modified.erase(8);
                else modified.insert(8);
                bound.erase(8);
            },
            [this](const std::string &last){
                if (SpreadMethod.get() == SpreadMethod.get_commit()) modified.erase(9);
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
                Cx.commit();
                if (Cx.get() == STR_NULL) return std::string("reset Cx");
                else return std::string("modify Cx \"" + Cx.get() + "\"");
            },
            [this](){
                Cy.commit();
                if (Cy.get() == STR_NULL) return std::string("reset Cy");
                else return std::string("modify Cy \"" + Cy.get() + "\"");
            },
            [this](){
                Fr.commit();
                if (Fr.get() == STR_NULL) return std::string("reset Fr");
                else return std::string("modify Fr \"" + Fr.get() + "\"");
            },
            [this](){
                Fx.commit();
                if (Fx.get() == STR_NULL) return std::string("reset Fx");
                else return std::string("modify Fx \"" + Fx.get() + "\"");
            },
            [this](){
                Fy.commit();
                if (Fy.get() == STR_NULL) return std::string("reset Fy");
                else return std::string("modify Fy \"" + Fy.get() + "\"");
            },
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
                R.commit();
                if (R.get() == STR_NULL) return std::string("reset R");
                else return std::string("modify R \"" + R.get() + "\"");
            },
            [this](){
                SpreadMethod.commit();
                if (SpreadMethod.get() == STR_NULL) return std::string("reset SpreadMethod");
                else return std::string("modify SpreadMethod \"" + SpreadMethod.get() + "\"");
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
        std::shared_ptr<SVGIRadialGradient> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIRadialGradient &operator=(const SVGIRadialGradient &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
