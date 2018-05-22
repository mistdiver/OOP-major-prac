#include <iostream>
#include <cstdlib> // for srand()
#include <ctime> // for time()
#include <string> 
#include "room.h"
#include "player.h"
#include "monster.h"


using namespace std; 

room::room(){
	room_x = 0;
	room_y = 0;
	is_monster = 0;
	player_location = 0;
}


room::room(int index_x, int index_y, bool monsterflag, bool playerflag)
{
	room_x = index_x;
	room_y = index_y;
	is_monster = monsterflag;
	player_location = playerflag;
}

int room::get_room_numX(){
	return room_x;
}

int room::get_room_numY(){
	return room_y;
}

bool room::is_player_in_room(){
	return player_location;
}

//

void room::choose_door(string direction, int& x, int& y){
	if (direction == "north")
	{
		if (room_y == 0){
			cout << "You walk north and slam your face into a wall. Perhaps you should try going through a door?" << endl;				//std::cout << "player location: " << x << "," << y << std::endl;

		} 
		else { 
			player_location = 0;
			y -= 1;
			cout << "You move through the northern door." << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
	}
	if (direction == "west")
	{
		if (room_x == 0 ){
			cout << "You walk west and slam your face into a wall. Perhaps you should try going through a door?" << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
		else {
			player_location = 0;
			x -= 1;
			cout << "You move through the western door." << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;
			}

		}

	if (direction == "south")
	{
		if (room_y == 2 ){
			cout << "You walk south and slam your face into a wall. Perhaps you should try going through a door?" << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
		else {
			player_location = 0;
			y += 1;
			cout << "You move through the southern door." << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
	}
	if (direction == "east")
	{
		if (room_x == 2 ){
			cout << "You walk east and slam your face into a wall. Perhaps you should try going through a door?" << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
		else {
			player_location = 0;
			x += 1;
			cout << "You move through the eastern door." << endl;
			//std::cout << "player location: " << x << "," << y << std::endl;

		}
	}
	/*if (isTrap = true){
		cout << "On your way out you step on the bear trap. It hurts." << endl;
		pc.damage();
	*/ //unfinished trapcode, will do later.
}

void room::movement(){
		player_location = 1;
		return;
}

void room::create_map(int x, int y, bool monsterflag, bool exitflag){
	room_x = x;
	room_y = y;
	is_monster = monsterflag;
	is_exit = exitflag;
	return;
}
void room::entrance(){
	cout << "You find yourself in a dark room." << endl;
	cout << "Use wasd to move through the doors." << endl;
}

void room::enter(){
	cout << "You look around the room.";
	cout << " This is room: " << room_x << ", " << room_y << endl;
	cout << "You see";
	switch (room_y)
	{
		case 0:
		cout << " a solid stone wall on north side and a door on the south side,";
		break;
		case 2:
		cout << " a door on the north side and a solid stone wall on the south side,";
		break;
		default: 
		cout << " a door on the north side and a door on the south side,";
		break;	
	}
	
		cout << " and" << endl;
	switch (room_x)
	{
		case 0:
		cout << "a door on the east side and a solid stone wall on the west side." << endl;
		break;
		case 2:
		cout << "a solid stone wall on the east side and a door on the west side." << endl;
		break;
		default:
		cout <<"a door on the east side and a door on the west side." << endl;
		break;
	}

	switch (is_monster)
	{
		case 0:
		//cout << "The floor is clear, dirty and gross, but clear." << endl;
		break;

		case 1:
		cout << "You see a bear trap and promptly step in it because we've yet to implement disarming." << endl;
		break;
	}

	switch (is_exit)
	{
		case 1: 
		cout << "Shining down through a hole in ceiling of the room, you see a ray of glorious light" << endl;
		cout << "Dangling from the hole is a rope. You climb your way to freedom!" << endl;
		break;
	}
}

void room::call_attack()
	{
		room_monster.attack_monster();
	}

/*void room::disarmTrap(trap floorTrap){
	srand(time(0));
	int disarmSuccess = (rand() % 10) + 1;
	if (disarmSuccess > 3){
		floorTrap.health -= 1;
		cout << "You make progress disarming the trap." << endl; 
	}
	else {
		cout << "You attempt to disarm the trap but fail to make any tangible progress." << endl;
	}

	if (floorTrap.health == 0){
		floorTrap.destroy_trap();
		isTrap = false; 
		cout << "You've successfully disarmed the trap!" << endl;
	}

	return;
}
*/
