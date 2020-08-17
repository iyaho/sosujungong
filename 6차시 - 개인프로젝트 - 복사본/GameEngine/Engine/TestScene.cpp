#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
	player = new Player();
	portalA = new Portal();
	portalB = new Portal();
	portalA->setPos(600, 375);
	portalB->setPos(200, 375);
	portalA->setPortalType(0);
	portalB->setPortalType(1);
	portalA->setPortalRot(3);
	portalB->setPortalRot(1);
}

TestScene::~TestScene()
{
}

void TestScene::Render()
{
	player->Render();
	portalA->Render();
	portalB->Render();
}

void TestScene::Update(float dTime)
{
	player->Update(dTime);
	portalA->Update(dTime);
	portalB->Update(dTime);

	if (player->getPosX() > portalB->getPosX() - 5 && player->getPosX() < portalB->getPosX() + 5) {
		switch (portalB->getPortalRot())
		{
		case 0: player->setPos(portalA->getPosX(), portalA->getPosY() + 10); break;
		case 1: player->setPos(portalA->getPosX() + 10, portalA->getPosY()); break;
		case 2: player->setPos(portalA->getPosX(), portalA->getPosY() - 10); break;
		case 3: player->setPos(portalA->getPosX() - 10, portalA->getPosY()); break;
		}
	}

	if (player->getPosX() > portalA->getPosX() - 5 && player->getPosX() < portalA->getPosX() + 5) {
		switch (portalA->getPortalRot())
		{
		case 0: player->setPos(portalB->getPosX(), portalB->getPosY() + 10); break;
		case 1: player->setPos(portalB->getPosX() + 10, portalB->getPosY()); break;
		case 2: player->setPos(portalB->getPosX(), portalB->getPosY() - 10); break;
		case 3: player->setPos(portalB->getPosX() - 10, portalB->getPosY()); break;
		}
	}
}
