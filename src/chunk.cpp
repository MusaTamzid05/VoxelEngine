#include "chunk.h"
#include "consts.h"
#include "block.h"
#include "shader.h"
#include "headers.h"
#include "texture_manager.h"
#include <cmath>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

Chunk::Chunk() {

    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
                m_blocks.push_back(Block(glm::vec3(0.0f, 0.0f, 0.0f), TextureManager::Type::Grass));

            }

        }
    }



}

Chunk::~Chunk() {
}

void Chunk::init_render() {
    current_render_models.clear();

    // top bottom = y axis 
    
    for(int z = 0; z < CHUNK_SIZE; z += 1) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            bool active_block_found = false;

            for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
                Block block = get_block(x, y, z);

                if(block.active) {
                    block.render_block = true;
                    set_block(x, y, z , block);
                    active_block_found = true;
                    add_models(glm::vec3(x, y, z));
                    break;
                }
            }

            if(active_block_found) {
                for(int y = CHUNK_HEIGHT - 1; y >= 0; y -= 1) {

                    Block block = get_block(x, y, z);

                    if(block.active) {
                        block.render_block = true;
                        set_block(x, y, z , block);
                        add_models(glm::vec3(x, y, z));
                        break;
                    }

                }

            }
        }
    }


    // forward backward = z axis 
    
    for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            bool active_block_found = false;

            for(int z = 0; z < CHUNK_SIZE; z += 1) {
                Block block = get_block(x, y, z);

                if(block.active) {
                    block.render_block = true;
                    set_block(x, y, z , block);
                    active_block_found = true;
                    add_models(glm::vec3(x, y, z));
                    break;
                }
            }

            if(active_block_found) {
                for(int z = CHUNK_SIZE - 1; z >= 0; z -= 1) {

                    Block  block = get_block(x, y, z);

                    if(block.active) {
                        block.render_block = true;
                        set_block(x, y, z , block);
                        add_models(glm::vec3(x, y, z));
                        break;
                    }
                }

            }
        }
    }

    // left right = x axis 
    
    for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
        for(int z = 0; z < CHUNK_SIZE; z += 1) {
            bool active_block_found = false;

            for(int x = 0; x < CHUNK_SIZE; x += 1) {
                Block block = get_block(x, y, z);

                if(block.active) {
                    block.render_block = true;
                    set_block(x, y, z , block);
                    active_block_found = true;
                    add_models(glm::vec3(x, y, z));
                    break;
                }
            }

            if(active_block_found) {
                for(int x = CHUNK_SIZE - 1; x >= 0; x -= 1) {

                    Block block = get_block(x, y, z);

                    if(block.active) {
                        block.render_block = true;
                        set_block(x, y, z , block);
                        add_models(glm::vec3(x, y, z));
                        break;
                    }
                }

            }
        }
    }


}

void Chunk::add_models(const glm::vec3& position) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    current_render_models.push_back(model);

}


void Chunk::render(Shader* shader) {
    glDrawArraysInstanced(
            GL_TRIANGLES,
            0,
            36,
            current_render_models.size()
            );
    //for(Block block : m_blocks)
        //block.render(shader);

}

void Chunk::set_block(int x, int y, int z, const Block& block) {
    m_blocks[z * (CHUNK_SIZE * CHUNK_HEIGHT) + x * CHUNK_HEIGHT + y] = block;
}
Block Chunk::get_block(int x, int y, int z) const {
    return m_blocks[z * (CHUNK_SIZE * CHUNK_HEIGHT) + x * CHUNK_HEIGHT + y];
}
