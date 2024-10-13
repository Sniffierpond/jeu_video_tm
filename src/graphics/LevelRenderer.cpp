/*
    -------------------------
    LevelRenderer.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/LevelRenderer.hpp"
#include "../../include/graphics/BlockRenderer.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <functional>
#include <iostream>

LevelRenderer::LevelRenderer(const Level* const level, const Player& player, const Camera& camera, const TextureRegistry& textureRegistry): level_(level), player_(player), camera_(std::reference_wrapper<const Camera>(camera)), textureRegistry_(textureRegistry) {}


void LevelRenderer::setCamera(const Camera& camera) {
    camera_ = std::reference_wrapper<const Camera>(camera);
}

void LevelRenderer::render(sf::RenderTarget& target) const {
    sf::FloatRect renderArea(
            (camera_.get().getPosition().x - camera_.get().getWidth() / 2) - std::floor(camera_.get().getPosition().x - camera_.get().getWidth() / 2), 
            (camera_.get().getPosition().y - camera_.get().getHeight() / 2) - std::floor(camera_.get().getPosition().y - camera_.get().getHeight() / 2),
            camera_.get().getWidth(),
            camera_.get().getHeight());

    BlockRenderer renderer(
        level_->getBlocks(
            sf::IntRect(
                std::floor(camera_.get().getPosition().x - camera_.get().getWidth() / 2), 
                std::floor(camera_.get().getPosition().y - camera_.get().getHeight() / 2), 
                std::ceil(renderArea.width + renderArea.left), 
                std::ceil(renderArea.height + renderArea.top))), 
        renderArea,
        textureRegistry_);

    sf::Texture playerTexture = *textureRegistry_.get(player_.getTextureId());
    
    sf::Sprite playerSprite(playerTexture);
    
    playerSprite.setPosition(sf::Vector2f((player_.movementHandler().getPosition().x - 0.5 - (camera_.get().getPosition().x - renderArea.width / 2)) + renderArea.left,  ((camera_.get().getPosition().y + renderArea.height / 2) - player_.movementHandler().getPosition().y - 2) - renderArea.top));
    playerSprite.setScale(1.0 / playerTexture.getSize().x, 1.0 / playerTexture.getSize().y * 2);
    
    sf::View view;

    sf::Vector2f size;
    sf::Vector2f center;

    if (static_cast<float>(target.getSize().x)  / renderArea.width * renderArea.height >= static_cast<float>(target.getSize().y)) {
        size.x = renderArea.width;
        size.y = renderArea.width / static_cast<float>(target.getSize().x) * target.getSize().y;
    }
    else {
        size.y = renderArea.height;
        size.x = renderArea.height / static_cast<float>(target.getSize().y) * target.getSize().x;
    }

    center.x = renderArea.width / 2 + renderArea.left;
    center.y = renderArea.height / 2 - renderArea.top;

    view.setCenter(center);
    view.setSize(size);
    
    target.setView(view);

    target.clear(sf::Color::Cyan);

    renderer.render(target);

    target.draw(playerSprite);
}