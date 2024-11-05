#include "VKBase.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#pragma comment(lib, "glfw3.lib") //链接编译所需的静态库

//窗口的指针，全局变量自动初始化为NULL
GLFWwindow* pWindow;
//显示器信息的指针
GLFWmonitor* pMonitor;
//窗口标题
const char* windowTitle = "LearnVulkan";


inline bool InitializeWindow(VkExtent2D size, bool fullScreen = false, bool isResizable = true,
                             bool limitFrameRate = true)
{
    if (!glfwInit())
    {
        std::cout << std::format("[ InitializeWindow ] ERROR\nFailed to initialize GLFW!\n");
        return false;
    }


    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, isResizable);

    pMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    pWindow = fullScreen
                  ? glfwCreateWindow(pMode->width, pMode->height, windowTitle, pMonitor, nullptr)
                  : glfwCreateWindow(size.width, size.height, windowTitle, nullptr, nullptr);

    if (!pWindow)
    {
        std::cout << std::format("[ InitializeWindow ] ERROR\nFailed to create GLFW window!\n");
        glfwTerminate();
        return false;
    }
    return true;
}

inline void TerminateWindow()
{
    glfwTerminate();
}

inline void SetWindowTitleWithFPS()
{
    static double currentTime = 0.0; //初始化局部静态变量
    static double lastTime = glfwGetTime();
    static double timeDiff;
    static int frameCount = -1;
    static std::stringstream ss;

    currentTime = glfwGetTime(); //更新当前时间和帧数
    frameCount++;
    if ((timeDiff = currentTime - lastTime) >= 1)
    {
        ss.precision(1);
        ss << windowTitle << "     " << std::fixed << frameCount / timeDiff << " FPS";
        glfwSetWindowTitle(pWindow, ss.str().c_str()); //当前时间差超过1s更新标题
        ss.str("");
        lastTime = glfwGetTime(); //更新上一帧时间
        frameCount = 0; //清空帧数计数器
    }
}

inline void MakeWindowFullScreen()
{
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, pMonitor, 0, 0, pMode->width, pMode->height, pMode->refreshRate);
}

inline void MakeWindowWindowed(VkOffset2D position, VkExtent2D size)
{
    const GLFWvidmode* pMode = glfwGetVideoMode(pMonitor);
    glfwSetWindowMonitor(pWindow, pMonitor,  position.x, position.y, pMode->width, pMode->height, pMode->refreshRate);
}
