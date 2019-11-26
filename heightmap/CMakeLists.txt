cmake_minimum_required(VERSION 3.1)
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type")
project(heightmap CXX)

# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
set(CMAKE_AUTOMOC ON)
set (CMAKE_CXX_STANDARD 11)
# OpenGL & GLEW library
find_package(OpenGL)

# executable
add_executable(heightmap main.cxx heightmapwidget.cpp)
qt5_use_modules(heightmap Widgets OpenGL)
target_link_libraries(heightmap ${QT_LIBRARIES} ${OPENGL_LIBRARIES})

enable_testing()
add_test(NAME t_heightmap COMMAND xvfb-run ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:heightmap> ${MAIN_ARGS})
