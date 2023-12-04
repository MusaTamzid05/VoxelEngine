#include "camera.h"
#include "consts.h"
#include <cmath>
#include <iostream>


Camera* Camera::m_instance = nullptr;

Camera::Camera() {
    m_world_up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    m_up = glm::vec3(0.0f, 0.0f, 0.0f);
    m_yaw = -120.0f;
    m_pitch = -10.0f;
    zoom = 45.0f;
    m_speed = 20.f;
    m_sensitivity = 0.1f;

    camera_moved = false;
    m_camera_position_changed = true; // for first frame we want to 
                                      // render so we set camera movement to true
    m_camera_angle_changed = false;


}

void Camera::init(const glm::vec3& position) {
    m_position = position;
    update_camera_vectors();

}

void Camera::update_camera_vectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) *  cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) *  cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);

    m_right = glm::normalize(glm::cross(m_front, m_world_up));
    m_up = glm::normalize(glm::cross(m_right, m_front));

}


void Camera::update_camera_movement_flag() {
    if(m_camera_position_changed || m_camera_angle_changed) {
        camera_moved = true;
        m_camera_angle_changed = false;
        m_camera_position_changed = false;

    }
    else 
        camera_moved = false;

}

Camera* Camera::get_instance() {
    if(m_instance == nullptr)
        m_instance = new Camera();

    return m_instance;
}


glm::mat4 Camera::get_projection() const {
    return glm::perspective(
            glm::radians(zoom),
            (float) WIDTH / (float) HEIGHT,
            0.1f,
            100.0f
            );

}


glm::mat4 Camera::get_view() const {
    return glm::lookAt(m_position, m_position + m_front, m_up);

}

void Camera::handle_keyboard(const Direction& direction, float delta_time) {
    float velocity = m_speed * delta_time; // v = st

    if(direction == Direction::Forward)
        m_position += m_front * velocity;

    else if(direction == Direction::Backward)
        m_position -= m_front * velocity;

    if(direction == Direction::Left)
        m_position -= m_right * velocity;

    if(direction == Direction::Right)
        m_position += m_right * velocity;

    if(direction == Direction::Up)
        m_position += m_up * velocity;

    if(direction == Direction::Down)
        m_position -= m_up * velocity;

    m_camera_position_changed = true;


}

void Camera::handle_mouse_movement(float x_offset, float y_offset) {
    x_offset *= m_sensitivity;
    y_offset *= m_sensitivity;

    m_yaw += x_offset;
    m_pitch += y_offset;

    if(m_pitch > 89.0f)
        m_pitch = 89.0f;
    else if(m_pitch < -89.0f)
        m_pitch = -89.0f;


    m_camera_angle_changed = true;



}


glm::vec3 Camera::get_position() const {
    return m_position;
}
