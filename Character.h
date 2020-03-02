#include <iostream>
#include<string>
#pragma once
extern std::string lastTurnsMessages;
extern char map[15][15];
class Character
{
public:
	
	int health=10,xp=0,attack=4,x=1,y=1,inventory[8],maxhp=10,level=1,oldxp=xp;
	
	void Movement(int Vertical, int Horizontal);

	void LevelUp()
	{	
		oldxp=xp;
		level+=1;
		maxhp+=2;
		health=maxhp;
		attack+=2;
		xp=0;
	}
	
	int DeathFunction()			//No errors so does not affect code, but also does not return anything, cus i need to fix it somehow
	{
		if ((maxhp < 0) || (maxhp == 0))
		{
			system("pause");
			std::cout << "GAME OVER! \nYou have died!\n";
			std::string playername;
			std::cout << "What is your name? ";
			std::cin >> playername;
			int totalxp, score;
			totalxp = xp;
			score = totalxp * 100;
			std::cout << "Your score is " << score << "! \n Well done " << playername;
			
			
		}
	}

	int score()
	{
		int score;
		score = oldxp * 100;
		return score;
	}
	        	
};

class monster
{
	public:
	int health=6,attack=3,x,y;
	bool Alive=true;

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
//extern int playerhealth=10,playerxp=0,playerattack=4,playerx=1,playery=1,playerinventory[8],lvl;

extern int x;
extern int y;
