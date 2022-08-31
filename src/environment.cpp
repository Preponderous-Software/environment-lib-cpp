#include "header/environment.h"

#include <iostream>

namespace envlibcpp {
    Environment::Environment(std::string envName, int size) {
        id = rand() % 100 + 1;
        name = envName;
        grid = Grid(size);
    }

    int Environment::getId() {
        return id;
    }

    std::string Environment::getName() {
        return name;
    }

    Grid& Environment::getGrid() {
        return grid;
    }

    void Environment::setName(std::string newName) {
        name = newName;
    }

    void Environment::addEntity(Entity &entity) {
        entity.setEnvironmentId(id);
        grid.addEntity(entity);
    }

    void Environment::addEntityToLocation(Entity &entity, Location &location) {
        entity.setEnvironmentId(id);
        grid.addEntityToLocation(entity, location);
    }

    void Environment::removeEntity(Entity &entity) {
        entity.setEnvironmentId(-1);
        grid.removeEntity(entity);
    }

    bool Environment::isEntityPresent(Entity &entity) {
        return grid.isEntityPresent(entity);
    }

    int Environment::getNumEntities() {
        return grid.getNumEntities();
    }
    
    void Environment::printInfo() {
        std::cout << "=== " << getName() << " ===" << std::endl;
        std::cout << "Num entities: " << getNumEntities() << std::endl;
    }
}