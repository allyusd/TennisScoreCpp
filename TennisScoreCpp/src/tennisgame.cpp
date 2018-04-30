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
        if (game.first_player_score() >= 3)
        {
            return "Deuce";
        }

        return game.same_score_lookup();
    }
    else
    {
        return game.score_lookup();
    }
}
