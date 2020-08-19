#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
	wallRot = 0;
	wallType = 0;
	portal = new Portal();
	player = new Player();
	wallL = new Sprite("Resources/wallL.png");
	wallR = new Sprite("Resources/wallR.png");
	wallT = new Sprite("Resources/wallT.png");
	wallB = new Sprite("Resources/wallB.png");

	
	wallL->setPos(999, 0);
	wallR->setPos(0, 0);
	wallT->setPos(0, 460);
	wallB->setPos(0, 0);
	

}

Wall::~Wall()
{
	
}

void Wall::Render()
{
	if (wallType == 0) {
		wallT->Render();
	}
	if (wallType == 1) {
		wallR->Render();
	}
	if (wallType == 2) {
		wallB->Render();
	}
	if (wallType == 3) {
		wallL->Render();
	}
}

void Wall::Update(float dTime)
{
	Object::Update(dTime);

}

int Wall::getWallRot()
{
	return wallRot;
}

int Wall::getWallType()
{
	return wallType;
}

void Wall::setWallRot(int rot)
{
	wallRot = rot;
}

void Wall::setWallType(int type)
{
	wallType = type;
}
