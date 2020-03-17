#pragma once
#include <vector>
#include <array>
#include "mapPrototype.h"

struct coord
{
	int x, y;
};

using namespace std;
class pathing {
public:
	char nodePathingArray[100][100];
	int mpWidth, mpHeight;
	coord startNode;
	coord endNode;
	coord difference;
	vector<coord> solution;
	pathing(int mapSizeX, int mapSizeY, Dungeon holdMap, int coordXGoblin, int coordYGoblin)
	{
		startNode = { coordXGoblin, coordYGoblin };
		for (int i = 0; i < mapSizeX; i++)           //MAP GENERATION
		{
			for (int j = 0; j < mapSizeY; j++)
			{
				nodePathingArray[i][j] =  holdMap.getTile(i, j);
				if (nodePathingArray[i][j] == '@')
				{
					endNode = { i,j };
				}
				else if (nodePathingArray[i][j] == 'G' && (i != coordXGoblin && j != coordYGoblin))
				{
					map[i][j] = '#';
				}
				else if (nodePathingArray[i][j] == ' ')
				{
					nodePathingArray[i][j] = '.';
				}
			}
		}
		difference = { endNode.x - startNode.x, endNode.y - startNode.y };
		for (int i = 0; i < mapSizeX; i++)           //MAP GENERATION
		{
			if (nodePathingArray[i][0] == NULL)
			{
				mpWidth = i;
				break;
			}
		}
		for (int j = 0; j < mapSizeY; j++)
		{
			if (nodePathingArray[0][j] == NULL)
			{
				mpHeight = j;
				break;
			}
		}
	}
	vector<coord> pathCalc()
	{

		bool up, left;
		if (difference.x < 0 )
		{
			left = true;
		}
		else
		{
			left = false;
		}
		if (difference.y < 0)
		{
			up = true;
		}
		else
		{
			up = false;
		}
	}
	bool recursiveSolve(int x, int y)
	{
		if (x == endNode.x && y == endNode.y)
		{
			return true;
		}

		if (!(nodePathingArray[x][y] == '#' || x < 0 || y < 0 || x > mpWidth || y > mpHeight))
		{
			nodePathingArray[x][y] = 'T';
			solution.push_back({ x,y });
			if (recursiveSolve(x + 1, y))
			{
				return true;
			}
			if (recursiveSolve(x, y + 1))
			{
				return true;
			}
			if (recursiveSolve(x - 1, y))
			{
				return true;
			}
			if (recursiveSolve(x, y - 1))
			{
				return true;
			}
			solution.pop_back();
			nodePathingArray[x][y] = '.';
			return false;
		}
		return false;
	}
	void printNodes()
	{
		for (int i = 0; i < sizeof(nodePathingArray); i++)           //MAP GENERATION
		{
			for (int j = 0; j < sizeof(nodePathingArray); j++)
			{
				cout << nodePathingArray[i][j];
			}
			cout << endl;
		}
	}
};
