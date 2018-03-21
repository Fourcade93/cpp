#include "ft_retro.hpp"
#include "EnemiesMap.hpp"
#include "PlayerBullets.hpp"
#include "Player.hpp"

void	move_pl(Player *pl, char ch)
{
	if (ch == 4)
		pl->moveLeft();
	if (ch == 5)
		pl->moveRight();
	if (ch == 3)
		pl->moveTop();
	if (ch == 2)
		pl->moveBottom();
}

void	update_win(WINDOW *game_win, EnemiesMap *enemies, Player *pl, PlayerBullets *pl_shots, double seconds)
{
	attron(COLOR_PAIR(INFO_CL_PAIR));
	mvprintw(1, 2, "Time: %-10.2f", seconds / 1000);
	mvprintw(2, 2, "Lives: %-5d", pl->getLives());
	wattron(game_win, COLOR_PAIR(RED_CL_PAIR));
	enemies->printLines(game_win);
	wattron(game_win, COLOR_PAIR(PLR_CL_PAIR));
	pl_shots->printLines(game_win);
	mvwprintw(game_win, pl->getY(), pl->getX(), "^");

	wrefresh(game_win);
	werase(game_win);
}

void	check_collision(EnemiesMap *enemies, Player *pl)
{
	if (enemies->checkCollision(pl->getY(), pl->getX()))
		pl->decreaseLives();
	if (pl->getLives() <= 0)
	{
		mvprintw(2, 2, "Lives: %-5d", pl->getLives());
		delete pl;
		delete enemies;
		mvprintw(2, 45, "GAME OVER");
		refresh();
		while (getch() == ERR)
			;
		endwin();
		exit(0);
	}
}

void	fire_if(PlayerBullets *pl_shots, Player *pl, EnemiesMap *enemies)
{
	if (enemies->checkIfTarget(pl->getY(), pl->getX()))
		pl_shots->addBullets(pl->getY() - 1, pl->getX());
	pl_shots->checkCollision(enemies);
}

void	play_game(WINDOW *game_win)
{
	Player *pl = new Player;
	char ch;
	std::chrono::high_resolution_clock::time_point checkTime;
	std::chrono::high_resolution_clock::time_point begin;
	std::chrono::high_resolution_clock::time_point cur;
	double seconds = 0;
	EnemiesMap *enemies = new EnemiesMap;
	PlayerBullets *pl_shots = new PlayerBullets;

	wattron(game_win, A_BOLD);

	begin = checkTime  = std::chrono::high_resolution_clock::now();
	while ((ch = getch()) != 32)
	{
		cur = std::chrono::high_resolution_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(cur - checkTime).count() > 100)
		{
			checkTime = std::chrono::high_resolution_clock::now();
			enemies->addLine();
		}
		if (!((int)seconds % 50))
			pl_shots->shiftLines();
		if (ch > 1 && ch < 6)
			move_pl(pl, ch);
		seconds = std::chrono::duration_cast<std::chrono::milliseconds>(cur - begin).count();
		check_collision(enemies, pl);
		fire_if(pl_shots, pl, enemies);
		update_win(game_win, enemies, pl, pl_shots, seconds);
	}
}
