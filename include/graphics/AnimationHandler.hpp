/*
    -------------------------
    AnimationHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../../include/contracts/Updatable.hpp"
#include "Animation.hpp"
#include <chrono>

class AnimationHandler: public Updatable {
    private:
    const Animation animation_;
    mutable std::chrono::nanoseconds timeElapsed_;

    public:
    AnimationHandler(Animation animation);

    std::string getTextureId() const;

    void update(std::chrono::nanoseconds timeDifference) override;
};