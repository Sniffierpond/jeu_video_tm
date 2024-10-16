/*
    -------------------------
    EventHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "EventType.hpp"
#include "../contracts/EventListener.hpp"
#include <functional>
#include <vector>

class EventHandler {
    private:
    std::vector<std::pair<std::reference_wrapper<EventListener>, EventType>> listeners_;
    
    public:
    void registerListener(EventListener& listener, EventType eventType);
    void notify(Event& event);
};