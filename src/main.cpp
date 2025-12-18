#include <iostream>
#include "Player.hpp"

void draw_game_board(char const cases[9]);

int main()
{

/*
Menu de démarrage
Vous devez réaliser un menu de démarrage qui permet à l'utilisateur de choisir le mode de jeu (deux joueurs ou un joueur contre l'IA).

Exemple:

Bienvenue dans le jeu du TicTacToe
Veuillez choisir un mode de jeu :
1. Deux joueurs
2. Un joueur contre l'IA
*/

std::cout <<"Bienvenue dans le jeu du TicTacToe"<< std::endl;
std::cout <<"Veuillez choisir un mode de jeu :"<< std::endl;
std::cout <<"1. Deux joueurs"<< std::endl;
std::cout <<"2. Un joueur contre l'IA"<< std::endl;

int modes {0};
std::cin >> modes;

/*
Deux joueurs
Vous devez réaliser un mode de jeu où deux joueurs peuvent s'affronter sur le jeu.

Le jeu doit alterner entre les deux joueurs pour leur permettre de jouer un coup à tour de rôle.
*/

/*
Structure de joueur
Vous devez réaliser une structure Player qui contient les informations suivantes :

name : nom du joueur
symbol : symbole du joueur (e.g. 'X' ou 'O')
Cette structure doit être utilisée pour stocker les informations des joueurs
et placée dans des fichiers dédiés Player.hpp et Player.cpp.
*/

if (modes == 1)
{
    std::cout << "Mode deux joueurs"<< std::endl;
    Player joueur1 { create_player() };
    Player joueur2 { create_player() };
    std::cout <<"Joueur 1 : " << joueur1.nom << " (" << joueur1.symbole << ")"<< std::endl;
    std::cout <<"Joueur 2 : " << joueur2.nom << " (" << joueur2.symbole << ")"<< std::endl; 

}
else if (modes == 2)
{
    std::cout << "Mode joueur contre IA"<< std::endl;
    Player joueur {create_player ()};
    Player ia {};
    ia.nom ="IA";
    ia.symbole = '0';
    std::cout <<"Joueur :" << joueur.nom << " (" << joueur.symbole << ")"<< std::endl;
    std::cout<<"Adversaire : " << ia.nom << " (" << ia.symbole << ")"<< std::endl;
}
else
{
    std::cout << "Veuillez choisir parmis le mode 1 ou 2 "<< std::endl;
}

/*
Affichage du plateau de jeu
Vous devez réaliser une fonction draw_game_board (vous pouvez modifier légèrement le nom de la fonction si vous le souhaitez) qui prend en paramètre un tableau de caractères (char) et affiche le plateau de jeu dans la terminal.
Le plateau de jeu doit être affiché de la manière suivante :

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |

où chaque chiffre représente une case du plateau de jeu.

Le plateau doit être représenté dans le code sous forme d'un tableau de caractères (char) représentant les symboles des joueurs ou un caractère "vide" (par exemple un .) pour une case vide.

⚠️ Ici le nombre de cases du plateau est connu à l'avance, vous devez donc de préférence utiliser un tableau statique plutôt qu'un tableau dynamique pour représenter le plateau de jeu.
*/
    char cases[9] {'1','2','3','4','5','6','7','8','9'};
    draw_game_board(cases);
    return 0;
}

/*
Affichage du plateau de jeu
Vous devez réaliser une fonction draw_game_board (vous pouvez modifier légèrement le nom de la fonction si vous le souhaitez)
qui prend en paramètre un tableau de caractères (char) et affiche le plateau de jeu dans la terminal.
*/

void draw_game_board(char const cases[9])
{
    std::cout <<"| "<< cases[0] << "| "<< cases[1] << "| "<< cases[2] << "| "<<std::endl;
    std::cout <<"| "<< cases[3] << "| "<< cases[4] << "| "<< cases[5] << "| "<<std::endl;
    std::cout <<"| "<< cases[6] << "| "<< cases[7] << "| "<< cases[8] << "| "<<std::endl;
}


