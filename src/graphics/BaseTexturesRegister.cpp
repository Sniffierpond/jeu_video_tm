/*
    -------------------------
    BaseTextureRegister.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/BaseTexturesRegister.hpp"
#include "../../include/persistence/TextureLoader.hpp"

void BaseTexturesRegister::registerTextures(TextureRegistry& registry) {
    TextureLoader loader;

    registry.registerElement("base:bricks", loader.load("resources/bricks.png"));
    registry.registerElement("base:dirt:1", loader.load("resources/dirt1.png"));
    registry.registerElement("base:dirt:2", loader.load("resources/dirt2.png"));
    registry.registerElement("base:dirt:3", loader.load("resources/dirt3.png"));
    registry.registerElement("base:grass:1", loader.load("resources/grass1.png"));
    registry.registerElement("base:grass:2", loader.load("resources/grass2.png"));
    registry.registerElement("base:grass:3", loader.load("resources/grass3.png"));
    registry.registerElement("base:leaves", loader.load("resources/leaves.png"));
    registry.registerElement("base:sand", loader.load("resources/sand.png"));
    registry.registerElement("base:stone", loader.load("resources/stone.png"));
    registry.registerElement("base:tree_log", loader.load("resources/tree_log.png"));
    registry.registerElement("base:player", loader.load("resources/player.png"));
    registry.registerElement("base:player:walkingLeft:1", loader.load("resources/player_walking_left_1.png"));
    registry.registerElement("base:player:walkingLeft:2", loader.load("resources/player_walking_left_2.png"));
    registry.registerElement("base:player:walkingLeft:3", loader.load("resources/player_walking_left_3.png"));
    registry.registerElement("base:player:walkingRight:1", loader.load("resources/player_walking_right_1.png"));
    registry.registerElement("base:player:walkingRight:2", loader.load("resources/player_walking_right_2.png"));
    registry.registerElement("base:player:walkingRight:3", loader.load("resources/player_walking_right_3.png"));
    registry.registerElement("base:player:idle", loader.load("resources/player_idle.png"));

}