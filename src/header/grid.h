#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <vector>

#include "location.h"

namespace envlibcpp {

    // @author Daniel McCoy Stephenson
    // @since August 26th, 2022
    class Grid {
        public:
            Grid();
            Grid(int gridId, int gridSize);
            int getId();
            std::vector<Location> getLocations();
            Location getFirstLocation();
            int getSize();
            int getNumEntities();
            void setId(int newId);
            void setSize(int newSize);
            void addLocation(Location location);
            void removeLocation(Location location);
            void addEntity(Entity entity);
            void addEntityToLocation(Entity entity, Location location);
            void removeEntity(Entity entity);
            bool isEntityPresent(Entity entity);
            Location getLocation(int locationId);
            Location getUp(Location location);
            Location getRight(Location location);
            Location getDown(Location location);
            Location getLeft(Location location);
        private:
            int id;
            int size;
            std::vector<Location> locations;

            void generateLocations();
    };
}

#endif