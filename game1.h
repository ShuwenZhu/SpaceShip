#include "ConsoleDefine.h"
#include <time.h>				/* time */
#include <stdlib.h>			/* srand, rand */
#include <string>				/* string */

using namespace std;
int const MAXDIFFICULTY = 10;
class Game
{
public:
	Game();
	/* game run function*/
	boolean run();
	/* set freq of "-" shows up*/
	void setDifficulty(int d);
	/* return the given cord of space stats in string*/
	string getSpaceCord(int x, int y);
	/* return the given cord of player stats in string*/
	string getPlayerCord(int x);
	/* function to move player left or right*/
	void movePlayer(int vert);
	/* return the current score*/
	int getScore();
	~Game();

private:
	/* space size equals to the given window size*/
	string space[WINDOW_HEIGHT][WINDOW_WIDTH];
	/* player moveable width*/
	string player[WINDOW_WIDTH];
	int score = 0 - WINDOW_HEIGHT + 1;
	int playerPos = WINDOW_WIDTH / 2;
	int difficulty = 0;
	void generateBars();
	boolean collision();
};
