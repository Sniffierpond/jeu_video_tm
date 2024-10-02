/*
    -------------------------
    LevelRenderer.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Renderer.hpp"
#include "../contracts/Camera.hpp"
#include "../game/Player.hpp"
#include "../game/Level.hpp"
#include "TextureRegistry.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <functional>

/*
Classe réalisant le rendu de tous les éléments contenus dans un niveau.
*/
class LevelRenderer: public Renderer {
    private:
    const Level* const level_;
    const Player& player_;
    
    std::reference_wrapper<const Camera> camera_;

    const TextureRegistry& textureRegistry_;

    public:
    LevelRenderer(const Level* const level, const Player& player, const Camera& camera, const TextureRegistry& textureRegistry);

    void setCamera(const Camera& camera);

    void render(sf::RenderTarget& target) const override;
};