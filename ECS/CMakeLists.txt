file(GLOB ecsHeaders include/*.h)
file(GLOB ecsSources source/*.cpp)

include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})
add_library(ECS STATIC ${ecsSources} ${ecsHeaders})