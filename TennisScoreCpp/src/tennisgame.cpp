#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
    m_repo = repo;
}

std::string TennisGame::score_result(const int game_id) const
{
    return m_repo->get_game(game_id).result();
}
