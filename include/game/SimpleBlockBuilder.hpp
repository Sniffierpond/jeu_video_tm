/*
    -------------------------
    SimpleBlockBuilder.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <string>
#include "../contracts/BlockBuilder.hpp"

/*
Permet d'instancier des blocs considérés comme "simples".
*/
class SimpleBlockBuilder: BlockBuilder {
    protected:
    std::string blockType_;
    public:
    SimpleBlockBuilder& setBlockType(std::string blockType);

    Block build() const override;
};