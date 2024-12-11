#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord; // Coordenadas de textura

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoord;  // Passa as coordenadas de textura para o fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    
    TexCoord = aTexCoord; // Passa as coordenadas de textura diretamente

    gl_Position = projection * view * vec4(FragPos, 1.0);
}
