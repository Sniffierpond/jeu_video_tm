/*
    -------------------------
    main.cpp
    auteur: Jonathan Rochat
    -------------------------
    Fichier contenant la fonction main.
*/

#include "../include/cxxopts.hpp"
#include "../include/core/GameApplication.hpp"
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

int main (int argc, char** argv) {
    cxxopts::Options options("jeu");

    options.add_options()
    ("blockgrid", "chemin du fichier blockgrid qui doit être lu", cxxopts::value<std::string>())
    ("f,fps", "images par seconde", cxxopts::value<unsigned int>()->default_value("60"))
    ("F,fullscreen", "si l'application est en mode plein écran", cxxopts::value<bool>()->default_value("false"))
    ("W,windowwidth", "largeur de la fenêtre si en mode fenêtré", cxxopts::value<unsigned int>()->default_value("1600"))
    ("H,windowheight", "hauteur de la fenêtre si en mode fenêtré", cxxopts::value<unsigned int>()->default_value("900"))
    ("x, playerinitialx", "abscisse de la position initiale du joueur", cxxopts::value<float>())
    ("y,playerinitialy", "ordonnée de la position initiale du joueur", cxxopts::value<float>())
    ("h,help", "afficher l'aide");

    options.parse_positional("blockgrid");

    cxxopts::ParseResult result;

    try {
        result = options.parse(argc, argv);
    }
    catch (const cxxopts::exceptions::no_such_option& exception) {
        std::cout << "Erreur: Option invalide.\n" << options.help() << std::endl;
        return EXIT_FAILURE;
    }

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return EXIT_SUCCESS;
    }
    else if(!result.count("blockgrid")) {
        std::cout << "Erreur: Veuillez spécifier le chemin d'accès du fichier blockgrid.\n" << options.help() << std::endl;
        return EXIT_FAILURE;
    }
    else if(!std::filesystem::exists(result["blockgrid"].as<std::string>()) || !std::filesystem::is_regular_file(result["blockgrid"].as<std::string>())) {
        std::cout << "Erreur: Le chemin d'accès spécifié ne semble pas être valide." << std::endl;
        return EXIT_FAILURE;
    }
    else if(!result.count("playerinitialx") || !result.count("playerinitialy")) {
        std::cout << "Veuillez spécifier la position initiale du joueur.\n" << options.help() << std::endl;
    }

    GameApplication app(result);

    return app.launch();
}