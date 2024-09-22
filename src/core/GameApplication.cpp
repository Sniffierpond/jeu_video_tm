/*
    -------------------------
    GameApplication.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/GameApplication.hpp"
#include "../../include/core/PlayingGameState.hpp"
#include "../../include/graphics/BaseTexturesRegister.hpp"
#include "../../include/game/BaseBlocksRegister.hpp"
#include "../../include/persistence/BlockGridLoader.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <filesystem>

GameApplication::GameApplication(const cxxopts::ParseResult& options): 
    fps_(options["fps"].as<unsigned int>()),
    fullscreen_(options["fullscreen"].as<bool>()),
    windowHeight_(options["windowheight"].as<unsigned int>()),
    windowWidth_(options["windowwidth"].as<unsigned int>()),
    gridPath_(options["blockgrid"].as<std::string>())
{}

int GameApplication::launch() noexcept {
    if (!initialised_)
        init();

    try {
        std::chrono::steady_clock clock;
        auto start = clock.now();

        while (stack_.size() > 0 || !shouldExit_) {
            if (clock.now() - start < std::chrono::seconds(1) / 1.0 / fps_) {
                std::this_thread::sleep_for(std::chrono::seconds(1) / 1.0 / fps_ - (clock.now() - start));
                continue;
            }
            stack_.update();
            window_.display();

            start = clock.now();
        }

        return EXIT_SUCCESS;
    }
    catch (...) {
        std::cerr << "An unknown exception occured." << std::endl;
        return EXIT_FAILURE;
    }
}


void GameApplication::init() {
    std::chrono::steady_clock clock;
    auto start = clock.now();

    std::cout << "Initialisation de l'application..." << std::endl;

    std::cout << "Chargement des textures..." << std::endl;
    BaseTexturesRegister::registerTextures(textureRegistry_);

    std::cout << "Enregistrement des blocs..." << std::endl;
    BaseBlocksRegister::registerBlocks(blockRegistry_);

    std::cout << "Chargement du niveau..." << std::endl;
    
    BlockGridLoader loader(gridPath_);
    auto result = loader.load();
    auto intArray = result.toIntArray();

    auto vecteur = sf::Vector2i((intArray.front().size() - 1) / 2, 0);

    if (fullscreen_)
        window_.create(sf::VideoMode::getFullscreenModes()[0], "Jeu TM", sf::Style::Fullscreen);
    else
        window_.create(sf::VideoMode(windowWidth_, windowHeight_), "JeuTM");

    Level level(blockRegistry_, result.toIntArray(),  {0, 0}, result.blocksNumericIds());

    stack_.push(std::make_shared<PlayingGameState>(textureRegistry_, std::move(level), window_));
    stack_.at(stack_.size() - 1).start();

    auto end = clock.now();
    std::cout << "Terminé (" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms)." << std::endl;

    initialised_ = true;
}

GameStateStack& GameApplication::gameStateStack() {
    return stack_;
}

void GameApplication::exit() {
    shouldExit_ = true;
}