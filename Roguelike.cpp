#include <iostream>
#include "Character.h"
#include "Windows.h"
#include "saveAndLoad.cpp"

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

		if (GetAsyncKeyState(0x57))			// 0x77 is the virtual key code for the w key, checks if w has been pressed
			character.Movement(-1, 0);		// moves up

		if (GetAsyncKeyState(0x53))			// 0x53 is the virtual key code for the w key, checks if w has been pressed
			character.Movement(1, 0);		// moves down

		if (GetAsyncKeyState(0x44))			// 0x44 is the virtual key code for the w key, checks if w has been pressed
			character.Movement(0, 1);		// moves right

		if (GetAsyncKeyState(0x41))         // 0x41 is the virtual key code for the w key, checks if w has been pressed
		{	if ((character.x==goblin.x+1) && (character.y==goblin.y))
			{
				goblin.health-=character.attack;
				if (goblin.health < 0){
					cout<<"You killed him lmao";
					map[goblin.x][goblin.y]=' ';
				}
			}
		if (((character.x==goblin.x-1) && (character.y==goblin.y)) || ((character.x==goblin.x+1) && (character.y==goblin.y)) || ((character.x==goblin.x) && (character.y==goblin.y+1)) || ((character.x==goblin.x) && (character.y==goblin.y-1))){
			character.health-=goblin.attack;
		}
						
			character.Movement(0, -1);      // moves left
		}
		if (GetAsyncKeyState(0x50))         //0x50 is the virtual key code for the p key, checks if P has been pressed
			{								//Hopefully creates a .txt file
				//saveGame();
			}

		if (GetAsyncKeyState(0x4C))
			{
				//loadGame();
			}
	}
}