#include "header/entity.h"

#include <string>
#include <iostream>

namespace envlibcpp {
    Entity::Entity(std::string entityName) {
        id = rand() % 100 + 1;
        name = entityName;
        environmentId = -1;
        gridId = -1;
        locationId = -1;
    }

    int Entity::getId() {
        return id;
    }

    std::string Entity::getName() {
        return name;
    }

    int Entity::getEnvironmentId() {
        return environmentId;
    }

    int Entity::getGridId() {
        return gridId;
    }

    int Entity::getLocationId() {
        return locationId;
    }

    void Entity::setName(std::string newName) {
        name = newName;
    }

    void Entity::setEnvironmentId(int id) {
        std::cout << "Entity::setEnvironmentId()" << std::endl;
        environmentId = id;
    }

    void Entity::setGridId(int id) {
        std::cout << "Entity::setGridId()" << std::endl;
        gridId = id;
    }

    void Entity::setLocationId(int id) {
        locationId = id;
    }
}