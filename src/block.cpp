#include "block.h"
#include "shader.h"
#include "headers.h"
#include <glm/gtc/matrix_transform.hpp>

    
Block::Block(const glm::vec3& position, unsigned int texture_shader_index, bool active):
    m_position(position),
    m_texture_shader_index(texture_shader_index),
    active(active) {

    }

Block::~Block() {

}


