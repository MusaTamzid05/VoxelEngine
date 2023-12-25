#include "noise_chunk.h"
#include "consts.h"
#include "block.h"
#include "chunk_manager.h"
#include <iostream>


NoiseChunk::NoiseChunk(ChunkManager* chunk_manager,
        const glm::vec3& start_position) {

    int z_offset = start_position.z;
    int x_offset = start_position.x;

    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {

            float height = chunk_manager->get_height(x_offset, z_offset);

            for(int y = 0; y < CHUNK_HEIGHT; y += 1)  {
                Block block = get_block(x, y, z);
                block.world_position = glm::vec3(x_offset, y, z_offset);

                block.active = y < height ? true : false;
                set_block(x, y, z, block);

            }

            x_offset  += 1;

        }

        z_offset += 1;
        x_offset = start_position.x;
    }

}

NoiseChunk::~NoiseChunk() {

}
