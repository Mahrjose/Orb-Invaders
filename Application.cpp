#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ErrorHandler.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

GLFWwindow* Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return nullptr;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(960, 540, "OpenGL Tutorials", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    // Enable OpenGL debugging
    ErrorHandler::EnableDebugOutput();
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    return window;
}

int main(void) {
    GLFWwindow* window = Initialize();
    if (!window) {
        return -1;
    }

    Renderer renderer;

    while (!glfwWindowShouldClose(window)) {
        renderer.Clear();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
