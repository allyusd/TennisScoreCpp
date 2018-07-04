#pragma once
#include "d:\Workspace\tdd\TennisScoreCpp\TennisScoreCpp\src\irepository.h"
#include "hardware_api.h"
#include "src\game.h"

class HardWareRepository : public IRepository, public HardWareAPI
{
public:
    HardWareRepository();
    virtual ~HardWareRepository();

    virtual Game get_game(int game_id);
    virtual void player1_get();
    virtual void player2_get();

private:
    Game m_game;
};

