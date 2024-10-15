/*
    -------------------------
    AnimationHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../../include/contracts/Updatable.hpp"
#include "../contracts/Animation.hpp"
#include <chrono>
#include <functional>

class AnimationHandler: public Updatable {
    private:
    const std::reference_wrapper<const Animation> animation_;
    mutable std::chrono::nanoseconds timeElapsed_;

    public:
    AnimationHandler(const Animation& animation);

    virtual std::string getTextureId() const;

    virtual void update(std::chrono::nanoseconds timeDifference) override;

    virtual ~AnimationHandler() = default;
};