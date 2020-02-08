#include <iostream>
#include <string>

using namespace std;

void menu(int &c);


int main()
{
	int choice = 0;
	menu(choice);
	while (choice > 0)
	{
		switch (choice)
		{
		case 1:		//Start playing
			break;
		case 2:		//Manual
			break;
		case 3:		//Tutorial
			break;
		default:
			break
		}

		menu(choice);
	}
	system("PAUSE");

	return 0;
}

void menu(int &c)
{
	cout << "Choices: /n(0 quit, 1 start playing, 2 manual, 3 tutorial /nWhat do you choose? ";
	cin >> c;
}