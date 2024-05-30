/*
    -------------------------
    View.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/View.hpp"

View::View(Renderer& renderer, unsigned int width, unsigned int height, sf::Vector2f windowPos0): renderer_(&renderer), width_(width), height_(height), windowPos0_(windowPos0) {
    renderer_->setViewable(*this);
}

void View::setRenderer(Renderer& renderer) {
    renderer_ = &renderer;
}

void View::refresh() {
    renderer_->render();
}

unsigned int View::getWidth() {
    return width_;
}

unsigned int View::getHeight() {
    return height_;
}

sf::Vector2f View::getWindowPos0() {
    return windowPos0_;
}