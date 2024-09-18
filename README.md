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
## Exécuter le jeu
La compilation produit un exécutable *jeu* qui peut être exécuté en ligne de commande avec comme argument le chemin d'un fichier au format *blockgrid* comme celui se trouvant dans les ressources du projet.
## Éditeur de niveau
Pour l'instant, le projet comporte également un éditeur de niveau extrêmement basique en ligne de commande. Il peut être exécuté avec comme argument le chemin d'un fichier qui sera créé au format *blockgrid*. 
### Utilisation
Premièrement, les identifiants des différents blocks que l'on souhaite ajouter au jeu doivent être entrés.
**Exemple:**
`base:stone;base:dirt;base:grass:1;`
Deuxièmement, la hauteur, puis la largeur doivent être entrés.
Enfin,les ids **numériques** des blocs doivent être entrés, ces ids correspondant à la position dans la liste entrée précédemment du bloc, pour chaque ligne, une ligne étant confirmée avec "enter" (la première position correspondant à l'indice "1", "0" étant réservée pour l'air (base:air)).
**Exemple:**
`0;0;0;0;0;0;0;0;0;0`