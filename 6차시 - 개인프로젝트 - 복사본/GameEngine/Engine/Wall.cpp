#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
	portal = new Portal();
	player = new Player();
	wallL = new Sprite("Resoureces/wallL.png");
	wallR = new Sprite("Resoureces/wallR.png");
	wallT = new Sprite("Resoureces/wallT.png");
	wallB = new Sprite("Resoureces/wallB.png");

	AddChild(wallL);
	AddChild(wallR);
	AddChild(wallB);
	AddChild(wallT);
}

Wall::~Wall()
{
}

void Wall::Render()
{
}

void Wall::Update(float dTime)
{
}
