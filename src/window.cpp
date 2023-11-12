#include "window.h"
#include <iostream>
#include "headers.h"
#include "consts.h"
#include "triangle.h"
#include "camera.h"



Window::Window(const std::string& title):m_running(false) {

    m_window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), title);
    GLenum err = glewInit();

    if(err != GLEW_OK) {
        std::cerr << "Could not init glew\n";
        exit(1);
    }



    glEnable(GL_DEPTH_TEST);
    

    m_triangle = new Triangle();
    Camera::get_instance()->init(glm::vec3(0.0f, 0.0f, 4.0f));


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
            handle_event(frame_per_seconds.asSeconds());
            update(frame_per_seconds.asSeconds());
            time_since_last_frame -= frame_per_seconds;

        }

        render();

    }

    m_window->close();

}

void Window::handle_event(float delta_time) {
    sf::Event event;

    while(m_window->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_running = false;

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                m_running = false;
                break;

            }

            if(event.key.code == sf::Keyboard::W) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Forward, delta_time);

            if(event.key.code == sf::Keyboard::S) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Backward, delta_time);

            if(event.key.code == sf::Keyboard::A) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Left, delta_time);

            if(event.key.code == sf::Keyboard::D) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Right, delta_time);
            

        }


    }

}


void Window::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    m_triangle->render();
    m_window->display();

}


void Window::update(float delta_time) {
    Camera::get_instance()->update_camera_vectors();
    m_triangle->update();
}
