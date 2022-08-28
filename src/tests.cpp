#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"
#include "header/location.h"
#include "header/grid.h"

using namespace envlibcpp;

void testPlacingEntityInLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 1 - Placing entity in location" << std::endl;
    Entity entity("Daniel");
    Location location(0, 0);

    location.addEntity(entity);

    assert(location.isEntityPresent(entity) == true);
    std::cout << "Success" << std::endl;
}

void testGeneratingGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 2 - Generating grid" << std::endl;
    int size = 4;
    Environment environment("test environment", 4);
    int numLocations = environment.getGrid().getLocations().size();
    int expectedNumLocations = size*size;
    assert(numLocations == expectedNumLocations);
    std::cout << "Success" << std::endl;
}

void testRetrievingLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 3 - Retrieving location" << std::endl;
    Grid grid(5);
    Location firstLocation = grid.getFirstLocation();
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 4 - Placing entity in grid" << std::endl;
    Entity entity("Daniel");
    Grid grid(4);

    grid.addEntity(entity);

    assert(grid.isEntityPresent(entity) == true);
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInEnvironment() {
    std::cout << "---" << std::endl;
    std::cout << "Test 5 - Placing entity in environment" << std::endl;
    Entity entity("Daniel");
    Environment environment("Earth", 2);

    environment.addEntity(entity);

    assert(environment.isEntityPresent(entity) == true);
    std::cout << "Success" << std::endl;
}

int main() {
    srand (time (NULL));
    testPlacingEntityInLocation();
    testGeneratingGrid();
    testRetrievingLocation();
    testPlacingEntityInGrid();
    testPlacingEntityInEnvironment();
    return 0;
}