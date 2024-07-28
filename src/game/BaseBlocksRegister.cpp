/*
    -------------------------
    BaseBlocksRegister.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/BaseBlocksRegister.hpp"
#include "../../include/game/SimpleBlockBuilder.hpp"

void BaseBlocksRegister::registerBlocks(BlockRegistry& registry) const {
    SimpleBlockBuilder builder;

    registry.registerElement("base:bricks", builder.setBlockType("base:bricks"));
    registry.registerElement("base:dirt:1", builder.setBlockType("base:dirt:1"));
    registry.registerElement("base:dirt:2", builder.setBlockType("base:dirt:2"));
    registry.registerElement("base:dirt:3", builder.setBlockType("base:dirt:3"));
    registry.registerElement("base:grass:1", builder.setBlockType("base:grass:1"));
    registry.registerElement("base:grass:2", builder.setBlockType("base:grass:2"));
    registry.registerElement("base:grass:3", builder.setBlockType("base:grass:3"));
    registry.registerElement("base:leaves", builder.setBlockType("base:leaves"));
    registry.registerElement("base:sand", builder.setBlockType("base:sand"));
    registry.registerElement("base:stone", builder.setBlockType("base:stone"));
    registry.registerElement("base:tree_log", builder.setBlockType("base:tree_log"));
}