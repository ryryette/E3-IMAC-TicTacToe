#pragma once
#include <string>

struct Player
{
    std::string nom;
    char symbole;
};

Player create_player();               
Player create_player(char symbole_pris);
