#include <string>
#include <set>
#ifndef __LZ_TEXT_STYLE__
#define __LZ_TEXT_STYLE__
namespace Lewzen
{
    /**
     * @brief Text style for text SVG element
     *
     */
    class TextStyle
    {
    private:
        enum class TextDecoration;
        enum class TextAlign;
        enum class ParagraphDecoration;
        // text color, using property of tag text:fill, eg:"red","#FFFFFF"
        std::string _fill;
        // text font family
        std::string _font_family;
        // text font size
        int _font_size;
        // text align method
        TextAlign _text_align;
        // text paragraph decoration, including font size and text decorations
        ParagraphDecoration _paragraph_decoration;
        // the set of text decoration
        std::set<TextDecoration> _text_decoration_set;

    public:
        /**
         * @brief Construct a new Text Style object
         *
         */
        TextStyle();
        /**
         * @brief Destroy the Text Style object
         *
         */
        ~TextStyle();
        // Properties
        /**
         * @brief Get the fill object
         *
         * @return const std::string
         */
        const std::string &get_fill() const;
        /**
         * @brief Set the fill object
         *
         * @param fill
         */
        void set_fill(const std::string &fill);
        /**
         * @brief Get the font family object
         *
         * @return std::string&
         */
        std::string &get_font_family() const;
        /**
         * @brief Set the font family object
         *
         * @param font_family
         */
        void set_font_family(std::string &font_family);
        /**
         * @brief Get the font size object
         *
         * @return int
         */
        int &get_font_size();
        /**
         * @brief Set the font size object
         *
         * @param font_size
         */
        void set_font_size(int font_size);
        /**
         * @brief Get the text align object
         *
         * @return TextAlign
         */
        TextAlign get_text_align();
        /**
         * @brief Set the text align object
         *
         * @param text_align
         */
        void set_text_align(TextAlign &text_align);
        /**
         * @brief Get the paragraph decoration object
         *
         * @return ParagraphDecoration
         */
        ParagraphDecoration get_paragraph_decoration();
        /**
         * @brief Set the paragraph decoration object
         *
         * @param paragraph_decoration
         */
        void set_paragraph_decoration(ParagraphDecoration paragraph_decoration);
        /**
         * @brief Get the string of text decoration set
         *
         * @return std::string
         */
        std::string get_text_decoration_set();
        /**
         * @brief Append a new text decoration to the text decoration set
         *
         * @param text_decoration
         */
        void add_text_decoration(TextDecoration text_decoration);
        /**
         * @brief delete a specific text decoration
         *
         */
        void delete_text_decoration(TextDecoration text_decoration);

        /**
         * @brief Parse this fill style to XML properties
         *
         * @return std::string
         */
        std::string to_properties() const;
    }

}

#endif __LZ_TEXT_STYLE__