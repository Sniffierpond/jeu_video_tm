/*
    -------------------------
    Event.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../core/EventType.hpp"

class Event {
    public:
    virtual const EventType& eventType() = 0;

    virtual ~Event() = 0;
};