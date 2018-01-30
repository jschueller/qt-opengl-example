project(qt5test CXX)
cmake_minimum_required(VERSION 2.8.12)

# Qt library
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
set(CMAKE_AUTOMOC ON)
set (CMAKE_CXX_STANDARD 11)
# OpenGL & GLEW library
find_package(OpenGL)

# executable
add_executable(qt5test main.cxx heightmapwidget.cpp)
qt5_use_modules(qt5test Widgets OpenGL)
target_link_libraries(qt5test ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
