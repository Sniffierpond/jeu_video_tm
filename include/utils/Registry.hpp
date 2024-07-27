/*
    -------------------------
    Registry.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <map>
#include <stdexcept>
#include <string>

/*
Représente un registre stockant des références sur des objets associées à des identifiants
sous forme de chaîne de caractères
*/
template <typename T>
class Registry {
    private:
    std::map<std::string, T> registry_;
    public:
    /*
    Enregistre la copie d'un élément (t) à l'aide de son identifiant (id)
    */
    void registerElement(const std::string& id, const T& t) {
        if (registry_.find(id) != registry_.end()) {
            throw std::runtime_error("Error: the element cannot be registered because it already is.");
        }
        else {
            registry_[id] = t;
        }
    }
    /*
    Récupère un élément à l'aide de son identifiant (id)
    */
    const T& get(const std::string& id) const {
        if (registry_.find(id) == registry_.end()) {
            throw std::runtime_error("Error: The element with the given id isn't registered");
        }
        return registry_.at(id);
    }
};