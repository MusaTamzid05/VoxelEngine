#include "chunk.h"
#include "consts.h"
#include "block.h"
#include "shader.h"
#include "headers.h"
#include <cmath>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

Chunk::Chunk() {

    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
                m_blocks.push_back(Block(glm::vec3(x, y, z))); // done off the video, need to save position for future

            }

        }
    }



}

Chunk::~Chunk() {
}

void Chunk::init_render() {
    current_render_models.clear();

    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {
            for(int y = 0; y < CHUNK_HEIGHT; y += 1) {
                Block block = get_block(x, y, z);

                if(!block.active)
                    continue;

                if(is_block_hidden(block))
                    continue;

                add_models(block.world_position);


            }

        }
    }



}

bool Chunk::is_block_hidden(const Block& block) const {
    int side_block_count = 0;

    int x = block.local_position.x;
    int y = block.local_position.y;
    int z = block.local_position.z;

    int side_x = x;
    int side_y = y;
    int side_z = z;




    // x axis
    

    side_x = x - 1;
    
    if(side_x >= 0) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_x = x + 1;

    if(side_x < CHUNK_SIZE) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_x = x;

    // z axis


    side_z = z - 1;
    
    if(side_z >= 0) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_z = z + 1;

    if(side_x < CHUNK_SIZE) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_z = z;


    // y axis


    side_y = y - 1;
    
    if(side_y >= 0) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_y = y + 1;

    if(side_x < CHUNK_HEIGHT) {
        Block side_block = get_block(side_x, side_y, side_z);
        if(side_block.active)
            side_block_count += 1;
    }

    side_y = y;



    return side_block_count == 6;

}

void Chunk::add_models(const glm::vec3& position) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    current_render_models.push_back(model);
    current_positions.push_back(position);

}


/*
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
*/

void Chunk::set_block(int x, int y, int z, const Block& block) {
    m_blocks[z * (CHUNK_SIZE * CHUNK_HEIGHT) + x * CHUNK_HEIGHT + y] = block;
}
Block Chunk::get_block(int x, int y, int z) const {
    return m_blocks[z * (CHUNK_SIZE * CHUNK_HEIGHT) + x * CHUNK_HEIGHT + y];
}
