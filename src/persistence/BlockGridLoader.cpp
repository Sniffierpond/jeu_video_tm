/*
    -------------------------
    BlockGridLoader.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/persistence/BlockGridLoader.hpp"
#include "../../include/persistence/BinaryFileReader.hpp"
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>

#include <cassert>

BlockGridLoader::BlockGridLoader(std::istream& inputStream) {
    stream_ = &inputStream;
}

BlockGridLoader::BlockGridLoader(const std::string& filePath) {
    streamUPtr_ = std::make_unique<std::ifstream>(std::ifstream(filePath, std::ios::in | std::ios::binary));
    stream_ = &(*streamUPtr_);
}


BlockGridLoader::Result BlockGridLoader::load() const {
    BinaryFileReader reader(*stream_);

    std::vector<std::vector<unsigned int>> blocks;
    std::vector<std::string> blocksNumericIds;

    std::uint32_t versionMajor = reader.readElement<std::uint32_t>();
    std::uint32_t versionMinor = reader.readElement<std::uint32_t>();
    std::uint32_t versionPatch = reader.readElement<std::uint32_t>();

    if (versionMajor != blockgridFormatVersionMajor || versionMinor != blockgridFormatVersionMinor || versionPatch != blockgridFormatVersionPatch) {
        throw std::runtime_error("Format version not supported.");
    }
    
    blocksNumericIds = reader.readElementArray<std::string>();
    blocksNumericIds.insert(blocksNumericIds.begin(), "base:air");

    blocks = reader.read2DElementArray<std::uint32_t>();

    return Result(blocks, blocksNumericIds);
}

/*
NOTE: Les objets sont copiés.
*/
BlockGridLoader::Result::Result(const std::vector<std::vector<unsigned int>>& blocks, const std::vector<std::string>& blocksNumericIds): blocksPtr_(std::make_shared<std::vector<std::vector<unsigned int>>>(blocks)), blocksNumericIds_(blocksNumericIds) {}

BlockGridLoader::Result::Result(const std::shared_ptr<std::vector<std::vector<unsigned int>>>& blocksPtr, const std::vector<std::string>& blocksNumericIds): blocksPtr_(blocksPtr), blocksNumericIds_(blocksNumericIds) {}


const std::vector<std::string>& BlockGridLoader::Result::blocksNumericIds() const {
    return blocksNumericIds_;
}


std::vector<std::vector<unsigned int>> BlockGridLoader::Result::toIntArray() const {
    return *blocksPtr_;
}


BlockGrid BlockGridLoader::Result::toBlockGrid(const BlockRegistry& blockRegistry) const {
    std::vector<std::vector<Block>> blocks;

    for (auto& y: *blocksPtr_) {
        blocks.emplace_back();

        for (auto& x: y) {
            if (!blockRegistry.get(blocksNumericIds_[x]).has_value()) {
                throw std::runtime_error("Block \"" + blocksNumericIds_[x] + "\" not registered.");
            }
            else {
                blocks.back().push_back(*blockRegistry.get(blocksNumericIds_[x])->get().build());
            }
        }
    }

    return BlockGrid(blocks);
}