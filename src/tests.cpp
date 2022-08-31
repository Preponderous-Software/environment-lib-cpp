#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"
#include "header/location.h"
#include "header/grid.h"

using namespace envlibcpp;

void testTemplate() {
    std::cout << "---" << std::endl;
    std::cout << "Test 0 - Template" << std::endl;
    assert(true);
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 1 - Placing entity in location" << std::endl;
    Entity entity("Daniel");
    Location location(0, 0);
    location.addEntity(entity);
    assert(location.isEntityPresent(entity) == true);
    assert(entity.getLocationId() == location.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 2 - Removing entity from location" << std::endl;
    Entity entity("Daniel");
    Location location(0, 0);
    location.addEntity(entity);
    location.removeEntity(entity);
    assert(!location.isEntityPresent(entity));
    assert(entity.getLocationId() == -1);
    std::cout << "Success" << std::endl;
}

void testGeneratingGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 3 - Generating grid" << std::endl;
    int size = 4;
    Environment environment("test environment", 4);
    int numLocations = environment.getGrid().getLocations().size();
    int expectedNumLocations = size*size;
    assert(numLocations == expectedNumLocations);
    std::cout << "Success" << std::endl;
}

void testRetrievingLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 4 - Retrieving location" << std::endl;
    Grid grid(5);
    Location firstLocation = grid.getFirstLocation();
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    std::cout << "Success" << std::endl;
}

void testRetrievingLocationAfterModification() {
    std::cout << "---" << std::endl;
    std::cout << "Test 5 - Retrieving location after modification" << std::endl;
    Grid grid(5);
    Location firstLocation = grid.getFirstLocation();
    Entity entity = Entity("test");
    firstLocation = grid.getFirstLocation();
    firstLocation.addEntity(entity);
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    assert(firstLocation.isEntityPresent(entity));
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 6 - Placing entity in grid" << std::endl;
    Entity entity("Daniel");
    Grid grid(4);
    grid.addEntity(entity);
    assert(grid.isEntityPresent(entity));
    assert(entity.getGridId() == grid.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 7 - Removing entity from grid" << std::endl;
    Entity entity("Daniel");
    Grid grid(4);
    grid.addEntity(entity);
    grid.removeEntity(entity);
    assert(!grid.isEntityPresent(entity));
    assert(entity.getGridId() == -1);
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInEnvironment() {
    std::cout << "---" << std::endl;
    std::cout << "Test 8 - Placing entity in environment" << std::endl;
    Entity entity("Daniel");
    Environment environment("Earth", 2);
    environment.addEntity(entity);
    assert(environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == environment.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromEnvironment() {
    std::cout << "---" << std::endl;
    std::cout << "Test 9 - Removing entity from environment" << std::endl;
    Entity entity("Daniel");
    Environment environment("Earth", 2);
    environment.addEntity(entity);
    environment.removeEntity(entity);
    assert(!environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == -1);
    std::cout << "Success" << std::endl;
}

void seedRandomNumberGenerator() {
    srand (time (NULL));
}

int main() {
    // seed RNG
    seedRandomNumberGenerator();
    
    // tests
    testPlacingEntityInLocation();
    testRemovingEntityFromLocation();
    testGeneratingGrid();
    testRetrievingLocation();
    testRetrievingLocationAfterModification();
    testPlacingEntityInGrid();
    testRemovingEntityFromGrid();
    testPlacingEntityInEnvironment();
    testRemovingEntityFromEnvironment();
    return 0;
}