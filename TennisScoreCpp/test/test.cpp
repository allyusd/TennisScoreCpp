#include "src/game.h"
#include "src/tennisgame.h"
#include "mockrepository.hpp"

#include <gtest/gtest.h>

class TennisGameTest : public testing::Test {
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(TennisGameTest, AllLove) {
	Game game;
	game.set_id(1);
	game.set_first_player_score(0);
	game.set_second_player_score(0);

	MockRepository repo;
	repo.set_game(game);

	TennisGame tennisGame(&repo);

	int game_id = 1;
	auto result = tennisGame.score_result(game_id);

	EXPECT_EQ("All Love", result);
}