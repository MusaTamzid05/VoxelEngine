#ifndef NOISE_CHUNK_H
#define NOISE_CHUNK_H

#include "chunk.h"
struct ChunkManager;

struct NoiseChunk : Chunk {

    NoiseChunk(ChunkManager* chunk_manager, const glm::vec3& start_position);
    virtual ~NoiseChunk();


};


#endif
