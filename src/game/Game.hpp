#ifndef BS_GAME_H
#define BS_GAME_H

#include "chess_piece.hpp"

#include <string>
#include <vector>
#include <map>

struct geme_drawable_data
{
	std::vector<std::string> map;
	std::string answer;
};

// ---------------- GAME ---------------------------------------
class Game {
	static Game* _self;
private:
	Game();

	std::string last_command;
	geme_drawable_data drawable_data;

	static std::vector<std::vector<I_chess_piece*>> default_map;

	void fill_map_to_default();
	std::vector<std::vector<I_chess_piece*>> game_map;

	bool inmap(int x, int y);

	int step_counter{ 0 } ;
public:
	static Game* get();
	static int Initialization();

	int step(const std::string& input);

	const geme_drawable_data& get_drawable_data();
	const std::vector<std::vector<I_chess_piece*>>& get_map();
	int get_step_count();
};

#endif