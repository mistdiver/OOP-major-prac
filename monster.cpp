#include "entity.h"
#include "monster.h"
#include "room.h"
#include <string>
#include <cstdlib> // for srand()
#include <ctime> // for time()
using namespace std;

//default constructor
monster::monster() : entity(){
	name = "Monster";
	health = 1;
}

//With input name constructor
monster::monster(string InName) : entity(InName){
	name = InName;
	health = 1;
}

//if the player enters a room with the trap in it, they both take damage and the trap destroys itself
void monster::destroy_monster() : entity(){
	if(health == 0){
		~monster();
		cout << "Monster killed" << endl;
	}
}

//Prompts 
void monster::attack_monster() : entity(){
	
	//6/10 chance of disarming the trap (randomising based on time)
	srand(time(0));
	int attackSuccess = (rand() % 10) + 1;
	
	if (attackSuccess > 3){
		damage();
		cout << "You attack the monster." << endl; 
	}
	
	else {
		cout << "You attempt to hit the monster but miss." << endl;
	}
	
	if (health == 0){
		damage();
		isMonster = false; 
		cout << "You've successfully defeated the monster!" << endl;
	}
	return;
}
