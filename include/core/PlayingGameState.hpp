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
    MovableCamera camera_;
    CameraController controller_;
    View viewable_;
    LevelRenderer renderer_;
    SfmlInputHandler inputHandler_;
    const Level& level_;

    bool active_ = false;
    bool paused_ = false;
    
    public:
    PlayingGameState(const TextureRegistry& textureRegistry, const Level& level, sf::RenderWindow& window);

    void start() override;

    bool active() override;

    void update() override;

    void pause() override;
    void resume() override;

    bool paused() override;

    void stop() override;
};