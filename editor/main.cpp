
#include <GlfwGeneral.hpp>

int main() {
    if (!initialize_window({ 1280, 720 })) {
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        set_window_title_with_fps();
    }

    terminate_window();
    return 0;
}