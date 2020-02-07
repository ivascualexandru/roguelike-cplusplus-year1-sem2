#pragma once

class Character
{
public:
	void Movement(int Vertical, int Horizontal);
	int health=10,xp=0,attack=4,x=1,y=1;
};

class monster
{
	public:
	int health=6,attack=3,x=3,y=3;
};

extern char map[15][15];
extern int x;
extern int y;