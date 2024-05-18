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
    virtual void handleInputs() = 0;
};