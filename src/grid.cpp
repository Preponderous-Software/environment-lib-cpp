#include "header/grid.h"

namespace envlibcpp {
    Grid::Grid() {
        // unused
    }

    Grid::Grid(int gridId, int gridSize) {
        id = gridId;
        size = gridSize;
        generateLocations();
    }

    int Grid::getId() {
        // TODO: implement
    }

    std::vector<Location> Grid::getLocations() {
        // TODO: implement
    }

    Location Grid::getFirstLocation() {
        // TODO: implement
    }

    int Grid::getSize() {
        // TODO: implement
    }

    int Grid::getNumEntities() {
        // TODO: implement
    }

    void Grid::setId(int newId) {
        // TODO: implement
    }

    void Grid::setSize(int newSize) {
        // TODO: implement
    }

    void Grid::addLocation(Location location) {
        // TODO: implement
    }

    void Grid::removeLocation(Location location) {
        // TODO: implement
    }

    void Grid::addEntity(Entity entity) {
        // TODO: implement
    }

    void Grid::addEntityToLocation(Entity entity, Location location) {
        // TODO: implement
    }

    void Grid::removeEntity(Entity entity) {
        // TODO: implement
    }

    bool Grid::isEntityPresent(Entity entity) {
        // TODO: implement
    }

    Location Grid::getLocation(int locationId) {
        // TODO: implement
    }

    Location Grid::getUp(Location location) {
        // TODO: implement
    }

    Location Grid::getRight(Location location) {
        // TODO: implement
    }

    Location Grid::getDown(Location location) {
        // TODO: implement
    }
    
    Location Grid::getLeft(Location location) {
        // TODO: implement
    }
    
    void Grid::generateLocations() {
        // TODO: implement
    }
}