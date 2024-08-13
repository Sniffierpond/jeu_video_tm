/*
    -------------------------
    GameApplication.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/GameApplication.hpp"
#include <chrono>
#include <cstdlib>

GameApplication::GameApplication(const cxxopts::ParseResult& options) {
    fps_ = options["fps"].as<unsigned int>();
}

int GameApplication::launch() {
    std::chrono::steady_clock clock;
    auto start = clock.now();

    while (stack_.size() > 0 || !shouldExit_) {
        if (clock.now() - start < std::chrono::seconds(1) / 1.0 / fps_) {
            continue;
        }

        stack_.update();
        start = clock.now();
    }

    return EXIT_SUCCESS;
}

void GameApplication::exit() {
    shouldExit_ = true;
}