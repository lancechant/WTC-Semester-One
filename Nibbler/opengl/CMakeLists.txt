cmake_minimum_required (VERSION 3.0)

project(opengl)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

include(ExternalProject)

add_library(${PROJECT_NAME} SHARED
        src/Functions.cpp
        )

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/lib${PROJECT_NAME}d)

ExternalProject_Add(
        lib${PROJECT_NAME}src
        URL https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        -DGLFW_DEPENDENCIES_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}/Frameworks
        -DGLFW_MISC_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION})
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

add_dependencies(${PROJECT_NAME} lib${PROJECT_NAME}src)

target_link_libraries(${PROJECT_NAME} ${EXTERNAL_INSTALL_LOCATION}/lib/libglfw3.a)
