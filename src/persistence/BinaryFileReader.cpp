/*
    -------------------------
    BinaryFileReader.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/persistence/BinaryFileReader.hpp"
#include <iostream>

template<>
std::string BinaryFileReader::readElement<std::string>() {
    std::string string;

    char c;
    while ((c = readElement<char>()) != '\0') {
        string += c;
    }

    return string;
}