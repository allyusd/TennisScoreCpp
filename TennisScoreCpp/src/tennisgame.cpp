﻿#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
    m_repo = repo;
}

std::string TennisGame::score_result(const int game_id) const
{
    auto game = m_repo->get_game(game_id);

    if (game.is_same_score())
    {
        return game.is_deuce() ? "Deuce" : game.same_score_lookup();
    }
    else
    {
        if (game.first_player_score() > 3)
        {
            return game.first_player_name().append(" Adv");
        }

        return game.score_lookup();
    }
}
