#ifndef GAME_H
#define GAME_H
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"
#include <string>

using namespace std;

class room;
class game 
{
public:
	int matSize;
	string str_input;
	bool victory;
	bool death;

	game();

	void input(int x, int y, room map[][5], player pc);
	void start(int number, room map[][5]);

	void death_check(player pc);
	void intro();
	void help();
	bool escape(room map[][5], int x, int y);
	void spawn(room map[][5]);

};

#endif