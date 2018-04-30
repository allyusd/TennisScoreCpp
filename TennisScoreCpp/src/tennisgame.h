#pragma once

#include "irepository.h"

#include <string>
#include <map>

class TennisGame
{
public:
    TennisGame(IRepository* repo);
    std::string score_result(const int game_id) const;

    bool is_same_score(Game& game) const;

private:
    std::string score_lookup(const int score) const;
    std::string score_lookup(const Game& game) const;
    std::string same_score_lookup(const Game& game) const;
private:
    IRepository* m_repo;
    std::map<int, std::string> m_score_lookup_map;
};
