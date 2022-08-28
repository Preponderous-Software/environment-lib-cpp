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
    int numLocations = environment.getGrid().getLocations().size();
    int expectedNumLocations = size*size;
    assert(numLocations == expectedNumLocations);
    std::cout << "Success" << std::endl;
}

void testEntityPlacement() {
    std::cout << "---" << std::endl;
    std::cout << "Test - Entity Placement" << std::endl;
    Entity entity("Daniel");
    Environment environment("Earth", 2);

    environment.addEntity(entity);

    assert(environment.isEntityPresent(entity) == true);
    std::cout << "Success" << std::endl;
}

int main() {
    srand (time (NULL));
    testGridGeneration();
    testEntityPlacement();
    return 0;
}