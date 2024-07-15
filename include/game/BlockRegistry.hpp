/*
    -------------------------
    BlockRegistry.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <map>
#include "../contracts/BlockBuilder.hpp"
#include "../utils/Registry.hpp"

using BlockRegistry = Registry<BlockBuilder>;