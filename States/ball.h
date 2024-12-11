//
// Created by pola on 19.11.2024.
//
#ifndef BREAKCLONE_BALL_H
#define BREAKCLONE_BALL_H

#include <memory>
#include <random>
#include <raylib.h>
#include "../app.h"
#include "../constants.h"

class Ball {
public:
    explicit Ball(App* app);
    Ball(const Ball&) = delete;
    Ball& operator=(const Ball&) = delete;
    Ball(Ball&&) = default;
    Ball& operator=(Ball&&) = default;
    ~Ball() = default;

    void Render() const noexcept;
    void Move() noexcept;
    void ReflectVelocity() noexcept;
    [[nodiscard]] Vector2 GetPosition() const noexcept { return position_; }
    [[nodiscard]] float GetRadius() const noexcept { return radius_; }

private:
    [[nodiscard]] static Vector2 GetRandomDirection() noexcept;
    
    App* const app_;
    Vector2 velocity_;
    Vector2 position_;
    const float radius_;
    static std::random_device rd_;
    static std::mt19937 gen_;
};

#endif // BREAKCLONE_BALL_H
