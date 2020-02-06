// Roguelike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Windows.h"

using namespace std;

bool gameStarted = true;

Character character;

int main()
{
	//cout << "WELCOME TO THE GAME\nPRESS ENTER TO START" << endl;

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

		if (GetAsyncKeyState(0x41))			// 0x41 is the virtual key code for the w key, checks if w has been pressed
			character.Movement(0, -1);		// moves left

	}
}
