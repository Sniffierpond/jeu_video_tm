/*
    -------------------------
    Animation.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <chrono>
#include <string>
#include <vector>

class Animation {
    private:
    std::vector<std::string> frames_;

    std::chrono::nanoseconds frameDuration_;

    public:
    Animation(std::chrono::nanoseconds frameDuration);

    Animation& addFrame(std::string frameTexture);

    std::string frame(unsigned int index) const;
    std::string frame(std::chrono::nanoseconds timeElapsed) const;

    unsigned int length() const;
    std::chrono::nanoseconds duration() const;
};