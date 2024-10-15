/*
    -------------------------
    SimpleAnimation.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Animation.hpp"
#include <chrono>
#include <string>
#include <vector>

class SimpleAnimation: public Animation {
    private:
    std::vector<std::string> frames_;

    std::chrono::nanoseconds frameDuration_;

    public:
    SimpleAnimation(std::chrono::nanoseconds frameDuration);

    SimpleAnimation& addFrame(std::string frameTexture);

    std::string frame(unsigned int index) const;
    std::string frame(std::chrono::nanoseconds timeElapsed) const override;

    unsigned int length() const;
    std::chrono::nanoseconds duration() const override;
};