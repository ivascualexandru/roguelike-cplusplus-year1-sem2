// Text Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Player
{
public:
	int health = 50;
};


enum Character { Nice, Greedy };
enum EItemType { E_UTILITY, E_POTION, E_ARMOUR, E_WEAPONS, SIZE };

// Bubbly Potion - Heal/Poison/Speed Up
class Item
{
	std::string name = "";
	std::string description = "";
};

class Merchant
{
	Character charType = Nice;

	std::string interractionArr[2][3] = { {"*Gives potion to Player*", "Lowers price of Health potion"},
										 {"Refuse to trade unless offered more money", "Rise price of Health potion"} };

	std::vector<Item> inventory = {};

	Merchant()
	{
		// Create all the Item objects
		// Randomise how many items from each available type
	}

	void Decide(Player player)
	{
		std::string actions = "";

		switch (charType)
		{
		case Character::Nice:

			if (player.health < 50)
			{
				actions = interractionArr[0][0];
			}
			else if (player.health >= 50)
			{
				actions = interractionArr[0][1];
			}
			break;

		case Character::Greedy:

			if (player.health < 50)
			{
				actions = interractionArr[1][0];
			}
			else if (player.health >= 50)
			{
				actions = interractionArr[1][1];
			}
			break;

		default:
			break;
		}
	}
};

class Shop
{
public:

	std::string shopText[(int)SIZE]{ "You have encounterd a <<Shop Type>> Shop. Would you like to approach merchent? Y/N",
									"Hello stranger, would you like to check out my stock? \n\t 1) Yes, show me what you have. \n\t 2) Maybe another time. \n\t 3) Of course, I am here to rob you. *Points weapon at merchant..*" };

	// Public Member Variables
	EItemType shopType_ = E_UTILITY;


	// INIT THE SHOP OBJECT

	// This function could take the player information to customise the experience and give some AI to the shopkeeper. 
	// For example if the player has low health there may be a chance that the shopkeeper is greedy and will rise the price of the health potions. 
	void ControlEncounter()
	{

		// Build the encounter string.
		std::cout << shopText[0] << std::endl;
	}

	// Could generate the full encounter with all the possible options before the player triggers the encounter.
	void GenerateFullEncounter()
	{
		std::vector<std::string> fullEncounter;
	}
};

class Vehicle
{
public:
	int speed;

	Vehicle()
	{
		speed = 1;
	}

	Vehicle(int s)
	{
		speed = s;
	}
};


int main()
{
	//Shop newShop;
	//newShop.ControlEncounter();

	bool startEngine = true;

	std::string playerInput;
	std::cout << "Enter input: ";
	std::cin >> playerInput;
	std::cout << std::endl;

	//Vehicle plane;
	//std::cout << plane.speed << std::endl;

	return 0;
}


    
/*#include <iostream>
#include <string>
#include "windows.h"
//#include "Character.h"

using namespace std;

bool gameStarted;

int main()
{
	int choice = 0;
	

	do
	{
		cout << "Choices: /n(0 quit, 1 start playing, 2 manual, 3 tutorial /nWhat do you choose? ";
		cin >> choice;
		switch (choice)
		{
		case 1:					//Start playing
			cout << "Great! Let's play... /n";
			bool gameStarted = true;
				//system("PAUSE");	//Not sure how to make it continue onto the game.
			break;				   //Not sure if it should be return or break
		case 2:		//Manual - a list of commands that are put out by the system
			cout << "*** Forwards: W *** Backwards: S *** Left: A *** Right: D ***" << endl << "*** Save Game: P ***" << endl; // << "*** Check Inventory: I ***";
			break; // need this to make sure it continues into the game.
		case 3:		//Tutorial - an example of how the player can play the game.
			cout << "Learn how to play the game!" << endl << "Press W to move forwards, A to move left, S to move backwards, and D to move right!" << endl << "When you are ready to exit press 0!";
			//char map[25][12] = {			//static map in array (Changed what it looks like for the tutorial only)
				//"*************************",
				//"*@                      *",
				//"*                       *",
				//"*  G                    *",
				//"*                       *",
				//"*                       *",
				//"*                       *",
				//"*************************"
			};

			/*void Character::Movement(int Vertical, int Horizontal)
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
	} while (choice != 0)

		return 0;
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
