cmake_minimum_required(VERSION 3.10)
project(Orb-Invaders)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Enable ccache
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

# Set up source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/includes/*.h")
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "lib/**/*.cpp" "lib/**/*.h")

# Entry Point
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/Application.cpp)

add_executable(Orb-Invaders ${SOURCES} ${LIB_SOURCES})

# OpenGL preference
set(OpenGL_GL_PREFERENCE "GLVND")

# Find and link OpenGL libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Link the libraries to the executable
target_link_libraries(Orb-Invaders OpenGL::GL GLUT::GLUT GLEW::GLEW glfw)

# Include additional directories
target_include_directories(Orb-Invaders PRIVATE ./lib ./src)
