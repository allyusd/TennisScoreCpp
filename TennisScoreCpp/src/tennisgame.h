#pragma once

#include "irepository.h"

#include <string>

class TennisGame
{
public:
	TennisGame(IRepository* repo);
	std::string score_result(const int game_id) const;

private:
	IRepository* m_repo;
};
