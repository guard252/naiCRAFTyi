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
        src/Gameplay/GameObjects/GameObject.h
        src/Gameplay/GameObjects/Block.h
        src/Gameplay/Models/Model.cpp
        src/Gameplay/Models/Model.h
        src/Gameplay/Models/CubeModel.cpp
        src/Gameplay/Models/CubeModel.h src/Gameplay/GameObjects/DirtBlock.cpp src/Gameplay/GameObjects/DirtBlock.h src/Player/Camera.cpp src/Player/Camera.h src/Gameplay/Game.cpp src/Gameplay/Game.h src/Player/Controller.cpp src/Player/Controller.h)

target_link_libraries(naiCRAFTyi -lglfw -lGL -lGLEW)
