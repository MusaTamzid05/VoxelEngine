#version 330 core

layout (location=0) in vec3 position;
layout (location=1) in vec3 normals;
layout (location=2) in vec2 textureCoords;
layout (location=3) in mat4 instance_model;

out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 projection;
uniform mat4 view;

void main() {
    FragPos = vec3(instance_model* vec4(position, 1.0f));
    Normal = mat3(transpose(inverse(instance_model))) * normals;
    gl_Position = projection * view * instance_model * vec4(position, 1.0);
    TexCoords = textureCoords;
}
