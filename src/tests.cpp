#include <string>
#include <iostream>
#include <assert.h>

#include "header/entity.h"
#include "header/environment.h"

using namespace envlibcpp;

void testEntityPlacement() {
    std::cout << "---" << std::endl;
    std::cout << "Testing Entity Placement" << std::endl;
    Entity entity(-1, "Daniel");
    Environment environment(-1, "Earth", 2);
    environment.addEntity(entity);
    assert(environment.getNumEntities() > 0);
    std::cout << "Success" << std::endl;
}

int main() {
    testEntityPlacement();
    return 0;
}