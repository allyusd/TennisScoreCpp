#include "tennisgame.h"
#include "game.h"

TennisGame::TennisGame(IRepository* repo)
{
    m_repo = repo;

    m_score_lookup_map.insert(std::pair<int, std::string>(0, "Love"));
    m_score_lookup_map.insert(std::pair<int, std::string>(1, "Fifteen"));
    m_score_lookup_map.insert(std::pair<int, std::string>(2, "Thirty"));
    m_score_lookup_map.insert(std::pair<int, std::string>(3, "Forty"));
}

std::string TennisGame::score_result(const int game_id) const
{
    auto game = m_repo->get_game(game_id);

    if (is_same_score(game))
    {
        if (game.first_player_score() >= 3)
        {
            return "Deuce";
        }

        return same_score_lookup(game);
    }
    else
    {
        return score_lookup(game);
    }
}

bool TennisGame::is_same_score(Game& game) const
{
    return game.first_player_score() == game.second_player_score();
}

std::string TennisGame::score_lookup(const int score) const
{
    return static_cast<std::string>(m_score_lookup_map.at(score));
}

std::string TennisGame::score_lookup(const Game& game) const
{
    return score_lookup(game.first_player_score())
        .append(" ")
        .append(score_lookup(game.second_player_score()));
}

std::string TennisGame::same_score_lookup(const Game& game) const
{
    return score_lookup(game.first_player_score()).append(" All");
}

