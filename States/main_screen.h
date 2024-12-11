//
// Created by polarnik on 13.10.2024.
//
#ifndef BREAKCLONE_MAIN_SCREEN_H
#define BREAKCLONE_MAIN_SCREEN_H

#include <array>
#include <string>
#include <memory>
#include <string_view>
#include <raylib.h>
#include "state.h"
#include "../app.h"

class MainScreen final : public GameState {
public:
    explicit MainScreen(App* app);
    MainScreen(const MainScreen&) = delete;
    MainScreen& operator=(const MainScreen&) = delete;
    ~MainScreen() override = default;

    void Render() override;
    void Logic() override;
    void HandleInput() override;

private:
    enum class MenuOption : std::uint8_t {
        kPlay,
        kExit
    };

    struct MenuItem {
        std::string text;
        Vector2 position;
    };

    static constexpr std::size_t kMenuItemCount = 2;
    static constexpr float kVerticalRatio = 0.4f;
    static constexpr float kSpacingRatio = 0.1f;
    static constexpr int32_t kTitleFontSize = 80;
    static constexpr int32_t kMenuFontSize = 40;
    static constexpr std::string_view kTitle = "BREAKOUT";

    App* const app_;
    std::array<MenuItem, kMenuItemCount> menu_items_;
    MenuOption selected_item_;

    void InitMenuItems() noexcept;
    void ExecuteOption();
    void MoveSelection(int32_t direction) noexcept;
};

#endif // BREAKCLONE_MAIN_SCREEN_H