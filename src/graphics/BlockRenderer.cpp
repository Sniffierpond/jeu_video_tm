/*
    -------------------------
    BlockRenderer.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/BlockRenderer.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <stdexcept>
#include <cmath>

BlockRenderer::BlockRenderer(const BlockGrid& grid, sf::FloatRect renderArea, const TextureRegistry& registry): grid_(grid), renderArea_(renderArea), textureRegistry_(registry) {
    if (renderArea_.width < 0 || renderArea_.height < 0) {
        throw std::invalid_argument("Size of the render area must not be negative.");
    }
    if (renderArea_.left + renderArea_.width > grid.getWidth() || renderArea_.top + renderArea_.height > grid.getHeight()) {
        throw std::invalid_argument("Render area must be contained in block grid area.");
    }
}

sf::Texture BlockRenderer::render() const {
    sf::Texture texture;

    sf::IntRect area(std::floor(renderArea_.left), std::floor(renderArea_.top), std::ceil(renderArea_.width), std::ceil(renderArea_.height));

    texture.create(area.width * 16, area.height * 16);

    for (int x = area.left; x < area.left + area.width; ++x) {
        for (int y = area.top; y < area.top + area.height; ++y) {
            Block block = grid_.getBlock(sf::Vector2i(x, y));

            sf::Texture blockTexture;

            if (block.getBlockType() == "base:air") {}
            else if (const auto& optional = textureRegistry_.get(block.getTextureId())) {
                blockTexture = *optional;
                texture.update(blockTexture, (x - area.left) * 16, (((area.height - 1 - y - area.top)) * 16));
            }
            else {
                throw std::runtime_error("No texture registered with id " + block.getTextureId());
            }
        }
    }
    return texture;
}