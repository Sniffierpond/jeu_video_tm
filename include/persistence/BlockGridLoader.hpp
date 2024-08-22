/*
    -------------------------
    BlockGridLoader.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../game/BlockGrid.hpp"
#include "../game/BlockRegistry.hpp"
#include <istream>
#include <memory>

constexpr int blockgridFormatVersionMajor = 1;
constexpr int blockgridFormatVersionMinor = 0;
constexpr int blockgridFormatVersionPatch = 0;
/*
Classe chargeant une grille de blocs à partir d'un fichier au format blockgrid 1.0.
*/
class BlockGridLoader {
    private:
    std::istream* stream_;
    std::unique_ptr<std::istream> streamUPtr_;

    public:
    class Result {
        private:
        std::shared_ptr<std::vector<std::vector<unsigned int>>> blocksPtr_;
        std::vector<std::string> blocksNumericIds_;

        public:
        Result(const std::vector<std::vector<unsigned int>>& blocks, const std::vector<std::string>& blocksNumericIds);
        Result(const std::shared_ptr<std::vector<std::vector<unsigned int>>>& blocksPtr, const std::vector<std::string>& blocksNumericIds);

        const std::vector<std::string>& blocksNumericIds() const;

        std::vector<std::vector<unsigned int>> toIntArray() const;
        BlockGrid toBlockGrid(const BlockRegistry& BlockRegistry) const;
    };

    explicit BlockGridLoader(std::istream& inputStream);
    explicit BlockGridLoader(const std::string& filePath);

    Result load() const;
};