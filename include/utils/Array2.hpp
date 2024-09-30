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

    Array2(const std::vector<std::vector<T>>& array, sf::Vector2i origin): origin_(origin) {
        array_.resize(array.size());
        
        for (int j = 0; j < array.size(); ++j) {
            for (int i = 0; i < array.at(j).size(); ++i) {
                array_.at(j).push_back(array.at(j).at(i));
            }
        }
    }

    Array2(Array2&& other): array_(std::move(other.array_)), origin_(std::move(other.origin_)) {}

    Array2(const Array2& other) = delete;
    
    void set(int x, int y, T id) {
        array_.at(origin_.y + y).at(origin_.x + x) = id; 
    }

    T at(int x, int y) const {
        return array_.at(origin_.y + y).at(origin_.x + x);
    }

    unsigned int width() const {
        return array_.empty() ? 0 : array_.back().size();
    }

    unsigned int height() const {
        return array_.size();
    }
};