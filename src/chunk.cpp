#include "chunk.h"
#include "consts.h"
#include "block.h"
#include "shader.h"
#include "texture_manager.h"
#include <cmath>

Chunk::Chunk() {
    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int y = 0; y < CHUNK_SIZE; y += 1) {
            for(int x = 0; x < CHUNK_SIZE; x += 1) {
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


    // top bottom = y axis 
    
    for(int z = 0; z < CHUNK_SIZE; z += 1) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            bool active_block_found = false;

            for(int y = 0; y < CHUNK_SIZE; y += 1) {
                Block* block = get_block(x, y, z);

                if(block->active) {
                    block->render_block = true;
                    active_block_found = true;
                    break;
                }
            }

            if(active_block_found) {
                for(int y = CHUNK_SIZE - 1; y >= 0; y -= 1) {

                    Block* block = get_block(x, y, z);

                    if(block->active) {
                        block->render_block = true;
                        break;
                    }

                }

            }
        }
    }


    // forward backward = z axis 
    
    for(int y = 0; y < CHUNK_SIZE; y += 1) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            bool active_block_found = false;

            for(int z = 0; z < CHUNK_SIZE; z += 1) {
                Block* block = get_block(x, y, z);

                if(block->active) {
                    block->render_block = true;
                    active_block_found = true;
                    break;
                }
            }

            if(active_block_found) {
                for(int z = CHUNK_SIZE - 1; z >= 0; z -= 1) {

                    Block* block = get_block(x, y, z);

                    if(block->active) {
                        block->render_block = true;
                        break;
                    }
                }

            }
        }
    }

    // left right = x axis 
    
    for(int y = 0; y < CHUNK_SIZE; y += 1) {
        for(int z = 0; z < CHUNK_SIZE; z += 1) {
            bool active_block_found = false;

            for(int x = 0; x < CHUNK_SIZE; x += 1) {
                Block* block = get_block(x, y, z);

                if(block->active) {
                    block->render_block = true;
                    active_block_found = true;
                    break;
                }
            }

            if(active_block_found) {
                for(int x = CHUNK_SIZE - 1; x >= 0; x -= 1) {

                    Block* block = get_block(x, y, z);

                    if(block->active) {
                        block->render_block = true;
                        break;
                    }
                }

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

Block* Chunk::get_block(int x, int y, int z) const {
    return m_blocks[x + CHUNK_SIZE * (y + CHUNK_SIZE * z)];
}
