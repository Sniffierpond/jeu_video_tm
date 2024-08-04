/*
    -------------------------
    View.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/View.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

View::View(sf::RenderTarget& renderTarget, Renderer& renderer, unsigned int width, unsigned int height, sf::Vector2i windowPos0):renderTarget_(&renderTarget), renderer_(&renderer), width_(width), height_(height), windowPos0_(windowPos0) {}

void View::setRenderer(Renderer& renderer) {
    renderer_ = &renderer;
}

void View::refresh() {
    float rectHeight;
    float rectWidth, x, y;

    float width = renderTarget_->mapCoordsToPixel(sf::Vector2f(width_, 0)).x;
    float height = renderTarget_->mapCoordsToPixel(sf::Vector2f(0, height_)).y;


    sf::Texture texture = renderer_->render();

    if (texture.getSize().x / 1.0 / width * height >= texture.getSize().y) {
        rectHeight = texture.getSize().y;
        rectWidth = texture.getSize().y / 1.0 / height * width;
        x = (texture.getSize().x - rectWidth) / 2;
        y = 0;
    }
    else {
        rectWidth = texture.getSize().x;
        rectHeight = texture.getSize().x / 1.0 / width * height;
        y = (texture.getSize().y - rectHeight) / 2;
        x = 0;
    }

    sf::Sprite sprite(texture, sf::IntRect(x, y, rectWidth, rectHeight));

    sprite.setScale(width_ / 1.0 / sprite.getTextureRect().width, height_ / 1.0 / sprite.getTextureRect().height);

    sprite.setPosition(sf::Vector2f(windowPos0_));

    renderTarget_->draw(sprite);
}

unsigned int View::getWidth() {
    return width_;
}

unsigned int View::getHeight() {
    return height_;
}

sf::Vector2i View::getWindowPos0() {
    return windowPos0_;
}