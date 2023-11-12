#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Shader;

struct Triangle {
    Triangle();
    virtual ~Triangle();

    void render();
    void update();

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    Shader* m_shader;


};

#endif
