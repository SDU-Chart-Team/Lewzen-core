#ifndef __LZ_SVGI_CIRCLE__
#define __LZ_SVGI_CIRCLE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <circle> SVG element is an SVG basic shape, used to draw circles based on a center point and a radius.
    */
    class SVGICircle : public virtual SVGIElement, public virtual SVGCircle {
    public:
        /**
        * Constructor of circle.
        */
        SVGICircle();
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

        /// Circle
    public:
        /**
        * The x-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Cx;
    public:
        /**
        * The y-axis coordinate of the center of the circle. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Cy;
    public:
        /**
        * The radius of the circle. A value lower or equal to zero disables rendering of the circle. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        */
        AttrLength R;
    public:
        /**
        * The total length for the circle's circumference, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 4> _attr_on_assign = {
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
                if (R.get() == R.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (PathLength.get() == PathLength.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
        };
        const std::array<std::function<void()>, 4> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 4> _attr_commit = {
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
                R.commit();
                if (R.get() == STR_NULL) return std::string("reset R");
                else return std::string("modify R \"" + R.get() + "\"");
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
        std::shared_ptr<SVGICircle> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGICircle &operator=(const SVGICircle &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
