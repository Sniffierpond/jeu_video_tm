# Projet de jeu-vidéo de travail de maturité
Ce dépôt contient le code utilisé par mon jeu-vidéo bac-à-sable pour mon projet de travail de maturité.
## Structure
Le projet est composé des modules suivants:
- **core**: le coeur de l'application
- **contracts**: module contenant les abstractions de haut niveau de l'application
- **controller**: la partie de l'application chargée de contrôller les interactions entre ses différents composants et l'utilisateur
- **graphics**: le module gérant tout le côté graphique de l'application - gestion de fenêtre, calculs relatifs aux caméras, guis, affichage du jeu, etc...
- **physics**: module calculant, comme son nom l'indique, toute la partie physique du jeu
- **persistence**: module chargé des fonctionnalités liées à la persistance des informations du jeu
- **audio**: Le module qui gère le son.
- **game**: partie de l'application qui effectue les calculs relatifs aux modes de jeu et décrivant les différents élements de mon jeu