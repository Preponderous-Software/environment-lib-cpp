#include "header/entity.h"

#include <string>

namespace envlibcpp {
    Entity::Entity(int entityId, std::string entityName) {
        id = entityId;
        name = entityName;
        environmentId = -1;
        gridId = -1;
        locationId = -1;
    }

    int Entity::getID() {
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
        environmentId = id;
    }

    void Entity::setGridId(int id) {
        gridId = id;
    }

    void Entity::setLocationId(int id) {
        locationId = id;
    }
}