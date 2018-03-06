#include "src/game.h"
#include "src/tennisgame.h"
#include "mockrepository.hpp"

#include <gtest/gtest.h>

const int any_game_id = 1;

class TennisGameTest : public testing::Test
{
protected:
	void SetUp() override {}
	void TearDown() override {}

	void given_game(const Game& game)
	{
		m_repo.set_game(game);
	}

	void score_should_be(const std::string& expected)
	{
		TennisGame tennis_game(&m_repo);
		EXPECT_EQ(expected, tennis_game.score_result(any_game_id));
	}

	MockRepository m_repo;
};

TEST_F(TennisGameTest, AllLove)
{
	Game game;
	game.set_id(any_game_id);
	game.set_first_player_score(0);
	game.set_second_player_score(0);

	given_game(game);
	score_should_be("All Love");
}