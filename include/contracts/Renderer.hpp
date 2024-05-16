/*
    -------------------------
    Renderer.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

class Viewable;

/*
Représente un objet effectuant le rendu de quelque chose.
*/
class Renderer {
    public:
    virtual void setViewable(Viewable& viewable) = 0;

    /*
    Effectue le rendu.
    */
    virtual void render() = 0;
};