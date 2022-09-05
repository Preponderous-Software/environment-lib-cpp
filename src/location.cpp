#include "header/location.h"

#include <iostream>

namespace envlibcpp {
    Location::Location(std::string identifier, int xpos, int ypos) {
        id = identifier;
        x = xpos;
        y = ypos;
    }

    std::string Location::getId() {
        return id;
    }

    int Location::getX() {
        return x;
    }
    
    int Location::getY() {
        return y;
    }
    
    int Location::getNumEntities() {
        return entities.size();
    }
    
    void Location::addEntity(Entity& entity) {
        entity.setLocationId(getId());
        entities.push_back(entity);
    }
    
    void Location::removeEntity(Entity& entity) {
        int index = -1;
        for (int i = 0; i < getNumEntities(); i++) {
            if (entities[i].getId() == entity.getId()) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            entities.erase(entities.begin() + index);
        }
        entity.resetLocationId();
    }
    
    bool Location::isEntityPresent(Entity& entity) {
        for (Entity &e : entities) {
            if (e.getId() == entity.getId()) {
                return true;
            }
        }
        return false;
    }
    
    std::vector<Entity>& Location::getEntities() {
        return entities;
    }
    
}