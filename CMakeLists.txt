cmake_minimum_required(VERSION 3.28)
project(PsxEngine)

set(SDL_INCLUDE "" CACHE PATH "sdl include path")
set(SDL_LIBS "" CACHE PATH "sdl library path")

add_subdirectory(Core)
add_subdirectory(Test)