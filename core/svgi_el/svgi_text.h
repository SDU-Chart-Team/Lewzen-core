#ifndef __LZ_SVGI_TEXT__
#define __LZ_SVGI_TEXT__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The SVG <text> element draws a graphics element consisting of text. It's possible to apply a gradient, pattern, clipping path, mask, or filter to <text>, like any other SVG graphics element.
    */
    class SVGIText : public virtual SVGIElement, public virtual SVGText {
    public:
        /**
        * Constructor of circle.
        */
        SVGIText();
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

        /// Text
    public:
        /**
        * The x coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> X;
    public:
        /**
        * The y coordinate of the starting point of the text baseline. 
        * Value type: <length>|<percentage> ; Default value: 0; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Y;
    public:
        /**
        * Shifts the text position horizontally from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Dx;
    public:
        /**
        * Shifts the text position vertically from a previous text element. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> Dy;
    public:
        /**
        * Rotates orientation of each individual glyph. Can rotate glyphs individually. 
        * Value type: <list-of-numbers> ; Default value: none; Animatable: yes
        */
        AttrListOfNumbers Rotate;
    public:
        /**
        * How the text is stretched or compressed to fit the width defined by the textLength attribute. 
        * Value type: spacing|spacingAndGlyphs; Default value: spacing; Animatable: yes
        */
        AttrEnumerate<AttrConstSpacing, AttrConstSpacingAndGlyphs> LengthAdjust;
    public:
        /**
        * A width that the text should be scaled to fit. 
        * Value type: <length>|<percentage> ; Default value: none; Animatable: yes
        */
        AttrEnumerate<AttrLength, AttrPercentage> TextLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 7> _attr_on_assign = {
            [this](const std::string &last){
                if (X.get() == X.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (Y.get() == Y.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
            [this](const std::string &last){
                if (Dx.get() == Dx.get_commit()) modified.erase(2);
                else modified.insert(2);
                bound.erase(2);
            },
            [this](const std::string &last){
                if (Dy.get() == Dy.get_commit()) modified.erase(3);
                else modified.insert(3);
                bound.erase(3);
            },
            [this](const std::string &last){
                if (Rotate.get() == Rotate.get_commit()) modified.erase(4);
                else modified.insert(4);
                bound.erase(4);
            },
            [this](const std::string &last){
                if (LengthAdjust.get() == LengthAdjust.get_commit()) modified.erase(5);
                else modified.insert(5);
                bound.erase(5);
            },
            [this](const std::string &last){
                if (TextLength.get() == TextLength.get_commit()) modified.erase(6);
                else modified.insert(6);
                bound.erase(6);
            },
        };
        const std::array<std::function<void()>, 7> _attr_on_bind = {
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
        };
        const std::array<std::function<const std::string()>, 7> _attr_commit = {
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
                Dx.commit();
                if (Dx.get() == STR_NULL) return std::string("reset Dx");
                else return std::string("modify Dx \"" + Dx.get() + "\"");
            },
            [this](){
                Dy.commit();
                if (Dy.get() == STR_NULL) return std::string("reset Dy");
                else return std::string("modify Dy \"" + Dy.get() + "\"");
            },
            [this](){
                Rotate.commit();
                if (Rotate.get() == STR_NULL) return std::string("reset Rotate");
                else return std::string("modify Rotate \"" + Rotate.get() + "\"");
            },
            [this](){
                LengthAdjust.commit();
                if (LengthAdjust.get() == STR_NULL) return std::string("reset LengthAdjust");
                else return std::string("modify LengthAdjust \"" + LengthAdjust.get() + "\"");
            },
            [this](){
                TextLength.commit();
                if (TextLength.get() == STR_NULL) return std::string("reset TextLength");
                else return std::string("modify TextLength \"" + TextLength.get() + "\"");
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
        std::shared_ptr<SVGIText> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIText &operator=(const SVGIText &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif
