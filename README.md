TicTacToe – C++

Je suis Romane VARO-TUPIN et dans le cadre du cours d’ALGO PROG en E3 IMAC, j’ai réalisé un jeu de TicTacToe en C++ jouable dans le terminal.  
Le jeu permet soit de jouer à deux joueurs, soit de jouer contre une IA.

---------------------
Organisation du code
---------------------

J’ai séparé le projet en plusieurs fichiers pour que ce soit plus clair et plus simple à comprendre et en respectant la consigne qui le demandais.

Le fichier "main.cpp" contient toute la logique principale du jeu : le menu de démarrage, la gestion des tours, l’affichage du plateau, la vérification de la victoire ou de l’égalité, ainsi que le déroulement complet d’une partie.

J’ai utilisé plusieurs fonctions (hormis draw_game_board), comme par exemple : 

- "victoire" pour vérifier si un joueur a gagné,
- "board_rempli" pour savoir si le plateau est plein,
- "ia_choix_case" pour gérer le tour de l’IA.

Les fichiers "Player.hpp" et "Player.cpp" contiennent la structure "Player" (nom et symbole) ainsi que les fonctions liées à la création des joueurs.

--------------------
Choix que j’ai faits
--------------------

Pour représenter le plateau et vérifier la victoire, j’ai choisi une méthode que je trouvais simple même si elle prend plus de lignes de code. Par exemple, dans la fonction "victoire", toutes les combinaisons gagnantes sont écrites directement avec des conditions sur le tableau.

Je sais qu’il est possible de faire cette vérification avec des tableaux de positions ou des boucles plus compactes, mais j’ai préféré garder une solution que je comprends vraiment et que je trouve plus lisible pour moi, même si ça fait plus de lignes de code comme ici la consigne n'imposait pas de forcément faire avec le moins de ligne de code possible.

-----------------------
Améliorations réalisées
-----------------------

Par rapport à la consigne demandée, j'ai choisi comme amélioration principale l’amélioration de l’IA.

Du coup, au lieu de jouer uniquement au hasard, l'IA vérifie d’abord si le joueur est sur le point de gagner. C'est une fonction ("ia_blocage_case_restante") qui parcourt les différentes combinaisons possibles et qui regarde s’il y a deux symboles du joueur alignés avec une case encore libre, si oui, l’IA joue sur cette case pour bloquer le joueur. Sinon, elle choisit une case libre aléatoirement.

J’ai aussi amélioré la création des joueurs, j’ai quand même gardé la fonction create_player() demandée dans la consigne mais comme j’avais besoin d’empêcher deux joueurs d’avoir le même symbole, j’ai préféré créer une deuxième version, create_player(char symbole_pris), plutôt que de modifier celle imposée.
Ça m’a permis de respecter la consigne tout en ajoutant une vérification en plus.

Le paramètre "symbole_pris" permet d’empêcher qu’un joueur (ou l’IA) choisisse un symbole déjà utilisé. Cette vérification est faite directement dans la fonction, ce qui évite de dupliquer la logique dans le "main".

J'ai aussi ajoutée plein d’autres petites améliorations  au fur et à mesure comme par exemple  : 

- l’imposition du choix de symbole uniquement entre "X" et "O" (je suis pas sûre que c'était imposée, donc je l'ai fait car ça ma permis de gerer des bugs quand on mettait des chaines de caractères par exemple),

- la gestion des erreurs de saisie avec "std::cin.fail()",

- la possibilité de rejouer une partie à la fin du jeu.(que j'ai rajouté en dernier)

--------------------
Problèmes rencontrés
--------------------

J’ai rencontré plusieurs problèmes liés aux entrées utilisateur.  
Par exemple, quand un joueur entrait une lettre au lieu d’un chiffre pour choisir une case, ou un nombre en dehors de l’intervalle 1 à 9, le jeu se comportait mal.

Pour corriger ça, j’ai ajouté des vérifications avec "std::cin.fail()", des "std::cin.clear()" et "std::cin.ignore()", ainsi que des boucles "while" qui forcent le joueur à entrer une valeur valide avant de continuer.

J’ai aussi eu des soucis avec la gestion des tours et de l’affichage : le plateau s’affichait parfois deux fois ou au mauvais moment.  
Ces problèmes ont été corrigés progressivement en testant le jeu directement dans le terminal et en déplaçant certains appels à "draw_game_board".

La gestion de la fin de partie a aussi été compliquée au début.  Le jeu continuait parfois à demander des coups même après une victoire ou une égalité.  
Le problème venait de la boucle principale ("while (true)"), que j’ai corrigée en ajoutant des "break" juste après les appels à "victoire" et "board_rempli", et voilà pour mes améliorations. 

------------------------
Compilation et exécution
------------------------

Le projet a été développé sur macOS, donc j'ai tester directement en ligne de commande sur mac0S uniquement !

Voilà ! Merci pour la correction et la lecture. 
Passez de bonnes fêtes.

