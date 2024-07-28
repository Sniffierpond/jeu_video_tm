/*
    -------------------------
    BaseTextureRegister.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../graphics/TextureRegistry.hpp"
#include <vector>

class BaseTexturesRegister {
    public:
    void registerTextures(TextureRegistry& registry) const;
};