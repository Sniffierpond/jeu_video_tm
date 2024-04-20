cmake_minimum_required(VERSION 3.7...3.28)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(JeuTM VERSION 0.1 DESCRIPTION "Jeu bac-à-sable créé pour mon travail de maturité" LANGUAGES CXX)

add_executable(jeu src/main.cpp)