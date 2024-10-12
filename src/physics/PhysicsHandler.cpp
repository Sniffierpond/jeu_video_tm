/*
    -------------------------
    PhysicsHandler.cpp
    auteur: Jonathan Rochat                                                         
    -------------------------
*/

#include "../../include/physics/PhysicsHandler.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <vector>

sf::Vector2i PhysicsHandler::getMovementDirection(sf::Vector2f trajectory) {
    return sf::Vector2i(
        trajectory.x == 0 ? 0 : trajectory.x / std::abs(trajectory.x),
        trajectory.y == 0 ? 0 : trajectory.y / std::abs(trajectory.y)
    );
}


bool PhysicsHandler::collidesOnlyInX(sf::Vector2f pos0) {
    sf::Vector2f pos1 = movementHandler_->getPosition();

    return !collides({pos0.x, pos1.y}) && collides(pos1);
}

bool PhysicsHandler::collidesOnlyInY(sf::Vector2f pos0) {
    sf::Vector2f pos1 = movementHandler_->getPosition();

    return !collides({pos1.x, pos0.y}) && collides(pos1);
}

bool PhysicsHandler::collides(sf::Vector2f pos) {
    sf::FloatRect hitBoxArea(
        pos.x + hitBox_.left,
        pos.y + hitBox_.top,
        hitBox_.width,
        hitBox_.height
    );

    BlockGrid blocks = level_->getBlocks(sf::IntRect(
        std::floor(hitBoxArea.left),
        std::floor(hitBoxArea.top),
        std::ceil(hitBoxArea.left + hitBoxArea.width) - std::floor(hitBoxArea.left), 
        std::ceil(hitBoxArea.top + hitBoxArea.height) - std::floor(hitBoxArea.top)
    ));

    for (int x = 0; x < blocks.getWidth(); ++x) {
        for (int y = 0; y < blocks.getHeight(); ++y) {
            if ((blocks.getBlock({x, y}).getBlockType() != "base:air")) {
                std::cout << "Collision en {" << pos.x << ";" << pos.y  << "}" << std::endl;
                return true;
            }
        }
    }

    return false;
}


PhysicsHandler::PhysicsHandler(Acceleration gravityAcceleration, Speed maxHorSpeed, Speed maxVertSpeed, sf::FloatRect hitBox, MovementHandler& movementHandler, const Level& level):
    gravityAcceleration_(gravityAcceleration),
    maxHorSpeed_(maxHorSpeed),
    maxVertSpeed_(maxVertSpeed),
    hitBox_(hitBox),
    movementHandler_(&movementHandler),
    level_(&level)
{
    movementHandler_->setAcceleration({0.0_bps2, -gravityAcceleration_});
    std::cout << "jkdjf";
}

void PhysicsHandler::update(std::chrono::nanoseconds timeDifference) {
    sf::Vector2f pos0 = movementHandler_->getPosition();
    
    if (std::abs(movementHandler_->getSpeed().x.getSpeed(Speed::bps)) > maxHorSpeed_.getSpeed(Speed::bps)) {
        movementHandler_->setSpeed({maxHorSpeed_ * movementHandler_->getSpeed().x.getSpeed(Speed::bps) / std::abs(movementHandler_->getSpeed().x.getSpeed(Speed::bps)), movementHandler_->getSpeed().y});
    }
    if (std::abs(movementHandler_->getSpeed().y.getSpeed(Speed::bps)) > maxVertSpeed_.getSpeed(Speed::bps)) {
        movementHandler_->setSpeed({movementHandler_->getSpeed().x, maxVertSpeed_ * movementHandler_->getSpeed().y.getSpeed(Speed::bps) / std::abs(movementHandler_->getSpeed().y.getSpeed(Speed::bps))});
    }

    movementHandler_->update(timeDifference);

    sf::Vector2f pos1 = movementHandler_->getPosition();
    
    sf::Vector2f trajectory = pos1 - pos0;
    sf::Vector2i direction = getMovementDirection(trajectory);

    sf::Vector2f newPos1 = pos1;

    if (!collidesOnlyInX(pos0) && !collidesOnlyInY(pos0) && collides(pos1)) {    // si l'objet est en collision à la fois en x et en y
        newPos1.x = direction.x > 0 ? std::floor(pos1.x) - hitBox_.left : std::ceil(pos1.x) + hitBox_.left;
        newPos1.y = direction.y > 0 ? std::floor(pos1.y) - hitBox_.top : std::ceil(pos1.y) + hitBox_.top;

        movementHandler_->setSpeed({0.0_bps, 0.0_bps});
    }
    else if (collidesOnlyInX(pos0)) {
        newPos1.x = direction.x > 0 ? std::floor(pos1.x) - hitBox_.left : std::ceil(pos1.x) + hitBox_.left;

        movementHandler_->setSpeed({0.0_bps, movementHandler_->getSpeed().y});
    }
    else if (collidesOnlyInY(pos0)) {
        newPos1.y = direction.y > 0 ? std::floor(pos1.y) - hitBox_.top : std::ceil(pos1.y) + hitBox_.top;

        movementHandler_->setSpeed({movementHandler_->getSpeed().x, 0.0_bps});
    }

    movementHandler_->setPosition(newPos1);
}