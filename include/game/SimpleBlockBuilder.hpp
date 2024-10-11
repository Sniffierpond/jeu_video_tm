/*
    -------------------------
    SimpleBlockBuilder.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <memory>
#include <string>
#include "../contracts/BlockBuilder.hpp"

/*
Permet d'instancier des blocs considérés comme "simples".
*/
class SimpleBlockBuilder: public BlockBuilder {
    protected:
    std::string blockType_;
    public:
    SimpleBlockBuilder& setBlockType(std::string blockType);

    std::shared_ptr<Block> build() const override;
};