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
        src/Player/Camera.cpp
        src/Player/Camera.h
        src/Gameplay/Game.cpp
        src/Gameplay/Game.h
        src/Player/Controller.cpp
        src/Player/Controller.h
        src/Gameplay/GameObjects/Chunk.cpp
        src/Gameplay/GameObjects/Chunk.h
        src/GLAbstraction/ArrayTexture.cpp
        src/GLAbstraction/ArrayTexture.h
        src/Gameplay/GameObjects/ChunkTypedefs.h
        src/Gameplay/GameObjects/ChunkConstants.h
        src/Gameplay/GameObjects/ChunkMesh.cpp
        src/Gameplay/GameObjects/ChunkMesh.h
        src/GLAbstraction/IBO.cpp
        src/GLAbstraction/IBO.h src/Gameplay/GameObjects/Terrain.cpp src/Gameplay/GameObjects/Terrain.h src/Others/KeyFunctions.h src/Gameplay/GameObjects/Coordinates.h src/Gameplay/GameObjects/Coordinates.cpp)

target_link_libraries(naiCRAFTyi -lglfw -lGL -lGLEW)
