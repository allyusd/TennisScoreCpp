#include "hardwarerepository.h"



HardWareRepository::HardWareRepository()
{
}


HardWareRepository::~HardWareRepository()
{
}

Game HardWareRepository::get_game(int game_id)
{
    return m_game;
}

void HardWareRepository::player1_get()
{
    m_game.set_first_player_score(m_game.first_player_score() + 1);
}

void HardWareRepository::player2_get()
{
    m_game.set_second_player_score(m_game.second_player_score() + 1);
}
