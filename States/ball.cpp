//
// Created by pola on 19.11.2024.
//

#include "ball.h"
#include "../window.h"
#include "main_screen.h"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <raymath.h>

Ball::Ball(App* app): m_app(app) {
    position = {static_cast<float>(Window::getWidth()) / 2 - 5, static_cast<float>(Window::getHeight()) / 2 - 5};
    radius = 10;
    velocity = getRandomDirection();
}

void Ball::move() {
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x - radius <= 0 || position.x + radius >= Window::getWidth()) {
        velocity.x *= -1;
    }
    if (position.y - radius <= 0) {
        velocity.y *= -1;
    }
    if (position.y - radius > Window::getHeight()) {
        m_app->changeState(std::make_unique<MainScreen>(m_app));
    }
}

void Ball::render() {
    DrawCircle(position.x, position.y, radius, RED);
}

Vector2 Ball::getRandomDirection() {
    std::srand(std::time(0));
    
    float angle = static_cast<float>(std::rand()) / RAND_MAX * 4 * PI;

    Vector2 direction = {std::cos(angle), std::sin(angle)};
    direction = Vector2Normalize(direction);
    direction = Vector2Scale(direction, 0.1);
    return direction;
}
