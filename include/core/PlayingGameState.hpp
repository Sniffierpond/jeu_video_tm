/*
    -------------------------
    PlayingGameState.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/GameState.hpp"
#include "../controller/GameController.hpp"
#include "../graphics/View.hpp"
#include "../controller/SfmlInputHandler.hpp"
#include "../graphics/LevelRenderer.hpp"
#include "../graphics/PlayerCamera.hpp"
#include "../physics/PlayerPhysicsHandler.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class PlayingGameState: public GameState {
    private:
    const Acceleration gravityAcceleration_ = 9.8_bps2;
    const Speed maxHorSpeed_ = 2.0_bps;
    const Speed maxVertSpeed_ = 5.0_bps;
    const Speed jumpSpeed_ = 5.0_bps;

    Level level_;
    Player player_;
    
    PlayerPhysicsHandler physicsHandler_;

    PlayerCamera camera_;
    LevelRenderer renderer_;
    View viewable_;
    SfmlInputHandler inputHandler_; 
    GameController controller_;

    bool active_ = false;
    bool paused_ = false;
    
    public:
    PlayingGameState(const TextureRegistry& textureRegistry, Level&& level_, sf::RenderWindow& window);

    void start() override;

    bool active() override;

    void update() override;

    void pause() override;
    void resume() override;

    bool paused() override;

    void stop() override;
};