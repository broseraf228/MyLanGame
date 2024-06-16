
#include "screen.hpp"
#include "game/Game.hpp"

#include <iostream>

int main()
{
	if (Screen::Initialization()) {
		std::cout << "can't initialize Screen";
		return -1;
	}
	Screen* screen = Screen::get();

	if (Game::Initialization()) {
		std::cout << "can't initialize Game";
		return -1;
	}
	Game* game = Game::get();

	std::string command = "start";

	game->step(command);
	screen->clear();
	screen->draw_game(game->get_drawable_data());
	screen->display();

	while(true) // <----- game mainloop
	{
		do { // <----- try do step
			std::cout << "command: ";
			std::cin >> command;

			if (!game->step(command))
				break;

			screen->clear();
			screen->draw_game(game->get_drawable_data());
			screen->display();

		} while (true);
		

		screen->clear();
		screen->draw_game(game->get_drawable_data());
		screen->display();
	}

	

	return 0;
}