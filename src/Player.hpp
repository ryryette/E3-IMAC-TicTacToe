/*
Structure de joueur
Vous devez réaliser une structure Player qui contient les informations suivantes :

name : nom du joueur
symbol : symbole du joueur (e.g. 'X' ou 'O')
Cette structure doit être utilisée pour stocker les informations des joueurs et placée dans des fichiers dédiés Player.hpp et Player.cpp.

Vous devez réaliser une fonction create_player qui ne prend aucun paramètre et qui retourne une structure Player initialisée avec les informations du joueur. Cette fonction doit demander le nom du joueur à l'utilisateur (std::cin) et lui demander de choisir un symbole (X ou O généralement mais vous pouvez choisir d'autres symboles si vous le souhaitez).
*/

#pragma once
#include <string>

struct Player 
{
    std::string nom {};
    char symbole {};
};

Player create_player();