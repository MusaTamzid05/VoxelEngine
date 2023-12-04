#include "material.h"



Material::Material() {
    diffuse = 0.0f;
    shininess = 64.0f;
    specular = glm::vec3(0.5f);

}

Material::~Material() {

}
