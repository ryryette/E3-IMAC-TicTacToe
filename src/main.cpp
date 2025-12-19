#include <iostream>
#include "Player.hpp"

void draw_game_board(char const cases[9]);

int main()
{

int modes {0};
while (modes !=1 && modes !=2)
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

    std::cin >> modes;

    if (modes !=1 && modes != 2)
    {
         std::cout << "Veuillez choisir parmis le mode 1 ou 2 "<< std::endl;
    }
  
}

Player joueur1 {};
Player joueur2 {};

/*
Structure de joueur
Vous devez réaliser une structure Player qui contient les informations suivantes :

name : nom du joueur
symbol : symbole du joueur (e.g. 'X' ou 'O')
Cette structure doit être utilisée pour stocker les informations des joueurs
et placée dans des fichiers dédiés Player.hpp et Player.cpp.
*/

/*
Deux joueurs
Vous devez réaliser un mode de jeu où deux joueurs peuvent s'affronter sur le jeu.

Le jeu doit alterner entre les deux joueurs pour leur permettre de jouer un coup à tour de rôle.
*/

if (modes == 1)
{
    std::cout << "Mode deux joueurs"<< std::endl;
    joueur1 = create_player();
    joueur2 = create_player();
    std::cout << "Joueur 1 : " << joueur1.nom << " (" << joueur1.symbole << ")"<< std::endl;
    std::cout << "Joueur 2 : " << joueur2.nom << " (" << joueur2.symbole << ")"<< std::endl; 

}

/*
Un joueur et IA
Vous devez réaliser un mode de jeu où un joueur affronte une IA (Intelligence Artificielle) qui joue aléatoirement sur une case vide.

Dans ce cas de figure vous réutiliserez la structure Player pour l'IA en initialisant le nom de l'IA à "IA" et un symbole pré-défini (différent de celui du joueur).

Le jeu doit alterner entre le joueur et l'IA pour leur permettre de jouer un coup à tour de rôle.
*/

else if (modes == 2)
{
    std::cout << "Mode joueur contre IA"<< std::endl;
    joueur1 = create_player();
    joueur2.nom = "IA";
    joueur2.symbole = 'O';
    std::cout << "Joueur : " << joueur1.nom << " (" << joueur1.symbole << ")"<< std::endl;
    std::cout << "Adversaire : " << joueur2.nom << " (" << joueur2.symbole << ")"<< std::endl;
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

    int choix_case {0};
    std::cout <<joueur1.nom <<", choisis une case (1 à 9) : ";
    std::cin >>choix_case;

    cases[choix_case - 1] = joueur1.symbole;

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


