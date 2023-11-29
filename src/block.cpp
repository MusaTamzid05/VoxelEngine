#include "block.h"
#include "shader.h"
#include "headers.h"
#include <glm/gtc/matrix_transform.hpp>

    
Block::Block(const glm::vec3& position):
    m_position(position) {

    }

Block::~Block() {

}


void Block::render(Shader* shader) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, m_position);

    shader->use();
    shader->set_mat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);



}


