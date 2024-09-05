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
#include <functional>

LevelRenderer::LevelRenderer(const Level& level, const Camera& camera, const TextureRegistry& textureRegistry): level_(level), camera_(std::reference_wrapper<const Camera>(camera)), textureRegistry_(textureRegistry) {}


void LevelRenderer::setCamera(const Camera& camera) {
    camera_ = std::reference_wrapper<const Camera>(camera);
}

sf::Texture LevelRenderer::render() const {
    sf::Texture texture;

    BlockRenderer renderer(level_.getBlocks(sf::IntRect(camera_.get().getPosition().x, camera_.get().getPosition().y, camera_.get().getWidth(), camera_.get().getHeight())), sf::FloatRect(camera_.get().getPosition().x, camera_.get().getPosition().y, camera_.get().getWidth(), camera_.get().getHeight()), textureRegistry_);

    sf::Texture levelTexture;

    sf::Texture blocksTexture = renderer.render();

    sf::Image sky;
    sky.create(blocksTexture.getSize().x, blocksTexture.getSize().y, sf::Color::Blue);

    levelTexture.create(blocksTexture.getSize().x, blocksTexture.getSize().y);
    
    levelTexture.update(sky);
    levelTexture.update(blocksTexture);

    return levelTexture;
}