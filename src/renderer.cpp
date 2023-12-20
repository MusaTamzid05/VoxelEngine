#include "renderer.h"
#include "shader.h"
#include "headers.h"
#include "camera.h"
#include "material.h"
#include "light.h"
#include "texture_manager.h"
#include <vector>
#include <iostream>

Renderer::Renderer():
    m_block_VAO(0),
    m_block_VBO(0) {

        m_chunk_shader = new Shader("../shaders/chunk.vs", "../shaders/chunk.fs");
        m_light_shader = new Shader("../shaders/light.vs", "../shaders/light.fs");

		std::vector<float> vertices = {


        // Back face
		-0.5f,   -0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    0.0f,    0.0f,   // Bottom-left
		 0.5f,    0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    1.0f,    0.0f,   // top-right
		 0.5f,   -0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    1.0f,    1.0f,   // bottom-right
		 0.5f,    0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    1.0f,    1.0f,   // top-right
		-0.5f,   -0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    0.0f,    1.0f,   // bottom-left
		-0.5f,    0.5f,   -0.5f,    0.0f,    0.0f,   -1.0f,    0.0f,    0.0f,   // top-left
		// Front face
		-0.5f,   -0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    0.0f,    0.0f,   // bottom-left
		 0.5f,   -0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    1.0f,    0.0f,   // bottom-right
		 0.5f,    0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    1.0f,    1.0f,   // top-right
		 0.5f,    0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    1.0f,    1.0f,   // top-right
		-0.5f,    0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    0.0f,    1.0f,   // top-left
		-0.5f,   -0.5f,    0.5f,    0.0f,    0.0f,    1.0f,    0.0f,    0.0f,   // bottom-left
		// Left face
		-0.5f,    0.5f,    0.5f,   -1.0f,    0.0f,    0.0f,    1.0f,    0.0f,   // top-right
		-0.5f,    0.5f,   -0.5f,   -1.0f,    0.0f,    0.0f,    1.0f,    1.0f,   // top-left
		-0.5f,   -0.5f,   -0.5f,   -1.0f,    0.0f,    0.0f,    0.0f,    1.0f,   // bottom-left
		-0.5f,   -0.5f,   -0.5f,   -1.0f,    0.0f,    0.0f,    0.0f,    1.0f,   // bottom-left
		-0.5f,   -0.5f,    0.5f,   -1.0f,    0.0f,    0.0f,    0.0f,    0.0f,   // bottom-right
		-0.5f,    0.5f,    0.5f,   -1.0f,    0.0f,    0.0f,    1.0f,    0.0f,   // top-right
		// Right face
		 0.5f,    0.5f,    0.5f,    1.0f,    0.0f,    0.0f,    1.0f,    0.0f,   // top-left
		 0.5f,   -0.5f,   -0.5f,    1.0f,    0.0f,    0.0f,    1.0f,    1.0f,   // bottom-right
		 0.5f,    0.5f,   -0.5f,    1.0f,    0.0f,    0.0f,    0.0f,    1.0f,   // top-right
		 0.5f,   -0.5f,   -0.5f,    1.0f,    0.0f,    0.0f,    0.0f,    1.0f,   // bottom-right
		 0.5f,    0.5f,    0.5f,    1.0f,    0.0f,    0.0f,    0.0f,    0.0f,   // top-left
		 0.5f,   -0.5f,    0.5f,    1.0f,    0.0f,    0.0f,    1.0f,    0.0f,   // bottom-left
		// Bottom face
		-0.5f,   -0.5f,   -0.5f,    0.0f,   -1.0f,    0.0f,    0.0f,    1.0f,   // top-right
		 0.5f,   -0.5f,   -0.5f,    0.0f,   -1.0f,    0.0f,    1.0f,    1.0f,   // top-left
		 0.5f,   -0.5f,    0.5f,    0.0f,   -1.0f,    0.0f,    1.0f,    0.0f,   // bottom-left
		 0.5f,   -0.5f,    0.5f,    0.0f,   -1.0f,    0.0f,    1.0f,    0.0f,   // bottom-left
		-0.5f,   -0.5f,    0.5f,    0.0f,   -1.0f,    0.0f,    0.0f,    0.0f,   // bottom-right
		-0.5f,   -0.5f,   -0.5f,    0.0f,   -1.0f,    0.0f,    0.0f,    1.0f,   // top-right
		// Top face
		-0.5f,    0.5f,   -0.5f,    0.0f,    1.0f,    0.0f,    0.0f,    1.0f,   // top-left
		 0.5f,    0.5f,    0.5f,    0.0f,    1.0f,    0.0f,    1.0f,    1.0f,   // bottom-right
		 0.5f,    0.5f,   -0.5f,    0.0f,    1.0f,    0.0f,    1.0f,    0.0f,   // top-right
		 0.5f,    0.5f,    0.5f,    0.0f,    1.0f,    0.0f,    1.0f,    0.0f,   // bottom-right
		-0.5f,    0.5f,   -0.5f,    0.0f,    1.0f,    0.0f,    0.0f,    0.0f,   // top-left
		-0.5f,    0.5f,    0.5f,    0.0f,    1.0f,    0.0f,    0.0f,    1.0f,   // bottom-left

		};

        glGenVertexArrays(1, &m_block_VAO);
        glGenBuffers(1, &m_block_VBO);

        glBindVertexArray(m_block_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_block_VBO);

        glBufferData(
                GL_ARRAY_BUFFER,
                vertices.size() * sizeof(float),
                vertices.data(),
                GL_STATIC_DRAW
                );

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float) ));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float) ));
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        m_chunk_shader->use();
        glm::mat4 projection = Camera::get_instance()->get_projection();

        // light cube vertex object array data

        glGenVertexArrays(1, &m_light_VAO);

        glBindVertexArray(m_light_VAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_block_VBO);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);


        glBindBuffer(GL_ARRAY_BUFFER, 0);

        m_chunk_shader->set_mat4("projection", projection);

        Material material;
        m_chunk_shader->set_int("material.diffuse", material.diffuse);
        m_chunk_shader->set_float("material.shininess", material.shininess);
        m_chunk_shader->set_vec3("material.specular", material.specular);



        for(auto shader_data :  TextureManager::get_instance()->shader_map) {
            unsigned int index = shader_data.second;
            std::string type_name = "texture" + std::to_string(index);
            m_chunk_shader->set_int(type_name, index);
        }

        // The block textures

        grass_texture_id = TextureManager::get_instance()->get_texture(
                TextureManager::Type::Grass
                );
        farmland_texture_id = TextureManager::get_instance()->get_texture(
                TextureManager::Type::Farmland
                );

        m_light_shader->use();
        m_light_shader->set_mat4("projection", projection);





    }

Renderer::~Renderer() {

}

void Renderer::init_light(Light* light) {
    m_chunk_shader->use();
    m_chunk_shader->set_vec3("light.ambient", light->ambient);
    m_chunk_shader->set_vec3("light.diffuse", light->diffuse);
    m_chunk_shader->set_vec3("light.specular", light->specular);


}


void Renderer::init_instance_vbo(const std::vector<glm::mat4>& models) {
    glBindVertexArray(m_block_VAO);

    glGenBuffers(1, &m_instance_pos_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_instance_pos_VBO);

    glBufferData(
            GL_ARRAY_BUFFER,
            models.size() * sizeof(glm::mat4),
            models.data(),
            GL_STATIC_DRAW
            );

    std::size_t vec4_size = sizeof(glm::vec4);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4_size, (void*)0);
    glEnableVertexAttribArray(3);

    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4_size, (void*)(1 * vec4_size));
    glEnableVertexAttribArray(4);

    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * vec4_size, (void*)(2 * vec4_size));
    glEnableVertexAttribArray(5);

    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * vec4_size, (void*)(3 * vec4_size));
    glEnableVertexAttribArray(6);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);
    glVertexAttribDivisor(6, 1);





}


void Renderer::bind_block_render() {
    m_chunk_shader->use();
    glm::mat4 view = Camera::get_instance()->get_view();
    m_chunk_shader->set_mat4("view", view);

    glm::vec3 camera_position = Camera::get_instance()->get_position();

    m_chunk_shader->set_vec3("viewPos", camera_position );
    m_chunk_shader->set_vec3("light.position", camera_position);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, grass_texture_id);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, farmland_texture_id);

    glBindVertexArray(m_block_VAO);

}

void Renderer::bind_light_render() {
    m_light_shader->use();
    glm::mat4 view = Camera::get_instance()->get_view();
    m_light_shader->set_mat4("view", view);

    glBindVertexArray(m_light_VAO);

}
