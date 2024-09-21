
set(SRC_FILES BaseBlocksRegister.cpp Block.cpp BlockGrid.cpp Level.cpp SimpleBlockBuilder.cpp Player.cpp)

add_library(game ${SRC_FILES})

target_include_directories(game INTERFACE ../../include/game)

target_link_libraries(game PRIVATE contracts controller core graphics persistence physics sfml-graphics)