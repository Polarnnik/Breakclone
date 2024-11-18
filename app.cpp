//
// Created by polarnik on 13.10.2024.
//

#include "app.h"

#include <raylib.h>

#include "States/main_screen.h"

void App::init() {
    m_window.init(600, 400, "Breakout");
    m_gameState = std::make_shared<MainScreen>(this);
}

    void App::run() {
    while (!m_window.shouldClose()) {
        handleInput();
        logic();
        render();
    }
    m_window.close();
}

void App::logic() {
    m_gameState->logic();
}

void App::render() {
    BeginDrawing();
    m_gameState->render();

    EndDrawing();
}

void App::handleInput() {
    m_gameState->handleInput();
}

void App::changeState(std::shared_ptr<GameState> state) {
    m_gameState = std::move(state);
}
