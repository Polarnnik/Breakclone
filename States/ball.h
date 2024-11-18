//
// Created by pola on 19.11.2024.
//

#ifndef BREAKCLONE_BALL_H
#define BREAKCLONE_BALL_H


#include <raylib.h>
#include "../app.h"

class Ball {
public:
    Ball(App* app);
    void render();
    void move();
    void reflectVelocity();
    Vector2 getPosition();
    float getRadius();
private:
    App* m_app;
    Vector2 velocity;
    Vector2 position;
    float radius;

    Vector2 getRandomDirection();
};


#endif //BREAKCLONE_BALL_H
