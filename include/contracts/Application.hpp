/*
    -------------------------
    Application.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "GameState.hpp"
#include "../core/GameStateStack.hpp"

/*
Interface décrivant une application
*/
class Application {
    public:
    /*
    Lance l'application et retourne un code indiquant s'il y a eu des erreurs durant l'exécution.
    */
    virtual int launch() noexcept = 0;

    virtual GameStateStack& gameStateStack() = 0;

    /*
    Quitte l'application
    */
    virtual void exit() = 0;

    virtual ~Application() = 0;
};