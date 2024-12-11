//
// Created by polarnik on 13.10.2024.
//
#include "window.h"
#include <stdexcept>

int32_t Window::width_ = 0;
int32_t Window::height_ = 0;

void Window::Init(int32_t width, int32_t height, std::string_view title) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Window dimensions must be positive");
    }

    InitWindow(width, height, title.data());
    if (!IsWindowReady()) {
        throw std::runtime_error("Failed to initialize window");
    }

    width_ = width;
    height_ = height;
}

bool Window::ShouldClose() const noexcept {
    return WindowShouldClose();
}

void Window::Close() const noexcept {
    CloseWindow();
}

int32_t Window::GetHeight() noexcept {
    return height_;
}

int32_t Window::GetWidth() noexcept {
    return width_;
}