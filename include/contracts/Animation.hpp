/*
    -------------------------
    Animation.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <chrono>
#include <string>

class Animation {
    public:
    virtual std::string frame(std::chrono::nanoseconds timeElapsed) const = 0;
    virtual std::chrono::nanoseconds duration() const = 0;

    virtual ~Animation() = 0;
};