#include "header/location.h"

namespace envlibcpp {
    Location::Location(int locId, int xpos, int ypos) {
        id = id;
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
        entities.push_back(entity);
    }
    
    void Location::removeEntity(Entity entity) {
        // TODO: implement
        std::cout << "Warning: method unimplemented" << std::endl;
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