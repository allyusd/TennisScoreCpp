#pragma once

#include <string>
#include <map>

class Game
{
public:
	Game();
	~Game();
	int id() const;
	void set_id(int id);
	int first_player_score() const;
	void set_first_player_score(int score);
	int second_player_score() const;
	void set_second_player_score(int score);
	std::string first_player_name() const;
	void set_first_player_name(const std::string& name);
	std::string second_player_name() const;
	void set_second_player_name(const std::string& name);

	std::string result() const;

private:
	std::string adv_player() const;
	std::string score_lookup(int score) const;
	bool is_game_score() const;
	std::string same_score_lookup() const;
	bool is_deuce() const;
	std::string lookup_score() const;
	bool is_ready_for_win() const;
	bool is_adv() const;
	std::string adv_state() const;

private:
	int m_id = 0;
	int m_first_player_score = 0;
	int m_second_player_score = 0;
	std::map<int, std::string> m_score_lookup;
	std::string m_first_player_name;
	std::string m_second_player_name;
};
