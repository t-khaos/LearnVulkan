#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

#include <GlfwGeneral.hpp>

int main() {
    VkExtent2D size;
    size.width = 800;
    size.height = 600;
    InitializeWindow(size);
    return 0;
}