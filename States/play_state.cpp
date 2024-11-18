//
// Created by polarnik on 12.11.2024.
//

#include "play_state.h"
#include "../window.h"
#include <raylib.h>

PlayState::PlayState(App* app) : m_app(app), ball(app) {
    initGame();
}

void PlayState::render() {
    ClearBackground(BLACK);
    DrawRectangleRec(paddle, RAYWHITE);
    ball.render();

    for (const auto& brick : brics) {
        DrawRectangleRec(brick, PURPLE);
    }
}

void PlayState::handleInput() {
    if (IsKeyDown(KEY_A)) {
        paddle.x -= 0.2;
    }
    if (IsKeyDown(KEY_D)) {
            paddle.x += 0.2;
    }
}

void PlayState::logic() {
    ball.move();
}

void PlayState::checkCollisions() {

}

void PlayState::initGame() {
    paddle = {static_cast<float>(Window::getWidth()) / 2 - 50, static_cast<float>(Window::getHeight()) - 30, 100, 20};

    brics.clear();
    const int rows = 5;
    const int cols = 10;
    const float brickWidth = static_cast<float>(Window::getWidth()) / cols;
    const float brickHeight = 20.0f;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            brics.push_back({col * brickWidth, row * brickHeight, brickWidth - 5, brickHeight - 5});
        }
    }
}