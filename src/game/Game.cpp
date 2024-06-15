#include "Game.hpp"

#include <iostream>

int_vect::int_vect() {
	x = 0, y = 0;
}
int_vect::int_vect(int ix, int iy) {
	x = ix, y = iy;
}

std::vector<std::vector<I_chess_piece*>> Game::default_map
{ 
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr},
	{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, new chess_piece_pawn(1), nullptr}
};

Game* Game::_self = nullptr;
Game* Game::get()
{
	if (_self == nullptr)
		throw("game called without initialising");
	return _self;
}

void Game::fill_map_to_default()
{
	int sx = default_map.size(), sy = 0;
	game_map.resize(sx);
	for (int i = 0; i < sx;  i++) {
		sy = default_map[i].size();

		game_map[i].resize(sy, nullptr);
		for (int j = 0; j < sy; j++ )
		{
			delete game_map[i][j];
			if (default_map[i][j] == nullptr) {
				game_map[i][j] = nullptr;
				continue;
			}
			game_map[i][j] = default_map[i][j]->Clone();
		}
	}
}
Game::Game() {
	last_command = "";

	fill_map_to_default();
	drawable_data.map.resize(default_map[0].size(), std::string("?", default_map.size()));
}
int Game::Initialization() {
	if (_self != nullptr)
		throw("game double initialisation");

	_self = new Game();
	return 0;
}

int Game::step(const std::string& input) {
	last_command = input;

	int sx = game_map.size(), sy = game_map[0].size();
	for (int x = 0; x < sx; x++) {
		for (int y = 0; y < sy; y++)
		{
			if (game_map[x][y] == nullptr) {
				drawable_data.map[y][x] = (x+y) % 2 == 0 ? '8': '9';
				continue;
			}
			drawable_data.map[y][x] = game_map[x][y]->get_texture();
		}
	}

	if(input == "q"){ 
		drawable_data.answer = "";
		return 0; 
	}
	drawable_data.answer = "gGggRrrRRrrrrrr";
	return 1;
}

geme_drawable_data Game::get_drawable_data()
{
	return drawable_data;
}