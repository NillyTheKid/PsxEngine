file(GLOB inputHeaders include/*.h)
file(GLOB inputSources source/*.cpp)

include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})
add_library(Input STATIC ${inputSources} ${inputHeaders})
target_link_libraries(Input SDL2.lib SDL2main.lib SDL2test.lib)