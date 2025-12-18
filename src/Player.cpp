

/*
Vous devez réaliser une fonction create_player qui ne prend aucun paramètre
et qui retourne une structure Player initialisée avec les informations du joueur.
Cette fonction doit demander le nom du joueur à l'utilisateur (std::cin)
et lui demander de choisir un symbole.
*/

#include "Player.hpp"
#include <iostream>

Player create_player ()
{
    Player joueur {};
    std::cout <<"Entrez votre nom de joeur";
    std::cin >>joueur.nom;
    std::cout <<"Entrez votre symbole pour jouer :";
    std::cin >>joueur.symbole;
    return joueur; 
}