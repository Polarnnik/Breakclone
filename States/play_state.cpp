//
// Created by polarnik on 12.11.2024.
//
#include "play_state.h"
#include "../window.h"
#include "main_screen.h"
#include <stdexcept>

PlayState::PlayState(App* app) 
    : app_(app)
    , ball_(app) {
    if (!app) {
        throw std::invalid_argument("App pointer cannot be null");
    }
    InitGame();
}

void PlayState::Render() {
    ClearBackground(BLACK);
    DrawRectangleRec(paddle_, RAYWHITE);
    ball_.Render();

    for (const auto& brick : bricks_) {
        DrawRectangleRec(brick, PURPLE);
    }
}

void PlayState::HandleInput() {
    if (IsKeyDown(KEY_A)) {
        if (paddle_.x > 0.0f) {
            paddle_.x -= BreakClone::kDefaultPaddleSpeed;
        }
    }
    if (IsKeyDown(KEY_D)) {
        if (paddle_.x + paddle_.width < Window::GetWidth()) {
            paddle_.x += BreakClone::kDefaultPaddleSpeed;
        }
    }
}

void PlayState::Logic() {
    ball_.Move();
    CheckCollisions();
}

void PlayState::CheckCollisions() noexcept {
    if (CheckCollisionCircleRec(ball_.GetPosition(), ball_.GetRadius(), paddle_)) {
        ball_.ReflectVelocity();
    }

    for (auto it = bricks_.begin(); it != bricks_.end(); ) {
        if (CheckCollisionCircleRec(ball_.GetPosition(), ball_.GetRadius(), *it)) {
            ball_.ReflectVelocity();
            it = bricks_.erase(it);
            
            if (bricks_.empty()) {
                try {
                    app_->ChangeState(std::make_unique<MainScreen>(app_));
                } catch (const std::exception& e) {
                    // todo!(): Log error and handle gracefully :D
                }
            }
        } else {
            ++it;
        }
    }
}

void PlayState::InitGame() {
    paddle_ = {
        static_cast<float>(Window::GetWidth()) / 2.0f - BreakClone::kDefaultPaddleWidth / 2.0f,
        static_cast<float>(Window::GetHeight()) - BreakClone::kDefaultPaddleY,
        BreakClone::kDefaultPaddleWidth,
        BreakClone::kDefaultPaddleHeight
    };

    bricks_.clear();
    const float brick_width = static_cast<float>(Window::GetWidth()) / BreakClone::kDefaultBrickCols;

    bricks_.reserve(BreakClone::kDefaultBrickRows * BreakClone::kDefaultBrickCols);
    for (int32_t row = 0; row < BreakClone::kDefaultBrickRows; ++row) {
        for (int32_t col = 0; col < BreakClone::kDefaultBrickCols; ++col) {
            bricks_.push_back({
                col * brick_width,
                row * BreakClone::kDefaultBrickHeight,
                brick_width - BreakClone::kDefaultBrickSpacing,
                BreakClone::kDefaultBrickHeight - BreakClone::kDefaultBrickSpacing
            });
        }
    }
}