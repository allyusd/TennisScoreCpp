#pragma once

class Game
{
public:
	int id() const;
	void set_id(int id);
	int first_player_score() const;
	void set_first_player_score(int score);
	int second_player_score() const;
	void set_second_player_score(int score);

private:
	int m_id = 0;
	int m_first_player_score = 0;
	int m_second_player_score = 0;
};
