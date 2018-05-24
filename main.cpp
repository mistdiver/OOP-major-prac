#include <iostream>
#include <string>
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"
#include "game.h"

using namespace std;



int main(){
	int map_size;

	//Creating game object to handle game functionality
	game game_one;

	//Creating room object matrix
	room map[5][5];

	//Populating room matrix
	game_one.start(5, map);


	player hero = player(); 


	game_one.spawn(map);
	map[2][2].is_exit = true;
	game_one.intro();
	//Calling input function loop
	game_one.input(0, 0, map, hero);



}

