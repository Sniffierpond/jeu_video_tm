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
    do {
        c = readElement<char>();
        string += c;
    }
    while (c != '\0');

    return string;
}