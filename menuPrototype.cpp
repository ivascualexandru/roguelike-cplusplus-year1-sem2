#include <iostream>
#include <string>
#include "windows.h"
#include "Character.h"

using namespace std;

bool gameStarted

int main()
{
	int choice = 0;
	cin >> choice;

	do
	{
		cout << "Choices: /n(0 quit, 1 start playing, 2 manual, 3 tutorial /nWhat do you choose? ";
		switch (choice)
		{
			case 1:					//Start playing
				cout << "Great! Let's play... /n";
				bool gameStarted = true
					system("PAUSE");	//Not sure how to make it continue onto the game.
				break;				   //Not sure if it should be return or break
			case 2:		//Manual - a list of commands that are put out by the system
				cout << "*** Forwards: W *** Backwards: S *** Left: A *** Right: D ***" << endl << "*** Save Game: P ***" << endl; // << "*** Check Inventory: I ***";
				break; // need this to make sure it continues into the game.
			case 3:		//Tutorial - an example of how the player can play the game.
				cout << "Learn how to play the game!" << endl << "Press W to move forwards, A to move left, S to move backwards, and D to move right!" << endl << "When you are ready to exit press 0!";
				char map[25][12] = {			//static map in array (Changed what it looks like for the tutorial only)
					"*************************",
					"*@                      *",
					"*                       *",
					"*  G                    *",
					"*                       *",
					"*                       *",
					"*                       *",
					"*************************"
				};

				void Character::Movement(int Vertical, int Horizontal)
				{
					int x2 = x + Horizontal;	// movement on x-axis
					int y2 = y + Vertical;		// movement on y-axis

					if (map[y][x2] == ' ') // if player moves horizontally the space before becomes an empty space and the space moved to becomes '@'
					{
						map[y][x] = ' ';
						x += Horizontal;
						map[y][x] = '@';
					}



					if (map[y2][x] == ' ') // if player moves vertically the space before becomes an empty space and the space moved to becomes '@'
					{
						map[y][x] = ' ';
						y += Vertical;
						map[y][x] = '@';
					}
				}
					//just copied and pasted the character.cpp file here, but changed the map, so its different for the tutorial
				break;
			default:
				break
		}
	}
	while (choice != 0)

	return 0;
}