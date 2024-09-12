
set(SRC_FILES TextureLoader.cpp BlockGridLoader.cpp BinaryFileReader.cpp BinaryFileWriter.cpp)

add_library(persistence ${SRC_FILES})

target_include_directories(persistence INTERFACE ../../include/persistence)

target_link_libraries(persistence PRIVATE contracts controller core game graphics physics sfml-graphics)