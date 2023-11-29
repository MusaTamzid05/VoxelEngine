#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <map>

class TextureManager {

    public:
        enum Type {
            Grass,
            Farmland,
        };

        virtual ~TextureManager();
        static TextureManager* get_instance();

        bool add(const Type& type, const std::string& path);
        unsigned int get_texture(const Type& type) const;

        std::map<Type, unsigned int> maps;
        std::map<Type, unsigned int> shader_map; // texture id used in shader

    private:

        TextureManager();
        static TextureManager* m_instance;





};


#endif
