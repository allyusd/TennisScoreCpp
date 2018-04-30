#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
    m_repo = repo;
}

std::string TennisGame::score_result(const int game_id) const
{
    auto game = m_repo->get_game(game_id);

    return game.is_same_score() ?
        game.is_deuce() ? "Deuce" : game.same_score_lookup() :
        game.is_ready_for_win() ? game.adv_state() : game.score_lookup();
}
