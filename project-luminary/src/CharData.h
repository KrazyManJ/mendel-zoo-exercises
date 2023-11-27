#ifndef PROJECT_LUMINARY_CHARDATA_H
#define PROJECT_LUMINARY_CHARDATA_H

#define COLOR_NONE 0x1000000

#include <vector>
#include "ConsoleHandler.h"

class CharData {
private:
    char m_character;
    unsigned int m_backgroundColor;
    unsigned int m_foregroundColor;
    std::vector<ConsoleHandler::ConsoleFormatType> m_formats;
public:
    CharData(char character, unsigned int backgroundColor, unsigned int foregroundColor);
    void addFormat(ConsoleHandler::ConsoleFormatType format);
    std::string toFullChar();
};


#endif //PROJECT_LUMINARY_CHARDATA_H
