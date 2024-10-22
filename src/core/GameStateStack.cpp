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

int GameStateStack::size() const {
    return stack_.size();
}
void GameStateStack::update() {
    if (!stack_.empty()) {
        for (auto iterator = stack_.begin(); iterator != stack_.end(); ++iterator) {
            // Retire un état du tas d'états
            if (!(*iterator)->active()) {
                stack_.erase(iterator);
            }
            else {
                (*iterator)->update();
            }
        }
    }
}