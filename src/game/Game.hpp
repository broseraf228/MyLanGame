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


struct int_vect {
	int_vect();
	int_vect(int x, int y);
	int x, y;
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
public:
	static Game* get();
	static int Initialization();

	int step(const std::string& input);

	geme_drawable_data get_drawable_data();
};

#endif