/*
    -------------------------
    EventType.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <string>
#include <vector>

/*
Représente un type ou plusieurs types d'évènement.
*/
class EventType {
    private:
    std::vector<std::string> eventTypes_;
    
    public:
    void addEventType(std::string eventType);

    /*
    Indique si un type d'évènement est le même que "other" ou dérive d'"other" autre type.
    */
    bool is(const EventType& other) const;
}; 