#include "chunk_manager.h"
#include "headers.h"
#include "consts.h"
#include "linear_interpolator.h"
#include "noise_chunk.h"
#include "renderer.h"
#include <libnoise/noise.h>

ChunkManager::ChunkManager(int chunk_count) {
    total_blocks_count = CHUNK_SIZE * chunk_count;


    noise::module::Perlin noise_module;
    LinearInterpolator interpolator(-1.0f, 1.0f, 1.0f, 16.0f);

    for(int z = 0; z < total_blocks_count; z += 1 ) {
        for(int x = 0; x < total_blocks_count; x += 1) {

            double x_ = ((double)x /  (double)total_blocks_count);
            double z_ = ((double)z /  (double)total_blocks_count);

            float current_noise = noise_module.GetValue(x_, 0.0, z_);
            float height = interpolator.map(current_noise);

            noise_data.push_back(height);



        }
    }

    glm::vec3 current_position = glm::vec3(0.0f);

    for(int i = 0; i < chunk_count; i += 1) {
        for(int j = 0; j < chunk_count; j += 1) {
            NoiseChunk chunk(this, current_position);
            chunk.init_render();
            chunks.push_back(chunk);

            current_position.x += CHUNK_SIZE;
        }

        current_position.z += CHUNK_SIZE;
        current_position.x = 0.0f;


    }

}

ChunkManager::~ChunkManager() {

}

void ChunkManager::render(Shader* shader) {
    glDrawArraysInstanced(
            GL_TRIANGLES,
            0,
            36,
            current_render_models.size()
            );



}
void ChunkManager::update_instance_vbo(Renderer* renderer) {
    current_render_models.clear();

    for(Chunk chunk : chunks) {
        for(glm::mat4 model : chunk.current_render_models)
            current_render_models.push_back(model);
    }

    renderer->init_instance_vbo(current_render_models);


}

float ChunkManager::get_height(int x, int z) const {
    return noise_data[(z * total_blocks_count) + x];

}
