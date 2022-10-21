#ifndef Location_h
#define Location_h

#include <iostream>
#include <vector>

#include "entity.h"

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Location {
        public:
            Location(std::string id, int xpos, int ypos);
            std::string getId();
            int getX();
            int getY();
            size_t getNumEntities();
            void addEntity(Entity* entity);
            void removeEntity(Entity* entity);
            bool isEntityPresent(Entity* entity);
            std::vector<Entity*>& getEntities();
        private:
            std::string id = "";
            int x = -1;
            int y = -1;
            std::vector<Entity*> entities;
    };
}

#endif