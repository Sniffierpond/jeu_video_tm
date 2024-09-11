/*
    -------------------------
    PlayingGameState.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/GameState.hpp"
#include "../controller/CameraController.hpp"
#include "../graphics/View.hpp"
#include "../controller/SfmlInputHandler.hpp"
#include "../graphics/LevelRenderer.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class PlayingGameState: public GameState {
    private:
    Level level_;

    MovableCamera camera_;
    LevelRenderer renderer_;
    View viewable_;
    SfmlInputHandler inputHandler_; 
    CameraController controller_;

    bool active_ = false;
    bool paused_ = false;
    
    public:
    PlayingGameState(const TextureRegistry& textureRegistry, Level&& level, sf::RenderWindow& window);

    void start() override;

    bool active() override;

    void update() override;

    void pause() override;
    void resume() override;

    bool paused() override;

    void stop() override;
};