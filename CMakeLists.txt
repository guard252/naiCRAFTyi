cmake_minimum_required(VERSION 3.15)
project(naiCRAFTyi)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(Threads)
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
        src/Gameplay/World/Chunk.cpp
        src/Gameplay/World/Chunk.h
        src/GLAbstraction/ArrayTexture.cpp
        src/GLAbstraction/ArrayTexture.h
        src/Gameplay/World/ChunkTypedefs.h
        src/Gameplay/World/ChunkConstants.h
        src/Gameplay/World/ChunkMesh.cpp
        src/Gameplay/World/ChunkMesh.h
        src/GLAbstraction/IBO.cpp
        src/GLAbstraction/IBO.h src/Gameplay/World/Terrain.cpp src/Gameplay/World/Terrain.h src/Others/KeyFunctions.h src/Gameplay/World/Coordinates.h src/Gameplay/World/Coordinates.cpp src/Others/Math.cpp src/Others/Math.h src/Others/Random.cpp src/Others/Random.h src/Gameplay/World/TerrainGenertion.cpp src/Gameplay/World/TerrainGenertion.h)

target_link_libraries(naiCRAFTyi -lglfw -lGL -lGLEW -pthread)
