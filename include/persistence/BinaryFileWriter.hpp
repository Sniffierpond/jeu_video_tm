/*
    -------------------------
    BinaryFileWriter.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <ostream>
#include <vector>

class BinaryFileWriter {
    private:
    std::ostream& ostream_;
    
    public:
    /*
    NOTE: Le flux doit être ouvert en mode binaire.
    */
    BinaryFileWriter(std::ostream& ostream): ostream_(ostream) {}

    template<typename T>
    void writeElement(T t) {
        static_assert(std::is_fundamental_v<T>, "La méthode writeElement ne supporte que les types primitifs.");

        ostream_.write(reinterpret_cast<char*>(&t), sizeof(t));

        if (ostream_.fail()) {
            ostream_.clear();
            throw std::runtime_error("Erreur lors de l'écriture du fichier.");
        }
    }

    template<typename T>
    void writeElementArray(const std::vector<T> array) {
        writeElement<std::uint32_t>(array.size());

        for (const auto& element: array) {
            writeElement<T>(element);
        }
    }

    template<typename T>
    void write2DElementArray(const std::vector<std::vector<T>>& array) {
        writeElement<std::uint32_t>(array.front().size);
        writeElement<std::uint32_t>(array.size());

        for (const auto& row: array) {
            for (const auto& element: row) {
                writeElement<T>(element);
            }
        }
    }

    void clear() {
        ostream_.flush();
        ostream_.clear();
    }

    ~BinaryFileWriter() {
        clear();
    }
};

template<>
void BinaryFileWriter::writeElement(std::string element);