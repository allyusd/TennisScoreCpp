#pragma once

#include "irepository.h"

#include <QtCore/QString>

class TennisGame
{
public:
    TennisGame(IRepository* repo);
	QString score_result(const int game_id) const;

private:
    IRepository* m_repo;
};
