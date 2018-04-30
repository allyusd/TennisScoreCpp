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

TEST_F(TennisGameTest, ThirtyAll)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(2);
    game.set_second_player_score(2);

    given_game(game);
    score_should_be("Thirty All");
}

TEST_F(TennisGameTest, Deuce)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(3);
    game.set_second_player_score(3);

    given_game(game);
    score_should_be("Deuce");
}

TEST_F(TennisGameTest, FifteenLove)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(1);
    game.set_second_player_score(0);

    given_game(game);
    score_should_be("Fifteen Love");
}

TEST_F(TennisGameTest, ThirtyFifteen)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(2);
    game.set_second_player_score(1);

    given_game(game);
    score_should_be("Thirty Fifteen");
}

TEST_F(TennisGameTest, FortyFifteen)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(3);
    game.set_second_player_score(1);

    given_game(game);
    score_should_be("Forty Fifteen");
}

TEST_F(TennisGameTest, FirstPlayer_Advance)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(4);
    game.set_second_player_score(3);
    game.set_first_player_name("Joey");

    given_game(game);
    score_should_be("Joey Adv");
}

TEST_F(TennisGameTest, SecondPlayer_Advance)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(3);
    game.set_second_player_score(4);
    game.set_second_player_name("Tom");

    given_game(game);
    score_should_be("Tom Adv");
}

TEST_F(TennisGameTest, FirstPlayer_Win)
{
    Game game;
    game.set_id(kAnyGameID);
    game.set_first_player_score(5);
    game.set_second_player_score(3);
    game.set_first_player_name("Joey");

    given_game(game);
    score_should_be("Joey Win");
}
