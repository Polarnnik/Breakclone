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

    for (const auto& brick : bricks) {
        DrawRectangleRec(brick, PURPLE);
    }
}

void PlayState::handleInput() {
    if (IsKeyDown(KEY_A)) {
        if (paddle.x > 0) {
            paddle.x -= PADDLE_SPEED;
        }
    }
    if (IsKeyDown(KEY_D)) {
        if (paddle.x + paddle.width < Window::getWidth()) {
            paddle.x += PADDLE_SPEED;
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

    for (auto it = bricks.begin(); it != bricks.end(); ) {
        if (CheckCollisionCircleRec(ball.getPosition(), ball.getRadius(), *it)) {
            ball.reflectVelocity();
            it = bricks.erase(it);
            
            if (bricks.empty()) {
                m_app->changeState(std::make_unique<MainScreen>(m_app));
            }
        } else {
            ++it;
        }
    }
}

void PlayState::initGame() {
    constexpr float paddleWidth = 100.0f;
    constexpr float paddleHeight = 20.0f;
    constexpr float paddleY = 30.0f;
    
    paddle = {
        static_cast<float>(Window::getWidth()) / 2 - paddleWidth / 2,
        static_cast<float>(Window::getHeight()) - paddleY,
        paddleWidth,
        paddleHeight
    };

    bricks.clear();
    constexpr int rows = 5;
    constexpr int cols = 10;
    constexpr float brickSpacing = 5.0f;
    
    const float brickWidth = static_cast<float>(Window::getWidth()) / cols;
    constexpr float brickHeight = 20.0f;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            bricks.push_back({
                col * brickWidth,
                row * brickHeight,
                brickWidth - brickSpacing,
                brickHeight - brickSpacing
            });
        }
    }
}
