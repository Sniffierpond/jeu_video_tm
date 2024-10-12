/*
    -------------------------
    PhysicsHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Updatable.hpp"
#include "../game/Level.hpp"
#include "Acceleration.hpp"
#include "MovementHandler.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

/*
Calcule la physique d'un objet et met à jour son gestionnaire de mouvements.
*/
class PhysicsHandler: Updatable {
    private:
    const Acceleration gravityAcceleration_;

    const Speed maxHorSpeed_;
    const Speed maxVertSpeed_;

    /*
    La hitbox est définie par un rectangle dont les coordonnées sont celles "en bas à gauche" relatives à la position de l'objet.
    Exemple: pour un carré de 4 par 4 autour de l'objet: {-2;-2} 
    */
    const sf::FloatRect hitBox_;

    MovementHandler* movementHandler_;

    const Level* const level_;

    protected:
    /*
    Retourne un vecteur dont les composantes sont négatives (-1), nulles ou positives (1) en fonction de la direction de la trajectoire.
    */
    sf::Vector2i getMovementDirection(sf::Vector2f trajectory);
    /*
    Retourne si la hitbox est en collision avec des blocs uniquement à cause d'un mouvement en x.
    */
    bool collidesOnlyInX(sf::Vector2f pos0);
    /*
    Retourne si la hitbox est en collision avec des blocs uniquement à cause d'un mouvement en y.
    */
    bool collidesOnlyInY(sf::Vector2f pos0);

    /*
    Retourne si la hitbox est en collision avec des blocs à une position pos
    */
    bool collides(sf::Vector2f pos);

    public:
    PhysicsHandler(Acceleration gravityAcceleration, Speed maxHorSpeed, Speed maxVertSpeed, sf::FloatRect hitBox, MovementHandler& movementHandler, const Level& level);

    void update(std::chrono::nanoseconds timeDifference) override; 
};