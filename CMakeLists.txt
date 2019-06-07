cmake_minimum_required(VERSION 3.13)
project(LenseSim VERSION 0.1.0 DESCRIPTION "A 2-dimensional Lense and Light Simulator")

set(CMAKE_CXX_STANDARD 11)

# source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE RESOURCES)

add_compile_options(-m64)

add_link_options(-static-libgcc -static-libstdc++)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -W -Wall -Wextra -Wshadow -Weffc++ -pedantic)
else()
    add_compile_options(-O2)
endif()

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# add SFML to the project
set(SFML_ROOT ${PROJECT_SOURCE_DIR}/../SFML-2.5.1)
# this is the directory of the SFMLConfig.cmake
# this is required to use find_package
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)

if (SFML_FOUND)
    # we need to manually link these, as ${SFML_DEPENDENCIES} has been removed from SFML.
    target_link_libraries(${PROJECT_NAME} sfml-graphics)
else()
    message(FATAL_ERROR "SFML Could not be found.")
endif()

# copy the dlls from SFML to the exe dir
add_custom_command(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_ROOT}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)