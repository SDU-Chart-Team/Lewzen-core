#include "text_parser.h"

namespace Lewzen
{
    std::string PureTextParser::to_XML(std::string source_code, TextStyle text_style)
    {
        {
            this->STARTTAG = "<text " + text_style.to_properties() + ">"
            this->ENDTAG = "</text>"
            std::string xml = this->STARTTAG + source_code + this->ENDTAG;
            return xml;
        }
    }

}