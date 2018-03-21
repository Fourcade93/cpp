#include "ft_retro.hpp"

static void	draw_frame(void)
{
	attron(COLOR_PAIR(FRAME_CL_PAIR));
	mvhline(0, 0, ' ', WIN_WIDTH);
	mvhline(5, 0, ' ', WIN_WIDTH);
	mvhline(WIN_HEIGHT, 0, ' ', WIN_WIDTH + 1);
	mvvline(0, 0, ' ', WIN_HEIGHT);
	mvvline(0, WIN_WIDTH, ' ', WIN_HEIGHT);
}

static void	init_colors(void)
{
	init_pair(FRAME_CL_PAIR, COLOR_BLUE, COLOR_BLUE);
	init_pair(PLR_CL_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(RED_CL_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(INFO_CL_PAIR, COLOR_YELLOW, COLOR_BLACK);
}

WINDOW*		init_window(void)
{
	WINDOW *game_win = NULL;

	setlocale(LC_ALL, "");
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	start_color();
	init_colors();
	noecho();
	draw_frame();
	refresh();
	game_win = newwin(WIN_HEIGHT - 6, WIN_WIDTH - 2, 6, 1);
	return (game_win);
}
