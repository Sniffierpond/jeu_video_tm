/*
    -------------------------
    InputHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

class Controller;

/*
Gère la lecture des entrées de l'utilisateur qu'il peut ensuite envoyer au Controller
*/
class InputHandler {
    public:
    virtual void setController(Controller& controller) = 0;
    /*
    Traite les entrées de l'utilisateur et appelle les méthodes correspondantes du contrôleur.
    */
    virtual void handleInputs() = 0;

    virtual ~InputHandler() = 0;
};