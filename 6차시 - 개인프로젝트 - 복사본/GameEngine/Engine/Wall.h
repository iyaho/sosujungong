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
	Portal* portal;
	Player* player;
	Sprite* wallL, *wallR, *wallB, *wallT;

public:
	Wall();
	~Wall();

	void Render();
	void Update(float dTime);
};

