#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

void draw_game_board(char const cases[9]);
bool board_rempli(char const cases[9]);
bool victoire(char const cases[9], char symbole);
int ia_choix_case(char const cases[9]);


int main()
{

    std::srand(static_cast<unsigned>(std::time(nullptr)));

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

if (std::cin.fail())
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    modes = 0;
}

if (modes != 1 && modes != 2)
{
    std::cout << "Veuillez choisir parmis le mode 1 ou 2 " << std::endl;
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
    joueur2 = create_player(joueur1.symbole);
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
    joueur2.symbole = (joueur1.symbole == 'X') ? 'O' : 'X';
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

while (true)
{
    draw_game_board(cases);

    /*
    Tour de jeu
    Vous devez permettre aux joueurs de jouer à tour de rôle.
    À chaque tour, le joueur choisit une case libre et son symbole est placé sur le plateau.
    */

    int choix_case {0};
    std::cout << joueur1.nom << ", choisis une case (1 à 9) : ";
    std::cin >> choix_case;
    if (std::cin.fail())
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    choix_case = 0;
}


    while (choix_case < 1 || choix_case > 9 ||
           cases[choix_case - 1] == joueur1.symbole ||
           cases[choix_case - 1] == joueur2.symbole)
    {
        std::cout << "Choisis une case DISPONIBLE (1 à 9) : ";
        std::cin >> choix_case;
if (std::cin.fail())
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    choix_case = 0;
}

        
    }

    cases[choix_case - 1] = joueur1.symbole;
    draw_game_board(cases);

    if (victoire(cases, joueur1.symbole))
{
    std::cout << joueur1.nom << " a gagné !" << std::endl;
    break;
}

    if (board_rempli(cases))
{
    std::cout << "Égalité !" << std::endl;
    break;
}

if (modes == 1)
{
    std::cout << joueur2.nom << ", choisis une case (1 à 9) : ";
    std::cin >> choix_case;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        choix_case = 0;
    }

    while (choix_case < 1 || choix_case > 9 ||
           cases[choix_case - 1] == joueur1.symbole ||
           cases[choix_case - 1] == joueur2.symbole)
    {
        std::cout << "Choisis une case DISPONIBLE (1 à 9) : ";
        std::cin >> choix_case;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            choix_case = 0;
        }
    }

    cases[choix_case - 1] = joueur2.symbole;
    draw_game_board(cases);

    if (victoire(cases, joueur2.symbole))
    {
        std::cout << joueur2.nom << " a gagné !" << std::endl;
        break;
    }

    if (board_rempli(cases))
    {
        std::cout << "Égalité !" << std::endl;
        break;
    }
}
else // mode 2
{
    int choix_ia = ia_choix_case(cases);
    std::cout << joueur2.nom << " joue : " << choix_ia << std::endl;

    cases[choix_ia - 1] = joueur2.symbole;
    draw_game_board(cases);

    if (victoire(cases, joueur2.symbole))
    {
        std::cout << joueur2.nom << " a gagné !" << std::endl;
        break;
    }

    if (board_rempli(cases))
    {
        std::cout << "Égalité !" << std::endl;
        break;
    }
}

}
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

bool board_rempli(char const cases[9])
{
    for (int i = 0; i < 9; ++i)
    {
        if (cases[i] >= '1' && cases[i] <= '9')
        {
            return false;
        }
    }
    return true;
}

bool victoire(char const cases[9], char symbole)
{
    return
        (cases[0] == symbole && cases[1] == symbole && cases[2] == symbole) ||
        (cases[3] == symbole && cases[4] == symbole && cases[5] == symbole) ||
        (cases[6] == symbole && cases[7] == symbole && cases[8] == symbole) ||

        (cases[0] == symbole && cases[3] == symbole && cases[6] == symbole) ||
        (cases[1] == symbole && cases[4] == symbole && cases[7] == symbole) ||
        (cases[2] == symbole && cases[5] == symbole && cases[8] == symbole) ||

        (cases[0] == symbole && cases[4] == symbole && cases[8] == symbole) ||
        (cases[2] == symbole && cases[4] == symbole && cases[6] == symbole);
}

int ia_choix_case(char const cases[9])
{
    int choix = 0;
    do {
        choix = (std::rand() % 9) + 1; 
    } while (!(cases[choix - 1] >= '1' && cases[choix - 1] <= '9')); 

    return choix;
}



