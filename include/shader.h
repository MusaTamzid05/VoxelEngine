#ifndef SHADER_H
#define SHADER_H


#include <string>

struct Shader {
    Shader(const std::string& vertex_shader_path,
            const std::string& fragment_shader_path);

    virtual ~Shader();
    void use();

    unsigned int id;
};

#endif
