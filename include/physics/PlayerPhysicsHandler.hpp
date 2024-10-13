/*
    -------------------------
    PlayerPhysicsHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "PhysicsHandler.hpp"
#include "../game/Player.hpp"
#include <chrono>

class PlayerPhysicsHandler: public PhysicsHandler {
    private:
    Player& player_;
    Speed jumpSpeed_;

    bool goingLeft_ = false;
    bool goingRight_ = false;
    bool slowingDown_ = false;

    public:
    PlayerPhysicsHandler(Player& player, Acceleration gravityAcceleration, Speed maxHorSpeed, Speed maxVertSpeed, Speed jumpSpeed, const Level& level);

    void update(std::chrono::nanoseconds timeDifference) override;

    /*
    Fait débuter un mouvement vers la gauche au joueur.
    */
    void startGoingLeft();
    /*
    Fait débuter un mouvement vers la droite au joueur.
    */
    void startGoingRight();

    /*
    Le fait s'arrêter.
    */
    void stop();

    /*
    Le fait sauter.
    */
    void jump();
};