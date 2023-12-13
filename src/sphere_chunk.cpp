#include "sphere_chunk.h"
#include "consts.h"
#include "block.h"
#include "texture_manager.h"
#include <cmath>



SphereChunk::SphereChunk() {
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

                Block* block = get_block(x, y, z);
                block->active = active;





            }

        }
    }

}

SphereChunk::~SphereChunk() {

}
