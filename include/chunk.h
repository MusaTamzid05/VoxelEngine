#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <glm/glm.hpp>
#include "block.h"

struct Shader;

struct Chunk {
    Chunk();
    virtual ~Chunk();

    void init_render();
    bool is_block_hidden(const Block& block) const;
    void add_models(const glm::vec3& position);

    //void render(Shader* shader);

    void set_block(int x, int y, int z, const  Block& block);
    Block get_block(int x, int y, int z) const;

    std::vector<Block> m_blocks;
    std::vector<glm::mat4> current_render_models;



};

#endif

