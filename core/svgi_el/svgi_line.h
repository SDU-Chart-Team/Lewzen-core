#ifndef __LZ_SVGI_LINE__
#define __LZ_SVGI_LINE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <line> element is an SVG basic shape used to create a line connecting two points.
    */
    class SVGILine : public virtual SVGIElement, public virtual SVGLine {
    public:
        /**
        * Constructor of circle.
        */
        SVGILine();
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

        /// Line
    public:
        /**
        * Defines the x-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> X1;
    public:
        /**
        * Defines the x-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> X2;
    public:
        /**
        * Defines the y-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> Y1;
    public:
        /**
        * Defines the y-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage, AttrNumber> Y2;
    public:
        /**
        * Defines the total path length in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 5> _attr_on_assign = {
            [this](const std::string &last){
                if (X1.get() == X1.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (X2.get() == X2.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Y1.get() == Y1.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Y2.get() == Y2.get_commit()) modified.erase(3);
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
        std::shared_ptr<SVGILine> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGILine &operator=(const SVGILine &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
