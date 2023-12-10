#include "block.h"
#include "shader.h"
#include "headers.h"
#include <glm/gtc/matrix_transform.hpp>

    
Block::Block(const glm::vec3& position, unsigned int texture_shader_index, bool active):
    m_position(position),
    m_texture_shader_index(texture_shader_index),
    m_active(active)
{

    }

Block::~Block() {

}


void Block::render(Shader* shader) {
    if(!m_active)
        return;
        
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, m_position);

    shader->use();
    shader->set_int("textureIndex", m_texture_shader_index);
    shader->set_mat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);



}


