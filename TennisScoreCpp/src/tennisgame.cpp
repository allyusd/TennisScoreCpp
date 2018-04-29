﻿#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
    m_repo = repo;

    m_score_lookup_map.insert(std::pair<int, std::string>(0, "Love"));
    m_score_lookup_map.insert(std::pair<int, std::string>(1, "Fifteen"));
    m_score_lookup_map.insert(std::pair<int, std::string>(2, "Thirty"));
}

std::string TennisGame::score_result(const int game_id) const
{
    auto game = m_repo->get_game(game_id);

    if (game.first_player_score() >= 3)
    {
        return "Deuce";
    }

    return score_lookup(game.first_player_score()).append(" All");
}

std::string TennisGame::score_lookup(const int score) const
{
    return static_cast<std::string>(m_score_lookup_map.at(score));
}
