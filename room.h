#ifndef ROOM_H
#define ROOM_H
#include "trap.h"
#include "player.h"
#include <string>

using namespace std;

//#include "trap.h"

//Class definition for room
class room
{
public:
	room();
	room(int index_x, int index_y, bool trapflag, bool playerflag);
	void create_map(int x, int y, bool trapflag, bool playerflag);
	void enter();
	void entrance();

	int get_room_numX();
	int get_room_numY();
	bool is_player_in_room();
	void choose_door(string direction, int& x, int& y); 
	void movement();
	void call_attack();
	

	monster *room_monster();
	int room_x;
	int room_y;
	bool is_monster;
	bool player_location;
	bool is_exit;
	
};

#endif
