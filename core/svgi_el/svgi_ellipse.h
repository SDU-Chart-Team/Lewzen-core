#ifndef __LZ_SVGI_ELLIPSE__
#define __LZ_SVGI_ELLIPSE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <ellipse> element is an SVG basic shape, used to create ellipses based on a center coordinate, and both their x and y radius.
    */
    class SVGIEllipse : public virtual SVGIElement, public virtual SVGEllipse {
    public:
        /**
        * Constructor of circle.
        */
        SVGIEllipse();
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

        /// Ellipse
    public:
        /**
        * The x position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Cx;
    public:
        /**
        * The y position of the ellipse. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Cy;
    public:
        /**
        * The radius of the ellipse on the x axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Rx;
    public:
        /**
        * The radius of the ellipse on the y axis. 
        * Value type: auto|<length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrConstAuto, AttrLength, AttrPercentage> Ry;
    public:
        /**
        * This attribute lets specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 5> _attr_on_assign = {
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
                if (Rx.get() == Rx.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Ry.get() == Ry.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (PathLength.get() == PathLength.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
        };
        const std::array<std::function<void()>, 5> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 5> _attr_commit = {
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
        std::shared_ptr<SVGIEllipse> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIEllipse &operator=(const SVGIEllipse &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
