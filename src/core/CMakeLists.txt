
set(SRC_FILES GameApplication.cpp GameStateStack.cpp PlayingGameState.cpp)

add_library(core ${SRC_FILES})

target_include_directories(core INTERFACE ../../include/core)

target_link_libraries(core PRIVATE contracts controller game graphics persistence physics sfml-graphics)