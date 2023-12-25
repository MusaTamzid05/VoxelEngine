#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class Window;
};

#include <string>

struct Renderer;
struct ChunkManager;
struct Light;

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event(float delta_time);
    void render();
    void update(float delta_time);


    sf::Window* m_window;
    bool m_running;

    bool first_mouse_move;
    float last_mouse_x;
    float last_mouse_y;

    Renderer* m_renderer;
    ChunkManager* chunk_manager;
    Light* m_light;



};

#endif
