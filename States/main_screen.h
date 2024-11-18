//
// Created by polarnik on 13.10.2024.
//

#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H
#include <memory>
#include "raylib/raylib.h"
#include <array>
#include "state.h"
#include "../app.h"
#include <string>


class MainScreen : public  GameState {
public:
    MainScreen(App* app);;
    void render() override;
    void logic() override;
    void handleInput() override;
    void initMenuItems();
    //void executeOption();
private:
    enum MenuOption {
        Play,
        Exit // Represents the number of options
    };

    struct MenuItem {
        std::string text;
        Vector2 position;
    };

    App* m_app;
    std::array<MenuItem, 3> m_menuItems;
    MenuOption m_selectedItem;
    void moveSelection(int direction);
};



#endif //MAIN_SCREEN_H
