#include "ft_retro.hpp"

int main(void)
{
	WINDOW *game_win = NULL;
	std::srand(std::time(0));

	game_win = init_window();
	play_game(game_win);
	while (getch() != 32)
		;
	endwin();
	return 0;
}
