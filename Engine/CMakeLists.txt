file(GLOB engineHeaders include/*.h)
file(GLOB engineSources source/*.cpp)

include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})
add_library(Engine STATIC ${engineSources} ${engineHeaders})
target_link_libraries(Engine Input Rendering ECS SDL2.lib SDL2main.lib SDL2test.lib)
target_include_directories(Engine PUBLIC $<TARGET_PROPERTY:Rendering,INCLUDE_DIRECTORIES> $<TARGET_PROPERTY:Input,INCLUDE_DIRECTORIES> $<TARGET_PROPERTY:ECS,INCLUDE_DIRECTORIES>)