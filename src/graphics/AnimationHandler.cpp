/*
    -------------------------
    AnimationHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/AnimationHandler.hpp"

AnimationHandler::AnimationHandler(const Animation& animation): animation_(animation) {}


std::string AnimationHandler::getTextureId() const {
    return animation_.get().frame(timeElapsed_);
}


void AnimationHandler::update(std::chrono::nanoseconds timeDifference) {
    timeElapsed_ += timeDifference;
}