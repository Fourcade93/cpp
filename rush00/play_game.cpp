#include "ft_retro.hpp"
#include "EnemiesMap.hpp"
#include "PlayerBullets.hpp"
#include "EnemyBullets.hpp"
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

void	update_win(WINDOW *game_win, EnemiesMap *enemies, Player *pl, PlayerBullets *pl_shots, double seconds, EnemyBullets * en_shots)
{
	attron(COLOR_PAIR(INFO_CL_PAIR));
	mvprintw(1, 2, "Time: %-10.2f", seconds / 1000);
	mvprintw(2, 2, "Lives: %-5d", pl->getLives());
	mvprintw(3, 2, "Points: %-5d", pl->getPoints());
	wattron(game_win, COLOR_PAIR(RED_CL_PAIR));
	enemies->printLines(game_win);
	wattron(game_win, COLOR_PAIR(ENSHOT_CL_PAIR));
	en_shots->printLines(game_win);
	wattron(game_win, COLOR_PAIR(PLR_CL_PAIR));
	pl_shots->printLines(game_win);
	mvwprintw(game_win, pl->getY(), pl->getX(), "^");

	wrefresh(game_win);
	werase(game_win);
}

void	check_collision(EnemiesMap *enemies, Player *pl, PlayerBullets *pl_shots, EnemyBullets *en_shots)
{
	pl_shots->checkCollision(enemies, pl);
	en_shots->checkCollision(pl);
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
		pl_shots->addBullets(pl->getY() - 1, pl->getX());}

void	enemy_shot(EnemyBullets *en_shots, EnemiesMap *enemies)
{
	enemies->addBullets(en_shots);
}

void	play_game(WINDOW *game_win)
{
	char ch;
	int i = 0;
	std::chrono::high_resolution_clock::time_point checkTime;
	std::chrono::high_resolution_clock::time_point begin;
	std::chrono::high_resolution_clock::time_point cur;
	double seconds = 0;
	Player *pl = new Player;
	EnemiesMap *enemies = new EnemiesMap;
	PlayerBullets *pl_shots = new PlayerBullets;
	EnemyBullets *en_shots = new EnemyBullets;

	wattron(game_win, A_BOLD);

	begin = checkTime  = std::chrono::high_resolution_clock::now();
	while ((ch = getch()) != 32)
	{
		cur = std::chrono::high_resolution_clock::now();
		if (i++ % 1000 == 0)
		{
			pl_shots->shiftLines();
			en_shots->shiftLines();
		}
		if (i % 10000 == 0)
			enemy_shot(en_shots, enemies);
		if (std::chrono::duration_cast<std::chrono::milliseconds>(cur - checkTime).count() > 400)
		{
			checkTime = std::chrono::high_resolution_clock::now();
			enemies->addLine();
			fire_if(pl_shots, pl, enemies);
		}
		if (ch > 1 && ch < 6)
		{
			if (ch == 4 || ch == 5)
				fire_if(pl_shots, pl, enemies);
			move_pl(pl, ch);
		}
		seconds = std::chrono::duration_cast<std::chrono::milliseconds>(cur - begin).count();
		check_collision(enemies, pl, pl_shots, en_shots);
		update_win(game_win, enemies, pl, pl_shots, seconds, en_shots);
	}
}
