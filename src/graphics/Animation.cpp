/*
    -------------------------
    Animation.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/Animation.hpp"
#include <cmath>

Animation::Animation(std::chrono::nanoseconds frameDuration) {
    frameDuration_ = frameDuration;
}


Animation& Animation::addFrame(std::string frameTexture) {
    frames_.push_back(frameTexture);
    duration_ += frameDuration_;

    return *this;
}


std::string Animation::frame(unsigned int index) const {
    return frames_.at(index);
}

std::string Animation::frame(std::chrono::nanoseconds timeElapsed) const {
    return frames_.at(std::floor((timeElapsed % duration_) / frameDuration_));
}


unsigned int Animation::length() const {
    return frames_.size();
}