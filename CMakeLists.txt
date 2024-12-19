cmake_minimum_required(VERSION 3.28)
project(PsxEngine)

set(CMAKE_CXX_STANDARD_LIBRARIES "$(CMAKE_CXX_STANDARD_LIBRARIES) %(AdditionalDependencies) ")

set(SDL_INCLUDE "C:/Libraries/SDL2-2.0.22/include" CACHE PATH "sdl include path")
set(SDL_LIBS "C:/Libraries/SDL2-2.0.22/lib/x64" CACHE PATH "sdl library path")

add_subdirectory(Utils)
add_subdirectory(Input)
add_subdirectory(ECS)
add_subdirectory(Core)
add_subdirectory(Rendering)
add_subdirectory(Engine)
add_subdirectory(Test)
