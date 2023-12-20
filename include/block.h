#ifndef BLOCK_H
#define BLOCK_H

#include <glm/glm.hpp>

struct Shader;

struct Block {
    Block(const glm::vec3& position, unsigned int texture_shader_index, bool active=false);
    virtual ~Block();

    //void render(Shader* shader);
    glm::vec3 m_position;
    unsigned m_texture_shader_index;
    bool active;
    bool render_block;
};


#endif
