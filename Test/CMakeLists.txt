include_directories(include/)
set(CMAKE_VS_SDK_INCLUDE_DIRECTORIES "$(VC_IncludePath);$(WindowsSDK_IncludePath)" ${SDL_INCLUDE})
set(CMAKE_VS_SDK_LIBRARY_DIRECTORIES "$(VC_LibraryPath_x64);$(WindowsSDK_LibraryPath_x64)" ${SDL_LIBS})

file(GLOB testHeaders include/*.h)
file(GLOB testSources source/*.cpp)

add_executable(Test WIN32 Test.cpp ${testHeaders} ${testSources})
add_custom_command(TARGET Test POST_BUILD COMMAND copy \"${SDL_LIBS}\\SDL2.dll\" \"$(TargetDir)SDL2.dll\")
target_link_libraries(Test Engine)
target_include_directories(Test PUBLIC $<TARGET_PROPERTY:Engine,INCLUDE_DIRECTORIES>)
