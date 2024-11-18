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
    void changeState(std::shared_ptr<GameState> state);

    enum State {
        GameScreen,
        Game
    };
private:
    Window m_window;
    std::shared_ptr<GameState> m_gameState;

    void logic();
    void render();
    void handleInput();
};



#endif //APP_H
