#ifndef PROJECT_LUMINARY_CHARRENDERABLE_H
#define PROJECT_LUMINARY_CHARRENDERABLE_H

#include "CharData.h"

class CharRenderable {
protected:
    CharRenderable(CharData* charData);

    std::string renderChar();
};


#endif //PROJECT_LUMINARY_CHARRENDERABLE_H
