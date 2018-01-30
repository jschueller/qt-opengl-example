project(cube C)
cmake_minimum_required(VERSION 2.8.12)

# OpenGL & GLEW library
find_package(GLUT)
find_package(OpenGL)

# executable
add_executable(cube main.c)
include_directories(${GLUT_INCLUDE_DIRS})
target_link_libraries(cube ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
