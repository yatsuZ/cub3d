# Synthèse de l'énoncer du Projet Cub3D

## Introduction

Les objectifs du projet : Rigueur, utilisation du C, utilisation d’algorithmes basiques, recherche d’informations, etc.

Et aussi pour voir si on est de bon designer.

Avec l’aide des nombreux documents disponibles sur internet, vous utiliserez les mathématiques en temps qu’outil de création d’algorithmes élégants et efficaces.

Prendre en exemple le jeux [wolf3d](http://users.atw.hu/wolf3d/), l'un des tout premier jeux a utiliser le raycasting !! et faudre faire comme a l'époque ce qui est passionant !!!
🕹️🕹️🕹️

## RAPPEL des règles communes

- Le projet doit être écrit en langage C.
- Le code doit respecter la norminette de 42, incluant les fichiers ou fonctions bonus.
- Aucune interruption inattendue (segmentation fault, bus error, double free, etc.) n'est tolérée, sauf en cas de comportement indéfini.
- Toute mémoire allouée sur la heap doit être libérée, et aucun leak ne sera toléré.
- Si nécessaire, un Makefile doit être fourni, respectant les flags -Wall, -Wextra, et -Werror, sans relink.
- Pour les bonus, une règle bonus dans le Makefile est requise, et l'évaluation des parties obligatoire et bonus se fait séparément.
- En cas d'utilisation de la libft, ses sources et le Makefile associé doivent être copiés dans un dossier libft.
- Les programmes de test ne sont pas notés mais sont recommandés.

## Partie Obligatoire

### Rendu, Fonctions Externes Autorisées Description

| Règle               |                                |
|---------------------|--------------------------------|
| Nom du programme    | cub3D                          |
| Makefile            | all, clean, fclean, re, bonus  |
| Fichiers à rendre   | Tous les fichiers              |
| Arguments           | Une map dans le format *.cub   |
| LIBFT               | Autorisée                      |

| Fonctions Externes Autorisées                            | utilitée                                                        |
|----------------------------------------------------------|-----------------------------------------------------------------|
| open                                                     | ouvrier un fichier et donne file descriptor (fd)                |
| close                                                    | fermer un file descriptor pour securiser                        |
| read                                                     | lis le nombre de buffer dans un fd                              |
| write                                                    | ecris un buffer dans un fd                                      |
| printf                                                   | ecris une chaine de caractere dans la sortie standar            |
| malloc                                                   | il permet d'allouer de la memoir                                |
| free                                                     | il permet de libirée de la memoir                               |
| perror                                                   | affiche le message d'erreur qui son dans le sortie derreur      |
| strerror                                                 | donne le message d'erreur qui son dans le sortie derreur        |
| exit                                                     | permet de quiter un pogramme                                    |
| Toutes les fonctions de la lib math (-lm man man 3 math) | pour tout ce qui s'agit de calcule de mathémathique ou des float|
| Toutes les fonctions de la MinilibX                      | pour tout ce qui s'agit de la gestion de fenetre                |

## Description

Créer une représentation graphique 3D réaliste d'un labyrinthe en utilisant une vue subjective, en respectant les principes du ray-casting.

Les contraintes incluent l'utilisation de la MinilibX, une gestion parfaite des fenêtres, et l'affichage de textures différentes en fonction de l'orientation des murs (nord, sud, est, ouest).

## Ce que le programme CUB3D doit être capable de faire

1. Regarder l'aurgment verifier qu'il sagit d'un fichier ".cub".
2. Verifier qu'il y a tout les information et que tout est bon a linterieur du fichier et la map aussi.
3. Crée une fennetre ou il y a representation 3d de la map en first pov en fonction du spawn et la direction.
4. pouvoir s'y deplasser et tourner la camera et verifier que le raycasting marche. Faire les colisions.
5. fluiditer

Si un problème de configuration de n’importe quel type est rencontré dans
le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
d’erreur explicite de votre choix.

La gestion des fenêtres doit être parfaite : gestion de la minimalisation, du passage
d’une autre fenetre, etc.

### verification de l'argument

1. verifier son extension .cub

### verification du contenue du fichier .cub

il y a 2 chose a verifier dans un premier temp les textures puis la map.

tout peut etre separer par plusieur lignes vides.

#### verifier les texture

Les textures peuvent etre dans le desordre

les informations de chaque élément peuvent être
séparées par un ou plusieurs espace.

une texture et de compose de son element qui peut etre :
- NO pour nord
- SO pour sud
- WE pour ouest
- EA pour est

- F  pour sol
- C  pour ciel

puis separer d'1 espace minimume de la texture qui est soit :

- un chemin vers une texture pas de reglemation sur le chemin. pour les direction des point cardinaux.
- 3 chiffre separer par des virgule compris entre 0 et 255 pour le rgb POUR le sol et le ciel
exemple :

```cub
SO ./path_to_the_south_texture
NO         ./path_to_the_north_texture
WE ./path_to_the_west_texture

EA ./path_to_the_east_texture


F 220,100 ,0
C 225,   30,0
```

Vous devez afficher des textures différentes (vous avez le choix) selon si les murs
sont face nord, sud, est, ouest.

Votre programme doit être capable d’avoir des couleurs différentes pour le sol et
le plafond

#### verifier la map

La map doit être composée d’uniquement ces 6 caractères : 
- 0 pour les espaces vides
- 1 pour les murs
- N,S,E, W qui représentent la position de départ du joueur et son orientation.

La map doit être fermée/entourée de murs, sinon le programme doit renvoyer
une erreur.

Sauf pour la map elle-même, les informations de chaque élément peuvent être
séparées par un ou plusieurs espace(s).

#### les commandes des joueurs

Le programme affiche l’image dans une fenêtre et respecte les règles suivantes :

Les touches flèches du gauche et droite du clavier doivent permettre de faire
une rotation de la caméra (regarder a gauche et a droite)

Les touches W, A, S et D doivent permettre de déplacer la caméra (déplacement
du personnage)

Appuyer sur la touche ESC doit fermer la fenêtre et quitter le programme
proprement

Cliquer sur la croix rouge de la fenêtre doit fermer la fenêtre et quitter le
programme proprement

## BONUS

Je suis loibre de faire mon propre jeux CREE UNE REGLE dans le makefile pour compiler le code du bonus.

Je peux adapter mes regles si je justifie.

1. Un système de minicarte
2. Porte qui peuvent être ouvertes/fermées.
3. Animations (des sprites animés).
4. Faites pivoter le point de vue avec la souris.

Perso

1. Sauter
2. se teleporter


FIN DE LE SYNTHESE GO CODER!!