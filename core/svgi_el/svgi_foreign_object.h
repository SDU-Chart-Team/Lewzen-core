#ifndef __LZ_SVGI_FOREIGN_OBJECT__
#define __LZ_SVGI_FOREIGN_OBJECT__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <foreignObject> SVG element includes elements from a different XML namespace. In the context of a browser, it is most likely (X)HTML.
    */
    class SVGIForeignObject : public virtual SVGIElement, public virtual SVGForeignObject {
    public:
        /**
        * Constructor of circle.
        */
        SVGIForeignObject();
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

        /// ForeignObject
    public:
        /**
        * The height of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Width;
    public:
        /**
        * The width of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: auto; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Height;
    public:
        /**
        * The x coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> X;
    public:
        /**
        * The y coordinate of the foreignObject. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Y;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 4> _attr_on_assign = {
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
        std::shared_ptr<SVGIForeignObject> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIForeignObject &operator=(const SVGIForeignObject &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
