#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

struct Block;
struct Shader;

struct Chunk {
    Chunk();
    virtual ~Chunk();

    void render(Shader* shader);

    std::vector<Block*> m_blocks;



};

#endif

