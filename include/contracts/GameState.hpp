/*
    -------------------------
    GameState.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Controller.hpp"

/*
Représente un "état" du jeu, par exemple lorsque le joueur est en train de jouer, ou lorsqu'il a mis le jeu en pause.
*/
class GameState {
    public:
    virtual void setController(Controller& controller) = 0;

    /*
    Initialise les ressources utilisées par l'état du jeu.
    */
    virtual void start() = 0;
    
    /*
    Si l'état est ou non actif
    */
    virtual bool active() = 0;
    /*
    Méthode exécutée par la boucle de l'application qui met à jour le contrôleur.
    */
    virtual void update() = 0;

    /*
    Met en "pause" l'état du jeu bien qu'il continue à afficher son contenu.
    */
    virtual void pause() = 0;
    /*
    Remet en route l'état du jeu qui était précédemment en pause
    */
    virtual void resume() = 0;

    /*
    Si le jeu est ou non en pause
    */
    virtual bool paused() = 0;

    /*
    Arrête l'état du jeu et libère la mémoire
    */
    virtual void stop();
};