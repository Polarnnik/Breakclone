#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <raylib.h>


class Window {
public:
    Window() = default;
    void init(int width=800, int height=700, std::string title="Default");
    bool shouldClose() const;
    void close() const;
    static int getWidth();
    static int getHeight();
private:
    static int m_width, m_height;
};



#endif //WINDOW_H
