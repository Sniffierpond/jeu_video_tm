/*
    -------------------------
    PlayerPhysicsHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/PlayerPhysicsHandler.hpp"
#include <SFML/System/Vector2.hpp>
#include <cmath>

PlayerPhysicsHandler::PlayerPhysicsHandler(Player& player, Acceleration gravityAcceleration, Speed maxHorSpeed, Speed maxVertSpeed, Speed jumpSpeed, const Level& level):
    player_(player),
    jumpSpeed_(jumpSpeed),
    PhysicsHandler(gravityAcceleration, maxHorSpeed, maxVertSpeed, {-0.5, 0, 1, 2}, player.movementHandler(), level)
{}

void PlayerPhysicsHandler::update(std::chrono::nanoseconds timeDifference) {
    PhysicsHandler::update(timeDifference);

    sf::Vector2<Speed> playerSpeed = player_.movementHandler().getSpeed();
    
    if (slowingDown_) {
        // contrôle que le joueur est sur une surface solide pour le faire ralentir
        if (collides({player_.movementHandler().getPosition().x, std::ceil(player_.movementHandler().getPosition().y - 1)})) {
            if (goingLeft_) {
                player_.movementHandler().setAcceleration({4.0_bps2, player_.movementHandler().getAcceleration().y});
            }
            else if (goingRight_) {
                player_.movementHandler().setAcceleration({-4.0_bps2, player_.movementHandler().getAcceleration().y});
            }
        }
        // si ce n'est pas le cas, arrête la déccélération du joueur
        else {
            if (goingLeft_) {
                player_.movementHandler().setAcceleration({1.0_bps2, player_.movementHandler().getAcceleration().y});
            }
            else if (goingRight_) {
                player_.movementHandler().setAcceleration({-1.0_bps2, player_.movementHandler().getAcceleration().y});
            }
        }

        // si le joueur était en train de ralentir et qu'il a atteint une vitesse nulle ou inverse à la direction dans laquelle il allait, arrête la déccélération
        // et rend la vitesse nulle.
        if ((goingLeft_ && playerSpeed.x.getSpeed(Speed::bps) >= 0) || (goingRight_ && playerSpeed.x.getSpeed(Speed::bps) <= 0)) {
            player_.movementHandler().setSpeed({0.0_bps, playerSpeed.y});
            player_.movementHandler().setAcceleration({0.0_bps2, player_.movementHandler().getAcceleration().y});

            goingLeft_ = false;
            goingRight_ = false;
            slowingDown_ = false;
        }
    }
    
    if (playerSpeed.y.getSpeed(Speed::bps) <= 0) {

        if (playerSpeed.y.getSpeed(Speed::bps) < 0) {
            player_.status() = Player::FALLING;
        }
        else {
            if (playerSpeed.x.getSpeed(Speed::bps) == 0) {
                player_.status() = Player::STANDING;
            }
            else {
                player_.status() = Player::WALKING;
            }
        }
    }
    else {
        player_.status() = Player::JUMPING;
    }
}

void PlayerPhysicsHandler::startGoingLeft() {
    if (!goingLeft_ || slowingDown_) {
        goingLeft_ = true;
        goingRight_ = false;
        slowingDown_ = false;

        player_.movementHandler().setAcceleration({-2.0_bps2, player_.movementHandler().getAcceleration().y});
    }
}

void PlayerPhysicsHandler::startGoingRight() {
    if (!goingRight_ || slowingDown_) {
        goingLeft_ = false;
        goingRight_ = true;
        slowingDown_ = false;

        player_.movementHandler().setAcceleration({2.0_bps2, player_.movementHandler().getAcceleration().y});
    }
}

void PlayerPhysicsHandler::stop() {
    slowingDown_ = true;
}

void PlayerPhysicsHandler::jump() {
    // fait sauter le joueur uniquement s'il se trouve sur une surface solide (pas déjà dans les airs)
    if (collides({player_.movementHandler().getPosition().x, std::ceil(player_.movementHandler().getPosition().y - 1)})) {
        player_.movementHandler().addSpeed({player_.movementHandler().getSpeed().x, jumpSpeed_});
    }
}