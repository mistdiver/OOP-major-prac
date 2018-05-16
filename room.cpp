#include <iostream>
#include "game.h"
#include "room.h"

room::room(){
	room_index = 0;
	isTrap = 0;
	playerLocation = 0;
}

room::room(int index, bool trapYN, bool playerYN)
{
	room_index = index;
	isTrap = trapYN;
	playerLocation = playerYN;
}

int room::get_room_num(){
	return room_index;
}

bool room::is_player_in_room(int index){
	return playerLocation;
}

void room::choose_door(char direction, room map[3][3]){

	switch (direction){
		case "W":
			if (room_Y == 0){
				std::cout << "don't." << std::endl;
				return;
			} 
			else { 
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move up" << std::endl;
			}
		case "A":
			if (room_X == 0 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y-1].playerLocation = 1;
				std::cout << "you move left" << std::endl;
			}

		case "S":
			if (room_Y == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_X][room_Y+1].playerLocation = 1;
				std::cout << "you move down" << std::endl;
			}

		case "D":
			if (room_X == 2 ){
				std::cout << "don't." << std::endl;
				return;
			}
			else {
				map[room_X][room_Y].playerLocation = 0;
				map[room_x+1][room_Y].playerLocation = 1;
				std::cout << "you move right" << std::endl;
			}
	}

}
