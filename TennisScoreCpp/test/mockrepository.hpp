#pragma once

#include "src/game.h"
#include "src/irepository.h"

class MockRepository : public IRepository
{
public:
	Game get_game(int game_id) override
	{
		return m_fakeGame;
	}

	void set_game(Game game)
	{
		m_fakeGame = game;
	}

private:
	Game m_fakeGame;
};
