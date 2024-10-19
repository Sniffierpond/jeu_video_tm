
set(SRC_FILES Application.cpp BlockBuilder.cpp Camera.cpp Controller.cpp Drawable.cpp GameState.cpp InputHandler.cpp LevelInterface.cpp Movable.cpp Renderer.cpp Updatable.cpp Viewable.cpp Animable.cpp Animation.cpp)

add_library(contracts ${SRC_FILES})

target_include_directories(contracts INTERFACE ../../include/contracts)

target_link_libraries(contracts PRIVATE controller core game graphics persistence physics graphics sfml-graphics)