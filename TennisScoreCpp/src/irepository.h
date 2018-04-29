#pragma once
#include <list>

class Game;

class IRepository
{
public:
    virtual ~IRepository() {};

    virtual Game get_game(int game_id) = 0;
};
