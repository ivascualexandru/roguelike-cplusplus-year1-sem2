#include <iostream>
#include "Character.h"
#include "Windows.h"
#include "saveAndLoad.h"

using namespace std;

bool gameStarted = true;

Character character;
string lastTurnsMessages;
int main()
{
	int monsterPresentHere=0, willWalkIntoSomebody=0;
	cout << "Choices: \n1 start playing, 2 manual \nWhat do you choose? ";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:					//Start playing
		cout << "Great! Let's play... \n";
		break;
	case 2:					//Manual - a list of commands that are put out by the system
		cout << "How to play:\n*** Forwards: W *** Backwards: S *** Left: A *** Right: D ***\n*** Save Game: P ***" << endl; // << "*** Check Inventory: I ***";
		break;
	default:
		break;
	}

	monster monsterArray[256];

	for (int i=0; i<monster::numMonsters; i++)
	{
		cout<<"Goblin #"<<i+1<<"\nInbetween 1 and 9 please, any other things break the walls\n";
		monsterArray[i].getInfo();
	}
	while (gameStarted)						// while the game has started
	{
		std::system("cls");						// clears the screen after every key press


		cout<<"HP: "<<character.health<<"/"<<character.maxhp<<"    BASE DAMAGE:"<<character.attack<<"    \n";
		cout<<"XP: "<<character.xp<<"    LEVEL:"<<character.level<<"\n";



		for (int i = 0; i < 15; i++)
		{
			for (int j=0; j<15; j++)
			{
				for (int k=0; k<2; k++) 
				{
					if ((monsterArray[k].x == i) && (monsterArray[k].y == j) && (monsterArray[k].Alive == true)) monsterPresentHere=1;
				}
				if (map[i][j] == '*') cout<<'*';
				else if (monsterPresentHere)           //MAP
					{
						cout<<'G';
						monsterPresentHere=0;
					}
				else if (map[i][j] == ' ') cout<<' ';
				else if (map[i][j] == '@') cout<<'@';
			}
			cout<<endl;
		}



		cout<<lastTurnsMessages;
		lastTurnsMessages="";


		std::system("pause > nul");		// usually the console closes after one key press but this allows the user to input more key presses






		if (GetAsyncKeyState(0x57))										// moves up
			{
				for (int i=0; i<2; i++)
				{
					if ((monsterArray[i].x == character.x) && (monsterArray[i].y == character.y) && (monsterArray[i].Alive==true)) monsterArray[i].wasAttacked(&character.attack, &character.xp);
				

					if ((((character.x==monsterArray[i].x-1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x+1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y+1)) || ((character.x==monsterArray[i].x)) && (character.y==monsterArray[i].y-1)) && (monsterArray[i].Alive==true))
					{
						monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
					}
				}
				if (character.xp >= 15)
				{
					character.LevelUp();
				}
				for (int i=0; i<2; i++) 
					if ((character.x == monsterArray[i].x) && (character.y-1 == monsterArray[i].y) && (monsterArray[i].Alive == 1)) 
					{
					willWalkIntoSomebody=1;
					}
				if (willWalkIntoSomebody==0)
				{
				character.Movement(-1, 0);
				}
				willWalkIntoSomebody=0;
			}






		if (GetAsyncKeyState(0x53))										// moves down
			{	
				for (int i=0; i<2; i++)
				{
					if ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y-1) && (monsterArray[i].Alive==true)) monsterArray[i].wasAttacked(&character.attack, &character.xp);
					if ((((character.x==monsterArray[i].x-1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x+1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y+1)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y-1))) && (monsterArray[i].Alive==true))
				{	
					monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
				}
				}
				if (character.xp >= 15)
				{
					character.LevelUp();
				}
				for (int i=0; i<2; i++) 
					if ((character.x == monsterArray[i].x) && (character.y+1 == monsterArray[i].y) && (monsterArray[i].Alive == 1)) 
					{
					willWalkIntoSomebody=1;
					}
				if (willWalkIntoSomebody==0)
				{
				character.Movement(1, 0);
				}
				willWalkIntoSomebody=0;
			}





		if (GetAsyncKeyState(0x44)) //WALK RIGHT
			{	
			for (int i=0; i<2; i++)
				{
					if ((character.x==monsterArray[i].x-1) && (character.y==monsterArray[i].y) && (monsterArray[i].Alive==true)) monsterArray[i].wasAttacked(&character.attack, &character.xp);
					if ((((character.x==monsterArray[i].x-1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x+1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y+1)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y-1))) && (monsterArray[i].Alive==true))
						{	
						monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);	
						}
				}
				if (character.xp >= 15)
				{
					character.LevelUp();
				}
			for (int i=0; i<2; i++) 
					if ((character.x+1 == monsterArray[i].x) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == 1)) 
					{
					willWalkIntoSomebody=1;
					}
				if (willWalkIntoSomebody==0)
				{
				character.Movement(0, 1);
				}
				willWalkIntoSomebody=0;
			}




		if (GetAsyncKeyState(0x41)) //WALK LEFT
		{
			for (int i=0; i<2; i++)
				{
					if ((character.x==monsterArray[i].x+1) && (character.y==monsterArray[i].y) && (monsterArray[i].Alive==true))  monsterArray[i].wasAttacked(&character.attack, &character.xp);
					if ((((character.x==monsterArray[i].x-1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x+1) && (character.y==monsterArray[i].y)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y+1)) || ((character.x==monsterArray[i].x) && (character.y==monsterArray[i].y-1))) && (monsterArray[i].Alive==true))
						{	
							monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
						}
				}
				if (character.xp >= 15)
				{
					character.LevelUp();
				}	
			for (int i=0; i<2; i++) 
					if ((character.x-1 == monsterArray[i].x) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == 1)) 
					{
					willWalkIntoSomebody=1;
					}
				if (willWalkIntoSomebody==0)
				{
				character.Movement(0, -1);
				}
				willWalkIntoSomebody=0;
		}




		
		if (GetAsyncKeyState(0x50))
			{
				int playerx=character.x;
				int playery=character.y;
				int playerhealth=character.health;
				int playerattack=character.attack;             //0x50 is the virtual key code for the p key, checks if P has been pressed
				int playerxp=character.xp;
				saveGame(playerx,playery,playerhealth,playerattack,playerxp);
			}





		if (GetAsyncKeyState(0x4C))
			{
				//loadGame();
			}



		if (GetAsyncKeyState(0x49)){
			for (int i=0; i<8; i++) cout<<character.inventory[i];  //To be continued when Dimi's database becomes available
		}
	}
}