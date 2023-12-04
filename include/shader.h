#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <glm/glm.hpp>

struct Shader {
    Shader(const std::string& vertex_shader_path,
            const std::string& fragment_shader_path);

    virtual ~Shader();
    void use();

    void set_mat4(const std::string& name, const glm::mat4& mat);
    void set_vec3(const std::string& name, const glm::vec3& vec);
    void set_int(const std::string& name, int value);
    void set_float(const std::string& name, float value);

    unsigned int id;
};

#endif
