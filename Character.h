#include <iostream>
#include<string>
#pragma once
extern std::string lastTurnsMessages;
extern char map[15][15];
class Character
{
public:
	void Movement(int Vertical, int Horizontal);
	int health=10,playerxp=0,attack=4,x=1,y=1,inventory[8],mylvl=1,maxhp=10;
	
	void LevelUp(mylvl,playerxp);
	 if mylvl>1 and playerxp=10;
		mylvl= mylvl +1, maxhp = health + 2,attack= attack + 2, playerxp= playerxp + 2;
	cout<<mylvl<<playerxp;
	
	        	
};

class monster
{
	public:
	int health=6,attack=3,x,y;

	void getInfo()
	{
		std::cout<<"x=";
		std::cin>>x;
		std::cout<<"y=";
		std::cin>>y;
	}

	void wasAttacked(int *playerattack, int *playerxp)
	{
		health-=*playerattack;
		//string str = string(*playerattack);
		std::string str = std::to_string(*playerattack);
		lastTurnsMessages= lastTurnsMessages + "You dealt " + str + " damage to the goblin.\n";
		if (health <= 0)
		{
			map[x][y]=' ';
			*playerxp+=10;
			lastTurnsMessages+="It died.\n";
		}
	}

	void playerAttacked(int *playerx, int *playery, int *playerhealth)
	{
		*playerhealth-=attack;
		lastTurnsMessages+="You got attacked by an enemy\n";
		if (playerhealth<0) {lastTurnsMessages+="YOU DIED!\n";}
	}

};
//extern int playerhealth=10,playerxp=0,playerattack=4,playerx=1,playery=1,playerinventory[8],lvl;

extern int x;
extern int y;
