/*
    -------------------------
    EventHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/EventHandler.hpp"
#include <tuple>

void EventHandler::registerListener(EventListener& listener, EventType eventType) {
    listeners_.push_back(std::make_pair(std::reference_wrapper(listener), eventType));
}

void EventHandler::notify(Event& event) {
    for (auto& element: listeners_) {
        if (event.eventType().is(element.second)) {
            element.first.get().onEvent(event);
        }
    }
}