cmake_minimum_required(VERSION 3.16)

project(JeuTM VERSION 0.1 DESCRIPTION "Jeu bac-à-sable créé pour mon travail de maturité" LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src/contracts)
add_subdirectory(src/controller)
add_subdirectory(src/core)
add_subdirectory(src/game)
add_subdirectory(src/graphics)
add_subdirectory(src/persistence)   
add_subdirectory(src/physics)

add_executable(jeu src/main.cpp)
add_executable(editeur src/levelEditor.cpp)

install(DIRECTORY resources DESTINATION build/bin/resources)
target_include_directories(jeu PRIVATE "include" "lib")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(
    CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} -Werror -fsanitize=undefined -fsanitize=address"
  )
  target_link_options(jeu
    BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address
  )
endif()

target_link_libraries(jeu PRIVATE contracts controller core game graphics persistence physics sfml-graphics)
target_link_libraries(editeur persistence sfml-graphics)

target_compile_features(jeu PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
        TARGET jeu
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:jeu>
        VERBATIM)
endif()