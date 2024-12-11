#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;          // Posição da luz (farol do carro)
uniform vec3 lightDirection;    // Direção da luz
uniform vec3 viewPos;           // Posição do observador (câmera)
uniform vec3 lightColor;        // Cor da luz
uniform vec3 objectColor;       // Cor do objeto
uniform float specularStrength; // Intensidade do brilho especular

// texture samplers
uniform sampler2D texture1;

void main()
{
    // ambient
    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightDirection); // Use a direção da luz uniform
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = texture(texture1, TexCoord) * vec4(result, 1.0);
}

void main_()
{

	// ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * objectColor;

    FragColor = vec4(result, 1.0);

	FragColor = texture(texture1, TexCoord);
	FragColor = mix(texture(texture1, TexCoord), vec4(result, 1.0f), 0.5f);

	//FragColor = texture(texture1, TexCoord) * vec4(result, 1.0);
}
