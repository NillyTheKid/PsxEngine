file(GLOB coreHeaders include/*.h)
file(GLOB coreSources source/*.cpp)
add_library(Core STATIC ${coreSources} ${coreHeaders})