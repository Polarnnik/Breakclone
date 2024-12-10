//
// Created by polarnik on 12.11.2024.
//
#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include <vector>
#include "state.h"
#include "../app.h"
#include "ball.h"

class PlayState: public GameState {
public:
    explicit PlayState(App* app);
    void render() override;
    void logic() override;
    void handleInput() override;
    
private:
    App* const m_app;
    Rectangle paddle;
    Ball ball;
    std::vector<Rectangle> bricks;

    void initGame();
    void checkCollisions();
    static constexpr float PADDLE_SPEED = 0.2f;
};

#endif //PLAY_STATE_H
