/*
    -------------------------
    BlockGridWriter.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <memory>
#include "../game/BlockGrid.hpp"

class BlockGridWriter {
    private:
    std::ostream* stream_;
    std::unique_ptr<std::ostream> streamUPtr_;
    
    public:
    BlockGridWriter(std::ostream& outputStream);
    BlockGridWriter(const std::string& filePath);

    void write(const BlockGrid& blockGrid);
    void write(const std::vector<std::vector<unsigned int>>& blocks, const std::vector<std::string>& blockIds);
};