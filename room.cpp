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


void room::choose_door(string direction, int& x, int& y, player *pc){
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
		if (room_y == 4){
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
		if (room_x == 4 ){
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
	switch (is_monster)
	{
		case true:
		cout << "As you leave the room, the monster takes an attack of opportunity." << endl;
		pc->attacked();
		break;

		default:

		break;
	}
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
	if (is_monster = true)
	{
		room_monster = new monster();
	}
	return;
}

void room::enter(player* pc){
	room_desc();

	switch (is_monster)
	{
		case 1:
		cout << endl;
		cout << "As you enter, a monster jumps out at you and attacks." << endl;

		pc->attacked();
		
		break;

		default:

		break;
	}

	switch (is_exit)
	{
		case 1: 
		cout << endl;
		cout << "Shining down through a hole in ceiling of the room, you see a ray of glorious light" << endl;
		cout << "Dangling from the hole is a rope. You can climb your way to freedom!" << endl;
		break;
	}
}

void room::room_desc()
	{
	cout << endl;
	cout << "You look around the room.";
	cout << " This is room: " << room_x << ", " << room_y << endl;
	cout << "You see";
	
	switch (room_y)
	{
		case 0:
		cout << " a solid stone wall on north side and a door on the south side,";
		break;
		case 4:
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
		case 4:
		cout << "a solid stone wall on the east side and a door on the west side." << endl;
		break;
		default:
		cout <<"a door on the east side and a door on the west side." << endl;
		break;
	}

}

void room::roomlook()
{
	room_desc();
	switch (is_monster)
	{
		case 1:
		cout << "You see a really gross monster. It's super ugly. So ugly you don't bother describing it." << endl;
		cout << "Its got a chain around it's ankle. It can't follow you into next room. But if you turn your back on him and he might attack." << endl;
		break;
	}
}

void room::call_attack(player* pc)
{
	is_monster = room_monster->attack_monster(pc);
}

void room::add_monster()
{
	is_monster = true;
	room_monster = new monster();
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
