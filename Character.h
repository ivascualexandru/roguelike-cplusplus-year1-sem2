#include <iostream>
#include <string>
#include <vector>

#pragma once

extern std::string lastTurnsMessages;
extern char map[15][15];

/*void goblinGenerator()
{
	for (int i=0; i<15; i++) 
	{
		for (int j=0; j<15; j++)
		{
			if (map[i][j] == ' ')
			{
				if (rand()%100 < 20)
				{
					monster monsterArray[monsterCounter] = new monster {};
					monsterArray[monsterCounter+1].x = i;
					monsterArray[monsterCounter+1].y = j;
				}
			}
		}
	}
}*/


class Character
{
public:
	
	int health=10,xp=0,attack=4,x=1,y=1,inventory[8],maxhp=10,level=1;
	
	void Movement(int Vertical, int Horizontal);

	void LevelUp()
	{	
		level+=1;
		maxhp+=2;
		health=maxhp;
		attack+=2;
		xp=0;
	}
	        	
};

class monster
{
	public:
	int health=6,attack=3,x,y;
	static int numMonsters;
	bool Alive=true;

	monster()
	{
		numMonsters+=1;
	}

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

		std::string str = std::to_string(*playerattack);
		lastTurnsMessages= lastTurnsMessages + "You dealt " + str + " damage to the goblin.\n";
		
		if (health <= 0)
		{
			map[x][y]=' ';
			*playerxp+=10;
			Alive=false;
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

extern int x;
extern int y;
int monster::numMonsters=0;