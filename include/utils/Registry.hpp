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
Représente un registre
*/
template <typename T>
class Registry {
    private:
    std::map<std::string, T&> registry_;
    public:
    void registerElement(std::string id, T& t) {
        if (registry_.find(id) == registry_.end()) {
            throw std::runtime_error("Error: the block cannot be registered because it already is.");
        }
        else {
            registry_[id] = t;
        }
    }
    T& get(std::string id) const {
        return registry_.at(id);
    }
};