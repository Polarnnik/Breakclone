//
// Created by polarnik on 13.10.2024.
//

#ifndef APP_H
#define APP_H
#include <memory>

#include "window.h"
#include "States/state.h"


class App {
public:
    void init();
    void run();
    void changeState(std::unique_ptr<GameState> state);

private:
    Window m_window;
    std::unique_ptr<GameState> m_gameState;

    void logic();
    void render();
    void handleInput();
};



#endif //APP_H
