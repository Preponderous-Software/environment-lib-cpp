#include <string>
#include <iostream>
#include "environment.cpp"

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
    log("Creating environment.");
    Environment environment = Environment();

    log("Printing environment information.");
    environment.printInfo();
    return 0;
}