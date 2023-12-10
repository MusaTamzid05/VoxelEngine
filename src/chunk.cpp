#include "chunk.h"
#include "consts.h"
#include "block.h"
#include "shader.h"
#include "texture_manager.h"
#include <cmath>

Chunk::Chunk() {
    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            for(int y = 0; y < CHUNK_SIZE; y += 1) {
                bool active = false;

                float x_ = ( x - ((float)CHUNK_SIZE / 2.0f));
                float y_ = ( y - ((float)CHUNK_SIZE / 2.0f));
                float z_ = ( z - ((float)CHUNK_SIZE / 2.0f));

                float lhs = (x_ * x_) + (y_ * y_) + (z_ * z_);
                lhs = sqrt(lhs);

                float rhs = (float) CHUNK_SIZE / 2.0f;

                if(lhs <= rhs)
                    active = true;




                m_blocks.push_back(new Block(glm::vec3(x, y, z), TextureManager::Type::Grass, active));

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
