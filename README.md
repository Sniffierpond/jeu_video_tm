# Projet de jeu-vidéo de travail de maturité
Ce dépôt contient le code utilisé par mon jeu-vidéo bac-à-sable pour mon projet de travail de maturité.
## Exécuter le jeu
La compilation produit un exécutable *jeu* qui peut être exécuté en ligne de commande avec comme argument le chemin d'un fichier au format *blockgrid* comme celui se trouvant dans les ressources du projet.

Le jeu peut également être exécuté avec les options suivantes:

|option|description|
|--------------------|--------------------|
|**-f** / **--fps**|précise le nombre maximal de fps (par défaut, 60)|
|**-F**|lance le jeu en plein écran|
|**-W** / **--windowwidth**|précise la largeur de la fenêtre si le jeu est en mode fenêtré (par défaut, 1600 pixels)|
|**-H** / **--windowheight**|précise la hauteur de la fenêtre si le jeu est en mode fenêtré (par défaut, 900 pixels)|
|**-x** / **--playerinitialx**|indique l'abscisse de la position initiale du joueur. Cet argument **n'est pas optionnel**.|
|**-y** / **--playerinitialy**|indique l'ordonnée de la position initiale du joueur. Cet argument **n'est pas optionnel**.|
|**-h** / **--help**|affiche un message d'aide sur les arguments en ligne de commande|

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
