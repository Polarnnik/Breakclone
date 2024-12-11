//
// Created by polarnik on 13.10.2024.
//
#include "main_screen.h"
#include "play_state.h"
#include "../window.h"
#include <stdexcept>

MainScreen::MainScreen(App* app) 
    : app_(app)
    , selected_item_(MenuOption::kPlay) {
    if (!app) {
        throw std::invalid_argument("App pointer cannot be null");
    }
    InitMenuItems();
}

void MainScreen::Logic() {
    // todo!(): Implement if needed
}

void MainScreen::InitMenuItems() noexcept {
    const float start_y = Window::GetHeight() * kVerticalRatio;
    const float spacing = Window::GetHeight() * kSpacingRatio;

    menu_items_ = {{
        {"Play", {Window::GetWidth() * 0.5f, start_y}},
        {"Exit", {Window::GetWidth() * 0.5f, start_y + spacing * 2.0f}}
    }};
}

void MainScreen::Render() {
    ClearBackground(BLACK);
    
    const auto title_width = MeasureText(kTitle.data(), kTitleFontSize);
    DrawText(
        kTitle.data(), 
        Window::GetWidth() / 2 - title_width / 2,
        static_cast<int32_t>(Window::GetHeight() * 0.1f),
        kTitleFontSize, 
        GRAY
    );

    for (std::size_t i = 0; i < menu_items_.size(); ++i) {
        const auto& item = menu_items_[i];
        const Color text_color = (static_cast<std::size_t>(selected_item_) == i) ? PURPLE : GRAY;
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), item.text.c_str(), kMenuFontSize, 1.0f);
        
        DrawText(
            item.text.c_str(),
            static_cast<int32_t>(item.position.x - text_size.x / 2.0f),
            static_cast<int32_t>(item.position.y - text_size.y / 2.0f),
            kMenuFontSize,
            text_color
        );
    }
}

void MainScreen::HandleInput() {
    if (IsKeyPressed(KEY_W)) {
        MoveSelection(1);
    }
    if (IsKeyPressed(KEY_S)) {
        MoveSelection(-1);
    }
    if (IsKeyPressed(KEY_ENTER)) {
        ExecuteOption();
    }
}

void MainScreen::MoveSelection(int32_t direction) noexcept {
    const auto menu_size = static_cast<int32_t>(menu_items_.size());
    auto current_selection = static_cast<int32_t>(selected_item_);
    current_selection = (current_selection + direction + menu_size) % menu_size;
    selected_item_ = static_cast<MenuOption>(current_selection);
}

void MainScreen::ExecuteOption() {
    switch (selected_item_) {
        case MenuOption::kPlay:
            try {
                app_->ChangeState(std::make_unique<PlayState>(app_));
            } catch (const std::exception& e) {
                // todo!(): Log error and handle gracefully :D
            }
            break;
        case MenuOption::kExit:
            CloseWindow();
            break;
    }
}