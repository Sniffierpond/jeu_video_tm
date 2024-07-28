/*
    -------------------------
    BaseTextureRegister.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../graphics/TextureRegistry.hpp"

class BaseTexturesRegister {
    public:
    void registerTextures(TextureRegistry& registry) const;
};