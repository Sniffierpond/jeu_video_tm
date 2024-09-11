/*
    -------------------------
    GameStateStack.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/GameState.hpp"
#include <vector>
#include <memory>

/*
Classe gérant les différents états du jeu et retirant automatiquement les états inactifs.
*/
class GameStateStack {
    private:
    std::vector<std::shared_ptr<GameState>> stack_;

    public:
    template <typename T>
    void push(const std::shared_ptr<T> state) {
        stack_.push_back(state);
    }

    GameState& at(int i);
    const GameState& at(int i) const;

    int size() const;

    void update();
};