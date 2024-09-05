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

    texture.create(renderArea_.width * 16, renderArea_.height * 16);

    for (int x = floor(renderArea_.left); x < ceil(renderArea_.left + renderArea_.width); ++x) {
        for (int y = floor(renderArea_.top); y < ceil(renderArea_.top + renderArea_.height); ++y) {
            Block block = grid_.getBlock(sf::Vector2i(x, y));

            sf::Texture blockTexture;

            if (block.getBlockType() == "base:air") {}
            else if (const auto& optional = textureRegistry_.get(block.getTextureId())) {
                blockTexture = *optional;

                if (blockTexture.getSize().x != 16 || blockTexture.getSize().y != 16 ) {
                    throw std::runtime_error("Block renderer cannot handle textures whose size is not 16x16 pixels.");
                }
                else {
                    //texture.update(blockTexture, (x - area.left) * 16, (((area.height - 1 - y - area.top)) * 16));
                    sf::Image blockTextureImage = blockTexture.copyToImage();

                    float wPart = 1;
                    float hPart = 1;
                    float relPosX = 0;
                    float relPosY = 0;

                    if (renderArea_.left - x > 0) { // si la coordonnée x se trouve avant le début de la zone de rendu
                        wPart = renderArea_.left - x;
                        relPosX = 1 - wPart;
                    }
                    else if (x - (renderArea_.left + renderArea_.width - 1) > 0) {  // si la coordonnée x se trouve après la fin de la zone de rendu
                        wPart = x - (renderArea_.left + renderArea_.width - 1);
                    }
                    
                    if (renderArea_.top - y > 0) { // si la coordonnée y se trouve avant le début de la zone de rendu
                        hPart = renderArea_.top - y;
                        relPosY = 1 - hPart;
                    }
                    else if (y - (renderArea_.top + renderArea_.height - 1) > 0) {  // si la coordonnée y se trouve après la fin de la zone de rendu
                        hPart = y - (renderArea_.top + renderArea_.height - 1);
                    }

                    sf::Image truncatedTextureImage;
                    truncatedTextureImage.copy(blockTextureImage, 0, 0, sf::IntRect(round(relPosX * 16), round(relPosY * 16), round(wPart * 16), round(hPart * 16)));

                    texture.update(truncatedTextureImage, x - floor(renderArea_.left) + round(relPosX * 16), y - floor(renderArea_.top) + round(relPosY * 16));
                }
            }
            else {
                throw std::runtime_error("No texture registered with id " + block.getTextureId());
            }
        }
    }
    return texture;
}