

#ifndef PROJECT_LUMINARY_MAPOBJECT_H
#define PROJECT_LUMINARY_MAPOBJECT_H
#include "../console/CharData.h"
#include "../console/CharRenderable.h"

class MapObject : public CharRenderable {
protected:
    CharData* m_lightCharData;
private:
    bool m_isObstacle;
public:
    MapObject(CharData* charData, CharData* lightCharData, bool isObstacle);
    std::string renderChar(bool isLightened);

    bool isObstacle();
};


#endif //PROJECT_LUMINARY_MAPOBJECT_H
