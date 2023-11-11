#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class RenderWindow;
};

#include <string>

struct Triangle;

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event();
    void render();
    void update(float delta_time);


    sf::RenderWindow* m_window;
    Triangle* m_triangle;
    bool m_running;


};

#endif
