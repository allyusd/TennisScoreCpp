#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
	m_repo = repo;
}

std::string TennisGame::score_result(const int game_id) const
{
	auto game = m_repo->get_game(game_id);

	if (game.first_player_score() == 1 
		&& game.second_player_score() == 1)
	{
		return "Fifteen All";
	}

	return "Love All";
}
