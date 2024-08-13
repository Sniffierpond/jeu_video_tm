/*
    -------------------------
    GameStateStack.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/GameStateStack.hpp"

GameState& GameStateStack::at(int i) {
    return *stack_.at(i);
}


const GameState& GameStateStack::at(int i) const {
    return *stack_.at(i);
}


void GameStateStack::update() {
    for (auto iterator = stack_.begin(); iterator != stack_.end(); ++iterator) {
        if (!(*iterator)->active()) {
            stack_.erase(iterator);
        }
        else {
            (*iterator)->update();
        }
    }
}