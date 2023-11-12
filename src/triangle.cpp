#include "triangle.h"
#include "shader.h"
#include "headers.h"
#include "camera.h"
#include <vector>


Triangle::Triangle() {
    m_shader = new Shader("../shaders/triangle.vs", "../shaders/triangle.fs");

    // mesh initialization

    std::vector<float> vertices({
            -1.0f, -1.0f, 0.0f, 
             1.0f, -1.0f, 0.0f, 
             0.0f, 1.0f, 0.0f, 
            });

    std::vector<unsigned int> indices({
            0,1,2
            });

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER,
            vertices.size() * sizeof(float),
            vertices.data(),
            GL_STATIC_DRAW
            );

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            indices.size() * sizeof(unsigned int),
            indices.data(),
            GL_STATIC_DRAW
            );

    glBindVertexArray(0);

    m_shader->use();

    glm::mat4 projection = Camera::get_instance()->get_projection();
    m_shader->set_mat4("projection", projection);


    



}


Triangle::~Triangle() {

}



void Triangle::render() {
    m_shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);


}

void Triangle::update() {
    m_shader->use();
    glm::mat4 view = Camera::get_instance()->get_view();
    m_shader->set_mat4("view", view);

    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(0.0f));
    m_shader->set_mat4("model", model);


}
