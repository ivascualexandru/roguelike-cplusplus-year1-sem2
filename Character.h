#include <iostream>
#include<string>
#pragma once
extern std::string lastTurnsMessages;
extern char map[15][15];
class Character
{
public:
	
	int health=10,xp=0,attack=4,x=1,y=1,inventory[8],maxhp=10,level=1,totalxp,gold=0;
	
	//void Movement(int Vertical, int Horizontal);

	void Movement(int Vertical, int Horizontal)
{
	int x2 = x + Horizontal;	// movement on x-axis
	int y2 = y + Vertical;		// movement on y-axis

	if (map[y][x2] == ' ') // if player moves horizontally the space before becomes an empty space and the space moved to becomes '@'
	{
		map[y][x] = ' ';
		x += Horizontal;
		map[y][x] = '@';
	}
	if (map[y][x2] == 'M')
	{
		map[y][x] = ' ';
		x+=Horizontal;
		map[y][x] = '@';
		gold+=10;
	}



	if (map[y2][x] == ' ') // if player moves vertically the space before becomes an empty space and the space moved to becomes '@'
	{
		map[y][x] = ' ';
		y += Vertical;
		map[y][x] = '@';
	}
	if (map[y2][x] == 'M')
	{
		map[y][x] = ' ';
		y+=Vertical;
		map[y][x] = '@';
		gold+=10;
	}
}
	void LevelUp()
	{	
		//oldxp=xp;
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
		score = totalxp * 100;
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

	void wasAttacked(int *playerattack, int *playerxp, int *playertotalxp)
	{
		health-=*playerattack;

		std::string str = std::to_string(*playerattack);
		lastTurnsMessages= lastTurnsMessages + "You dealt " + str + " damage to the goblin.\n";
		
		if (health <= 0)
		{
			map[x][y]=' ';
			*playerxp+=10;
			*playertotalxp+=10;
			Alive=false;
			lastTurnsMessages+="It died.\n";
			map[y][x]='M';
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
