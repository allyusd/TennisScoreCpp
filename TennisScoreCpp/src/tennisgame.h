#pragma once

#include "irepository.h"

#include <string>
#include <map>

class TennisGame
{
public:
	TennisGame(IRepository* repo);
	std::string score_lookup(int score) const;
	std::string score_result(int game_id) const;

private:
	IRepository* m_repo;
	std::map<int, std::string> m_score_lookup;
};
