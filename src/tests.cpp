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
    
    Location firstLocation = environment.getGrid().getFirstLocation();
    std::cout << "before placement the first location (" << firstLocation.getId() << ") has " << firstLocation.getNumEntities() << " entities." << std::endl;

    environment.addEntity(entity);

    std::cout << "after placement the first location (" << firstLocation.getId() << ") has " << firstLocation.getNumEntities() << " entities." << std::endl;
    int numEntities = environment.getNumEntities();
    int expectedNumEntities = 1;
    assert(numEntities == expectedNumEntities);
    std::cout << "Success" << std::endl;
}

int main() {
    srand (time (NULL));
    testGridGeneration();
    testEntityPlacement();
    return 0;
}