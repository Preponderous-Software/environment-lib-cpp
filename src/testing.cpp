#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"

using namespace envlibcpp;

bool debugFlag = true;

/**
 * Log a message to the console.
 */
void log(std::string message) {
    std::cout << "[LOG] " << message << std::endl;
}

/**
 * Log a debug message to the console.
 */
void debug(std::string message) {
    if (debugFlag) {
        std::cout << "[DEBUG] " << message << std::endl;
    }
}

int main() {
    Entity entity(-1, "Daniel");
    std::cout << "An entity with the name '" << entity.getName() << "' was created." << std::endl;

    Environment environment(-1, "Earth", 2);
    std::cout << "An environment with the name '" << environment.getName() << "' was created." << std::endl;

    environment.addEntity(entity);
    std::cout << "Placed " << entity.getName() << " into " << environment.getName() + "." << std::endl;
    
    assert(environment.getNumEntities() > 0);
    
    return 0;
}