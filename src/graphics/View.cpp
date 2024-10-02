/*
    -------------------------
    View.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/View.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

View::View(sf::RenderTarget& renderTarget, Renderer& renderer, unsigned int width, unsigned int height, sf::Vector2i windowPos0):renderTarget_(&renderTarget), renderer_(&renderer), width_(width), height_(height), windowPos0_(windowPos0) {}

void View::setRenderer(Renderer& renderer) {
    renderer_ = &renderer;
}

void View::refresh() {
    /* float rectHeight;
    float rectWidth, x, y; */
    float width =  renderTarget_->mapCoordsToPixel(sf::Vector2f(width_, 0)).x;
    float height = renderTarget_->mapCoordsToPixel(sf::Vector2f(0, height_)).y;

    renderTexture_.create(width, height);

    renderTexture_.clear(sf::Color::Transparent);
    renderer_->render(renderTexture_);
    renderTexture_.display();
    

    sf::Sprite sprite(renderTexture_.getTexture() );

    sprite.setScale(width_ / 1.0 / renderTexture_.getSize().x, height_ / 1.0 / renderTexture_.getSize().y);

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