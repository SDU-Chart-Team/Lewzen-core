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
public:
    std::string sourceCode2XML(std::string sourceCode)
    {
        std::string xml = "";
        return xml;
    }
};

class MarkdownTextParser : public TextParser
{
public:
    std::string sourceCode2XML(std::string sourceCode)
    {
        std::string xml = "";
        return xml;
    }
};

class KatexTextParser : public TextParser
{
public:
    std::string sourceCode2XML(std::string sourceCode)
    {
        std::string xml = "";
        return xml;
    }
};

#endif