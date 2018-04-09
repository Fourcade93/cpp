#include "ft_retro.hpp"
#include "EnemiesMap.hpp"
#include "PlayerBullets.hpp"
#include "EnemyBullets.hpp"
#include "Player.hpp"

void	print_game_over(WINDOW *game_win)
{
	std::ifstream ifs("game_over");
	char str[1600];

	if (!ifs)
		return;
	wmove(game_win, 15, 0);
	ifs.read(str, 1600);
	wprintw(game_win, "%s", str);
	ifs.close();
}

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
	werase(game_win);
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
	mvwprintw(game_win, pl->getY(), pl->getX(), "%C", L'^');

	wrefresh(game_win);
}

void	check_collision(EnemiesMap *enemies, Player *pl, PlayerBullets *pl_shots, EnemyBullets *en_shots, WINDOW *game_win)
{
	pl_shots->checkCollision(enemies, pl, game_win);
	en_shots->checkCollision(pl);
	if (enemies->checkCollision(pl->getY(), pl->getX()))
		pl->decreaseLives();
	if (pl->getLives() <= 0)
	{
		mvprintw(2, 2, "Lives: %-5d", pl->getLives());
		delete pl;
		delete enemies;
		print_game_over(game_win);
		mvprintw(2, 45, "GAME OVER");
		mvprintw(3, 39, "Press enter to finish");
		refresh();
		wrefresh(game_win);
		while (getch() != '\n')
			;
		endwin();
		exit(0);
	}
}

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
	while ((ch = getch()) != 27)
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
		}
		if (ch == 32)
			pl_shots->addBullets(pl->getY() - 1, pl->getX());
		if (ch > 1 && ch < 6)
			move_pl(pl, ch);
		seconds = std::chrono::duration_cast<std::chrono::milliseconds>(cur - begin).count();
		check_collision(enemies, pl, pl_shots, en_shots, game_win);
		update_win(game_win, enemies, pl, pl_shots, seconds, en_shots);
	}
	endwin();
}
