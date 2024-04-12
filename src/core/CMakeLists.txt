set(SOURCES main.cpp)

add_executable(jeu ${SOURCES})
target_include_directories(jeu ${PROJECT_SOURCE_DIR}/include/core)