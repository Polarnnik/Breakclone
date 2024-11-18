//
// Created by polarnik on 12.11.2024.
//

#include "play_state.h"
#include "../window.h"
#include "main_screen.h"
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
        if (paddle.x > 0) {
            paddle.x -= 0.2;
        }
    }
    if (IsKeyDown(KEY_D)) {
        if (paddle.x + paddle.width < Window::getWidth()) {
            paddle.x += 0.2;
        }
    }
}

void PlayState::logic() {
    ball.move();
    checkCollisions();
}

void PlayState::checkCollisions() {
    if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), paddle)) {
        ball.reflectVelocity();
    }

    for (auto it = brics.begin(); it != brics.end(); ) {
        if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), *it)) {
            ball.reflectVelocity();

            it = brics.erase(it);
            if (brics.size() == 0) {
                m_app->changeState(std::make_unique<MainScreen>(m_app));
            }
        } else {
            ++it;
        }
    }
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