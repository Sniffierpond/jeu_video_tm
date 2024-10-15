/*
    -------------------------
    SimpleAnimation.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/SimpleAnimation.hpp"
#include <cmath>

SimpleAnimation::SimpleAnimation(std::chrono::nanoseconds frameDuration) {
    frameDuration_ = frameDuration;
}


SimpleAnimation& SimpleAnimation::addFrame(std::string frameTexture) {
    frames_.push_back(frameTexture);

    return *this;
}


std::string SimpleAnimation::frame(unsigned int index) const {
    return frames_.at(index);
}

std::string SimpleAnimation::frame(std::chrono::nanoseconds timeElapsed) const {
    return frames_.at(std::floor((timeElapsed % duration()) / frameDuration_));
}


unsigned int SimpleAnimation::length() const {
    return frames_.size();
}

std::chrono::nanoseconds SimpleAnimation::duration() const {
    return (frames_.size() * frameDuration_);
}