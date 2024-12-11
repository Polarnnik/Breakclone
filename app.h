//
// Created by polarnik on 13.10.2024.
//
#ifndef BREAKCLONE_APP_H
#define BREAKCLONE_APP_H

#include <memory>
#include "window.h"
#include "States/state.h"

class App {
public:
    App() = default;
    App(const App&) = delete;
    App& operator=(const App&) = delete;
    ~App() = default;

    void Init();
    void Run();
    void ChangeState(std::unique_ptr<GameState> state);

private:
    Window window_;
    std::unique_ptr<GameState> game_state_;

    void Logic();
    void Render();
    void HandleInput();
};

#endif // BREAKCLONE_APP_H