#ifndef __LZ_SVGI_PATH__
#define __LZ_SVGI_PATH__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <anything>:path SVG element is the generic element to define a shape. All the basic shapes can be created with a path element.
    */
    class SVGIPath : public virtual SVGIElement, public virtual SVGPath {
    public:
        /**
        * Constructor of circle.
        */
        SVGIPath();
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

        /// Path
    public:
        /**
        * This attribute defines the shape of the path. 
        * Value type: <string> ; Default value: ''; Animatable: yes
        */
        AttrAnything D;
    public:
        /**
        * This attribute lets authors specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 2> _attr_on_assign = {
            [this](const std::string &last){
                if (D.get() == D.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (PathLength.get() == PathLength.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
        };
        const std::array<std::function<void()>, 2> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
            std::bind([this](){
                modified.erase(1);
                bound.insert(1);
            }),
        };
        const std::array<std::function<const std::string()>, 2> _attr_commit = {
            [this](){
                D.commit();
                if (D.get() == STR_NULL) return std::string("reset D");
                else return std::string("modify D \"" + D.get() + "\"");
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
        std::shared_ptr<SVGIPath> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIPath &operator=(const SVGIPath &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
