#include "header/environment.h"

namespace envlibcpp {
    Environment::Environment(int envId, std::string envName, int size) {
        id = envId;
        name = envName;
        grid = Grid(-1, size);
    }

    int Environment::getId() {
        return id;
    }

    std::string Environment::getName() {
        return name;
    }

    Grid Environment::getGrid() {
        return grid;
    }

    void Environment::setName(std::string newName) {
        name = newName;
    }

    void Environment::addEntity(Entity entity) {
        entity.setEnvironmentId(id);
        grid.addEntity(entity);
    }

    void Environment::addEntityToLocation(Entity entity, Location location) {
        entity.setEnvironmentId(id);
        grid.addEntityToLocation(entity, location);
    }

    void Environment::removeEntity(Entity entity) {
        entity.setEnvironmentId(-1);
        grid.removeEntity(entity);
    }

    bool Environment::isEntityPresent(Entity entity) {
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