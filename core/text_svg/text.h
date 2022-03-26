// TextSVGElement -> TextSVG ->
// SVGElement -> SVG -> ShapeSVG -> ComponentShapeSVG

#include <string>
#include <list>
#include "../svg/svg.h"
#include "text_element.h"
#ifndef __LZ_TEXT__
#define __LZ_TEXT__
namespace Lewzen
{
    /**
     * @brief the text context, consisting text elements and SVG defines
     *
     */
    class Text : SVG
    {
        // the types of text SVG
        enum class TextType
        {
            PURETEXT,
            MARKDOWN,
            KATEX
        } text_types;

    private:
        // The input string of a text SVG
        std::string _sourceCode;
        // Text elements in order
        std::list<TextElement> _text_elements;
        // The type of the text
        TextType _text_type;

        /**
         * @brief generate the list of text elements according to type and source code
         *
         */
        void _generate_elements();

    public:
        /**
         * @brief Construct a new Text object
         * generate the _text_elements
         */
        Text() : SVG();
        /**
         * @brief Destroy the Text object
         *
         */
        ~Text();
    };


}
#endif