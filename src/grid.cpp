#include "header/grid.h"

namespace envlibcpp {
    Grid::Grid() {
        // unused
        std::cout << "Warning: default constructor used" << std::endl;
    }

    Grid::Grid(int gridId, int gridSize) {
        id = gridId;
        size = gridSize;
        generateLocations();
    }

    int Grid::getId() {
        return id;
    }

    std::vector<Location> Grid::getLocations() {
        return locations;
    }

    Location Grid::getFirstLocation() {
        return locations[0];
    }

    Location Grid::getLocationByCoordinates(int x, int y) {
        for (Location location : locations) {
            if (location.getX() == x && location.getY() == y) {
                return location;
            }
        }
        // TODO: return null or something?
        std::cout << "Warning: location not found" << std::endl;
    }

    int Grid::getSize() {
        return size;
    }

    int Grid::getNumEntities() {
        int count = 0;
        for (Location location : locations) {
            count += location.getNumEntities();
        }
        return count;
    }

    void Grid::setId(int newId) {
        id = newId;
    }

    void Grid::setSize(int newSize) {
        size = newSize;
    }

    void Grid::addLocation(Location location) {
        locations.push_back(location);
    }

    void Grid::removeLocation(Location location) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }

    void Grid::addEntity(Entity entity) {
        entity.setGridId(id);
        getFirstLocation().addEntity(entity);
    }

    void Grid::addEntityToLocation(Entity entity, Location location) {
        for (Location l : locations) {
            if (l.getId() == location.getId()) {
                location.addEntity(entity);
            }
        }
    }

    void Grid::removeEntity(Entity entity) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }

    bool Grid::isEntityPresent(Entity entity) {
        for (Location location : locations) {
            if (location.isEntityPresent(entity)) {
                return true;
            }
        }
        return false;
    }

    Location Grid::getLocation(int locationId) {
        for (Location location : locations) {
            if (location.getId() == locationId) {
                return location;
            }
        }
        // TODO: return null or something?
        std::cout << "Warning: location not found" << std::endl;
    }

    Location Grid::getUp(Location location) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }

    Location Grid::getRight(Location location) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }

    Location Grid::getDown(Location location) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }
    
    Location Grid::getLeft(Location location) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
    }
    
    void Grid::generateLocations() {
        for (int y = 0; y < getSize(); y++) {
            for (int x = 0; x < getSize(); x++) {
                Location location(-1, x, y);
                locations.push_back(location);
            }
        }
    }
}