#ifndef RENDERER_H
#define RENDERER_H

struct Shader;

struct Renderer {
    Renderer();
    virtual ~Renderer();

    void bind_block_render();

    unsigned int m_block_VAO;
    unsigned int m_VBO;

    Shader* m_block_shader;

    unsigned int grass_texture_id;
    unsigned int farmland_texture_id;




};

#endif
