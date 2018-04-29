#pragma once

#include "irepository.h"

#include <string>
#include <map>

class TennisGame
{
public:
    TennisGame(IRepository* repo);
    std::string score_result(const int game_id) const;

private:
    std::string& score_lookup(const int score) const;

private:
    IRepository* m_repo;
    std::map<int, std::string> m_score_lookup_map;
};
