#include "chunk.h"
#include "consts.h"
#include "block.h"
#include "shader.h"
#include "texture_manager.h"

Chunk::Chunk() {
    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            std::vector<Block*> blocks;
            for(int y = 0; y < 1; y += 1) {
                blocks.push_back(new Block(glm::vec3(x, y, z), TextureManager::Type::Grass));
            }
            m_blocks.push_back(blocks);

        }
    }

}

Chunk::~Chunk() {
}

void Chunk::render(Shader* shader) {
    for(std::vector<Block*> blocks : m_blocks)
        for(Block* block : blocks)
            block->render(shader);

}
