#ifndef __LZ_SVGI_USE__
#define __LZ_SVGI_USE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <use> element takes nodes from within the SVG document, and duplicates them somewhere else.
    */
    class SVGIUse : public virtual SVGIElement, public virtual SVGUse {
    public:
        /**
        * Constructor of circle.
        */
        SVGIUse();
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

        /// Use
    public:
        /**
        * The URL to an element/fragment that needs to be duplicated. 
        * Value type: <URL> ; Default value: none; Animatable: yes
        */
        AttrURL Href;
    public:
        /**
        * The x coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        */
        AttrCoordinate X;
    public:
        /**
        * The y coordinate of the use element. 
        * Value type: <coordinate> ; Default value: 0; Animatable: yes
        */
        AttrCoordinate Y;
    public:
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        */
        AttrLength Width;
    public:
        /**
        * The width of the use element. 
        * Value type: <length> ; Default value: 0; Animatable: yes
        */
        AttrLength Height;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 5> _attr_on_assign = {
            [this](const std::string &last){
                if (Href.get() == Href.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Width.get() == Width.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Height.get() == Height.get_commit()) modified.erase(4);
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
                Href.commit();
                if (Href.get() == STR_NULL) return std::string("reset Href");
                else return std::string("modify Href \"" + Href.get() + "\"");
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
        std::shared_ptr<SVGIUse> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIUse &operator=(const SVGIUse &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
