#include "window.h"
#include <iostream>
#include "headers.h"
#include "consts.h"
#include "renderer.h"
//#include "chunk.h"
//#include "sphere_chunk.h"
//#include "noise_chunk.h"
#include "chunk_manager.h"

#include "camera.h"
#include "texture_atlas.h"
#include "light.h"



Window::Window(const std::string& title):m_running(false) {

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;


    m_window = new sf::Window(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default, settings);
    GLenum err = glewInit();

    if(err != GLEW_OK) {
        std::cerr << "Could not init glew\n";
        exit(1);
    }



    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    

    //Camera::get_instance()->init(glm::vec3(0.0f, 0.0f, 4.0f));
    Camera::get_instance()->init(glm::vec3(2.423f, 23.675f, -6.98538f));
    first_mouse_move = true;

    std::string texture_path = "../resources/atlas.jpg";

    if(!TextureAtlas::get_instance()->load(
            texture_path))
        std::cerr << "Could not load texture atlas " << texture_path << "\n";
    else
        std::cout << "Texture atlas loaded\n";

    TextureAtlas::get_instance()->num_rows = 2;
    TextureAtlas::get_instance()->total_textures = 4;




    m_renderer = new Renderer();

    chunk_manager = new ChunkManager(4);
    chunk_manager->update_instance_vbo(m_renderer);
    //m_chunk = new NoiseChunk();
    //m_chunk->init_render();
    //m_renderer->init_instance_vbo(m_chunk->current_render_models);
    m_light = new Light(glm::vec3(10.0f, 20.0f, 10.0f));

    m_renderer->init_light(m_light);



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

            if(event.key.code == sf::Keyboard::Up) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Up, delta_time);

            if(event.key.code == sf::Keyboard::Down) 
                Camera::get_instance()->handle_keyboard(Camera::Direction::Down, delta_time);
            

        }

        if(event.type == sf::Event::MouseMoved) {
            sf::Vector2i mouse_position =  sf::Mouse::getPosition();
            float mouse_pos_x = (float)mouse_position.x;
            float mouse_pos_y = (float)mouse_position.y;

            if(first_mouse_move) {
                last_mouse_x = mouse_pos_x;
                last_mouse_y = mouse_pos_y;
                first_mouse_move = false;
            }

            float x_offset = mouse_pos_x - last_mouse_x;
            float y_offset = last_mouse_y - mouse_pos_y;

            last_mouse_x = mouse_pos_x;
            last_mouse_y = mouse_pos_y;

            Camera::get_instance()->handle_mouse_movement(x_offset, y_offset);

        }

        if(event.type == sf::Event::MouseLeft)
            first_mouse_move = true;


    }

}


void Window::render() {

    if(!Camera::get_instance()->camera_moved)
        return;


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_renderer->bind_block_render();
    //m_chunk->render(m_renderer->m_chunk_shader);
    chunk_manager->render(m_renderer->m_chunk_shader);

    m_renderer->bind_light_render();
    m_light->render(m_renderer->m_light_shader);

    m_window->display();

}


void Window::update(float delta_time) {
    Camera::get_instance()->update_camera_vectors();
    Camera::get_instance()->update_camera_movement_flag();
}
