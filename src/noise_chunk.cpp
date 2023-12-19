#include "noise_chunk.h"
#include "consts.h"
#include "block.h"
#include "texture_manager.h"
#include "linear_interpolator.h"

#include <libnoise/noise.h>
#include <iostream>

NoiseChunk::NoiseChunk() {
    noise::module::Perlin noise_module;
    LinearInterpolator interpolator(-1.0f, 1.0f, 1.0f, 8.0f);

    for(int z = 0; z < CHUNK_SIZE; z += 1 ) {
        for(int x = 0; x < CHUNK_SIZE; x += 1) {

            double x_ = ((double)x /  (double)CHUNK_SIZE);
            double z_ = ((double)z /  (double)CHUNK_SIZE);

            float current_noise = noise_module.GetValue(x_, 0.0, z_);
            float height = interpolator.map(current_noise);

            for(int y = 0; y < height; y += 1)  {
                Block block = get_block(x, y, z);
                block.active = true;
                set_block(x, y, z, block);

            }


        }
    }

}

NoiseChunk::~NoiseChunk() {

}
