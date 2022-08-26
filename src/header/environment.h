#ifndef Environment_h
#define Environment_h

#include <iostream>

#include "grid.h"

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Environment {
        public:
            Environment(int envId, std::string envName, int size);
            int getId();
            std::string getName();
            Grid getGrid();
            void setName(std::string newName);
            void addEntity(Entity entity);
            void addEntityToLocation(Entity entity, Location location);
            void removeEntity(Entity entity);
            bool isEntityPresent(Entity entity);
            int getNumEntities();
            void printInfo();
        private:
            int id;
            std::string name;
            Grid grid;
    };
}

#endif