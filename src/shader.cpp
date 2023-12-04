#include "shader.h"
#include "utils.h"
#include "headers.h"
#include <iostream>



Shader::Shader(const std::string& vertex_shader_path,
        const std::string& fragment_shader_path) {

    std::string vertex_shader_str = read_file(vertex_shader_path);
    std::string fragment_shader_str = read_file(fragment_shader_path);

    const char* vertex_shader_text = vertex_shader_str.c_str();
    const char* fragment_shader_text = fragment_shader_str.c_str();


    unsigned int vertex_id;
    unsigned int fragment_id;

    int success;

    vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id, 1,&vertex_shader_text, nullptr);
    glCompileShader(vertex_id);
    glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &success);

    GLchar info_log[512];

    if(!success) {
        glGetShaderInfoLog(vertex_id, 512, nullptr, info_log);
        std::cout << "Error compiling vertex shader : " << info_log << "\n";
        exit(3);
    }

    std::cout << "Vertex shader compiled successfully\n";


    fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id, 1,&fragment_shader_text, nullptr);
    glCompileShader(fragment_id);
    glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &success);


    if(!success) {
        glGetShaderInfoLog(fragment_id, 512, nullptr, info_log);
        std::cout << "Error compiling fragment shader : " << info_log << "\n";
        exit(3);
    }


    std::cout << "Fragment shader compiled successfully\n";

    id = glCreateProgram();
    glAttachShader(id, vertex_id);
    glAttachShader(id, fragment_id);
    glLinkProgram(id);


    glGetShaderiv(id, GL_LINK_STATUS, &success);


    if(!success) {
        glGetShaderInfoLog(id, 512, nullptr, info_log);
        std::cout << "Error linking shaders : " << info_log << "\n";
        exit(3);
    }


    std::cout << "Shader linking complete.\n";





}


Shader::~Shader() {

}

void Shader::use() {
    glUseProgram(id);

}

void Shader::set_mat4(const std::string& name, const glm::mat4& mat) {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);


}

void Shader::set_vec3(const std::string& name, const  glm::vec3& vec) {
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &vec[0]);


}


void Shader::set_int(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::set_float(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
