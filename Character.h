#include <iostream>
#pragma once
extern char map[15][15];
class Character
{
public:
	void Movement(int Vertical, int Horizontal);
	int health=10,xp=0,attack=4,x=1,y=1,inventory[8];
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
		if (health <= 0)
		{
			map[x][y]=' ';
			*playerxp+=10;
		}
	}

	void playerAttacked(int *playerx, int *playery, int *playerhealth)
	{
		*playerhealth-=attack;
		if (playerhealth<0)
			{
				map[*playerx][*playery]=' ';
				for (int i=0; i<15; i++)
				{
					for (int j=0; j<15; j++) map[i][j]='*';
				}
			}
	}

};
//extern int playerhealth=10,playerxp=0,playerattack=4,playerx=1,playery=1,playerinventory[8];

extern int x;
extern int y;