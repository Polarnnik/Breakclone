//
// Created by pola on 19.11.2024.
//
#include "ball.h"
#include "../window.h"
#include "main_screen.h"
#include <random>
#include <chrono>
#include <raymath.h>

Ball::Ball(App* app): 
    m_app(app),
    position{static_cast<float>(Window::getWidth()) / 2 - 5, static_cast<float>(Window::getHeight()) / 2 - 5},
    radius(10.0f),
    velocity(getRandomDirection()) {
}

void Ball::move() {
    position.x += velocity.x;
    position.y += velocity.y;

    constexpr float border = 0.0f;
    if (position.x - radius <= border || position.x + radius >= Window::getWidth()) {
        velocity.x *= -1;
    }
    if (position.y - radius <= border) {
        velocity.y *= -1;
    }
    if (position.y - radius > Window::getHeight()) {
        m_app->changeState(std::make_unique<MainScreen>(m_app));
    }
}

void Ball::render() {
    DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, RED);
}

Vector2 Ball::getRandomDirection() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(0.0f, 4.0f * PI);
    
    float angle = dis(gen);
    Vector2 direction = {std::cos(angle), std::sin(angle)};
    direction = Vector2Normalize(direction);
    return Vector2Scale(direction, 0.1f);
}

void Ball::reflectVelocity() {
    velocity.y *= -1;
}

Vector2 Ball::getPosition() const {
    return position;
}

float Ball::getRadius() const {
    return radius;
}
