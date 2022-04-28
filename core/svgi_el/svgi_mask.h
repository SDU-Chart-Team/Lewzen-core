#ifndef __LZ_SVGI_MASK__
#define __LZ_SVGI_MASK__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <mask> element defines an alpha mask for compositing the current object into the background. A mask is used/referenced using the mask property.
    */
    class SVGIMask : public virtual SVGIElement, public virtual SVGMask {
    public:
        /**
        * Constructor of circle.
        */
        SVGIMask();
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

        /// Mask
    public:
        /**
        * This attribute defines the height of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        */
        AttrLength Height;
    public:
        /**
        * This attribute defines the coordinate system for the contents of the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: userSpaceOnUse; Animatable: yes.
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstObjectBoundingBox> MaskContentUnits;
    public:
        /**
        * This attribute defines the coordinate system for attributes x, y, width and height on the <mask>. 
        * Value type: userSpaceOnUse|objectBoundingBox ; Default value: objectBoundingBox; Animatable: yes
        */
        AttrEnumerate<AttrConstUserSpaceOnUse, AttrConstObjectBoundingBox> MaskUnits;
    public:
        /**
        * This attribute defines the x-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        */
        AttrCoordinate X;
    public:
        /**
        * This attribute defines the y-axis coordinate of the top-left corner of the masking area. 
        * Value type: <coordinate> ; Default value: -10%; Animatable: yes
        */
        AttrCoordinate Y;
    public:
        /**
        * This attribute defines the width of the masking area. 
        * Value type: <length> ; Default value: 120%; Animatable: yes
        */
        AttrLength Width;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 6> _attr_on_assign = {
            [this](const std::string &last){
                if (Height.get() == Height.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (MaskContentUnits.get() == MaskContentUnits.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (MaskUnits.get() == MaskUnits.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (Width.get() == Width.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
        };
        const std::array<std::function<void()>, 6> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 6> _attr_commit = {
            [this](){
                Height.commit();
                if (Height.get() == STR_NULL) return std::string("reset Height");
                else return std::string("modify Height \"" + Height.get() + "\"");
            },
            [this](){
                MaskContentUnits.commit();
                if (MaskContentUnits.get() == STR_NULL) return std::string("reset MaskContentUnits");
                else return std::string("modify MaskContentUnits \"" + MaskContentUnits.get() + "\"");
            },
            [this](){
                MaskUnits.commit();
                if (MaskUnits.get() == STR_NULL) return std::string("reset MaskUnits");
                else return std::string("modify MaskUnits \"" + MaskUnits.get() + "\"");
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
        std::shared_ptr<SVGIMask> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIMask &operator=(const SVGIMask &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
