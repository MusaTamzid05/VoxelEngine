#ifndef BLOCK_H
#define BLOCK_H

#include <glm/glm.hpp>

struct Shader;

struct Block {
    Block(const glm::vec3& position);
    virtual ~Block();

    void render(Shader* shader);

    glm::vec3 m_position;
};


#endif
