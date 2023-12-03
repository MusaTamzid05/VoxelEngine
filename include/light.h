#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include "shader.h"

struct Light {
    Light(const glm::vec3& position);

    void render(Shader* shader);

    glm::vec3 position;

};

#endif
