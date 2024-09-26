/*
    -------------------------
    BlockRenderer.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/BlockRenderer.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>

BlockRenderer::BlockRenderer(const BlockGrid& grid, sf::FloatRect renderArea, const TextureRegistry& registry): grid_(grid), renderArea_(renderArea), textureRegistry_(registry) {
    if (renderArea_. width < 0 || renderArea_.height < 0) {
        throw std::invalid_argument("Size of the render area must not be negative.");
    }
    if (renderArea_.left + renderArea_.width > grid.getWidth() || renderArea_.top + renderArea_.height > grid.getHeight()) {
        throw std::invalid_argument("Render area must be contained in block grid area.");
    }
}

sf::Texture BlockRenderer::render() const {
    sf::Texture texture;
    texture.create(ceil(renderArea_.width * 16), ceil(renderArea_.height * 16));

    // endroit de la texture à partir duquel sera dessiné le prochain bloc
    sf::Vector2f texturePos;

    for (int y = grid_.getHeight() - 1; y >= 0; --y) {
        texturePos.x = 0;

        sf::IntRect blockRenderArea;

        if (0 < renderArea_.top - y && renderArea_.top - y < 1) {                                                   // si l'ordonnée est celle d'un bloc dans lequel commence la zone de rendu
            blockRenderArea.height = std::floor((renderArea_.top - y) * 16);
        }
        else if (renderArea_.top <= y && y <= renderArea_.top + renderArea_.height) {                               // si l'ordonnée est celle d'un bloc se trouvant dans la zone de rendu
            blockRenderArea.height = 16;
        }
        else if (0 < renderArea_.top + renderArea_.height - y && renderArea_.top + renderArea_.height - y < 1) {    // si l'ordonnée est celle d'un des derniers blocs se trouvant dans la zone de rendu
            blockRenderArea.top = std::floor((renderArea_.top + renderArea_.height - y) * 16);
            blockRenderArea.height = std::floor((1 - (renderArea_.top + renderArea_.height - y)) * 16);
        }

        for (int x = 0; x < grid_.getWidth(); ++x) {
            sf::Image blockImage;
 
            std::optional<sf::Texture> opt = textureRegistry_.get(grid_.getBlock({x, y}).getTextureId());
            if (grid_.getBlock({x, y}).getBlockType() == "base:air") {
                blockImage.create(16, 16);
            } 
            else if (opt.has_value()) {
                blockImage = opt->copyToImage();
            }
            else {
                std::string textureId = grid_.getBlock({x, y}).getTextureId();
                throw std::runtime_error("Texture \"" + grid_.getBlock({x, y}).getTextureId() + "\" not registered.");
            }

            if (0 < renderArea_.left - x && renderArea_.left - x < 1) {                                                 // si l'abscisse est celle d'un bloc dans lequel commence la zone de rendu
                blockRenderArea.width = std::floor((renderArea_.left - x) * 16);
            }
            else if (renderArea_.left <= x && x <= renderArea_.left + renderArea_.width) {                              // si l'abscisse est celle d'un bloc se trouvant dans la zone de rendu
                blockRenderArea.width = 16;
            }
            else if (0 < renderArea_.left + renderArea_.width - x && renderArea_.left + renderArea_.width - x < 1) {    // si l'absisse est celle d'un des derniers blocs se trouvant dans la zone de rendu
                blockRenderArea.left = std::floor((renderArea_.left + renderArea_.width - x) * 16);
                blockRenderArea.width = std::floor((1 - (renderArea_.left + renderArea_.width - x)) * 16);
            }

            sf::Image blockRenderedImage;
            blockRenderedImage.create(blockRenderArea.width, blockRenderArea.height);
            blockRenderedImage.copy(blockImage, 0, 0, blockRenderArea);

            assert(texturePos.x + blockRenderedImage.getSize().x <= texture.getSize().x);
            assert(texturePos.y + blockRenderedImage.getSize().y <= texture.getSize().y);

            texture.update(blockRenderedImage, texturePos.x, texturePos.y);

            texturePos.x += blockRenderArea.width;
        }

        texturePos.y += blockRenderArea.height;
    }

    return texture;
}