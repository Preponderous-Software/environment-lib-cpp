#include "header/grid.h"

#include <iostream>

namespace envlibcpp {
    Grid::Grid() {
        Grid(4);
    }

    Grid::Grid(int gridSize) {
        id = rand() % 100 + 1;
        size = gridSize;
        generateLocations();
    }

    int Grid::getId() {
        return id;
    }

    std::vector<Location>& Grid::getLocations() {
        return locations;
    }

    Location& Grid::getFirstLocation() {
        return locations.front();
    }

    Location& Grid::getLocationByCoordinates(int x, int y) {
        for (Location& location : locations) {
            if (location.getX() == x && location.getY() == y) {
                return location;
            }
        }
        throw std::exception();
    }

    int Grid::getSize() {
        return size;
    }

    int Grid::getNumEntities() {
        int count = 0;
        for (Location& location : locations) {
            count = count + location.getNumEntities();
        }
        return count;
    }

    void Grid::setId(int newId) {
        id = newId;
    }

    void Grid::setSize(int newSize) {
        size = newSize;
    }

    void Grid::addLocation(Location &location) {
        locations.push_back(location);
    }

    void Grid::removeLocation(Location &location) {
        for (auto i = locations.begin(); i != locations.end(); i++) {
            if (i->getId() == location.getId()) {
                locations.erase(i);
            }
        }
    }

    void Grid::addEntity(Entity &entity) {
        entity.setGridId(id);
        Location &firstLocation = getRandomLocation();
        firstLocation.addEntity(entity);
    }

    void Grid::addEntityToLocation(Entity &entity, Location &location) {
        for (Location &l : locations) {
            if (l.getId() == location.getId()) {
                location.addEntity(entity);
            }
        }
    }

    void Grid::removeEntity(Entity &entity) {
        for (Location &location : locations) {
            if (location.isEntityPresent(entity)) {
                location.removeEntity(entity);
                entity.setLocationId(-1);
            }
        }
        entity.setGridId(-1);
    }

    bool Grid::isEntityPresent(Entity &entity) {
        for (Location &location : locations) {
            if (location.isEntityPresent(entity)) {
                return true;
            }
        }
        return false;
    }

    Location& Grid::getLocation(int locationId) {
        for (Location &location : locations) {
            if (location.getId() == locationId) {
                return location;
            }
        }
        throw std::exception();
    }

    Location& Grid::getRandomLocation() {
        int index = rand() % getLocations().size();
        return getLocations()[index];
    }
    
    void Grid::generateLocations() {
        for (int y = 0; y < getSize(); y++) {
            for (int x = 0; x < getSize(); x++) {
                Location location(x, y);
                locations.push_back(location);
            }
        }
    }
}