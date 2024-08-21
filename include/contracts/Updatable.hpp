/*
    -------------------------
    Updatable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <chrono>

/*
Défini une interface pour un objet dont l'état est amené à changer dans le temps.
*/
class Updatable {
    public:
    /*
    timeDifference: nombre de millisecondes écoulées depuis le dernier appel de la méthode
    */
    virtual void update(std::chrono::nanoseconds timeDifference) = 0;

    virtual ~Updatable() = 0;
};