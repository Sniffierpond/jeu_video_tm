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
#include <memory>

/*
Représente un registre stockant des références sur des objets associées à des identifiants
sous forme de chaîne de caractères
*/
template <typename T1>
class Registry {
    private:
    std::map<std::string, std::unique_ptr<T1>> registry_;

    public:
    /*
    Enregistre la copie d'un élément (t) à l'aide de son identifiant (id)
    */
    template<typename T2>
    void registerElement(const std::string& id, const T2& t) {
        if (registry_.find(id) != registry_.end()) {
            throw std::runtime_error("Error: the element cannot be registered because it already is.");
        }
        else {
            registry_[id] = std::make_unique<T2>(t);
        }
    }
    /*
    Récupère un élément à l'aide de son identifiant (id)
    */
    const T1& get(const std::string& id) const {
        if (registry_.find(id) == registry_.end()) {
            throw std::runtime_error("Error: The element with the given id isn't registered");
        }
        return *registry_.at(id);
    }
};