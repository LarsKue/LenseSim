cmake_minimum_required(VERSION 3.14)
project(LenseSim)

set(CMAKE_CXX_STANDARD 11)

# source files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE RESOURCES)

add_compile_options(-m64)

add_link_options(-static-libgcc -static-libstdc++)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -Wall -Wextra -Wshadow -Weffc++ -pedantic)
else()
    add_compile_options(-O2)
endif()

include_directories()
link_directories()

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

#target_link_libraries()