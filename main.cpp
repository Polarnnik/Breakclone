//
// Created by polarnik on 13.10.2024.
//
#include "app.h"
#include <exception>
#include <iostream>

int main() {
    try {
        App app;
        app.Init();
        app.Run();
        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}