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




};

#endif
