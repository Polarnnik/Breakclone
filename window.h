//
// Created by polarnik on 13.10.2024.
//
#ifndef BREAKCLONE_WINDOW_H
#define BREAKCLONE_WINDOW_H

#include <string>
#include <string_view>
#include <raylib.h>
#include "constants.h"

class Window {
public:
    Window() = default;
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    ~Window() = default;

    void Init(int32_t width = BreakClone::kDefaultWindowWidth,
             int32_t height = BreakClone::kDefaultWindowHeight,
             std::string_view title = "Default");
    [[nodiscard]] bool ShouldClose() const noexcept;
    void Close() const noexcept;
    [[nodiscard]] static int32_t GetWidth() noexcept;
    [[nodiscard]] static int32_t GetHeight() noexcept;

private:
    static int32_t width_;
    static int32_t height_;
};

#endif // BREAKCLONE_WINDOW_H
