cmake_minimum_required (VERSION 3.0)

project(sdl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC -framework AudioToolbox -framework CoreAudio -framework Carbon -framework ForceFeedback -framework IOKit -framework Cocoa -framework CoreVideo -liconv -lm  -Wl,-undefined,error")
set(EXTERNAL_INSTALL_LOCATION ${PROJECT_SOURCE_DIR}/libsdld)
include(ExternalProject)
ExternalProject_Add(
    libsrc
    URL https://libsdl.org/release/SDL2-2.0.8.zip
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
add_library(sdl SHARED
        src/Functions.cpp)
   
include_directories(../../include/ include/ libsdld/include/)

add_dependencies(sdl libsrc)
target_link_libraries(sdl ${EXTERNAL_INSTALL_LOCATION}/lib/libSDL2.a ${EXTERNAL_INSTALL_LOCATION}/lib/libSDL2main.a)

