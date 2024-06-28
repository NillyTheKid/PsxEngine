file(GLOB utilHeaders include/*.h include/*.hpp)
file(GLOB utilSources source/*.cpp)

include_directories(include/)
add_library(Utils STATIC ${utilSources} ${utilHeaders})
set_target_properties(Utils PROPERTIES LINKER_LANGUAGE CXX)