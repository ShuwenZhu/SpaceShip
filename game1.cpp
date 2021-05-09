#include "game1.h"

Game::Game()
{
	/* initialize random seed */
	srand((unsigned int)time(NULL));
	player[playerPos] = "*";
	for (int i = WINDOW_HEIGHT - 1; i > 0; i--)
	{
		for (int j = 0; j < WINDOW_WIDTH; j++)
			space[i][j] = " ";
	}
}

boolean Game::run()
{
	generateBars();
	for (int i = WINDOW_HEIGHT - 1; i > 0; i--)
	{
		for (int j = 0; j < WINDOW_WIDTH; j++)
			space[i][j] = space[i - 1][j];
	}
	return collision();
}

void Game::setDifficulty(int d)
{
	difficulty = d;
}

string Game::getSpaceCord(int x, int y)
{
	return space[y][x];
}

string Game::getPlayerCord(int x)
{
	return player[x];
}

void Game::movePlayer(int hori)
{
	int newPos = playerPos + hori;
	if (newPos >= 0 && newPos < WINDOW_WIDTH)
	{
		player[playerPos] = " ";
		player[newPos] = "*";
		playerPos = newPos;
	}
}

boolean Game::collision()
{
	boolean collision = (space[WINDOW_HEIGHT - 1][playerPos].compare("-") == 0);
	if (!collision) score++;
	return !collision;
}

int Game::getScore()
{
	return (score >= 0)? score : 0;
}

Game::~Game()
{
}

void Game::generateBars()
{
	for (int i = 0; i < WINDOW_WIDTH; i++)
	{
		int obs = rand() % (MAXDIFFICULTY - difficulty);
		space[0][i] = (obs == 1)? "-" : " ";
	}
}

