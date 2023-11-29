#version 330 core

out vec4 FragColor;
in vec2 TexCoords;

uniform int textureIndex;
uniform sampler2D texture0;
uniform sampler2D texture1;



void main() {
    if(textureIndex == 0)
        FragColor = texture(texture0, TexCoords);
    else
        FragColor = texture(texture1, TexCoords);
}
