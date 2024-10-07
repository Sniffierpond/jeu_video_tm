
set(SRC_FILES Animation.cpp AnimationHandler.cpp BaseTexturesRegister.cpp BlockRenderer.cpp LevelRenderer.cpp MovableCamera.cpp PlayerCamera.cpp StaticCamera.cpp View.cpp)

add_library(graphics ${SRC_FILES})

target_include_directories(graphics INTERFACE ../../include/graphics)

target_link_libraries(graphics PRIVATE contracts controller core game persistence physics sfml-graphics)