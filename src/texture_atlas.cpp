#include "texture_atlas.h"
#include "headers.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureAtlas* TextureAtlas::m_instance = nullptr;

TextureAtlas::TextureAtlas():num_rows(0), total_textures(0) {

}

TextureAtlas::~TextureAtlas() {

}

bool TextureAtlas::load(const std::string& path) {

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);




    data = stbi_load(path.c_str(), 
            &width,
            &height,
            &n_channels,
            0);

    if(data)  {
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

    std::cout << "texture loaded\n";
    stbi_image_free(data);
    return true;


}



TextureAtlas* TextureAtlas::get_instance() {
    if(m_instance == nullptr)
        m_instance = new TextureAtlas();

    return m_instance;

}

