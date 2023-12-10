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
                m_blocks.push_back(new Block(glm::vec3(x, y, z), TextureManager::Type::Grass));
            }

        }
    }

}

Chunk::~Chunk() {
}

void Chunk::render(Shader* shader) {
    for(Block* block : m_blocks)
        block->render(shader);

}
