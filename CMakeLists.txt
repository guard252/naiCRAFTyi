cmake_minimum_required(VERSION 3.15)
project(naiCRAFTyi)

set(CMAKE_CXX_STANDARD 14)

# Add source files
file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.c
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/GLAbstraction/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
        ${CMAKE_SOURCE_DIR}/src/*.h
        ${CMAKE_SOURCE_DIR}/src/GLAbstraction/*.h)

#add_subdirectory(src)
add_executable(naiCRAFTyi src/main.cpp
        src/GLAbstraction/Tools.cpp
        src/GLAbstraction/VBO.cpp
        src/GLAbstraction/VAO.cpp
        src/GLAbstraction/VAO.h
        src/GLAbstraction/VBLayout.h
        src/GLAbstraction/ShaderProgram.cpp
        src/GLAbstraction/ShaderProgram.h
        src/GLAbstraction/Texture.cpp
        src/GLAbstraction/Texture.h
        src/Game/GameObject.h
        src/Game/Block.cpp
        src/Game/Block.h
        src/Game/Models/Model.cpp
        src/Game/Models/Model.h
        src/Game/Models/CubeModel.cpp
        src/Game/Models/CubeModel.h)

target_link_libraries(naiCRAFTyi -lglfw -lGL -lGLEW)
