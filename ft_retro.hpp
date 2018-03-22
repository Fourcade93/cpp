#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# include <chrono>
# include <iostream>
# include <ncurses.h>
# include <unistd.h>

/*
** numbers
*/
# define WIN_HEIGHT 55
# define WIN_WIDTH 100

/*
** colors
*/
# define FRAME_CL_PAIR 1
# define PLR_CL_PAIR 2
# define RED_CL_PAIR 3
# define INFO_CL_PAIR 4

/*
** init_window.cpp
*/
WINDOW*		init_window(void);

/*
** play_game.cpp
*/
void	play_game(WINDOW *game_win);

#endif