#ifndef BLOCK_H
#define BLOCK_H

#include <glm/glm.hpp>

struct Shader;

struct Block {
    Block(const glm::vec3& position, bool active=false);
    virtual ~Block();

    glm::vec3 world_position;
    glm::vec3 local_position;
    bool active;
};


#endif
