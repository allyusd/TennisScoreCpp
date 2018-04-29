#include "src/game.h"
#include "src/tennisgame.h"
#include "mockrepository.hpp"

#include <gtest/gtest.h>

class TennisGameTest : public testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}

    void given_game(const Game& game);
    void score_should_be(const std::string& expect);

    const int kAnyGameID = 1;
    MockRepository repo;
};

void TennisGameTest::given_game(const Game& game)
{
    repo.set_game(game);
}

void TennisGameTest::score_should_be(const std::string& expect)
{
    TennisGame tennisGame(&repo);
    auto result = tennisGame.score_result(kAnyGameID);
    EXPECT_EQ(expect, result);
}

TEST_F(TennisGameTest, LoveAll)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(0);
    game.set_second_player_score(0);

    given_game(game);
    score_should_be("Love All");
}

TEST_F(TennisGameTest, FifteenAll)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(1);
    game.set_second_player_score(1);

    given_game(game);
    score_should_be("Fifteen All");
}
