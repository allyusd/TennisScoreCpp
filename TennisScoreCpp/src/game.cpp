#include "game.h"

int Game::id() const
{
	return m_id;
}

void Game::set_id(int id)
{
	m_id = id;
}

int Game::first_player_score() const
{
	return m_first_player_score;
}

void Game::set_first_player_score(int score)
{
	m_first_player_score = score;
}

int Game::second_player_score() const
{
	return m_second_player_score;
}

void Game::set_second_player_score(int score)
{
	m_second_player_score = score;
}

