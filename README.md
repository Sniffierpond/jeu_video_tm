# Projet de jeu-vidéo de travail de maturité
Ce dépôt contient le code utilisé par mon jeu-vidéo bac-à-sable pour mon projet de travail de maturité.
## Structure
Le projet est composé des modules suivants:
- **core**: Le coeur de l'application où se trouve par exemple le fichier *main.cpp* et la fonction *main*, ainsi que les interfaces servants à faire le lien entre les différents composants de l'application
- **controller**: La partie de l'application chargée de contrôller les interactions entre ses différents composants et l'utilisateur
- **graphics**: Le module gérant tout le côté graphique de l'application - gestion de fenêtre, calculs relatifs aux caméras, guis, affichage du jeu, etc...
- **physics**: Module calculant, comme son nom l'indique, toute la partie physique du jeu
- **persistence**: Module chargé des fonctionnalités liées à la persistance des informations du jeu
- **audio**: Le module qui gère le son
- **gamemodes**: Partie de l'application qui effectue les calculs relatifs aux modes de jeu
## License
Copyright (C) 2024 Jonathan Rochat - Tous Droits Réservés.