//
// Created by polarnik on 12.11.2024.
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H
#include "state.h"
#include "../app.h"
#include "ball.h"
#include <vector>


class PlayState: public GameState{
public:
    PlayState(App* app);
    void render() override;
    void logic() override;
    void handleInput() override;
private:
    App* m_app;

    Rectangle paddle;
    Ball ball;
    std::vector<Rectangle> brics;

    void initGame();
    void checkCollisions();
};





#endif //PLAY_STATE_H
