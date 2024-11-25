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

float carroVertices[] = {
    1.3f, 1.0f, -0.5f, 0.875f, 0.5f,
    2.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    2.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    2.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    1.3f, 0.0f, 0.5f, 0.375f, 1.0f,
    2.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    1.3f, 1.0f, 0.5f, 0.625f, 0.0f,
    1.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    1.3f, 0.0f, 0.5f, 0.375f, 0.0f,
    2.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    1.3f, 0.0f, 0.5f, 0.125f, 0.75f,
    1.3f, -0.0f, -0.5f, 0.125f, 0.5f,
    2.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    2.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    2.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    1.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    2.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    1.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    1.3f, 1.0f, -0.5f, 0.875f, 0.5f,
    1.3f, 1.0f, 0.5f, 0.875f, 0.75f,
    2.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    2.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    1.3f, 1.0f, 0.5f, 0.625f, 1.0f,
    1.3f, 0.0f, 0.5f, 0.375f, 1.0f,
    1.3f, 1.0f, 0.5f, 0.625f, 0.0f,
    1.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    1.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    2.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    2.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    1.3f, 0.0f, 0.5f, 0.125f, 0.75f,
    2.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    2.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    2.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    1.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    2.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    2.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -2.25f, 4.449999f, -6.22f, 0.875f, 0.5f,
    2.25f, 4.45f, -0.22f, 0.625f, 0.75f,
    2.25f, 4.449999f, -6.22f, 0.625f, 0.5f,
    2.25f, 4.45f, -0.22f, 0.625f, 0.75f,
    -2.25f, 3.05f, -0.22f, 0.375f, 1.0f,
    2.25f, 3.05f, -0.22f, 0.375f, 0.75f,
    -2.25f, 4.45f, -0.22f, 0.625f, 0.0f,
    -2.25f, 3.049999f, -6.22f, 0.375f, 0.25f,
    -2.25f, 3.05f, -0.22f, 0.375f, 0.0f,
    2.25f, 3.049999f, -6.22f, 0.375f, 0.5f,
    -2.25f, 3.05f, -0.22f, 0.125f, 0.75f,
    -2.25f, 3.049999f, -6.22f, 0.125f, 0.5f,
    2.25f, 4.449999f, -6.22f, 0.625f, 0.5f,
    2.25f, 3.05f, -0.22f, 0.375f, 0.75f,
    2.25f, 3.049999f, -6.22f, 0.375f, 0.5f,
    -2.25f, 4.449999f, -6.22f, 0.625f, 0.25f,
    2.25f, 3.049999f, -6.22f, 0.375f, 0.5f,
    -2.25f, 3.049999f, -6.22f, 0.375f, 0.25f,
    -2.25f, 4.449999f, -6.22f, 0.875f, 0.5f,
    -2.25f, 4.45f, -0.22f, 0.875f, 0.75f,
    2.25f, 4.45f, -0.22f, 0.625f, 0.75f,
    2.25f, 4.45f, -0.22f, 0.625f, 0.75f,
    -2.25f, 4.45f, -0.22f, 0.625f, 1.0f,
    -2.25f, 3.05f, -0.22f, 0.375f, 1.0f,
    -2.25f, 4.45f, -0.22f, 0.625f, 0.0f,
    -2.25f, 4.449999f, -6.22f, 0.625f, 0.25f,
    -2.25f, 3.049999f, -6.22f, 0.375f, 0.25f,
    2.25f, 3.049999f, -6.22f, 0.375f, 0.5f,
    2.25f, 3.05f, -0.22f, 0.375f, 0.75f,
    -2.25f, 3.05f, -0.22f, 0.125f, 0.75f,
    2.25f, 4.449999f, -6.22f, 0.625f, 0.5f,
    2.25f, 4.45f, -0.22f, 0.625f, 0.75f,
    2.25f, 3.05f, -0.22f, 0.375f, 0.75f,
    -2.25f, 4.449999f, -6.22f, 0.625f, 0.25f,
    2.25f, 4.449999f, -6.22f, 0.625f, 0.5f,
    2.25f, 3.049999f, -6.22f, 0.375f, 0.5f,
    1.3f, 1.0f, -6.5f, 0.875f, 0.5f,
    2.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    2.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    2.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    1.3f, -0.0f, -5.5f, 0.375f, 1.0f,
    2.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    1.3f, 1.0f, -5.5f, 0.625f, 0.0f,
    1.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    1.3f, -0.0f, -5.5f, 0.375f, 0.0f,
    2.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    1.3f, -0.0f, -5.5f, 0.125f, 0.75f,
    1.3f, -0.0f, -6.5f, 0.125f, 0.5f,
    2.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    2.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    2.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    1.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    2.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    1.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    1.3f, 1.0f, -6.5f, 0.875f, 0.5f,
    1.3f, 1.0f, -5.5f, 0.875f, 0.75f,
    2.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    2.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    1.3f, 1.0f, -5.5f, 0.625f, 1.0f,
    1.3f, -0.0f, -5.5f, 0.375f, 1.0f,
    1.3f, 1.0f, -5.5f, 0.625f, 0.0f,
    1.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    1.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    2.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    2.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    1.3f, -0.0f, -5.5f, 0.125f, 0.75f,
    2.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    2.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    2.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    1.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    2.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    2.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -2.3f, 1.0f, -0.5f, 0.875f, 0.5f,
    -1.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    -1.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    -1.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    -2.3f, 0.0f, 0.5f, 0.375f, 1.0f,
    -1.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    -2.3f, 1.0f, 0.5f, 0.625f, 0.0f,
    -2.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    -2.3f, 0.0f, 0.5f, 0.375f, 0.0f,
    -1.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -2.3f, 0.0f, 0.5f, 0.125f, 0.75f,
    -2.3f, -0.0f, -0.5f, 0.125f, 0.5f,
    -1.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    -1.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    -1.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -2.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    -1.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -2.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    -2.3f, 1.0f, -0.5f, 0.875f, 0.5f,
    -2.3f, 1.0f, 0.5f, 0.875f, 0.75f,
    -1.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    -1.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    -2.3f, 1.0f, 0.5f, 0.625f, 1.0f,
    -2.3f, 0.0f, 0.5f, 0.375f, 1.0f,
    -2.3f, 1.0f, 0.5f, 0.625f, 0.0f,
    -2.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    -2.3f, -0.0f, -0.5f, 0.375f, 0.25f,
    -1.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -1.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    -2.3f, 0.0f, 0.5f, 0.125f, 0.75f,
    -1.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    -1.3f, 1.0f, 0.5f, 0.625f, 0.75f,
    -1.3f, 0.0f, 0.5f, 0.375f, 0.75f,
    -2.3f, 1.0f, -0.5f, 0.625f, 0.25f,
    -1.3f, 1.0f, -0.5f, 0.625f, 0.5f,
    -1.3f, -0.0f, -0.5f, 0.375f, 0.5f,
    -2.3f, 1.0f, -6.5f, 0.875f, 0.5f,
    -1.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    -1.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    -1.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    -2.3f, -0.0f, -5.5f, 0.375f, 1.0f,
    -1.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    -2.3f, 1.0f, -5.5f, 0.625f, 0.0f,
    -2.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    -2.3f, -0.0f, -5.5f, 0.375f, 0.0f,
    -1.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -2.3f, -0.0f, -5.5f, 0.125f, 0.75f,
    -2.3f, -0.0f, -6.5f, 0.125f, 0.5f,
    -1.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    -1.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    -1.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -2.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    -1.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -2.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    -2.3f, 1.0f, -6.5f, 0.875f, 0.5f,
    -2.3f, 1.0f, -5.5f, 0.875f, 0.75f,
    -1.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    -1.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    -2.3f, 1.0f, -5.5f, 0.625f, 1.0f,
    -2.3f, -0.0f, -5.5f, 0.375f, 1.0f,
    -2.3f, 1.0f, -5.5f, 0.625f, 0.0f,
    -2.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    -2.3f, -0.0f, -6.5f, 0.375f, 0.25f,
    -1.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -1.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    -2.3f, -0.0f, -5.5f, 0.125f, 0.75f,
    -1.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    -1.3f, 1.0f, -5.5f, 0.625f, 0.75f,
    -1.3f, -0.0f, -5.5f, 0.375f, 0.75f,
    -2.3f, 1.0f, -6.5f, 0.625f, 0.25f,
    -1.3f, 1.0f, -6.5f, 0.625f, 0.5f,
    -1.3f, -0.0f, -6.5f, 0.375f, 0.5f,
    -2.5f, 3.0f, -7.0f, 0.875f, 0.5f,
    2.5f, 3.0f, 1.0f, 0.625f, 0.75f,
    2.5f, 3.0f, -7.0f, 0.625f, 0.5f,
    2.5f, 3.0f, 1.0f, 0.625f, 0.75f,
    -2.5f, 1.0f, 1.0f, 0.375f, 1.0f,
    2.5f, 1.0f, 1.0f, 0.375f, 0.75f,
    -2.5f, 3.0f, 1.0f, 0.625f, 0.0f,
    -2.5f, 0.999999f, -7.0f, 0.375f, 0.25f,
    -2.5f, 1.0f, 1.0f, 0.375f, 0.0f,
    2.5f, 0.999999f, -7.0f, 0.375f, 0.5f,
    -2.5f, 1.0f, 1.0f, 0.125f, 0.75f,
    -2.5f, 0.999999f, -7.0f, 0.125f, 0.5f,
    2.5f, 3.0f, -7.0f, 0.625f, 0.5f,
    2.5f, 1.0f, 1.0f, 0.375f, 0.75f,
    2.5f, 0.999999f, -7.0f, 0.375f, 0.5f,
    -2.5f, 3.0f, -7.0f, 0.625f, 0.25f,
    2.5f, 0.999999f, -7.0f, 0.375f, 0.5f,
    -2.5f, 0.999999f, -7.0f, 0.375f, 0.25f,
    -2.5f, 3.0f, -7.0f, 0.875f, 0.5f,
    -2.5f, 3.0f, 1.0f, 0.875f, 0.75f,
    2.5f, 3.0f, 1.0f, 0.625f, 0.75f,
    2.5f, 3.0f, 1.0f, 0.625f, 0.75f,
    -2.5f, 3.0f, 1.0f, 0.625f, 1.0f,
    -2.5f, 1.0f, 1.0f, 0.375f, 1.0f,
    -2.5f, 3.0f, 1.0f, 0.625f, 0.0f,
    -2.5f, 3.0f, -7.0f, 0.625f, 0.25f,
    -2.5f, 0.999999f, -7.0f, 0.375f, 0.25f,
    2.5f, 0.999999f, -7.0f, 0.375f, 0.5f,
    2.5f, 1.0f, 1.0f, 0.375f, 0.75f,
    -2.5f, 1.0f, 1.0f, 0.125f, 0.75f,
    2.5f, 3.0f, -7.0f, 0.625f, 0.5f,
    2.5f, 3.0f, 1.0f, 0.625f, 0.75f,
    2.5f, 1.0f, 1.0f, 0.375f, 0.75f,
    -2.5f, 3.0f, -7.0f, 0.625f, 0.25f,
    2.5f, 3.0f, -7.0f, 0.625f, 0.5f,
    2.5f, 0.999999f, -7.0f, 0.375f, 0.5f
};

float placaVertices[] = {
    0.0f, 5.47798f, -0.11137f, 1.0f, 1.0f,
    0.02222f, 0.0f, -0.10919f, 0.96875f, 0.5f,
    0.0f, 0.0f, -0.11137f, 1.0f, 0.5f,
    0.02222f, 5.47798f, -0.10919f, 0.96875f, 1.0f,
    0.04358f, 0.0f, -0.1027f, 0.9375f, 0.5f,
    0.02222f, 0.0f, -0.10919f, 0.96875f, 0.5f,
    0.04358f, 5.47798f, -0.1027f, 0.9375f, 1.0f,
    0.06327f, 0.0f, -0.09218f, 0.90625f, 0.5f,
    0.04358f, 0.0f, -0.1027f, 0.9375f, 0.5f,
    0.06327f, 5.47798f, -0.09218f, 0.90625f, 1.0f,
    0.08053f, 0.0f, -0.07802f, 0.875f, 0.5f,
    0.06327f, 0.0f, -0.09218f, 0.90625f, 0.5f,
    0.08053f, 5.47798f, -0.07802f, 0.875f, 1.0f,
    0.09469f, 0.0f, -0.06076f, 0.84375f, 0.5f,
    0.08053f, 0.0f, -0.07802f, 0.875f, 0.5f,
    0.09469f, 5.47798f, -0.06076f, 0.84375f, 1.0f,
    0.10521f, 0.0f, -0.04107f, 0.8125f, 0.5f,
    0.09469f, 0.0f, -0.06076f, 0.84375f, 0.5f,
    0.10521f, 5.47798f, -0.04107f, 0.8125f, 1.0f,
    0.11169f, 0.0f, -0.01971f, 0.78125f, 0.5f,
    0.10521f, 0.0f, -0.04107f, 0.8125f, 0.5f,
    0.11169f, 5.47798f, -0.01971f, 0.78125f, 1.0f,
    0.11388f, 0.0f, 0.00251f, 0.75f, 0.5f,
    0.11169f, 0.0f, -0.01971f, 0.78125f, 0.5f,
    0.11388f, 5.47798f, 0.00251f, 0.75f, 1.0f,
    0.11169f, 0.0f, 0.02473f, 0.71875f, 0.5f,
    0.11388f, 0.0f, 0.00251f, 0.75f, 0.5f,
    0.11169f, 5.47798f, 0.02473f, 0.71875f, 1.0f,
    0.10521f, 0.0f, 0.04609f, 0.6875f, 0.5f,
    0.11169f, 0.0f, 0.02473f, 0.71875f, 0.5f,
    0.10521f, 5.47798f, 0.04609f, 0.6875f, 1.0f,
    0.09469f, 0.0f, 0.06578f, 0.65625f, 0.5f,
    0.10521f, 0.0f, 0.04609f, 0.6875f, 0.5f,
    0.09469f, 5.47798f, 0.06578f, 0.65625f, 1.0f,
    0.08053f, 0.0f, 0.08303f, 0.625f, 0.5f,
    0.09469f, 0.0f, 0.06578f, 0.65625f, 0.5f,
    0.08053f, 5.47798f, 0.08303f, 0.625f, 1.0f,
    0.06327f, 0.0f, 0.0972f, 0.59375f, 0.5f,
    0.08053f, 0.0f, 0.08303f, 0.625f, 0.5f,
    0.06327f, 5.47798f, 0.0972f, 0.59375f, 1.0f,
    0.04358f, 0.0f, 0.10772f, 0.5625f, 0.5f,
    0.06327f, 0.0f, 0.0972f, 0.59375f, 0.5f,
    0.04358f, 5.47798f, 0.10772f, 0.5625f, 1.0f,
    0.02222f, 0.0f, 0.1142f, 0.53125f, 0.5f,
    0.04358f, 0.0f, 0.10772f, 0.5625f, 0.5f,
    0.02222f, 5.47798f, 0.1142f, 0.53125f, 1.0f,
    0.0f, 0.0f, 0.11639f, 0.5f, 0.5f,
    0.02222f, 0.0f, 0.1142f, 0.53125f, 0.5f,
    0.0f, 5.47798f, 0.11639f, 0.5f, 1.0f,
    -0.02222f, 0.0f, 0.1142f, 0.46875f, 0.5f,
    0.0f, 0.0f, 0.11639f, 0.5f, 0.5f,
    -0.02222f, 5.47798f, 0.1142f, 0.46875f, 1.0f,
    -0.04358f, 0.0f, 0.10772f, 0.4375f, 0.5f,
    -0.02222f, 0.0f, 0.1142f, 0.46875f, 0.5f,
    -0.04358f, 5.47798f, 0.10772f, 0.4375f, 1.0f,
    -0.06327f, 0.0f, 0.0972f, 0.40625f, 0.5f,
    -0.04358f, 0.0f, 0.10772f, 0.4375f, 0.5f,
    -0.06327f, 5.47798f, 0.0972f, 0.40625f, 1.0f,
    -0.08053f, 0.0f, 0.08303f, 0.375f, 0.5f,
    -0.06327f, 0.0f, 0.0972f, 0.40625f, 0.5f,
    -0.08053f, 5.47798f, 0.08303f, 0.375f, 1.0f,
    -0.09469f, 0.0f, 0.06578f, 0.34375f, 0.5f,
    -0.08053f, 0.0f, 0.08303f, 0.375f, 0.5f,
    -0.09469f, 5.47798f, 0.06578f, 0.34375f, 1.0f,
    -0.10521f, 0.0f, 0.04609f, 0.3125f, 0.5f,
    -0.09469f, 0.0f, 0.06578f, 0.34375f, 0.5f,
    -0.10521f, 5.47798f, 0.04609f, 0.3125f, 1.0f,
    -0.11169f, 0.0f, 0.02473f, 0.28125f, 0.5f,
    -0.10521f, 0.0f, 0.04609f, 0.3125f, 0.5f,
    -0.11169f, 5.47798f, 0.02473f, 0.28125f, 1.0f,
    -0.11388f, 0.0f, 0.00251f, 0.25f, 0.5f,
    -0.11169f, 0.0f, 0.02473f, 0.28125f, 0.5f,
    -0.11388f, 5.47798f, 0.00251f, 0.25f, 1.0f,
    -0.11169f, 0.0f, -0.01971f, 0.21875f, 0.5f,
    -0.11388f, 0.0f, 0.00251f, 0.25f, 0.5f,
    -0.11169f, 5.47798f, -0.01971f, 0.21875f, 1.0f,
    -0.10521f, 0.0f, -0.04107f, 0.1875f, 0.5f,
    -0.11169f, 0.0f, -0.01971f, 0.21875f, 0.5f,
    -0.10521f, 5.47798f, -0.04107f, 0.1875f, 1.0f,
    -0.09469f, 0.0f, -0.06076f, 0.15625f, 0.5f,
    -0.10521f, 0.0f, -0.04107f, 0.1875f, 0.5f,
    -0.09469f, 5.47798f, -0.06076f, 0.15625f, 1.0f,
    -0.08053f, 0.0f, -0.07802f, 0.125f, 0.5f,
    -0.09469f, 0.0f, -0.06076f, 0.15625f, 0.5f,
    -0.08053f, 5.47798f, -0.07802f, 0.125f, 1.0f,
    -0.06327f, 0.0f, -0.09218f, 0.09375f, 0.5f,
    -0.08053f, 0.0f, -0.07802f, 0.125f, 0.5f,
    -0.06327f, 5.47798f, -0.09218f, 0.09375f, 1.0f,
    -0.04358f, 0.0f, -0.1027f, 0.0625f, 0.5f,
    -0.06327f, 0.0f, -0.09218f, 0.09375f, 0.5f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    -0.04358f, 5.47798f, -0.1027f, 0.0625f, 1.0f,
    -0.02222f, 0.0f, -0.10919f, 0.03125f, 0.5f,
    -0.04358f, 0.0f, -0.1027f, 0.0625f, 0.5f,
    -0.02222f, 5.47798f, -0.10919f, 0.03125f, 1.0f,
    0.0f, 0.0f, -0.11137f, 0.0f, 0.5f,
    -0.02222f, 0.0f, -0.10919f, 0.03125f, 0.5f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    0.0f, 5.47798f, -0.11137f, 1.0f, 1.0f,
    0.02222f, 5.47798f, -0.10919f, 0.96875f, 1.0f,
    0.02222f, 0.0f, -0.10919f, 0.96875f, 0.5f,
    0.02222f, 5.47798f, -0.10919f, 0.96875f, 1.0f,
    0.04358f, 5.47798f, -0.1027f, 0.9375f, 1.0f,
    0.04358f, 0.0f, -0.1027f, 0.9375f, 0.5f,
    0.04358f, 5.47798f, -0.1027f, 0.9375f, 1.0f,
    0.06327f, 5.47798f, -0.09218f, 0.90625f, 1.0f,
    0.06327f, 0.0f, -0.09218f, 0.90625f, 0.5f,
    0.06327f, 5.47798f, -0.09218f, 0.90625f, 1.0f,
    0.08053f, 5.47798f, -0.07802f, 0.875f, 1.0f,
    0.08053f, 0.0f, -0.07802f, 0.875f, 0.5f,
    0.08053f, 5.47798f, -0.07802f, 0.875f, 1.0f,
    0.09469f, 5.47798f, -0.06076f, 0.84375f, 1.0f,
    0.09469f, 0.0f, -0.06076f, 0.84375f, 0.5f,
    0.09469f, 5.47798f, -0.06076f, 0.84375f, 1.0f,
    0.10521f, 5.47798f, -0.04107f, 0.8125f, 1.0f,
    0.10521f, 0.0f, -0.04107f, 0.8125f, 0.5f,
    0.10521f, 5.47798f, -0.04107f, 0.8125f, 1.0f,
    0.11169f, 5.47798f, -0.01971f, 0.78125f, 1.0f,
    0.11169f, 0.0f, -0.01971f, 0.78125f, 0.5f,
    0.11169f, 5.47798f, -0.01971f, 0.78125f, 1.0f,
    0.11388f, 5.47798f, 0.00251f, 0.75f, 1.0f,
    0.11388f, 0.0f, 0.00251f, 0.75f, 0.5f,
    0.11388f, 5.47798f, 0.00251f, 0.75f, 1.0f,
    0.11169f, 5.47798f, 0.02473f, 0.71875f, 1.0f,
    0.11169f, 0.0f, 0.02473f, 0.71875f, 0.5f,
    0.11169f, 5.47798f, 0.02473f, 0.71875f, 1.0f,
    0.10521f, 5.47798f, 0.04609f, 0.6875f, 1.0f,
    0.10521f, 0.0f, 0.04609f, 0.6875f, 0.5f,
    0.10521f, 5.47798f, 0.04609f, 0.6875f, 1.0f,
    0.09469f, 5.47798f, 0.06578f, 0.65625f, 1.0f,
    0.09469f, 0.0f, 0.06578f, 0.65625f, 0.5f,
    0.09469f, 5.47798f, 0.06578f, 0.65625f, 1.0f,
    0.08053f, 5.47798f, 0.08303f, 0.625f, 1.0f,
    0.08053f, 0.0f, 0.08303f, 0.625f, 0.5f,
    0.08053f, 5.47798f, 0.08303f, 0.625f, 1.0f,
    0.06327f, 5.47798f, 0.0972f, 0.59375f, 1.0f,
    0.06327f, 0.0f, 0.0972f, 0.59375f, 0.5f,
    0.06327f, 5.47798f, 0.0972f, 0.59375f, 1.0f,
    0.04358f, 5.47798f, 0.10772f, 0.5625f, 1.0f,
    0.04358f, 0.0f, 0.10772f, 0.5625f, 0.5f,
    0.04358f, 5.47798f, 0.10772f, 0.5625f, 1.0f,
    0.02222f, 5.47798f, 0.1142f, 0.53125f, 1.0f,
    0.02222f, 0.0f, 0.1142f, 0.53125f, 0.5f,
    0.02222f, 5.47798f, 0.1142f, 0.53125f, 1.0f,
    0.0f, 5.47798f, 0.11639f, 0.5f, 1.0f,
    0.0f, 0.0f, 0.11639f, 0.5f, 0.5f,
    0.0f, 5.47798f, 0.11639f, 0.5f, 1.0f,
    -0.02222f, 5.47798f, 0.1142f, 0.46875f, 1.0f,
    -0.02222f, 0.0f, 0.1142f, 0.46875f, 0.5f,
    -0.02222f, 5.47798f, 0.1142f, 0.46875f, 1.0f,
    -0.04358f, 5.47798f, 0.10772f, 0.4375f, 1.0f,
    -0.04358f, 0.0f, 0.10772f, 0.4375f, 0.5f,
    -0.04358f, 5.47798f, 0.10772f, 0.4375f, 1.0f,
    -0.06327f, 5.47798f, 0.0972f, 0.40625f, 1.0f,
    -0.06327f, 0.0f, 0.0972f, 0.40625f, 0.5f,
    -0.06327f, 5.47798f, 0.0972f, 0.40625f, 1.0f,
    -0.08053f, 5.47798f, 0.08303f, 0.375f, 1.0f,
    -0.08053f, 0.0f, 0.08303f, 0.375f, 0.5f,
    -0.08053f, 5.47798f, 0.08303f, 0.375f, 1.0f,
    -0.09469f, 5.47798f, 0.06578f, 0.34375f, 1.0f,
    -0.09469f, 0.0f, 0.06578f, 0.34375f, 0.5f,
    -0.09469f, 5.47798f, 0.06578f, 0.34375f, 1.0f,
    -0.10521f, 5.47798f, 0.04609f, 0.3125f, 1.0f,
    -0.10521f, 0.0f, 0.04609f, 0.3125f, 0.5f,
    -0.10521f, 5.47798f, 0.04609f, 0.3125f, 1.0f,
    -0.11169f, 5.47798f, 0.02473f, 0.28125f, 1.0f,
    -0.11169f, 0.0f, 0.02473f, 0.28125f, 0.5f,
    -0.11169f, 5.47798f, 0.02473f, 0.28125f, 1.0f,
    -0.11388f, 5.47798f, 0.00251f, 0.25f, 1.0f,
    -0.11388f, 0.0f, 0.00251f, 0.25f, 0.5f,
    -0.11388f, 5.47798f, 0.00251f, 0.25f, 1.0f,
    -0.11169f, 5.47798f, -0.01971f, 0.21875f, 1.0f,
    -0.11169f, 0.0f, -0.01971f, 0.21875f, 0.5f,
    -0.11169f, 5.47798f, -0.01971f, 0.21875f, 1.0f,
    -0.10521f, 5.47798f, -0.04107f, 0.1875f, 1.0f,
    -0.10521f, 0.0f, -0.04107f, 0.1875f, 0.5f,
    -0.10521f, 5.47798f, -0.04107f, 0.1875f, 1.0f,
    -0.09469f, 5.47798f, -0.06076f, 0.15625f, 1.0f,
    -0.09469f, 0.0f, -0.06076f, 0.15625f, 0.5f,
    -0.09469f, 5.47798f, -0.06076f, 0.15625f, 1.0f,
    -0.08053f, 5.47798f, -0.07802f, 0.125f, 1.0f,
    -0.08053f, 0.0f, -0.07802f, 0.125f, 0.5f,
    -0.08053f, 5.47798f, -0.07802f, 0.125f, 1.0f,
    -0.06327f, 5.47798f, -0.09218f, 0.09375f, 1.0f,
    -0.06327f, 0.0f, -0.09218f, 0.09375f, 0.5f,
    -0.06327f, 5.47798f, -0.09218f, 0.09375f, 1.0f,
    -0.04358f, 5.47798f, -0.1027f, 0.0625f, 1.0f,
    -0.04358f, 0.0f, -0.1027f, 0.0625f, 0.5f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    0.02222f, 5.47798f, -0.10919f, 0.29682f, 0.48539f,
    0.0f, 5.47798f, -0.11137f, 0.25f, 0.49f,
    0.0f, 5.47798f, -0.11137f, 0.25f, 0.49f,
    -0.02222f, 5.47798f, -0.10919f, 0.20318f, 0.48539f,
    -0.04358f, 5.47798f, -0.1027f, 0.15816f, 0.47173f,
    -0.04358f, 5.47798f, -0.1027f, 0.15816f, 0.47173f,
    -0.06327f, 5.47798f, -0.09218f, 0.11666f, 0.44955f,
    -0.08053f, 5.47798f, -0.07802f, 0.08029f, 0.41971f,
    -0.08053f, 5.47798f, -0.07802f, 0.08029f, 0.41971f,
    -0.09469f, 5.47798f, -0.06076f, 0.05045f, 0.38334f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.11169f, 5.47798f, -0.01971f, 0.01461f, 0.29682f,
    -0.11388f, 5.47798f, 0.00251f, 0.01f, 0.25f,
    -0.11388f, 5.47798f, 0.00251f, 0.01f, 0.25f,
    -0.11169f, 5.47798f, 0.02473f, 0.01461f, 0.20318f,
    -0.10521f, 5.47798f, 0.04609f, 0.02827f, 0.15816f,
    -0.10521f, 5.47798f, 0.04609f, 0.02827f, 0.15816f,
    -0.09469f, 5.47798f, 0.06578f, 0.05045f, 0.11666f,
    -0.08053f, 5.47798f, 0.08303f, 0.08029f, 0.08029f,
    -0.08053f, 5.47798f, 0.08303f, 0.08029f, 0.08029f,
    -0.06327f, 5.47798f, 0.0972f, 0.11666f, 0.05045f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    -0.02222f, 5.47798f, 0.1142f, 0.20318f, 0.01461f,
    0.0f, 5.47798f, 0.11639f, 0.25f, 0.01f,
    0.0f, 5.47798f, 0.11639f, 0.25f, 0.01f,
    0.02222f, 5.47798f, 0.1142f, 0.29682f, 0.01461f,
    0.04358f, 5.47798f, 0.10772f, 0.34184f, 0.02827f,
    0.04358f, 5.47798f, 0.10772f, 0.34184f, 0.02827f,
    0.06327f, 5.47798f, 0.0972f, 0.38334f, 0.05045f,
    0.08053f, 5.47798f, 0.08303f, 0.41971f, 0.08029f,
    0.08053f, 5.47798f, 0.08303f, 0.41971f, 0.08029f,
    0.09469f, 5.47798f, 0.06578f, 0.44955f, 0.11666f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.11169f, 5.47798f, 0.02473f, 0.48539f, 0.20318f,
    0.11388f, 5.47798f, 0.00251f, 0.49f, 0.25f,
    0.11388f, 5.47798f, 0.00251f, 0.49f, 0.25f,
    0.11169f, 5.47798f, -0.01971f, 0.48539f, 0.29682f,
    0.10521f, 5.47798f, -0.04107f, 0.47173f, 0.34184f,
    0.10521f, 5.47798f, -0.04107f, 0.47173f, 0.34184f,
    0.09469f, 5.47798f, -0.06076f, 0.44955f, 0.38334f,
    0.08053f, 5.47798f, -0.07802f, 0.41971f, 0.41971f,
    0.08053f, 5.47798f, -0.07802f, 0.41971f, 0.41971f,
    0.06327f, 5.47798f, -0.09218f, 0.38334f, 0.44955f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    0.0f, 5.47798f, -0.11137f, 0.25f, 0.49f,
    -0.04358f, 5.47798f, -0.1027f, 0.15816f, 0.47173f,
    -0.04358f, 5.47798f, -0.1027f, 0.15816f, 0.47173f,
    -0.08053f, 5.47798f, -0.07802f, 0.08029f, 0.41971f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.11388f, 5.47798f, 0.00251f, 0.01f, 0.25f,
    -0.10521f, 5.47798f, 0.04609f, 0.02827f, 0.15816f,
    -0.10521f, 5.47798f, 0.04609f, 0.02827f, 0.15816f,
    -0.08053f, 5.47798f, 0.08303f, 0.08029f, 0.08029f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    0.0f, 5.47798f, 0.11639f, 0.25f, 0.01f,
    0.04358f, 5.47798f, 0.10772f, 0.34184f, 0.02827f,
    0.04358f, 5.47798f, 0.10772f, 0.34184f, 0.02827f,
    0.08053f, 5.47798f, 0.08303f, 0.41971f, 0.08029f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.11388f, 5.47798f, 0.00251f, 0.49f, 0.25f,
    0.10521f, 5.47798f, -0.04107f, 0.47173f, 0.34184f,
    0.10521f, 5.47798f, -0.04107f, 0.47173f, 0.34184f,
    0.08053f, 5.47798f, -0.07802f, 0.41971f, 0.41971f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    -0.04358f, 5.47798f, -0.1027f, 0.15816f, 0.47173f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.10521f, 5.47798f, 0.04609f, 0.02827f, 0.15816f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    0.04358f, 5.47798f, 0.10772f, 0.34184f, 0.02827f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.10521f, 5.47798f, 0.04609f, 0.47173f, 0.15816f,
    0.10521f, 5.47798f, -0.04107f, 0.47173f, 0.34184f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    0.04358f, 5.47798f, -0.1027f, 0.34184f, 0.47173f,
    -0.10521f, 5.47798f, -0.04107f, 0.02827f, 0.34184f,
    -0.04358f, 5.47798f, 0.10772f, 0.15816f, 0.02827f,
    -0.04358f, 5.47798f, -0.1027f, 0.0625f, 1.0f,
    -0.02222f, 5.47798f, -0.10919f, 0.03125f, 1.0f,
    -0.02222f, 0.0f, -0.10919f, 0.03125f, 0.5f,
    -0.02222f, 5.47798f, -0.10919f, 0.03125f, 1.0f,
    0.0f, 5.47798f, -0.11137f, 0.0f, 1.0f,
    0.0f, 0.0f, -0.11137f, 0.0f, 0.5f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    0.0f, 0.0f, -0.11137f, 0.75f, 0.49f,
    0.02222f, 0.0f, -0.10919f, 0.79682f, 0.48539f,
    0.02222f, 0.0f, -0.10919f, 0.79682f, 0.48539f,
    0.04358f, 0.0f, -0.1027f, 0.84184f, 0.47173f,
    0.06327f, 0.0f, -0.09218f, 0.88334f, 0.44955f,
    0.06327f, 0.0f, -0.09218f, 0.88334f, 0.44955f,
    0.08053f, 0.0f, -0.07802f, 0.91971f, 0.41971f,
    0.09469f, 0.0f, -0.06076f, 0.94955f, 0.38334f,
    0.09469f, 0.0f, -0.06076f, 0.94955f, 0.38334f,
    0.10521f, 0.0f, -0.04107f, 0.97173f, 0.34184f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.11388f, 0.0f, 0.00251f, 0.99f, 0.25f,
    0.11169f, 0.0f, 0.02473f, 0.98539f, 0.20318f,
    0.11169f, 0.0f, 0.02473f, 0.98539f, 0.20318f,
    0.10521f, 0.0f, 0.04609f, 0.97173f, 0.15816f,
    0.09469f, 0.0f, 0.06578f, 0.94955f, 0.11666f,
    0.09469f, 0.0f, 0.06578f, 0.94955f, 0.11666f,
    0.08053f, 0.0f, 0.08303f, 0.91971f, 0.08029f,
    0.06327f, 0.0f, 0.0972f, 0.88334f, 0.05045f,
    0.06327f, 0.0f, 0.0972f, 0.88334f, 0.05045f,
    0.04358f, 0.0f, 0.10772f, 0.84184f, 0.02827f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    0.0f, 0.0f, 0.11639f, 0.75f, 0.01f,
    -0.02222f, 0.0f, 0.1142f, 0.70318f, 0.01461f,
    -0.02222f, 0.0f, 0.1142f, 0.70318f, 0.01461f,
    -0.04358f, 0.0f, 0.10772f, 0.65816f, 0.02827f,
    -0.06327f, 0.0f, 0.0972f, 0.61666f, 0.05045f,
    -0.06327f, 0.0f, 0.0972f, 0.61666f, 0.05045f,
    -0.08053f, 0.0f, 0.08303f, 0.58029f, 0.08029f,
    -0.09469f, 0.0f, 0.06578f, 0.55045f, 0.11666f,
    -0.09469f, 0.0f, 0.06578f, 0.55045f, 0.11666f,
    -0.10521f, 0.0f, 0.04609f, 0.52827f, 0.15816f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.11388f, 0.0f, 0.00251f, 0.51f, 0.25f,
    -0.11169f, 0.0f, -0.01971f, 0.51461f, 0.29682f,
    -0.11169f, 0.0f, -0.01971f, 0.51461f, 0.29682f,
    -0.10521f, 0.0f, -0.04107f, 0.52827f, 0.34184f,
    -0.09469f, 0.0f, -0.06076f, 0.55045f, 0.38334f,
    -0.09469f, 0.0f, -0.06076f, 0.55045f, 0.38334f,
    -0.08053f, 0.0f, -0.07802f, 0.58029f, 0.41971f,
    -0.06327f, 0.0f, -0.09218f, 0.61666f, 0.44955f,
    -0.06327f, 0.0f, -0.09218f, 0.61666f, 0.44955f,
    -0.04358f, 0.0f, -0.1027f, 0.65816f, 0.47173f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    0.02222f, 0.0f, -0.10919f, 0.79682f, 0.48539f,
    0.06327f, 0.0f, -0.09218f, 0.88334f, 0.44955f,
    0.06327f, 0.0f, -0.09218f, 0.88334f, 0.44955f,
    0.09469f, 0.0f, -0.06076f, 0.94955f, 0.38334f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.11169f, 0.0f, 0.02473f, 0.98539f, 0.20318f,
    0.09469f, 0.0f, 0.06578f, 0.94955f, 0.11666f,
    0.09469f, 0.0f, 0.06578f, 0.94955f, 0.11666f,
    0.06327f, 0.0f, 0.0972f, 0.88334f, 0.05045f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    -0.02222f, 0.0f, 0.1142f, 0.70318f, 0.01461f,
    -0.06327f, 0.0f, 0.0972f, 0.61666f, 0.05045f,
    -0.06327f, 0.0f, 0.0972f, 0.61666f, 0.05045f,
    -0.09469f, 0.0f, 0.06578f, 0.55045f, 0.11666f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.11169f, 0.0f, -0.01971f, 0.51461f, 0.29682f,
    -0.09469f, 0.0f, -0.06076f, 0.55045f, 0.38334f,
    -0.09469f, 0.0f, -0.06076f, 0.55045f, 0.38334f,
    -0.06327f, 0.0f, -0.09218f, 0.61666f, 0.44955f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    0.06327f, 0.0f, -0.09218f, 0.88334f, 0.44955f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.09469f, 0.0f, 0.06578f, 0.94955f, 0.11666f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    -0.06327f, 0.0f, 0.0972f, 0.61666f, 0.05045f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.11169f, 0.0f, 0.02473f, 0.51461f, 0.20318f,
    -0.09469f, 0.0f, -0.06076f, 0.55045f, 0.38334f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    -0.02222f, 0.0f, -0.10919f, 0.70318f, 0.48539f,
    0.11169f, 0.0f, -0.01971f, 0.98539f, 0.29682f,
    0.02222f, 0.0f, 0.1142f, 0.79682f, 0.01461f,
    -1.05782f, 3.78637f, -0.31016f, 0.625f, 0.0f,
    1.05782f, 3.78637f, -0.08984f, 0.375f, 0.25f,
    -1.05782f, 3.78637f, -0.08984f, 0.375f, 0.0f,
    1.05782f, 3.78637f, -0.31016f, 0.625f, 0.25f,
    1.05782f, 5.90201f, -0.08984f, 0.375f, 0.5f,
    1.05782f, 3.78637f, -0.08984f, 0.375f, 0.25f,
    1.05782f, 5.90201f, -0.31016f, 0.625f, 0.5f,
    -1.05782f, 5.90201f, -0.08984f, 0.375f, 0.75f,
    1.05782f, 5.90201f, -0.08984f, 0.375f, 0.5f,
    -1.05782f, 5.90201f, -0.31016f, 0.625f, 0.75f,
    -1.05782f, 3.78637f, -0.08984f, 0.375f, 1.0f,
    -1.05782f, 5.90201f, -0.08984f, 0.375f, 0.75f,
    1.05782f, 5.90201f, -0.08984f, 0.375f, 0.5f,
    -1.05782f, 3.78637f, -0.08984f, 0.125f, 0.75f,
    1.05782f, 3.78637f, -0.08984f, 0.125f, 0.5f,
    1.05782f, 3.78637f, -0.31016f, 0.875f, 0.5f,
    -1.05782f, 5.90201f, -0.31016f, 0.625f, 0.75f,
    1.05782f, 5.90201f, -0.31016f, 0.625f, 0.5f,
    -1.05782f, 3.78637f, -0.31016f, 0.625f, 0.0f,
    1.05782f, 3.78637f, -0.31016f, 0.625f, 0.25f,
    1.05782f, 3.78637f, -0.08984f, 0.375f, 0.25f,
    1.05782f, 3.78637f, -0.31016f, 0.625f, 0.25f,
    1.05782f, 5.90201f, -0.31016f, 0.625f, 0.5f,
    1.05782f, 5.90201f, -0.08984f, 0.375f, 0.5f,
    1.05782f, 5.90201f, -0.31016f, 0.625f, 0.5f,
    -1.05782f, 5.90201f, -0.31016f, 0.625f, 0.75f,
    -1.05782f, 5.90201f, -0.08984f, 0.375f, 0.75f,
    -1.05782f, 5.90201f, -0.31016f, 0.625f, 0.75f,
    -1.05782f, 3.78637f, -0.31016f, 0.625f, 1.0f,
    -1.05782f, 3.78637f, -0.08984f, 0.375f, 1.0f,
    1.05782f, 5.90201f, -0.08984f, 0.375f, 0.5f,
    -1.05782f, 5.90201f, -0.08984f, 0.375f, 0.75f,
    -1.05782f, 3.78637f, -0.08984f, 0.125f, 0.75f,
    1.05782f, 3.78637f, -0.31016f, 0.875f, 0.5f,
    -1.05782f, 3.78637f, -0.31016f, 0.875f, 0.75f,
    -1.05782f, 5.90201f, -0.31016f, 0.625f, 0.75f
};

float floorVertices[] = {
    -30.0f, -0.5f,  30.0f,  0.0f, 0.0f,
     30.0f, -0.5f,  30.0f,  1.0f, 0.0f,
     30.0f, -0.5f, -30.0f,  1.0f, 1.0f,
     30.0f, -0.5f, -30.0f,  1.0f, 1.0f,
    -30.0f, -0.5f, -30.0f,  0.0f, 1.0f,
    -30.0f, -0.5f,  30.0f,  0.0f, 0.0f
};

std::vector<glm::vec2> innerTrack = {
    glm::vec2(-23.0f,  3.0f),
    glm::vec2( 23.0f,  3.0f),
    glm::vec2( 23.0f, -3.0f),
    glm::vec2( 23.0f, -3.0f),
    glm::vec2(-23.0f, -3.0f),
    glm::vec2(-23.0f,  3.0f)
};

std::vector<glm::vec2> outerTrack = {
    glm::vec2(-28.0f,  10.0f),
    glm::vec2( 28.0f,  10.0f),
    glm::vec2( 28.0f, -10.0f),
    glm::vec2( 28.0f, -10.0f),
    glm::vec2(-28.0f, -10.0f),
    glm::vec2(-28.0f,  10.0f)
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

bool permitirMovimentacao = true;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(-45.0f, 2.0f, 45.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

glm::vec3 carroPosicao(-7.0f, -1.5f, 7.0f); // Origem
float velocidadeCarro = 0.05f;
float carroRotacao = 90.0f;                 // Rotação inicial

bool isPointInsidePolygon(const glm::vec2& point, const std::vector<glm::vec2>& polygon) {
    int intersections = 0;
    size_t n = polygon.size();

    for (size_t i = 0; i < n; i++) {
        glm::vec2 v1 = polygon[i];
        glm::vec2 v2 = polygon[(i + 1) % n];

        // Verifica se o ponto está entre a borda vertical do segmento
        if ((point.y > v1.y) != (point.y > v2.y)) {
            float xIntersection = v1.x + (point.y - v1.y) * (v2.x - v1.x) / (v2.y - v1.y);
            if (point.x < xIntersection) {
                intersections++;
            }
        }
    }

    // Retorna true se o número de interseções for ímpar (dentro do polígono)
    return intersections % 2 == 1;
}

bool isCarInsideTrack(const glm::vec2& carPosition, 
                      const std::vector<glm::vec2>& innerTrack, 
                      const std::vector<glm::vec2>& outerTrack) {
    // O carro deve estar:
    // - Fora do polígono interno
    // - Dentro do polígono externo
    return isPointInsidePolygon(carPosition, outerTrack) &&
           !isPointInsidePolygon(carPosition, innerTrack);
}

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
    unsigned int VAOcarro, VBOcarro;
    glGenVertexArrays(1, &VAOcarro);
    glGenBuffers(1, &VBOcarro);
    glBindVertexArray(VAOcarro);

    glBindBuffer(GL_ARRAY_BUFFER, VBOcarro);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carroVertices), carroVertices, GL_STATIC_DRAW);

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


    unsigned int placaVAO, placaVBO;
    // Gerar o VAO e o VBO
    glGenVertexArrays(1, &placaVAO);
    glGenBuffers(1, &placaVBO);

    // Vincular o VAO da placa
    glBindVertexArray(placaVAO);

    // Vincular o VBO e carregar os dados dos vértices
    glBindBuffer(GL_ARRAY_BUFFER, placaVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(placaVertices), placaVertices, GL_STATIC_DRAW);

    // Configurar o atributo de posição (layout location 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Configurar o atributo de coordenadas de textura (layout location 1)
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Desvincular o VAO e o VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    unsigned int coneVAO, coneVBO;

    // Gerar o VAO e o VBO
    glGenVertexArrays(1, &coneVAO);
    glGenBuffers(1, &coneVBO);

    // Vincular o VAO da placa
    glBindVertexArray(coneVAO);

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
    unsigned int texture1, texture2, texture3;
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
    unsigned char *data = stbi_load("res/images/sla.jpg", &width, &height, &nrChannels, 0);
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
    data = stbi_load("res/images/Chao.png", &width, &height, &nrChannels, 0);
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
        model = glm::translate(model, carroPosicao); // Translada para nova posição
        model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
        model = glm::rotate(model, glm::radians(carroRotacao), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotação inicial do carro 

        std::cout << "Posição: " << carroPosicao.x << " | " << carroPosicao.z;
        std::cout << "\nRotação: " << carroRotacao << " graus" << std::endl << "\n";

        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp); // Atualize a matriz de visão
        view = glm::rotate(view, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 1.0f)); // Rotação em torno do eixo X
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

        // Renderizar o carro
        glBindVertexArray(VAOcarro);
        glDrawArrays(GL_TRIANGLES, 0, 1000);
        glBindVertexArray(0); // Desvincular o VAO

        // Placa
        glBindVertexArray(placaVAO); // Certifique-se de ter configurado o VAO da placa
        glm::mat4 modelPlaca = glm::mat4(1.0f); // Matriz identidade
        modelPlaca = glm::translate(modelPlaca, glm::vec3(-4.0f, -1.5f, 11.5f)); // Posiciona a placa
        modelPlaca = glm::scale(modelPlaca, glm::vec3(0.50f, 0.60f, 0.50f)); // Ajuste o tamanho se necessário
        modelPlaca = glm::rotate(modelPlaca, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Sem rotação para este exemplo
        ourShader.setMat4("model", modelPlaca);
        glDrawArrays(GL_TRIANGLES, 0, 1000); // Use o número de vértices da placa (6 para dois triângulos de um retângulo)
        glBindVertexArray(0); // Desvincula o VAO

        // Chão
        glBindVertexArray(floorVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture2); // Use a mesma textura do cubo
        glm::mat4 modelFloor = glm::mat4(1.0f);
        modelFloor = glm::translate(modelFloor, glm::vec3(0.0f, -1.0f, 0.0f));  // Desloca o chão para baixo
        ourShader.setMat4("model", modelFloor);
        glBindVertexArray(floorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAOcarro);
    glDeleteBuffers(1, &VBOcarro);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    glm::vec2 carPosition = glm::vec2(carroPosicao.x, carroPosicao.z);

    // Rotação do carro
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        carroRotacao += 2.0f; // Rotaciona para a esquerda
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        carroRotacao -= 2.0f; // Rotaciona para a direita
    }

    // Converte o ângulo para radianos
    float anguloRad = glm::radians(carroRotacao);

    // Direção do movimento baseado na rotação
    glm::vec3 direcaoFrente = glm::vec3( sin(anguloRad), 0.0f,cos(anguloRad));

    if (isCarInsideTrack(carPosition, innerTrack, outerTrack)) {
        // Movimentação para frente ou para trás
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            carroPosicao += velocidadeCarro * direcaoFrente;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            carroPosicao -= velocidadeCarro * direcaoFrente;
        }       
    }

    // Normaliza a rotação para mantê-la dentro do intervalo [0, 360)
    if (carroRotacao >= 360.0f) carroRotacao -= 360.0f;
    if (carroRotacao < 0.0f) carroRotacao += 360.0f;

    if (!permitirMovimentacao) return; // Ignorar teclas

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    const float cameraSpeed = 0.05f;
    // ajustar de acordo com a velocidade do computador
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
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