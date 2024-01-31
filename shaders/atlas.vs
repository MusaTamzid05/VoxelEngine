#version 330 core

layout (location=0) in vec3 position;
layout (location=1) in vec3 normals;
layout (location=2) in vec2 textureCoords;
layout (location=3) in mat4 instance_model;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

uniform int numRows;

uniform mat4 projection;
uniform mat4 view;

vec2 get_texture_offset(int textureIndex) {
    int col = textureIndex % numRows; 
    float x = float(col) / float(numRows);

    int row = textureIndex / numRows; 
    float y = float(row) / float(numRows);

    return vec2(x, y);




}

void main() {
    FragPos = vec3(instance_model* vec4(position, 1.0f));
    Normal = mat3(transpose(inverse(instance_model))) * normals;
    gl_Position = projection * view * instance_model * vec4(position, 1.0);

    int textureIndex = 0;

    float height = FragPos.y;

    if(height < 4.0)
        textureIndex = 0;

    else if( height >= 4.0 && height <= 10.0)
        textureIndex = 2;

    else if( height > 10.0 && height <= 12.0)
        textureIndex = 3;
    else
        textureIndex = 1;



    vec2 offset = get_texture_offset(textureIndex);
    TexCoords = (textureCoords / numRows) + offset;
}
