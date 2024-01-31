#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H

#include <string>


class TextureAtlas {

    public:
        virtual ~TextureAtlas();

        bool load(const std::string& path);



        static TextureAtlas* get_instance();


        unsigned int id;
        int width;
        int height;
        int n_channels;
        unsigned char* data;

        int num_rows; // num rows and cols must be equal
        int total_textures;

    private:
        TextureAtlas();
        static TextureAtlas* m_instance;

};

#endif
