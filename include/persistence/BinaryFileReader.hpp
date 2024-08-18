/*
    -------------------------
    BinaryFileReader.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <cstdint>
#include <istream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <iostream>

class BinaryFileReader {
    private:
    std::istream& istream_;

    public:
    /*
    NOTE: Le flux doit être ouvert en mode binaire.
    */
    BinaryFileReader(std::istream& istream): istream_(istream) {}


    template<typename T>
    T readElement() {
        static_assert(std::is_fundamental_v<T>, "La méthode readElement ne supporte que les types primitifs.");
        T t;

        istream_.read(reinterpret_cast<char*>(&t), sizeof(T));

        if (istream_.fail()) {
            istream_.clear();
            throw std::runtime_error("Erreur lors de la lecture du fichier.");
        }
        return t;
    }


    template<typename T>
    std::vector<T> readElementArray() {
        std::vector<T> array;

        int n = readElement<std::uint32_t>();

        for (int i = 0; i < n; ++i) {
            array.push_back(readElement<T>());
        }

        return array;
    }

    template<typename T>
    std::vector<std::vector<T>> read2DElementArray() {
        std::vector<std::vector<T>> array;

        int width = readElement<std::uint32_t>();
        int height = readElement<std::uint32_t>();

        for (int y = 0; y < height; ++y) {
            array.emplace_back();
            
            for (int x = 0; x < width; ++x) {
                array[y].push_back(readElement<T>());
            }
        }

        return array;
    }


    void clear() {
        istream_.clear();
        istream_.seekg(0);
    }


    ~BinaryFileReader() {
        clear();
    }
};

template<>
std::string BinaryFileReader::readElement<std::string>();