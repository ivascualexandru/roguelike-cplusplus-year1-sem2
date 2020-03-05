// RoguelikePrototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Character.h"
#include "Windows.h"
#include "saveAndLoad.h"
#include "mapPrototype.h"
using namespace std;

bool gameStarted = true;

//leaderboard
string line;
ifstream f;
string textName;
int leaderboardScore;
vector < pair <int, string>> vScore; //creates avector and pairs the values within the text file

Character character;
int willWalkIntoSomebody = 0, playerAlreadyPlaced = 0;
string lastTurnsMessages;
char map[100][100];
int main()
{
	srand (time(NULL));
	int monsterPresentHere = 0;
	cout << "Choices: \n1 start playing, 2 manual, 3 View Leaderboards What do you choose? ";
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
	case 3:
		cout << "NAME\tSCORE\n";
		f.open("highscores.txt");
		while (f >> textName >> leaderboardScore)
		{
			vScore.push_back(make_pair(leaderboardScore, textName));
			cout << line;
		}
		f.close();
		sort(vScore.begin(), vScore.end());				//sorts in ascending
		reverse(vScore.begin(), vScore.end());			//flips the sort to descending
		for (int i = 0; i < vScore.size(); i++)
		{
			cout << vScore[i].second << "\t" << vScore[i].first << endl;	//outputs the leaderboard to console
		}
		return 0;
		break;
	default:
		break;
	}

	int mapX, mapY, mapFeatures;
	mapX=rand()%40 + 10;
	//srand (time(NULL));
	mapY=rand()%30 + 10;
	//srand (time(NULL));
	mapFeatures = rand()%20 + 15;
	//srand (time(NULL));
    Dungeon d(mapX,mapY);
    d.generate(mapFeatures);
    for (int i=0; i<mapX; i++)           //MAP GENERATION
    {
        for (int j=0; j<mapY; j++)
        {
            map[i][j] = d.getTile(i,j);
			if ((playerAlreadyPlaced == 0) && (map[i][j] == ' '))
			{
				character.x = i;
				character.y = j;
				map[i][j] = '@';
				playerAlreadyPlaced = 1;
			}
        }
    }


	monster monsterArray[5];

	for (int i = 0; i < 2; i++)
	{
		cout << "Goblin #" << i + 1 << "\nInbetween 1 and 9 please, any other things break the walls\n";
		monsterArray[i].getInfo();
	}

	while (gameStarted)						// while the game has started
	{
		system("cls");						// clears the screen after every key press


		cout << "HP: " << character.health << "/" << character.maxhp << "    BASE DAMAGE:" << character.attack << "    \n";
		cout << "XP: " << character.xp << "    LEVEL:" << character.level << "      GOLD:" << character.gold << "    x POSITION:" << character.x << "    y POSITION:"<< character.y << "\n";
		

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					if ((monsterArray[k].x == j) && (monsterArray[k].y == i) && (monsterArray[k].Alive == true)) monsterPresentHere = 1;
				}
				if (monsterPresentHere)           //MAP
				{
					cout << 'G';
					monsterPresentHere = 0;
				}
				else if (map[i][j] == 'M') cout << 'M';
				else cout<<map[i][j];
			}
			cout << endl;
		}



		cout << lastTurnsMessages;
		lastTurnsMessages = "";


		system("pause > nul");		// usually the console closes after one key press but this allows the user to input more key presses






		if (GetAsyncKeyState(0x57))										// moves up
		{
			for (int i = 0; i < 2; i++)
			{
				if ((monsterArray[i].x == character.x) && (monsterArray[i].y == character.y-1) && (monsterArray[i].Alive == true)) monsterArray[i].wasAttacked(&character.attack, &character.xp, &character.totalxp);


				if ((((character.x == monsterArray[i].x - 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x + 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y + 1)) || ((character.x == monsterArray[i].x)) && (character.y == monsterArray[i].y - 1)) && (monsterArray[i].Alive == true))
				{
					monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
				}
			}
			if (character.xp >= 15)
			{
				character.LevelUp();
			}
			for (int i = 0; i < 2; i++)
				if ((character.x == monsterArray[i].x) && (character.y - 1 == monsterArray[i].y) && (monsterArray[i].Alive == 1))
				{
					willWalkIntoSomebody = 1;
				}
			if (willWalkIntoSomebody == 0)
			{
				character.Movement(0, -1); //UP
			}
			willWalkIntoSomebody = 0;
		}






		if (GetAsyncKeyState(0x53))										// moves down
		{
			for (int i = 0; i < 2; i++)
			{
				if ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y - 1) && (monsterArray[i].Alive == true)) monsterArray[i].wasAttacked(&character.attack, &character.xp, &character.totalxp);
				if ((((character.x == monsterArray[i].x - 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x + 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y + 1)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y - 1))) && (monsterArray[i].Alive == true))
				{
					monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
				}
			}
			if (character.xp >= 15)
			{
				character.LevelUp();
			}
			for (int i = 0; i < 2; i++)
				if ((character.x == monsterArray[i].x) && (character.y + 1 == monsterArray[i].y) && (monsterArray[i].Alive == 1))
				{
					willWalkIntoSomebody = 1;
				}
			if (willWalkIntoSomebody == 0)
			{
				character.Movement(0, 1); //DOWN
			}
			willWalkIntoSomebody = 0;
		}





		if (GetAsyncKeyState(0x44)) //WALK RIGHT
		{
			for (int i = 0; i < 2; i++)
			{
				if ((character.x == monsterArray[i].x - 1) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == true)) monsterArray[i].wasAttacked(&character.attack, &character.xp, &character.totalxp);
				if ((((character.x == monsterArray[i].x - 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x + 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y + 1)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y - 1))) && (monsterArray[i].Alive == true))
				{
					monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
				}
			}
			if (character.xp >= 15)
			{
				character.LevelUp();
			}
			for (int i = 0; i < 2; i++)
				if ((character.x + 1 == monsterArray[i].x) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == 1))
				{
					willWalkIntoSomebody = 1;
				}
			if (willWalkIntoSomebody == 0)
			{
				character.Movement(1, 0); //RIGHT
			}
			willWalkIntoSomebody = 0;
		}




		if (GetAsyncKeyState(0x41)) //WALK LEFT
		{
			for (int i = 0; i < 2; i++)
			{
				if ((character.x == monsterArray[i].x + 1) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == true))  monsterArray[i].wasAttacked(&character.attack, &character.xp, &character.totalxp);
				if ((((character.x == monsterArray[i].x - 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x + 1) && (character.y == monsterArray[i].y)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y + 1)) || ((character.x == monsterArray[i].x) && (character.y == monsterArray[i].y - 1))) && (monsterArray[i].Alive == true))
				{
					monsterArray[i].playerAttacked(&character.x, &character.y, &character.health);
				}
			}
			if (character.xp >= 15)
			{
				character.LevelUp();
			}
			for (int i = 0; i < 2; i++)
				if ((character.x - 1 == monsterArray[i].x) && (character.y == monsterArray[i].y) && (monsterArray[i].Alive == 1))
				{
					willWalkIntoSomebody = 1;
				}
			if (willWalkIntoSomebody == 0)
			{
				character.Movement(-1, 0); //LEFT
			}
			willWalkIntoSomebody = 0;
		}





		if (GetAsyncKeyState(0x50))
		{
			int playerx = character.x;
			int playery = character.y;
			int playerhealth = character.health;
			int playerattack = character.attack;             //0x50 is the virtual key code for the p key, checks if P has been pressed
			int playerxp = character.xp;
			saveGame(playerx, playery, playerhealth, playerattack, playerxp);
		}





		if (GetAsyncKeyState(0x4C))
		{
			//loadGame();
		}
		
		if ((character.health < 0))		//Death Function until the classes version decides to work
		{
			gameStarted = false;
		}

		if (GetAsyncKeyState(0x49)) {
			for (int i = 0; i < 8; i++) cout << character.inventory[i];  //To be continued when Dimi's database becomes available
		}
	}

	if (gameStarted == false)
	{
		system("cls");
		
		cout << "GAME OVER! You have died!\nWhat is your name? ";
		std::string name;
		cin >> name;
		int scored;
		scored = character.totalxp * 100;
		cout << std::endl << name << " you have scored... " << scored << " points!\n";//"Do you want to see the leaderboard?\n";
		//Include the highscore leaderboard here
		ofstream f("highscores.txt", ios::app);
		f << name << " " << scored << "\n";
		f.close();
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
