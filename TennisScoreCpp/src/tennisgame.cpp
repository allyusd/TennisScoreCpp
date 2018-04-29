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

    return static_cast<std::string>(m_score_lookup_map.at(game.first_player_score()))
        .append(" All");
}
