/*
    -------------------------
    EventListener.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Event.hpp"

class EventListener {
    public:
    virtual void onEvent(Event& event) = 0;

    virtual ~EventListener() = 0;
};