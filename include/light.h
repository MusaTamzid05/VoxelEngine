#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include "shader.h"

struct Light {
    Light(const glm::vec3& position);
    ~Light();

    void render(Shader* shader);

    glm::vec3 position;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

};

#endif
