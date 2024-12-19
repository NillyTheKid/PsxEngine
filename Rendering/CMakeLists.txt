file(GLOB renderHeaders include/*.h)
file(GLOB renderSources source/*.cpp)

include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})
add_library(Rendering STATIC ${renderSources} ${renderHeaders})
target_link_libraries(Rendering SDL2.lib SDL2main.lib SDL2test.lib OpenGL32.lib Core ECS)
target_include_directories(Rendering PUBLIC $<TARGET_PROPERTY:Core,INCLUDE_DIRECTORIES> $<TARGET_PROPERTY:ECS,INCLUDE_DIRECTORIES>)