/*
    -------------------------
    BlockGridWriter.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/persistence/BlockGridWriter.hpp"
#include "../../include/persistence/BinaryFileWriter.hpp"
#include <SFML/System/Vector2.hpp>
#include <fstream>

BlockGridWriter::BlockGridWriter(std::ostream& outputStream): stream_(&outputStream) {}

BlockGridWriter::BlockGridWriter(const std::string& filePath) {
    streamUPtr_ = std::make_unique<std::ofstream>(std::ofstream(filePath, std::ios::out | std::ios::binary));
    stream_ = &(*streamUPtr_);
}


void BlockGridWriter::write(const BlockGrid& blockGrid) {
    std::vector<std::vector<unsigned int>> blocks;
    std::vector<std::string> blockIds;

    for (int y = 0; y < blockGrid.getHeight(); ++y) {
        blocks.emplace_back();

        for (int x = 0; x < blockGrid.getWidth(); ++x) {
            std::string thisId = blockGrid.getBlock(sf::Vector2i(x, y)).getBlockType();
            int numId;

            if (thisId != "base:air") {
                bool registered = false;

                for (int i = 0; i < blockIds.size(); ++i) {
                    if (thisId == blockIds.at(i)) {
                        numId = i;
                        registered = true;
                        break;
                    }
                }

                if (!registered) {
                    blockIds.push_back(thisId);
                    numId = blockIds.size() - 1;
                }

                blocks.back().push_back(numId + 1);
            }
            else {
                blocks.back().push_back(0);
            }
        }
    }

    write(blocks, blockIds);
}

void BlockGridWriter::write(const std::vector<std::vector<unsigned int>>& blocks, const std::vector<std::string>& blockIds) {
    BinaryFileWriter writer(*stream_);

    writer.writeElement<std::uint32_t>(1);      //version majeure
    writer.writeElement<std::uint32_t>(0);      //version mineure
    writer.writeElement<std::uint32_t>(0);      //patch

    writer.writeElementArray(blockIds);     //ids des blocs

    writer.write2DElementArray(blocks);     //blocks

    writer.clear();
}