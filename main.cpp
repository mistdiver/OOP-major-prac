#include <iostream>
#include <string>
#include "room.h"
#include "entity.h"
#include "monster.h"
#include "player.h"

using namespace std;

void input_func(int x, int y, room map[][3], player pc){

	string str_input; // wont work because of this
	
	cout << "What do you do?" << endl;
	cin >> str_input;

	// getline(cin , strInput)

	//stops taking input if "stop" is entered
	if(str_input != "\0"){
		
		//if input is valid, direction goes through
		if(str_input == "north" || str_input == "west" || str_input == "south" || str_input == "east")
		{
			//cout << "You went " << strInput << endl;
			map[x][y].choose_door(str_input, x, y);
			map[x][y].movement();
			map[x][y].enter();
			
			if (map[x][y].is_monster == true)
			{
				pc.damage();
				cout << "Your health is at " << pc.get_health() << endl;
				if (pc.player_death() == true)
				{
				return;
				}
			}
				
		else if (str_input == "disarm")
			{
			map[x][y].deadtrap();
			}	
	 	
	 	else if (str_input == "look")
	 		{

	 		}

			// cout << x << y << endl;
			if (map[x][y].is_exit == true){
				pc.player_victory();
				return;
			}
			

			input_func(x, y, map, pc);
		}

		//tell player the input is invalid --> ask for new input
		else if(str_input != "north" || str_input != "west" || str_input != "south" || str_input != "east" || str_input != "look" || str_input != "disarm" ){
			cout << "You entered " << str_input << endl;
			cout << "There's a time and a place for everything... but not now" << endl;
			input_func(x, y, map, pc);
		}

		/*if (strInput == 'x'){
			room.disarmTrap(trapStats)
		}*/ //unfinished trap code
		


		//suggested: draw an entity/person on top of the room and a trap on top of them
		/*void update(entity* e){
			e.draw()
		}*/
	}

	//if not finished/escaped --> call function again

}

int main(){
	
	//Variable to change size of map (mxn matrix)
	const int matSize = 3;

	//Initialising map
	room map[matSize][matSize];

	//Populating the map with room objects
	for(int y=0; y< matSize; y++){
		for(int x = 0; x<matSize; x++){
			map[x][y].create_map(x, y, false, false);
			//cout << map[x][y].get_room_numX() << map[x][y].get_room_numY() << endl;
		}
	}

	player hero = player(); 
	
	int pclocation_x = 0;
	int pclocation_y = 0;

	map[1][0].is_monster = true;
	map[2][2].is_exit = true;
	inputFunc(pclocation_x, pclocation_y, map, hero);
	//tests
	//map[0][0].playerLocation = true;
	//cout << map[1][1].is_player_in_room() << endl;
	//cout << map[1][0].is_player_in_room() << endl;
	//cout << map[2][0].is_player_in_room() << endl;
	/*
	map[playerLocationX][playerLocationY].choose_door('D', playerLocationX, playerLocationY);
	cout << playerLocationX << playerLocationY << endl;
	map[playerLocationX][playerLocationY].movement('D');

	cout << map[1][0].is_player_in_room() << endl;
	*/
}
