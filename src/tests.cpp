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
    Entity entity(0, "Daniel");
    Location location("my location id", 0, 0);
    location.addEntity(entity);
    assert(location.isEntityPresent(entity) == true);
    assert(entity.getLocationId() == location.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 2 - Removing entity from location" << std::endl;
    Entity entity(0, "Daniel");
    Location location("location-0-0", 0, 0);
    location.addEntity(entity);
    location.removeEntity(entity);
    assert(!location.isEntityPresent(entity));
    assert(entity.getLocationId() == "N/S");
    std::cout << "Success" << std::endl;
}

void testGeneratingGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 3 - Generating grid" << std::endl;
    int size = 4;
    Environment environment(0, "test environment", 4);
    int numLocations = environment.getGrid()->getLocations().size();
    int expectedNumLocations = size*size;
    assert(numLocations == expectedNumLocations);
    std::cout << "Success" << std::endl;
}

void testRetrievingLocation() {
    std::cout << "---" << std::endl;
    std::cout << "Test 4 - Retrieving location" << std::endl;
    Grid grid(0, 5);
    Location firstLocation = grid.getFirstLocation();
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    std::cout << "Success" << std::endl;
}

void testRetrievingLocationAfterModification() {
    std::cout << "---" << std::endl;
    std::cout << "Test 5 - Retrieving location after modification" << std::endl;
    Grid grid(0, 5);
    Location firstLocation = grid.getFirstLocation();
    Entity entity = Entity(0, "test");
    firstLocation = grid.getFirstLocation();
    firstLocation.addEntity(entity);
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    assert(firstLocation.isEntityPresent(entity));
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 6 - Placing entity in grid" << std::endl;
    Entity entity(0, "Daniel");
    Grid grid(0, 4);
    grid.addEntity(entity);
    assert(grid.isEntityPresent(entity));
    assert(entity.getGridId() == grid.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromGrid() {
    std::cout << "---" << std::endl;
    std::cout << "Test 7 - Removing entity from grid" << std::endl;
    Entity entity(0, "Daniel");
    Grid grid(0, 4);
    grid.addEntity(entity);
    grid.removeEntity(entity);
    assert(!grid.isEntityPresent(entity));
    assert(entity.getGridId() == -1);
    std::cout << "Success" << std::endl;
}

void testPlacingEntityInEnvironment() {
    std::cout << "---" << std::endl;
    std::cout << "Test 8 - Placing entity in environment" << std::endl;
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 2);
    environment.addEntity(entity);
    assert(environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == environment.getId());
    std::cout << "Success" << std::endl;
}

void testRemovingEntityFromEnvironment() {
    std::cout << "---" << std::endl;
    std::cout << "Test 9 - Removing entity from environment" << std::endl;
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 2);
    environment.addEntity(entity);
    environment.removeEntity(entity);
    assert(!environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == -1);
    std::cout << "Success" << std::endl;
}

void testPlacingMultipleEntities() {
    std::cout << "---" << std::endl;
    std::cout << "Test 10 - Placing multiple entities" << std::endl;
    Entity entity1(0, "Bob");
    Entity entity2(1, "Phil");
    Entity entity3(2, "Clarisse");
    Environment environment(0, "Earth", 6);
    environment.addEntity(entity1);
    environment.addEntity(entity2);
    environment.addEntity(entity3);
    assert(environment.getNumEntities() == 3);
    std::cout << "Success" << std::endl;
}

void testResettingEntityLocationId() {
    std::cout << "---" << std::endl;
    std::cout << "Test 11 - Resetting entity location id" << std::endl;
    EntityFactory entityFactory;
    Human human = entityFactory.createHuman();
    human.setLocationId("0-0-0");
    assert(human.getLocationId() == "0-0-0");
    human.resetLocationId();
    assert(human.getLocationId() == "N/S");
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
    testPlacingMultipleEntities();
    testResettingEntityLocationId();
    return 0;
}