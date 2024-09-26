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
#include <cmath>
#include <functional>
#include <iostream>

LevelRenderer::LevelRenderer(const Level* const level, const Player& player, const Camera& camera, const TextureRegistry& textureRegistry): level_(level), player_(player), camera_(std::reference_wrapper<const Camera>(camera)), textureRegistry_(textureRegistry) {}


void LevelRenderer::setCamera(const Camera& camera) {
    camera_ = std::reference_wrapper<const Camera>(camera);
}

sf::Texture LevelRenderer::render() const {
    sf::Texture texture;

    BlockRenderer renderer(
        level_->getBlocks(
            sf::IntRect(
                std::floor(camera_.get().getPosition().x), 
                std::floor(camera_.get().getPosition().y), 
                std::ceil(camera_.get().getWidth() + camera_.get().getPosition().x - std::floor(camera_.get().getPosition().x)), 
                std::ceil(camera_.get().getHeight() + camera_.get().getPosition().y - std::floor(camera_.get().getPosition().y)))), 
        sf::FloatRect(
            camera_.get().getPosition().x - std::floor(camera_.get().getPosition().x), 
            camera_.get().getPosition().y - std::floor(camera_.get().getPosition().y),
            camera_.get().getWidth(),
            camera_.get().getHeight()),
        textureRegistry_);

    sf::Texture levelTexture;

    sf::Texture blocksTexture = renderer.render();

    sf::Image sky;
    sky.create(blocksTexture.getSize().x, blocksTexture.getSize().y, sf::Color::Blue);

    levelTexture.create(blocksTexture.getSize().x, blocksTexture.getSize().y);
    
    levelTexture.update(sky);
    levelTexture.update(blocksTexture);

    return levelTexture;
}