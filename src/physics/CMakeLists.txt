
set(SRC_FILES Acceleration.cpp MovementHandler.cpp Speed.cpp PhysicsHandler.cpp)

add_library(physics ${SRC_FILES})

target_include_directories(physics INTERFACE ../../include/physics)

target_link_libraries(physics PRIVATE contracts controller core game graphics persistence sfml-graphics)