#include <iostream>

void draw_game_board(char const cases[9]);

int main()
{
    
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


