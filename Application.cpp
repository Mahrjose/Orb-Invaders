#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "src/includes/ErrorHandler.h"
#include "src/includes/GameUI.h"
#include "src/includes/IndexBuffer.h"
#include "src/includes/Renderer.h"
#include "src/includes/Shader.h"
#include "src/includes/Texture.h"
#include "src/includes/VertexArray.h"
#include "src/includes/VertexBuffer.h"

GLFWwindow* Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return nullptr;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(683, 738, "Orb Invader", NULL, NULL);
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

    // Shader shader("resources/shaders/basic.glsl");
    // shader.Bind();

    Renderer renderer;
    GameUI ui("../resources/shaders/MenuLine.shader");

    while (!glfwWindowShouldClose(window)) {
        renderer.Clear();
        ui.DrawLineDivider();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
