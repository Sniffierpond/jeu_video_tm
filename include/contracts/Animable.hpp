/*
    -------------------------
    Animable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../graphics/AnimationHandler.hpp"

#pragma once

class Animable {
    public:
    virtual AnimationHandler& animationHandler() = 0;

    virtual ~Animable() = 0;
};