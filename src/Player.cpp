/*
Vous devez réaliser une fonction create_player qui ne prend aucun paramètre
et qui retourne une structure Player initialisée avec les informations du joueur.
Cette fonction doit demander le nom du joueur à l'utilisateur (std::cin)
et lui demander de choisir un symbole.
*/

#include "Player.hpp"
#include <iostream>

Player create_player()
{
    return create_player('\0');
}

Player create_player(char symbole_pris)
{
    Player p;
    std::cout << "Entrez votre nom de joueur : ";
    std::cin >> p.nom;

    do {
        std::cout << "Choisissez votre symbole (X ou O) : ";
        std::cin >> p.symbole;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            p.symbole = '\0';
            std::cout << "Entrée invalide. Recommence.\n";
            continue;
        }

        if (p.symbole >= 'a' && p.symbole <= 'z')
            p.symbole = p.symbole - 'a' + 'A';

        if ((p.symbole != 'X' && p.symbole != 'O') || p.symbole == symbole_pris)
        {
            std::cout << "Symbole invalide";
            if (symbole_pris == 'X' || symbole_pris == 'O')
                std::cout << " (déjà pris)";
            std::cout << ". Recommence.\n";
            p.symbole = '\0';
        }

    } while (p.symbole == '\0');

    return p;
}
