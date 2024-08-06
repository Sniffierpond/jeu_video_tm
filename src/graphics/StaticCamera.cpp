/*
    -------------------------
    StaticCamera.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/StaticCamera.hpp"
#include <stdexcept>

StaticCamera::StaticCamera(sf::Vector2f position, float width, float height): position_(position), width_(width), height_(height) {};


void StaticCamera::setPosition(sf::Vector2f position) {
    position_ = position;
}

sf::Vector2f StaticCamera::getPosition() const {
    return position_;
}


void StaticCamera::setWidth(float width) {
    if (width >= 0) {
        width_ = width;
    }
    else {
        throw std::invalid_argument("Width cannot be negative.");
    }
}

float StaticCamera::getWidth() const {
    return width_;
}


void StaticCamera::setHeight(float height) {
    if (height >= 0) {
        height_ = height;
    }
    else {
        throw std::invalid_argument("Height cannot be negative.");
    }
}

float StaticCamera::getHeight() const {
    return height_;
}