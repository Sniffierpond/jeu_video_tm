/*
    -------------------------
    Application.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "GameState.hpp"

/*
Interface décrivant une application
*/
class Application {
    public:
    /*
    Lance l'application et retourne un code indiquant s'il y a eu des erreurs durant l'exécution.
    */
    virtual int launch() = 0;

    /*
    Change l'état du jeu.
    */
    virtual void changeState(GameState& state) = 0;

    /*
    Quitte l'application
    */
    virtual void exit() = 0;
};