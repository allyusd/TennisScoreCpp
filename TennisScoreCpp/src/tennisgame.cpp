#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
	m_repo = repo;
}

std::string TennisGame::score_result(const int game_id) const
{
	auto game = m_repo->get_game(game_id);

	if (game.is_game_score())
	{
		return game.is_deuce() ? "Deuce" : game.same_score_lookup();
	}

	if (game.first_player_score() > 3 || game.second_player_score() > 3)
	{
		return game.first_player_name().append(" Adv");
	}

	return game.lookup_score();
}
