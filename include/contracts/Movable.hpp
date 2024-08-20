/*
    -------------------------
    Movable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../physics/MovementHandler.hpp"
#include <SFML/System/Vector2.hpp>

class Movable {
    public:
    virtual MovementHandler& movementHandler() = 0;

    virtual ~Movable() = 0;
};