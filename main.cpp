// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <vector>
#include <glad/glad.h>
#include "opengl_utils.cpp"
#include "vendor/stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Shader.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(-15.0f, 2.0f, 15.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Necessário pro MacOs, desabilitar pra executar no Windows
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Coordenadas OpenGL : Cubo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // glew: load all OpenGL function pointers
    // ---------------------------------------
    // if(glewInit()!=GLEW_OK) {
    //     std::cout << "Ocorreu um erro iniciando GLEW!" << std::endl;
    // } else {
    //     std::cout << "GLEW OK!" << std::endl;
    //     std::cout << glGetString(GL_VERSION) << std::endl;
    // }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("vertex.glsl", "fragment.glsl");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float baseVertices[] = {
        // Face traseira
        -0.5f, -0.3f, -1.0f,  0.0f, 0.0f, // Dimensões ajustadas em Y e Z
        0.5f, -0.3f, -1.0f,  1.0f, 0.0f,
        0.5f,  0.3f, -1.0f,  1.0f, 1.0f,
        0.5f,  0.3f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.3f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.3f, -1.0f,  0.0f, 0.0f,

        // Face frontal
        -0.5f, -0.3f,  1.0f,  0.0f, 0.0f,
        0.5f, -0.3f,  1.0f,  1.0f, 0.0f,
        0.5f,  0.3f,  1.0f,  1.0f, 1.0f,
        0.5f,  0.3f,  1.0f,  1.0f, 1.0f,
        -0.5f,  0.3f,  1.0f,  0.0f, 1.0f,
        -0.5f, -0.3f,  1.0f,  0.0f, 0.0f,

        // Face lateral esquerda
        -0.5f,  0.3f,  1.0f,  1.0f, 0.0f,
        -0.5f,  0.3f, -1.0f,  1.0f, 1.0f,
        -0.5f, -0.3f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.3f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.3f,  1.0f,  0.0f, 0.0f,
        -0.5f,  0.3f,  1.0f,  1.0f, 0.0f,

        // Face lateral direita
        0.5f,  0.3f,  1.0f,  1.0f, 0.0f,
        0.5f,  0.3f, -1.0f,  1.0f, 1.0f,
        0.5f, -0.3f, -1.0f,  0.0f, 1.0f,
        0.5f, -0.3f, -1.0f,  0.0f, 1.0f,
        0.5f, -0.3f,  1.0f,  0.0f, 0.0f,
        0.5f,  0.3f,  1.0f,  1.0f, 0.0f,

        // Face inferior
        -0.5f, -0.3f, -1.0f,  0.0f, 1.0f,
        0.5f, -0.3f, -1.0f,  1.0f, 1.0f,
        0.5f, -0.3f,  1.0f,  1.0f, 0.0f,
        0.5f, -0.3f,  1.0f,  1.0f, 0.0f,
        -0.5f, -0.3f,  1.0f,  0.0f, 0.0f,
        -0.5f, -0.3f, -1.0f,  0.0f, 1.0f,

        // Face superior
        -0.5f,  0.3f, -1.0f,  0.0f, 1.0f,
        0.5f,  0.3f, -1.0f,  1.0f, 1.0f,
        0.5f,  0.3f,  1.0f,  1.0f, 0.0f,
        0.5f,  0.3f,  1.0f,  1.0f, 0.0f,
        -0.5f,  0.3f,  1.0f,  0.0f, 0.0f,
        -0.5f,  0.3f, -1.0f,  0.0f, 1.0f
    };

    float topVertices[] = {
        // Face traseira
        -0.5f,  0.3f, -0.8f,  0.0f, 0.0f,
        0.5f,  0.3f, -0.8f,  1.0f, 0.0f,
        0.5f,  0.6f, -0.8f,  1.0f, 1.0f,
        0.5f,  0.6f, -0.8f,  1.0f, 1.0f,
        -0.5f,  0.6f, -0.8f,  0.0f, 1.0f,
        -0.5f,  0.3f, -0.8f,  0.0f, 0.0f,

        // Face frontal
        -0.5f,  0.3f,  0.8f,  0.0f, 0.0f,
        0.5f,  0.3f,  0.8f,  1.0f, 0.0f,
        0.5f,  0.6f,  0.8f,  1.0f, 1.0f,
        0.5f,  0.6f,  0.8f,  1.0f, 1.0f,
        -0.5f,  0.6f,  0.8f,  0.0f, 1.0f,
        -0.5f,  0.3f,  0.8f,  0.0f, 0.0f,

        // Face lateral esquerda
        -0.5f,  0.6f,  0.8f,  1.0f, 0.0f,
        -0.5f,  0.6f, -0.8f,  1.0f, 1.0f,
        -0.5f,  0.3f, -0.8f,  0.0f, 1.0f,
        -0.5f,  0.3f, -0.8f,  0.0f, 1.0f,
        -0.5f,  0.3f,  0.8f,  0.0f, 0.0f,
        -0.5f,  0.6f,  0.8f,  1.0f, 0.0f,

        // Face lateral direita
        0.5f,  0.6f,  0.8f,  1.0f, 0.0f,
        0.5f,  0.6f, -0.8f,  1.0f, 1.0f,
        0.5f,  0.3f, -0.8f,  0.0f, 1.0f,
        0.5f,  0.3f, -0.8f,  0.0f, 1.0f,
        0.5f,  0.3f,  0.8f,  0.0f, 0.0f,
        0.5f,  0.6f,  0.8f,  1.0f, 0.0f,

        // Face inferior
        -0.5f,  0.3f, -0.8f,  0.0f, 1.0f,
        0.5f,  0.3f, -0.8f,  1.0f, 1.0f,
        0.5f,  0.3f,  0.8f,  1.0f, 0.0f,
        0.5f,  0.3f,  0.8f,  1.0f, 0.0f,
        -0.5f,  0.3f,  0.8f,  0.0f, 0.0f,
        -0.5f,  0.3f, -0.8f,  0.0f, 1.0f,

        // Face superior
        -0.5f,  0.6f, -0.8f,  0.0f, 1.0f,
        0.5f,  0.6f, -0.8f,  1.0f, 1.0f,
        0.5f,  0.6f,  0.8f,  1.0f, 0.0f,
        0.5f,  0.6f,  0.8f,  1.0f, 0.0f,
        -0.5f,  0.6f,  0.8f,  0.0f, 0.0f,
        -0.5f,  0.6f, -0.8f,  0.0f, 1.0f
    };


    unsigned int VAO1, VBO1;
    unsigned int VAO2, VBO2;

    // Primeiro paralelepípedo
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(baseVertices), baseVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Segundo paralelepípedo
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    glBindVertexArray(VAO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(topVertices), topVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Desvincular para evitar erros
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    unsigned int squareVAO, squareVBO;
    glGenVertexArrays(1, &squareVAO);
    glGenBuffers(1, &squareVBO);

    glBindVertexArray(squareVAO);

    glBindBuffer(GL_ARRAY_BUFFER, squareVBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Desvincular VAO
    glBindVertexArray(0);


    float floorVertices[] = {
        // Posição        // Coordenadas de textura
        -5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
        5.0f, -0.5f,  5.0f,  1.0f, 0.0f,
        5.0f, -0.5f, -5.0f,  1.0f, 1.0f,
        5.0f, -0.5f, -5.0f,  1.0f, 1.0f,
        -5.0f, -0.5f, -5.0f,  0.0f, 1.0f,
        -5.0f, -0.5f,  5.0f,  0.0f, 0.0f
    };

    // Configuração do VAO e VBO para o chão
    unsigned int floorVAO, floorVBO;
    glGenVertexArrays(1, &floorVAO);
    glGenBuffers(1, &floorVBO);

    glBindVertexArray(floorVAO);
    glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);

    // Atributos de posição
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Atributos de coordenadas de textura
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);


    // load and create a texture
    // -------------------------
    unsigned int texture1, texture2;
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("res/images/pedra-28.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //load image, create texture and generate mipmaps
    data = stbi_load("res/images/Pista.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, texture2);

        // activate shader
        ourShader.use();

        // Ângulo de yaw (em graus)
        float yawAngle = -45.0f; 

        // Converta o yaw para radianos
        float yawRadians = glm::radians(yawAngle);

        // Calcule o novo vetor "cameraFront" com base no yaw
        cameraFront.x = cos(yawRadians); // Componente X
        cameraFront.z = sin(yawRadians); // Componente Z
        cameraFront = glm::normalize(cameraFront); // Normalize o vetor

        // Matrizes de transformação
        glm::mat4 model = glm::mat4(1.0f); // Inicialize a matriz modelo como identidade
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp); // Atualize a matriz de visão

        glm::mat4 projection = glm::mat4(1.0f); // Inicialize a matriz de projeção
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.setMat4("projection", projection);

         // Renderizar o primeiro paralelepípedo
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vértices (6 faces * 2 triângulos * 3 vértices)

        // Renderizar o segundo paralelepípedo
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vértices novamente

        // Renderizar o chão
        glBindVertexArray(floorVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture2); // Use a mesma textura do cubo

        glm::mat4 modelFloor = glm::mat4(1.0f);
        modelFloor = glm::translate(modelFloor, glm::vec3(0.0f, -1.0f, 0.0f));  // Desloca o chão para baixo
        modelFloor = glm::scale(modelFloor, glm::vec3(2.0f, 1.0f, 2.0f));
        ourShader.setMat4("model", modelFloor);
        glBindVertexArray(floorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);

    glDeleteVertexArrays(1, &VAO2);
    glDeleteBuffers(1, &VBO2);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    const float cameraSpeed = 0.05f;
    // ajustar de acordo com a velocidade do computador
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

