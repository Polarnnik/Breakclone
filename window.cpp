#include "window.h"

#include <raylib/raylib.h>

int Window::m_width = 0;
int Window::m_height = 0;

void Window::init(int width, int height, std::string title) {
    InitWindow(width, height, title.c_str());
    m_width = width;
    m_height = height;

}

bool Window::shouldClose() const {
    return WindowShouldClose();
}

void Window::close() const {
    CloseWindow();
}

int Window::getHeight() {
    return m_height;
}
int Window::getWidth() {
    return m_width;
}
