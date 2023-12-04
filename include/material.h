#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

struct Material {
    Material();
    virtual ~Material();

    int diffuse;
    float shininess;
    glm::vec3 specular;

};

#endif
