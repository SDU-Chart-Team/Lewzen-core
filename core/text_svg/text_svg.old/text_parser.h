#include <string>

#ifndef __LZ_TEXT_PARSER__
#define __LZ_TEXT_PARSER__
/**
 * @brief The text parser
 *
 */
class TextParser
{
public:
    /**
     * @brief parse text source code into svg xml according to the text type
     *
     * @param sourceCode the string of text
     * @return std::string the string of svg xml
     */
    virtual std::string sourceCode2XML(std::string sourceCode);
};

// TODO:define the parse function
class PureTextParser : public TextParser
{
private:
    // the start tag and end tag of a SVG text
    const std::string STARTTAG = "<svg xmlns = \"http://www.w3.org/2000/svg\" version=\"1.1\"> <text> ";
    const std::string ENDTAG = "</text></svg>";

public:
    std::string sourceCode2XML(std::string sourceCode)
    {
        std::string xml = this.STARTTAG + sourceCode + this.ENDTAG;
        return xml;
    }
};

class MarkdownTextParser : public TextParser
{
public:
    std::string sourceCode2XML(std::string sourceCode)
    // {
    //     std::string xml = "";
    //     return xml;
    // }
};

class KatexTextParser : public TextParser
{
public:
    std::string sourceCode2XML(std::string sourceCode)
    // {
    //     std::string xml = "";
    //     return xml;
    // }
};

#endif