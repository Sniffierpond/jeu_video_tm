/*
    -------------------------
    EventType.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/EventType.hpp"

void EventType::addEventType(std::string eventType) {
    eventTypes_.push_back(eventType);
}

bool EventType::is(const EventType& other) const {
    for (const auto& type: eventTypes_) {
        if (type == other.eventTypes_.back())
            return true;
    }

    return false;
}