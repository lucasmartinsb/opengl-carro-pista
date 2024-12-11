#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;          // Posição da luz (do carro)
uniform vec3 lightDirection;    // Direção da luz (spotlight)
uniform vec3 viewPos;           // Posição da câmera
uniform vec3 lightColor;        // Cor da luz
uniform vec3 objectColor;       // Cor do objeto
uniform float specularStrength; // Intensidade do brilho especular

// Para o spotlight
uniform float cutOff;           // Ângulo interno do cone de luz
uniform float outerCutOff;      // Ângulo externo do cone de luz

uniform sampler2D texture1;

void main()
{
    // Luz ambiente
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    // Direção da luz (calcular em relação à posição da luz e o fragmento)
    vec3 lightDir = normalize(lightPos - FragPos);  // Luz vindo de lightPos

    // Cálculo da intensidade do cone de luz
    float theta = dot(lightDir, normalize(-lightDirection)); // Comparando direção do cone
    float epsilon = outerCutOff - cutOff;
    float intensity = clamp((theta - outerCutOff) / epsilon, 0.0, 1.0); // Intensidade do cone

    // Luz difusa
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Reflexão para brilho especular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Efeito do spotlight com intensidade aplicada
    vec3 spotlightEffect = (ambient + diffuse + specular) * intensity;
    vec3 result = (spotlightEffect + ambient) * objectColor;;

    // Aplicando a textura ao objeto
    FragColor = texture(texture1, TexCoord) * vec4(result, 1.0);
}
