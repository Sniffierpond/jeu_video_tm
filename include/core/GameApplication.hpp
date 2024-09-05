/*
    -------------------------
    GameApplication.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../cxxopts.hpp"
#include "../contracts/Application.hpp"
#include "../graphics/TextureRegistry.hpp"
#include "../game/BlockRegistry.hpp"
#include "../game/BlockGrid.hpp"
#include "../game/Level.hpp"
#include "GameStateStack.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class GameApplication: public Application {
    private:
    sf::RenderWindow window_;
    
    GameStateStack stack_;

    BlockRegistry blockRegistry_;
    TextureRegistry textureRegistry_;

    const std::string gridPath_;
    unsigned int fps_;
    const bool fullscreen_;
    unsigned int windowHeight_;
    unsigned int windowWidth_;

    bool shouldExit_ = false;
    bool initialised_ = false;

    public:
    GameApplication(const cxxopts::ParseResult& options);
    int launch() noexcept override;

    void init();

    GameStateStack& gameStateStack() override;

    void exit() override;
};