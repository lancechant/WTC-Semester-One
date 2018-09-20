cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC -stdlib=libc++")

project(SFML)

include(FetchContent)


FetchContent_Declare(
  sfml_downloaded
set(BUILD_SHARED_LIBS true)
  URL https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip
)
FetchContent_GetProperties(sfml_downloaded)
  if(NOT sfml_downloaded_POPULATED)
    FetchContent_Populate(sfml_downloaded)
    add_subdirectory(${sfml_downloaded_SOURCE_DIR} ${sfml_downloaded_BINARY_DIR})
endif()

add_library(SFML SHARED
    src/Functions.cpp
)

target_link_libraries(SFML sfml-graphics sfml-system sfml-window)
