/*
    -------------------------
    BinaryFileWriter.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/persistence/BinaryFileWriter.hpp"

template <>
void BinaryFileWriter::writeElement(std::string element) {
    for (const char& c: element) {
        writeElement<char>(c);
    }

    writeElement<char>('\0');
}