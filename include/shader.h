#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <glm/glm.hpp>

struct Shader {
    Shader(const std::string& vertex_shader_path,
            const std::string& fragment_shader_path);

    virtual ~Shader();
    void use();

    void set_mat4(const std::string& name, glm::mat4& mat);

    unsigned int id;
};

#endif
