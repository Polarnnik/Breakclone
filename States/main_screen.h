//
// Created by polarnik on 13.10.2024.
//
#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <array>
#include <string>
#include <memory>
#include <raylib.h>
#include "state.h"
#include "../app.h"

class MainScreen : public GameState {
public:
    explicit MainScreen(App* app);
    void render() override;
    void logic() override;
    void handleInput() override;
    
private:
    enum class MenuOption {
        Play,
        Exit
    };

    struct MenuItem {
        std::string text;
        Vector2 position;
    };

    App* const m_app;
    std::array<MenuItem, 2> m_menuItems;
    MenuOption m_selectedItem;

    void initMenuItems();
    void executeOption();
    void moveSelection(int direction);
};

#endif //MAIN_SCREEN_H
