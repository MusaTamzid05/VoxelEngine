#ifndef CHUNK_MANAGER_H
#define CHUNK_MANAGER_H

#include <vector>
#include "chunk.h"


struct Shader;
struct Renderer;

struct ChunkManager {
    ChunkManager(int chunk_count);
    virtual ~ChunkManager();

    void render(Shader* shader);
    void update_instance_vbo(Renderer* renderer);
    float get_height(int x, int z) const;


    std::vector<float> noise_data;
    std::vector<Chunk> chunks;
    std::vector<glm::mat4> current_render_models;

    int total_blocks_count;



};

#endif
