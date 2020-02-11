#include <iostream>
#include "Character.h"
#include "Windows.h"
#include "saveAndLoad.h"

using namespace std;

bool gameStarted = true;

Character character;
monster goblin;

int main()
{

	while (gameStarted)						// while the game has started
	{
		system("cls");						// clears the screen after every key press

		for (int i = 0; i < 15; i++)
		{
			cout << map[i] << endl;			// prints the map in console
		}
		
		system("pause > nul");		// usually the console closes after one key press but this allows the user to input more key presses






		if (GetAsyncKeyState(0x57))										// moves up
			{	
				if ((character.x==goblin.x) && (character.y==goblin.y+1))
			{
				goblin.health-=character.attack;
				if (goblin.health < 0){
					cout<<"You killed him lmao";
					map[goblin.x][goblin.y]=' ';
					character.xp+=10;
				}
			}
				if (((character.x==goblin.x-1) && (character.y==goblin.y)) || ((character.x==goblin.x+1) && (character.y==goblin.y)) || ((character.x==goblin.x) && (character.y==goblin.y+1)) || ((character.x==goblin.x) && (character.y==goblin.y-1)))
				{
					character.health-=goblin.attack;
					if (character.health<0){
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						map[character.x][character.y]=' ';          //PLAYER DEATH
				}
		}
			character.Movement(-1, 0);
			}







		if (GetAsyncKeyState(0x53))										// moves down
			{	
				if ((character.x==goblin.x) && (character.y==goblin.y-1))
			{
				goblin.health-=character.attack;
				if (goblin.health < 0){
					cout<<"You killed him lmao";
					map[goblin.x][goblin.y]=' ';
					character.xp+=10;
				}
			}
		if (((character.x==goblin.x-1) && (character.y==goblin.y)) || ((character.x==goblin.x+1) && (character.y==goblin.y)) || ((character.x==goblin.x) && (character.y==goblin.y+1)) || ((character.x==goblin.x) && (character.y==goblin.y-1))){
			character.health-=goblin.attack;
			if (character.health<0){
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						map[character.x][character.y]=' ';          //PLAYER DEATH
				}
		}
			character.Movement(1, 0);
			}






		if (GetAsyncKeyState(0x44))
			{	
				if ((character.x==goblin.x-1) && (character.y==goblin.y))
			{
				goblin.health-=character.attack;
				if (goblin.health < 0){
					cout<<"You killed him lmao";            			//moves right
					map[goblin.x][goblin.y]=' ';
					character.xp+=10;
				}
			}
		if (((character.x==goblin.x-1) && (character.y==goblin.y)) || ((character.x==goblin.x+1) && (character.y==goblin.y)) || ((character.x==goblin.x) && (character.y==goblin.y+1)) || ((character.x==goblin.x) && (character.y==goblin.y-1))){
			character.health-=goblin.attack;
			if (character.health<0){
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						map[character.x][character.y]=' ';          //PLAYER DEATH
				}
		}
			character.Movement(0, 1);
			}




		if (GetAsyncKeyState(0x41))
		{	if ((character.x==goblin.x+1) && (character.y==goblin.y))
			{
				goblin.health-=character.attack;
				if (goblin.health < 0){
					cout<<"You killed him lmao";				         // moves left
					map[goblin.x][goblin.y]=' ';
					character.xp+=10;
				}
			}
		if (((character.x==goblin.x-1) && (character.y==goblin.y)) || ((character.x==goblin.x+1) && (character.y==goblin.y)) || ((character.x==goblin.x) && (character.y==goblin.y+1)) || ((character.x==goblin.x) && (character.y==goblin.y-1))){
			character.health-=goblin.attack;
			if (character.health<0){
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						cout<<"You got killed by him lmao"<<endl;
						map[character.x][character.y]=' ';          //PLAYER DEATH
				}
		}
			character.Movement(0, -1);
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