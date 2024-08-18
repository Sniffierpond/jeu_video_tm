/*
    -------------------------
    Array2.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
template <typename T>
class Array2 {
    private:
    std::vector<std::vector<T>> array_;
    sf::Vector2i origin_;

    public:
    Array2(sf::Vector2i origin, unsigned int width, unsigned int height, T fill = T()): origin_(origin) {
        array_.resize(height);
        
        for (auto element : array_) {
            for (int i = 0; i < width; ++i) {
                element.push_back(fill);
            }
        }
    }

    Array2(const std::vector<std::vector<T>>& array, sf::Vector2i origin): array_(array), origin_(origin) {}

    T& at(int x, int y) {
        return array_.at(origin_.y + y).at(origin_.x + x);
    }

    const T& at(int x, int y) const {
        return at(x, y);
    }
};