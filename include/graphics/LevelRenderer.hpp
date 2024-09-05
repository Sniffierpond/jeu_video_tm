/*
    -------------------------
    LevelRenderer.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Renderer.hpp"
#include "../contracts/Camera.hpp"
#include "../game/Level.hpp"
#include "TextureRegistry.hpp"
#include <functional>

/*
Classe réalisant le rendu de tous les éléments contenus dans un niveau.
*/
class LevelRenderer: public Renderer {
    private:
    const Level& level_;

    std::reference_wrapper<const Camera> camera_;

    const TextureRegistry& textureRegistry_;

    public:
    LevelRenderer(const Level& level, const Camera& camera, const TextureRegistry& textureRegistry);

    void setCamera(const Camera& camera);

    sf::Texture render() const override;
};