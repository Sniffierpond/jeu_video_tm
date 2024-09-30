
set(SRC_FILES CameraController.cpp GameController.cpp SfmlInputHandler.cpp)

add_library(controller ${SRC_FILES})

target_include_directories(controller INTERFACE ../../include/controller)

target_link_libraries(controller PRIVATE contracts core game graphics persistence physics sfml-graphics)