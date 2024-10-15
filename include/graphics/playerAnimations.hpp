/*
    -------------------------
    playerAnimations.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "SimpleAnimation.hpp"

namespace playerAnimations {
    const SimpleAnimation walkingLeft = []{
        SimpleAnimation animation(std::chrono::milliseconds(250));

        animation.addFrame("base:player:walkingLeft:1")
        .addFrame("base:player:walkingLeft:2")
        .addFrame("base:player:walkingLeft:3")
        .addFrame("base:player:walkingLeft:2");
    
        return animation;
    }();

    const SimpleAnimation walkingRight = []{
        SimpleAnimation animation(std::chrono::milliseconds(250));

        animation.addFrame("base:player:walkingRight:1")
        .addFrame("base:player:walkingRight:2")
        .addFrame("base:player:walkingRight:3")
        .addFrame("base:player:walkingRight:2");
    
        return animation;
    }();
}