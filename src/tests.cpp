#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"
#include "header/location.h"
#include "header/grid.h"

using namespace envlibcpp;

void testTemplate() {
    std::cout << "Test 0 - Template";
    assert(true);
    std::cout << " --- " << "Success" << std::endl;
}

void testPlacingEntityInLocation() {
    std::cout << "Test 1 - Placing entity in location";
    Entity entity(0, "Daniel");
    Location location("my location id", 0, 0);
    location.addEntity(&entity);
    assert(location.isEntityPresent(&entity) == true);
    assert(entity.getLocationId() == location.getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testRemovingEntityFromLocation() {
    std::cout << "Test 2 - Removing entity from location";
    Entity entity(0, "Daniel");
    Location location("location-0-0", 0, 0);
    location.addEntity(&entity);
    location.removeEntity(&entity);
    assert(!location.isEntityPresent(&entity));
    assert(entity.getLocationId() == "N/S");
    std::cout << " --- " << "Success" << std::endl;
}

void testGeneratingGrid() {
    std::cout << "Test 3 - Generating grid";
    int size = 4;
    Environment environment(0, "test environment", 4);
    int numLocations = environment.getGrid()->getLocations().size();
    int expectedNumLocations = size*size;
    assert(numLocations == expectedNumLocations);
    std::cout << " --- " << "Success" << std::endl;
}

void testRetrievingFirstLocation() {
    std::cout << "Test 4 - Retrieving location";
    Grid grid(0, 5);
    Location firstLocation = grid.getFirstLocation();
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    std::cout << " --- " << "Success" << std::endl;
}

void testRetrievingLocationAfterModification() {
    std::cout << "Test 5 - Retrieving location after modification";
    Grid grid(0, 5);
    Location firstLocation = grid.getFirstLocation();
    Entity entity = Entity(0, "test");
    firstLocation = grid.getFirstLocation();
    firstLocation.addEntity(&entity);
    assert(firstLocation.getX() == 0 && firstLocation.getY() == 0);
    assert(firstLocation.isEntityPresent(&entity));
    std::cout << " --- " << "Success" << std::endl;
}

void testPlacingEntityInGrid() {
    std::cout << "Test 6 - Placing entity in grid";
    Entity entity(0, "Daniel");
    Grid grid(0, 4);
    grid.addEntity(entity);
    assert(grid.isEntityPresent(entity));
    assert(entity.getGridId() == grid.getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testRemovingEntityFromGrid() {
    std::cout << "Test 7 - Removing entity from grid";
    Entity entity(0, "Daniel");
    Grid grid(0, 4);
    grid.addEntity(entity);
    grid.removeEntity(entity);
    assert(!grid.isEntityPresent(entity));
    assert(entity.getGridId() == -1);
    std::cout << " --- " << "Success" << std::endl;
}

void testPlacingEntityInEnvironment() {
    std::cout << "Test 8 - Placing entity in environment";
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 2);
    environment.addEntity(entity);
    assert(environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == environment.getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testRemovingEntityFromEnvironment() {
    std::cout << "Test 9 - Removing entity from environment";
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 2);
    environment.addEntity(entity);
    environment.removeEntity(entity);
    assert(!environment.isEntityPresent(entity));
    assert(entity.getEnvironmentId() == -1);
    std::cout << " --- " << "Success" << std::endl;
}

void testPlacingMultipleEntities() {
    std::cout << "Test 10 - Placing multiple entities";
    Entity entity1(0, "Bob");
    Entity entity2(1, "Phil");
    Entity entity3(2, "Clarisse");
    Environment environment(0, "Earth", 6);
    environment.addEntity(entity1);
    environment.addEntity(entity2);
    environment.addEntity(entity3);
    assert(environment.getNumEntities() == 3);
    std::cout << " --- " << "Success" << std::endl;
}

void testResettingEntityLocationId() {
    std::cout << "Test 11 - Resetting entity location id";
    Entity entity(0, "Mark");
    entity.setLocationId("0-0-0");
    assert(entity.getLocationId() == "0-0-0");
    entity.resetLocationId();
    assert(entity.getLocationId() == "N/S");
    std::cout << " --- " << "Success" << std::endl;
}

void testRetrievingFirstEntity() {
    std::cout << "Test 12 - Retrieving first entity in an environment";
    Entity entity(34, "Daniel");
    Environment environment(0, "Earth", 3);
    environment.addEntity(entity);
    Entity& retrievedEntity = environment.getFirstEntity();
    assert(retrievedEntity.getId() == entity.getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testRetrievingEntityById() {
    std::cout << "Test 13 - Retrieving an entity from an environment by id";
    Entity entity(57, "Daniel");
    Environment environment(0, "Earth", 5);
    environment.addEntity(entity);
    Entity& retrievedEntity = environment.getEntity(entity.getId());
    assert(retrievedEntity.getId() == entity.getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testRetrievingLocationById() {
    std::cout << "Test 14 - Retrieving location by id from an grid.";
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 7);
    environment.addEntity(entity);
    std::string locationId = entity.getLocationId();
    Location& location = environment.getGrid()->getLocation(locationId);
    assert(location.getId() == locationId);
    std::cout << " --- " << "Success" << std::endl;
}

void testMovingEntityToNewLocation() {
    std::cout << "Test 15 - Moving entity to new location";
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 8);
    environment.addEntity(entity);
    std::string initialLocationId = entity.getLocationId();
    assert(initialLocationId != "N/S");

    Location* newLocation;
    do {
        newLocation = &environment.getGrid()->getRandomLocation();
    } while(newLocation->getId() == initialLocationId);
    
    environment.moveEntityToNewLocation(entity.getId(), newLocation->getId());
    std::string currentLocationId = entity.getLocationId();
    assert(currentLocationId == newLocation->getId());
    std::cout << " --- " << "Success" << std::endl;
}

void testMovingEntityToNewLocationRepeatedly() {
    std::cout << "Test 16 - Moving entity to new location repeatedly.";
    Entity entity(0, "Daniel");
    Environment environment(0, "Earth", 8);
    environment.addEntity(entity);
    for (int i = 0; i < 10; i++) {
        std::string initialLocationId = entity.getLocationId();
        assert(initialLocationId != "N/S");

        Location* newLocation;
        do {
            newLocation = &environment.getGrid()->getRandomLocation();
        } while(newLocation->getId() == initialLocationId);

        environment.moveEntityToNewLocation(entity.getId(), newLocation->getId());
        std::string currentLocationId = entity.getLocationId();
        assert(currentLocationId == newLocation->getId());
    }
    std::cout << " --- " << "Success" << std::endl;
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
    testRetrievingFirstLocation();
    testRetrievingLocationAfterModification();
    testPlacingEntityInGrid();
    testRemovingEntityFromGrid();
    testPlacingEntityInEnvironment();
    testRemovingEntityFromEnvironment();
    testPlacingMultipleEntities();
    testResettingEntityLocationId();
    testRetrievingFirstEntity();
    testRetrievingEntityById();
    testRetrievingLocationById();
    testMovingEntityToNewLocation();
    testMovingEntityToNewLocationRepeatedly();
    return 0;
}