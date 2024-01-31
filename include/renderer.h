#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <glm/glm.hpp>

struct Shader;
struct Light;

struct Renderer {
    Renderer();
    virtual ~Renderer();

    void init_light(Light* light);
    void init_instance_vbo(const std::vector<glm::mat4>& models);
    void bind_block_render();
    void bind_light_render();

    unsigned int m_block_VAO;
    unsigned int m_light_VAO;

    unsigned int m_block_VBO;
    unsigned int m_instance_pos_VBO;

    Shader* m_chunk_shader;
    Shader* m_light_shader;

    unsigned int texture_atlas_id;




};

#endif
