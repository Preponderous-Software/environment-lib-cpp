#ifndef Environment_h
#define Environment_h

#include <iostream>

#include "grid.h"

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Environment {
        public:
            Environment(int id, std::string envName, int size);
            ~Environment();
            int getId();
            std::string getName();
            Grid* getGrid();
            void setName(std::string newName);
            void addEntity(Entity& entity);
            void addEntityToLocation(Entity& entity, Location& location);
            void removeEntity(Entity& entity);
            bool isEntityPresent(Entity& entity);
            int getNumEntities();
            void printInfo();
            Entity& getFirstEntity();
            Entity& getEntity(int entityId);
            void moveEntityToNewLocation(int entityId, std::string locationId);
            bool moveEntityUp(int entityId);
            bool moveEntityRight(int entityId);
            bool moveEntityDown(int entityId);
            bool moveEntityLeft(int entityId);
        private:
            int id;
            std::string name;
            Grid* grid;

            bool moveEntityInDirection(int entityId, int direction);
    };
}

#endif