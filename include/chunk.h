#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

struct Block;
struct Shader;

struct Chunk {
    Chunk();
    virtual ~Chunk();

    void init_render();

    void render(Shader* shader);
    Block* get_block(int x, int y, int z) const;

    std::vector<Block*> m_blocks;



};

#endif

