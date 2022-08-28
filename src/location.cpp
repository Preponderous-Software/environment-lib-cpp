#include "header/location.h"

#include <iostream>

namespace envlibcpp {
    Location::Location(int xpos, int ypos) {
        id = rand() % 100 + 1;
        x = xpos;
        y = ypos;
    }

    int Location::getId() {
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
    
    void Location::addEntity(Entity entity) {
        entity.setLocationId(getId());
        entities.push_back(entity);
    }
    
    void Location::removeEntity(Entity entity) {
        for (auto i = entities.begin(); i != entities.end(); i++) {
            if ((*i).getId() == entity.getId()) {
                entities.erase(i);
            }
        }
    }
    
    bool Location::isEntityPresent(Entity entity) {
        for (Entity e : entities) {
            if (e.getId() == entity.getId()) {
                return true;
            }
        }
        return false;
    }
    
    std::vector<Entity> Location::getEntities() {
        return entities;
    }
    
}