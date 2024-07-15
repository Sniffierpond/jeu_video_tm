/*
    -------------------------
    Expandable2DArray.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <deque>
#include <SFML/System/Vector2.hpp>

template <typename T>
/*
Classe représentant un tableau ayant la capacité d'être agrandi
NOTE: Le vecteur origin_ contient un index absolu alors que les paramètres x et y des fonctions at et set sont relatifs à l'origine.
*/
class Expandable2DArray {
    private:
    std::deque<std::deque<T>> array_;
    sf::Vector2i origin_;
    public:
    Expandable2DArray(): origin_(0, 0) {
        array_.emplace_back();
    }

    Expandable2DArray(Expandable2DArray<T>& t) {
        array_ = t.array_;
        origin_ = t.origin_;
    }


    /*
    Retourne une référence à l'objet situé à l'index x et y
    */
    T& at(int x, int y) {
        return array_.at(origin_.y + y).at(origin_.x + x);
    }

    const T& at(int x, int y) const {
        return array_.at(origin_.y + y).at(origin_.x + x);
    }
    

    /*
    Remplace l'objet situé à l'index x et y par l'objet T.
    Si l'index se situe en dehors du tableau, agrandi automatiquement le tableau et remplit les indexes vides avec l'objet fillingObject.
    */
    void set(T t, int x, int y, T fillingObject) {
        while (origin_.x + x < 0) {
            for (auto it = array_.begin(); it != array_.end(); ++it) {
                it->push_front(fillingObject);
            }
            origin_.x++;
        }

        while (origin_.x + x >= array_.size()) {
            for (auto it = array_.begin(); it != array_.end(); ++it) {
                it->push_back(fillingObject);
            }
        }

        while (origin_.y + y < 0) {
            array_.emplace_front(getWidth(), fillingObject);

            origin_.y++;
        }
        
        while (origin_.y + y >= getHeight()) {
            array_.emplace_back(getWidth(), fillingObject);
        }

        array_.at(origin_.x + x).at(origin_.y + y) = t;
    }


    int getWidth() const {
        return array_.empty() ? 0 :array_.begin()->size();
    }

    int getHeight() const {
        return array_.size();
    }
};