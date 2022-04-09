#include <string>
#include "../svg/svg_element.h"
#include "text_parser.h"
#include "text_style.h"
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

    private:
        // the character of pure text or the string of markdown/katex
        std::string _content;
        // the parser used to parse _content into xml
        TextParser _parser;
        // the text style
        TextStyle *_text_style;

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
         * @brief Get the content object
         *
         * @return std::string
         */
        std::string get_content();

        /**
         * @brief Set the content object
         *
         * @param content
         */
        void set_content(std::string content);

        /**
         * @brief Get the text parser object
         *
         * @return TextParser*
         */
        TextParser *get_text_parser();

        /**
         * @brief Set the text parser object
         *
         * @param text_parser
         * @return TextParser*
         */
        TextParser *set_text_parser(TextParser text_parser);

        /**
         * @brief Get the text style object
         *
         * @return TextStyle*
         */
        TextStyle *get_text_style();

        /**
         * @brief Set the text style object
         *
         * @param text_style
         * @return TextStyle*
         */
        TextStyle *set_text_style(TextStyle text_style);

        /**
         * @brief parse this text SVG element object to XML according to _parser
         *
         */
        std::string to_XML() const;
    };
}
#endif