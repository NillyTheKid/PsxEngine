file(GLOB coreHeaders include/*.h)
file(GLOB coreSources source/*.cpp)

include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})
add_library(Core STATIC ${coreSources} ${coreHeaders})
target_link_libraries(Core Rendering SDL2.lib SDL2main.lib SDL2test.lib)
target_include_directories(Core PUBLIC $<TARGET_PROPERTY:Rendering,INCLUDE_DIRECTORIES>)