#include "light.h"
#include "shader.h"
#include "headers.h"
#include <glm/gtc/matrix_transform.hpp>


Light::Light(const glm::vec3& position):position(position) {
    ambient = glm::vec3(0.2f);
    diffuse = glm::vec3(0.5f);
    specular = glm::vec3(1.0f);

}

Light::~Light() {

}

void Light::render(Shader* shader) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    shader->use();
    shader->set_mat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

}
