#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class RenderWindow;
};

#include <string>

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event();
    void render();
    void update();


    sf::RenderWindow* m_window;
    bool m_running;


};

#endif
