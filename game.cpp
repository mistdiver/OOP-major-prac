#include <iostream>
#include <string>
#include "game.h"
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"
#include <cstdlib> // for srand()
#include <ctime> // for time()

using namespace std;

game::game()
{
	victory = false;
	death = false;
}

void game::input(int x, int y, room map[][5], player pc){
	player * pc_ptr;
	pc_ptr = &pc;

	cout << endl; 

	if (death == true){
		return;
	}

	if (victory == true){
		return;
	}

	cout << "What do you do?" << endl;
	cin >> str_input;


	// getline(cin , strInput)

	//stops taking input if "stop" is entered
	if(str_input != "giveup"){
	
		
		//if input is valid, direction goes through
		if(str_input == "north" || str_input == "west" || str_input == "south" || str_input == "east")
		{
			//cout << "You went " << strInput << endl;
			map[x][y].choose_door(str_input, x, y, pc_ptr);
			death_check(pc);

			map[x][y].movement();
			map[x][y].enter(pc_ptr);
			death_check(pc);
			
		}
				
		else if(str_input == "attack")
			{
				if (map[x][y].is_monster == 1)
				{
					map[x][y].call_attack(pc_ptr);
					death_check(pc);
				if (map[x][y].is_monster == 0)
				{
					delete map[x][y].room_monster;
				}

				}

				else 
				{
					cout << "You swing at the air." << endl;
					cout << "Your imaginary friend Steve winces and takes a step back." << endl;
				}
			}	
	 	
	 	else if (str_input == "look")
	 	{
	 		map[x][y].roomlook();
		}

		else if (str_input == "rest")
		{
			pc.rest(map, x, y); 
		}

		else if (str_input == "status")
		{
			pc.get_health();
		}

		else if (str_input == "escape")
		{
			victory = escape(map, x, y);
		}

		else if (str_input == "help")
		{
			help();
		}
		
	

		//tell player the input is invalid --> ask for new input
		else //if (str_input != "north" || str_input != "west" || str_input != "south" || str_input != "east" || str_input != "look" || str_input != "attack")
		{
			cout << "You tried to " << str_input << endl;
			cout << "There's a time and a place for everything... but not now" << endl;
			input(x, y, map, pc);
		}

		input(x, y, map, pc);
	}

}



void game::start(int number, room map[][5]){
		//Variable to change size of map (mxn matrix)
	matSize = number; 

	//Initialising map
	

	//Populating the map with room objects
	for(int y=0; y< matSize; y++){
		for(int x = 0; x<matSize; x++){
			map[x][y].create_map(x, y, false, false);
			//cout << map[x][y].get_room_numX() << map[x][y].get_room_numY() << endl;
		}
	}

}

void game::death_check(player pc){
	if (pc.player_death() == true)
	{
	death = true;
	}
}

bool game::escape(room map[][5], int x, int y)
{
	if (map[x][y].is_exit == true)
	{
		cout << "You climb the rope to the open air!" << endl;
		cout << "You've escaped!" << endl;
		return true;
	}
	else
	{
		cout << "If only it were that easy." << endl;
		return false;
	}
}

void game::intro(){
	cout << "You find yourself in a dungeon. It's dark and cold. You need to escape." << endl;
	cout << "Find the exit, but be wary of what lurks in the darkness." << endl;
	cout << endl;
	help();
	cout << endl;
}

void game::help(){
	cout << "To move input the directions 'north', 'south', 'east' and 'west'." << endl;
	cout << "In the event you need to defend yourself, input 'attack'." << endl;
	cout << "To remind yourself of your surroundings, input 'look'." << endl;
	cout << "To check your health, input 'status'." << endl;
	cout << "To recover your health, input 'rest'." << endl;
	cout << "In the event you find the exit, input 'escape'." << endl;
	cout << "Input 'help' to recall this information." << endl;

}

void game::spawn(room map[][5])
{
	map[1][0].is_monster = true;

	srand(time(0));
	int spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][2].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][3].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[1][2].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[1][4].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[2][3].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[3][0].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][2].add_monster();
	}

	spawn_chance = (rand() % 10) + 1;
	if (spawn_chance > 5)
	{
		map[0][2].add_monster();
	}
}


