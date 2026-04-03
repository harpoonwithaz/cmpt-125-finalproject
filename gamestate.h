#pragma once

#include <string>

struct Gamestate
{
    bool player_one_move = true;
    bool anvil_move = false;
    bool anvil_used = false;

    std::string player_one_username = "Player one";
    std::string player_two_username = "Player two";
};
