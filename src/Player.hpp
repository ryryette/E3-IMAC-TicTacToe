/*
Structure de joueur
Vous devez réaliser une structure Player qui contient les informations suivantes :

name : nom du joueur
symbol : symbole du joueur (e.g. 'X' ou 'O')
Cette structure doit être utilisée pour stocker les informations des joueurs
et placée dans des fichiers dédiés Player.hpp et Player.cpp.

Vous devez réaliser une fonction create_player qui ne prend aucun paramètre
et qui retourne une structure Player initialisée avec les informations du joueur.
*/

#pragma once
#include <string>

struct Player
{
    std::string nom;
    char symbole;
};
Player create_player(); //Vous devez réaliser une fonction create_player qui ne prend aucun paramètre  
        
Player create_player(char symbole_pris);  

