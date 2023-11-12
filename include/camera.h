#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
    public:

        enum Direction {
            Forward,
            Backward,
            Left,
            Right

        };
        virtual ~Camera() {}

        void init(const glm::vec3& position);
        void update_camera_vectors();

        float zoom;

        static Camera* get_instance();

        glm::mat4 get_projection() const;
        glm::mat4 get_view() const;

        void handle_keyboard(const Direction& direction, float delta_time);


    private:
        Camera();

        glm::vec3 m_position;
        glm::vec3 m_world_up;
        glm::vec3 m_up;
        glm::vec3 m_front;
        glm::vec3 m_right;

        float m_yaw;
        float m_pitch;
        float m_speed;

        static Camera* m_instance;



};

#endif
