/*
    -------------------------
    GameApplication.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/GameApplication.hpp"
#include "../../include/core/PlayingGameState.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

GameApplication::GameApplication(const cxxopts::ParseResult& options) {
    fps_ = options["fps"].as<unsigned int>();
}

int GameApplication::launch() noexcept {
    try {
        std::chrono::steady_clock clock;
        auto start = clock.now();

        sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Jeu TM", sf::Style::Fullscreen);

        stack_.push(PlayingGameState(window));

        while (stack_.size() > 0 || !shouldExit_) {
            if (clock.now() - start < std::chrono::seconds(1) / 1.0 / fps_) {
                std::this_thread::sleep_for(std::chrono::seconds(1) / 1.0 / fps_ - (clock.now() - start));
                continue;
            }
      
            stack_.update();
            window.display();

            start = clock.now();
        }

        return EXIT_SUCCESS;
    }
    catch (...) {
        std::cerr << "An unknown exception occured." << std::endl;
        return EXIT_FAILURE;
    }
}

void GameApplication::exit() {
    shouldExit_ = true;
}