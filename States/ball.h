//
// Created by pola on 19.11.2024.
//
#ifndef BREAKCLONE_BALL_H
#define BREAKCLONE_BALL_H

#include <raylib.h>
#include "../app.h"

class Ball {
public:
    explicit Ball(App* app);
    void render();
    void move();
    void reflectVelocity();
    Vector2 getPosition() const;
    float getRadius() const;
private:
    App* const m_app;
    Vector2 velocity;
    Vector2 position;
    const float radius;

    static Vector2 getRandomDirection();
};

#endif //BREAKCLONE_BALL_H
