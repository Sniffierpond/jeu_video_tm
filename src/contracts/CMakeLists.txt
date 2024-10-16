
set(SRC_FILES Application.cpp BlockBuilder.cpp Camera.cpp Controller.cpp Drawable.cpp GameMode.cpp GameState.cpp InputHandler.cpp LevelInterface.cpp Movable.cpp Renderer.cpp Updatable.cpp Viewable.cpp Animable.cpp Animation.cpp Event.cpp EventListener.cpp)

add_library(contracts ${SRC_FILES})

target_include_directories(contracts INTERFACE ../../include/contracts)

target_link_libraries(contracts PRIVATE controller core game graphics persistence physics graphics sfml-graphics)