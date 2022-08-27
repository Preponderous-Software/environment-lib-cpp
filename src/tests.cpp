#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"

using namespace envlibcpp;

void testGridGeneration() {
    std::cout << "---" << std::endl;
    std::cout << "Test - Grid Generation" << std::endl;
    int size = 4;
    Environment environment("test environment", 4);
    assert(environment.getGrid().getLocations().size() == size*size);
    std::cout << "Success" << std::endl;
}

void testEntityPlacement() {
    std::cout << "---" << std::endl;
    std::cout << "Test - Entity Placement" << std::endl;
    Entity entity("Daniel");
    Environment environment("Earth", 2);
    environment.addEntity(entity);
    assert(environment.getNumEntities() > 0);
    std::cout << "Success" << std::endl;
}

int main() {
    srand (time (NULL));
    testGridGeneration();
    testEntityPlacement();
    return 0;
}