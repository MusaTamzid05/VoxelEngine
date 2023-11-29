#include "texture_manager.h"
#include "headers.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

TextureManager* TextureManager::m_instance = nullptr;

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {

}

TextureManager* TextureManager::get_instance() {
    if(m_instance == nullptr)
        m_instance = new TextureManager();

    return m_instance;
}

bool TextureManager::add(const Type& type, const std::string& path) {
    unsigned int texture_id;

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);


    // wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    // filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width;
    int height;
    int n_channnels;


    unsigned char* data = stbi_load(
            path.c_str(),
            &width,
            &height,
            &n_channnels,
            0
            );

    if(data) {
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGB,
                width,
                height,
                0,
                GL_RGB,
                GL_UNSIGNED_BYTE,
                data
                );
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else 
        return false;

    stbi_image_free(data);
    maps[type] = texture_id;
    shader_map[type] = shader_map.size();

    return true;
        


}

unsigned int TextureManager::get_texture(const Type& type) const {
    auto target = maps.find(type);

    if(target == maps.end()) {
        std::cerr << "Could not load texture type " << type << "\n";
        return -1;

    }

    return target->second;

}

