//
// Created by pola on 19.11.2024.
//
#include <stdexcept>
#include <raylib.h>
#include <raymath.h>
#include "ball.h"
#include "../window.h"
#include "main_screen.h"

std::random_device Ball::rd_;
std::mt19937 Ball::gen_(rd_());

Ball::Ball(App* app) 
    : app_(app)
    , position_{static_cast<float>(Window::GetWidth()) / 2.0f - BreakClone::kDefaultBallRadius / 2.0f,
               static_cast<float>(Window::GetHeight()) / 2.0f - BreakClone::kDefaultBallRadius / 2.0f}
    , radius_(BreakClone::kDefaultBallRadius)
    , velocity_(GetRandomDirection()) {
    if (!app) {
        throw std::invalid_argument("App pointer cannot be null");
    }
}

void Ball::Move() noexcept {
    position_.x += velocity_.x;
    position_.y += velocity_.y;

    const float border = 0.0f;
    if (position_.x - radius_ <= border || position_.x + radius_ >= Window::GetWidth()) {
        velocity_.x *= -1.0f;
    }
    if (position_.y - radius_ <= border) {
        velocity_.y *= -1.0f;
    }
    if (position_.y - radius_ > Window::GetHeight()) {
        try {
            app_->ChangeState(std::make_unique<MainScreen>(app_));
        } catch (const std::exception& e) {
            // todo!(): Log error and handle gracefully :D
        }
    }
}

void Ball::Render() const noexcept {
    DrawCircle(
        static_cast<int32_t>(position_.x),
        static_cast<int32_t>(position_.y),
        radius_,
        RED
    );
}

Vector2 Ball::GetRandomDirection() noexcept {
    static std::uniform_real_distribution<float> dis(0.0f, 4.0f * PI);
    const float angle = dis(gen_);
    Vector2 direction = {std::cos(angle), std::sin(angle)};
    direction = Vector2Normalize(direction);
    return Vector2Scale(direction, BreakClone::kDefaultBallSpeed);
}

void Ball::ReflectVelocity() noexcept {
    velocity_.y *= -1.0f;
}