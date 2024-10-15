/*
    -------------------------
    AnimationHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/AnimationHandler.hpp"

AnimationHandler::AnimationHandler(const Animation& animation): animation_(animation), timeElapsed_() {}


std::string AnimationHandler::getTextureId() const {
    return animation_.get().frame(timeElapsed_);
}


void AnimationHandler::update(std::chrono::nanoseconds timeDifference) {
    timeElapsed_ += timeDifference;
}