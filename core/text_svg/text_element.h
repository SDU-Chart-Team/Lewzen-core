#include <string>
#include "../svg/svg_element.h"
#include "text_parser.h"
//#include <wchar.h>

#ifndef __LZ_TEXT_ELEMENT__
#define __LZ_TEXT_ELEMENT__

namespace Lewzen
{

    /**
     * @brief The Text element
     *
     */
    class TextElement : public SVGElement
    {
        // // the types of text SVG
        // enum class TextType
        // {
        //     PURETEXT,
        //     MARKDOWN,
        //     KATEX
        // } text_types;

    private:
        // the character of pure text or the string of markdown/katex
        std::string _content;
        // the parser used to parse _content into xml
        TextParser _parser;
        // // the type of the _content
        // TextType _text_type;

    public:
        /**
         * @brief Construct a new Text Element object
         * genetate the _parser
         *
         */
        TextElement();
        /**
         * @brief Destroy the Text Element object
         *
         */
        ~TextElement();

        /**
         * @brief parse this text SVG element object to XML according to _parser
         *
         */
        const std::string &to_XML() const
        {
            // TODO
            // switch (_text_type)
            // {
            // case PURETEXT:
            //     /* code */
            //     break;
            // case MARKDOWN:
            //     /* code */
            //     break;
            // case KATEX:
            //     /* code */
            //     break;
            // default:
            //     break;
            // }
        }
    };
}
#endif