//
// Created by polarnik on 13.10.2024.
//
#include "app.h"
#include <stdexcept>
#include "constants.h"
#include "States/main_screen.h"

void App::Init() {
    window_.Init(BreakClone::kDefaultWindowWidth, 
                BreakClone::kDefaultWindowHeight, 
                "Breakout");
    try {
        game_state_ = std::make_unique<MainScreen>(this);
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to initialize game state");
    }
}

void App::Run() {
    if (!game_state_) {
        throw std::runtime_error("Game state not initialized");
    }

    while (!window_.ShouldClose()) {
        HandleInput();
        Logic();
        Render();
    }
    window_.Close();
}

void App::Logic() {
    if (game_state_) {
        game_state_->Logic();
    }
}

void App::Render() {
    BeginDrawing();
    if (game_state_) {
        game_state_->Render();
    }
    EndDrawing();
}

void App::HandleInput() {
    if (game_state_) {
        game_state_->HandleInput();
    }
}

void App::ChangeState(std::unique_ptr<GameState> state) {
    if (!state) {
        throw std::invalid_argument("New game state cannot be null");
    }
    game_state_ = std::move(state);
}