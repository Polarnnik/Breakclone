//
// Created by polarnik on 13.10.2024.
//

#include "main_screen.h"

#include "play_state.h"
#include <raylib.h>
#include "../window.h"

MainScreen::MainScreen(App* app) : m_app(app){
    initMenuItems();
}


void MainScreen::logic() {

}

void MainScreen::initMenuItems() {
    float startY = Window::getHeight() * 0.4f;
    float spacing = Window::getHeight() * 0.1f;

    m_menuItems =  {{{"Play", {Window::getWidth() * 0.5f , startY}},
        {"Exit", {Window::getWidth() * 0.5f , startY + spacing * 2}}}};

    m_selectedItem = Play;
}

void MainScreen::render() {
    ClearBackground(BLACK);
    DrawText("BREAKOUT", Window::getWidth() / 2 - MeasureText("BREAKOUT", 80) / 2, Window::getHeight() * 0.1f, 80, GRAY);

    for (size_t i = 0; i < m_menuItems.size(); ++i) {
        const auto& item = m_menuItems[i];
        Color textColor = (i == static_cast<size_t>(m_selectedItem)) ? PURPLE : GRAY;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), item.text.c_str(), 40, 1);
        DrawText(item.text.c_str(),
                 static_cast<int>(item.position.x - textSize.x / 2),
                 static_cast<int>(item.position.y - textSize.y / 2),
                 40, textColor);
    }
}

void MainScreen::handleInput() {
    if (IsKeyPressed(KEY_DOWN)) {
        moveSelection(1);
    } else if (IsKeyPressed(KEY_UP)) {
        moveSelection(-1);
    } else if (IsKeyPressed(KEY_ENTER)) {
        executeOption();
    }
}

void MainScreen::moveSelection(int direction) {
    int newSelection = (static_cast<int>(m_selectedItem) + direction + m_menuItems.size()) % m_menuItems.size();
    m_selectedItem = static_cast<MenuOption>(newSelection);
}

void MainScreen::executeOption() {
    switch (m_selectedItem) {
        case Play: m_app->changeState(std::make_shared<PlayState>(m_app));
            break;
        case Exit: CloseWindow();
            break;
    }
}