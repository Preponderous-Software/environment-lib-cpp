#include "header/entity.h"

#include <string>
#include <iostream>

namespace envlibcpp {
    Entity::Entity(int identifier, std::string entityName) {
        id = identifier;
        name = entityName;
        environmentId = -1;
        gridId = -1;
        locationId = "N/S";
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

    std::string Entity::getLocationId() {
        return locationId;
    }

    void Entity::setName(std::string newName) {
        name = newName;
    }

    void Entity::setEnvironmentId(int id) {
        environmentId = id;
    }

    void Entity::setGridId(int id) {
        gridId = id;
    }

    void Entity::setLocationId(std::string id) {
        locationId = id;
    }

    void Entity::resetLocationId() {
        setLocationId("N/S");
    }

    void Entity::setId(int identifier) {
        id = identifier;
    }
}