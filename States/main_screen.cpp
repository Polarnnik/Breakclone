//
// Created by polarnik on 13.10.2024.
//
#include "main_screen.h"
#include "play_state.h"
#include <raylib.h>
#include "../window.h"

MainScreen::MainScreen(App* app) : m_app(app), m_selectedItem(MenuOption::Play) {
    initMenuItems();
}


void MainScreen::logic() {

}

void MainScreen::initMenuItems() {
    constexpr float verticalRatio = 0.4f;
    constexpr float spacingRatio = 0.1f;
    float startY = Window::getHeight() * verticalRatio;
    float spacing = Window::getHeight() * spacingRatio;

    m_menuItems = {{
        {"Play", {Window::getWidth() * 0.5f, startY}},
        {"Exit", {Window::getWidth() * 0.5f, startY + spacing * 2}}
    }};
}

void MainScreen::render() {
    ClearBackground(BLACK);
    
    constexpr int titleFontSize = 80;
    constexpr int menuFontSize = 40;
    const char* title = "BREAKOUT";
    
    DrawText(title, 
             Window::getWidth() / 2 - MeasureText(title, titleFontSize) / 2,
             static_cast<int>(Window::getHeight() * 0.1f),
             titleFontSize, 
             GRAY);

    for (size_t i = 0; i < m_menuItems.size(); ++i) {
        const auto& item = m_menuItems[i];
        Color textColor = (static_cast<size_t>(m_selectedItem) == i) ? PURPLE : GRAY;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), item.text.c_str(), menuFontSize, 1);
        
        DrawText(item.text.c_str(),
                 static_cast<int>(item.position.x - textSize.x / 2),
                 static_cast<int>(item.position.y - textSize.y / 2),
                 menuFontSize,
                 textColor);
    }
}

void MainScreen::handleInput() {
    if (IsKeyPressed(KEY_W)) {
        moveSelection(1);
    }
    if (IsKeyPressed(KEY_S)) {
        moveSelection(-1);
    }
    if (IsKeyPressed(KEY_ENTER)) {
        executeOption();
    }
}

void MainScreen::moveSelection(int direction) {
    const int menuSize = static_cast<int>(m_menuItems.size());
    int currentSelection = static_cast<int>(m_selectedItem);
    currentSelection = (currentSelection + direction + menuSize) % menuSize;
    m_selectedItem = static_cast<MenuOption>(currentSelection);
}

void MainScreen::executeOption() {
    switch (m_selectedItem) {
        case MenuOption::Play:
            m_app->changeState(std::make_unique<PlayState>(m_app));
            break;
        case MenuOption::Exit:
            CloseWindow();
            break;
    }
}
