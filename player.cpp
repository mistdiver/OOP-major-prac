#include <string>
#include <iostream>
#include <cstdio>
#include "entity.h"
#include "player.h"
#include "room.h"
using namespace std;

//default constructor
player::player() : entity(){
	name = "Player";
	health = 5;
}

//With input name constructor 
player::player(string InName) : entity(InName){
	name = InName;
	health = 5;
}

//if player's health reaches 0, the player "dies" and the game ends
bool player::player_death(){
	if(health == 0){
		cout << "You are dead. GAME OVER." << endl;
		//quit/leave the program
		//exit(EXIT_SUCCESS);  idk how this works? it didn't compile so i just turned function into bool.
		return true;
		/*alt.
		void death(){
			cout << "You are dead. GAME OVER." << endl;
		}
		atexit(death);
		return 0;
		*/
	}
	else{
		return false;
	}
}

//allows player/controller to see current amount of health they haves
void player::get_health()
{
	cout << "Your health is at " << health << "." << endl;
}

void player::attacked()
{
	damage();
	get_health();
	return; 
}


void player::rest(room map[][5], int x, int y){
	if (map[x][y].is_monster == true)
	{
		cout << "You think about resting, but realise there's a monster in front of you.";
	}
	else
	{
		cout << "You sit down and rest for a bit." << endl;	

		if (health < 5)
		{ 
			health += 1;
			cout << "You feel a little better." << endl;
			get_health();
		}
		else 
		{
			cout << "You feel fine right now. No need to rest." << endl;
		}		
	}
}
