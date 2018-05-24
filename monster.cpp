#include <iostream>
#include "entity.h"
#include "monster.h"
#include "room.h"
#include "player.h"
#include <string>
#include <cstdlib> // for srand()
#include <ctime> // for time()

using namespace std;



//default constructor
monster::monster() : entity(){
	name = "Monster";
	health = 3;
}


//if the player enters a room with the trap in it, they both take damage and the trap destroys itself
/*bool monster::destroy_monster()
{
	if(health == 0){
		cout << "Monster killed" << endl;
		return true;
	}

}*/

//Prompts 
bool monster::attack_monster(player *pc)
{
	
	// 9/10 chance of successful attack(randomising based on time)
	srand(time(0));
	int attack_success = (rand() % 10) + 1;
	
	if (attack_success > 3)
	{
		damage();
		cout << "You swing at the monster and successfully hit it." << endl; 
		cout << "Looks like " << health << " more hits will take him out." << endl;

	}
	
	else 
	{
		cout << "You attempt to hit the monster but miss." << endl;

	}
	


	if (health == 0){
		cout << "You've successfully defeated the monster!" << endl;
		return false;
	}
	else {
		retaliate(pc);
		return true;
	}
}

void monster::retaliate(player *pc)
{
	srand(time(0));
	int attack_success = (rand() % 10) + 1;
	if (attack_success > 4)
	{
		cout << "The monster returns your attacks! It's claws bite into your flesh." << endl;
		pc->attacked();
	}
	else
	{
		cout << "The monster takes a swipe at you in return. He's clumsy and misses." << endl;
	}
}

monster::~monster()
{
	
}
