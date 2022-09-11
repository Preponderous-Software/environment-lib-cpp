#include "header/environment.h"

#include <iostream>

namespace envlibcpp {
    Environment::Environment(int identifier, std::string envName, int size) {
        id = identifier;
        name = envName;
        grid = new Grid(id, size);
    }

    Environment::~Environment() {
        free(grid);
    }

    int Environment::getId() {
        return id;
    }

    std::string Environment::getName() {
        return name;
    }

    Grid* Environment::getGrid() {
        return grid;
    }

    void Environment::setName(std::string newName) {
        name = newName;
    }

    void Environment::addEntity(Entity& entity) {
        entity.setEnvironmentId(id);
        grid->addEntity(entity);
    }

    void Environment::addEntityToLocation(Entity& entity, Location& location) {
        entity.setEnvironmentId(id);
        grid->addEntityToLocation(entity, location);
    }

    void Environment::removeEntity(Entity& entity) {
        entity.setEnvironmentId(-1);
        grid->removeEntity(entity);
    }

    bool Environment::isEntityPresent(Entity& entity) {
        return grid->isEntityPresent(entity);
    }

    int Environment::getNumEntities() {
        return grid->getNumEntities();
    }
    
    void Environment::printInfo() {
        std::cout << "=== " << getName() << " ===" << std::endl;
        std::cout << "Num entities: " << getNumEntities() << std::endl;
    }

    Entity& Environment::getFirstEntity() {
        for (Location& location : getGrid()->getLocations()) {
            if (location.getNumEntities() > 0) {
                return *location.getEntities()[0];
            }
        }
        throw new std::exception();
    }

    Entity& Environment::getEntity(int entityId) {
        for (Location& location : getGrid()->getLocations()) {
            for (Entity* entity : location.getEntities()) {
                if (entity->getId() == entityId) {
                    return *entity;
                }
            }
        }
        throw new std::exception();
    }

    void Environment::moveEntityToNewLocation(int entityId, std::string locationId) {
        Entity& entity = getEntity(entityId);
        Location& currentLocation = getGrid()->getLocation(entity.getLocationId());
        Location& newLocation = getGrid()->getLocation(locationId);
        removeEntity(entity);
        addEntityToLocation(entity, newLocation);
    }

    bool Environment::moveEntityUp(int entityId) {
        return moveEntityInDirection(entityId, 0);
    }

    bool Environment::moveEntityRight(int entityId) {
        return moveEntityInDirection(entityId, 1);
    }

    bool Environment::moveEntityDown(int entityId) {
        return moveEntityInDirection(entityId, 2);
    }

    bool Environment::moveEntityLeft(int entityId) {
        return moveEntityInDirection(entityId, 3);
    }

    bool Environment::moveEntityToRandomAdjacentLocation(int entityId) {
        int direction = rand() * 4 + 1;
        return moveEntityInDirection(entityId, direction);
    }

    bool Environment::moveEntityInDirection(int entityId, int direction) {
        Entity& entity = getEntity(entityId);
        Location& currentLocation = getGrid()->getLocation(entity.getLocationId());
        Location* newLocation;
        try {
            if (direction == 0) {
                newLocation = &getGrid()->getLocationByCoordinates(currentLocation.getX(), currentLocation.getY() - 1);
            }
            else if (direction == 1) {
                newLocation = &getGrid()->getLocationByCoordinates(currentLocation.getX() + 1, currentLocation.getY());
            }
            else if (direction == 2) {
                newLocation = &getGrid()->getLocationByCoordinates(currentLocation.getX(), currentLocation.getY() + 1);
            }
            else if (direction == 3) {
                newLocation = &getGrid()->getLocationByCoordinates(currentLocation.getX() - 1, currentLocation.getY());
            }
            removeEntity(entity);
            addEntityToLocation(entity, *newLocation);
            return true;
        } catch(std::exception e) {
            // no location found
            return false;
        }
    }
}