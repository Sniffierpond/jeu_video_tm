/*
    -------------------------
    levelEditor.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../include/persistence/BlockGridWriter.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <fstream>

std::vector<std::string> idAdder() {
    std::cout << "Veuillez ajouter les ids des blocs que vous souhaitez ajouter au niveau séparés par des point-virgules (;): ";

    std::vector<std::string> blockIds;

    std::string line;
    std::getline(std::cin, line);
    
    std::string id;
        for (const char& c: line) {
            if (c == ';') {
                if (!id.empty()) {
                    blockIds.push_back(id);
                    id.clear();
                }
            }
            else {
                id += c;
            }
        }

    std::cout << "\n";

    return blockIds;
}


std::vector<std::vector<unsigned int>> editor() {
    int width, height;
    std::vector<std::vector<unsigned int>> blocks;

    std::cout << "\néditeur de niveau\n";

    std::cout << "Largeur: ";
    std::cin >> width;

    std::cout << "\nHauteur: ";
    std::cin >> height;

    std::cout << "\n";

    std::string trash; std::getline(std::cin, trash);

    blocks.resize(height);
    
    for (int y = height - 1; y >= 0; --y) {
        std::cout << "y = " << y << ":    ";

        std::string inputLine;
        std::vector<unsigned int> line;

        std::getline(std::cin, inputLine);

        std::string id;
        for (const char& c: inputLine) {
            if (c == ';') {
                if (!id.empty()) {
                    line.push_back(std::stoi(id));
                    id.clear();
                }
            }
            else {
                id += c;
            }
        }
        blocks[y] = line;
        std::cin.clear();
        std::cout << "\n";
    }

    return blocks;
}

int main(int argc, char** argv) {
    std::vector<std::string> blockIds;
    std::vector<std::vector<unsigned int>> blocks;

    if (argc == 1) {
        std::cout << "Erreur: veuillez spécifier un fichier" << std::endl;
        return EXIT_FAILURE;
    }
    else {
        std::string filePath = argv[1];

        blockIds = idAdder();
        blocks = editor();

        BlockGridWriter writer(filePath);

        try {
            writer.write(blocks, blockIds);
            return EXIT_SUCCESS;
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            return EXIT_SUCCESS;
        }
    } 
}