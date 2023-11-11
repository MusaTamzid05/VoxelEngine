#include "window.h"
#include <iostream>
#include "headers.h"
#include "consts.h"
#include "triangle.h"



Window::Window(const std::string& title):m_running(false) {

    m_window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title);
    GLenum err = glewInit();

    if(err != GLEW_OK) {
        std::cerr << "Could not init glew\n";
        exit(1);
    }
    

    m_triangle = new Triangle();


}

Window::~Window() {
    delete m_window;

}

void Window::run() {
    m_running = true;


    sf::Clock clock;
    sf::Time frame_per_seconds = sf::seconds(1.0f / 60.0f);
    sf::Time time_since_last_frame = sf::Time::Zero;


    while(m_running) {
        sf::Time elased_time = clock.restart();
        time_since_last_frame += elased_time;

        while(time_since_last_frame > frame_per_seconds) {
            handle_event();
            update(frame_per_seconds.asSeconds());
            time_since_last_frame -= frame_per_seconds;

        }

        render();

    }

    m_window->close();

}

void Window::handle_event() {
    sf::Event event;

    while(m_window->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_running = false;

        if(event.type == sf::Event::KeyPressed)
            if(event.key.code == sf::Keyboard::Escape)
            m_running = false;


    }

}


void Window::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    m_triangle->render();

    m_window->display();

}


void Window::update(float delta_time) {
    std::cout << delta_time << "\n";

}
