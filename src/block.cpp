#include "block.h"
#include "shader.h"
#include "headers.h"
#include <glm/gtc/matrix_transform.hpp>

    
Block::Block(const glm::vec3& position, bool active):
    world_position(position),
    local_position(position),
    active(active) {

    }

Block::~Block() {

}


