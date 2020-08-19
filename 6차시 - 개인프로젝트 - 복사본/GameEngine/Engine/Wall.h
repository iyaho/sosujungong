#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Player.h"
#include "Portal.h"
#include <list>

class Wall :
	public Object
{
private:
	int wallRot;
	int wallType;

	Portal* portal;
	Player* player;
	Sprite* wallL, *wallR, *wallB, *wallT;

public:
	Wall();
	~Wall();

	void Render();
	void Update(float dTime);

	int getWallRot();
	int getWallType();

	void setWallRot(int rot);
	void setWallType(int type);
};

