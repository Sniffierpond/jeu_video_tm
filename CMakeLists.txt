cmake_minimum_required(VERSION 3.7...3.28)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SFML_DIR /usr/lib/x86_64-linux-gnu/cmake/SFML)

#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system)

project(JeuTM VERSION 0.1 DESCRIPTION "Jeu bac-à-sable créé pour mon travail de maturité" LANGUAGES CXX)

add_executable(jeu src/main.cpp)

target_include_directories(jeu PRIVATE "include" "lib")

target_link_libraries(jeu ${SFML_LIBRAIRIES})