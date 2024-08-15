/*
    -------------------------
    GameApplication.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Application.hpp"
#include "GameStateStack.hpp"

class GameApplication: public Application {
    private:
    GameStateStack stack_;
    unsigned int fps_;
    bool shouldExit_ = false;

    public:
    GameApplication(const cxxopts::ParseResult& options);
    int launch() noexcept override;

    GameStateStack& gameStateStack() override;

    void exit() override;
};