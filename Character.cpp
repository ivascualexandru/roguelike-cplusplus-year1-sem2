#include "Character.h"

char map[15][15] = {			//static map in array
	"**************",
	"*@           *",
	"*            *",
	"*  G         *",
	"*            *",
	"*            *",
	"*            *",
	"*            *",
	"*            *",
	"*            *",
	"**************"
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

	/*if (map[y][x2] == '-') //attempt at corridors lmao
	{
		map[y][x] = '-';
		x += Horizontal;
		map[y][x] = '@';
	}
	if (map[y2][x] == '|')
	{
		map[y][x] = '|';
		y += Vertical;
		map[y][x] = '@';
	}*/

}