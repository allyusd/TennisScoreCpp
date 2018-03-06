#include "game.h"

Game::Game()
{
	m_score_lookup.insert(std::pair<int, std::string>(0, "Love"));
	m_score_lookup.insert(std::pair<int, std::string>(1, "Fifteen"));
	m_score_lookup.insert(std::pair<int, std::string>(2, "Thirty"));
	m_score_lookup.insert(std::pair<int, std::string>(3, "Forty"));
}

Game::~Game()
{
}

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

std::string Game::first_player_name() const
{
	return m_first_player_name;
}

void Game::set_first_player_name(const std::string& name)
{
	m_first_player_name = name;
}

std::string Game::second_player_name() const
{
	return m_second_player_name;
}

void Game::set_second_player_name(const std::string& name)
{
	m_second_player_name = name;
}

std::string Game::score_lookup(const int score) const
{
	return static_cast<std::string>(m_score_lookup.at(score));
}

bool Game::is_game_score() const
{
	return first_player_score() == second_player_score();
}

std::string Game::same_score_lookup() const
{
	return score_lookup(first_player_score()).append(" All");
}

bool Game::is_deuce() const
{
	return first_player_score() >= 3;
}

std::string Game::lookup_score() const
{
	return score_lookup(first_player_score()).append(" ").append(score_lookup(second_player_score()));
}

bool Game::is_ready_for_win() const
{
	return first_player_score() > 3 || second_player_score() > 3;
}

std::string Game::adv_player() const
{
	return first_player_score() > second_player_score() ? first_player_name() : second_player_name();
}