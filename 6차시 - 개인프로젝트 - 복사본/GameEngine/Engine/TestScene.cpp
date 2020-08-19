#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
	player = new Player();
	portalA = new Portal();
	portalB = new Portal();
	portalA->setPortalType(0);
	portalB->setPortalType(1);
	portalA->setPortalRot(3);
	portalB->setPortalRot(1);
	lwall = new Wall();
	rwall = new Wall();
	bwall = new Wall();
	twall = new Wall();
	lwall->setWallType(3);
	rwall->setWallType(1);
	bwall->setWallType(2);
	twall->setWallType(0);
}

TestScene::~TestScene()
{
}

void TestScene::Render()
{
	lwall->Render();
	rwall->Render();
	twall->Render();
	bwall->Render();
	player->Render();
	portalA->Render();
	portalB->Render();
}

void TestScene::Update(float dTime)
{
	
	player->Update(dTime);
	portalA->Update(dTime);
	portalB->Update(dTime);
	if (player->getPosX() > portalB->getPosX() - 5 && player->getPosX() < portalB->getPosX() + 5 && player->getPosY() > portalB->getPosY() - 100 && player->getPosY() < portalB->getPosY() + 100) {
		switch (portalB->getPortalRot())
		{
		case 0: player->setPos(portalA->getPosX(), portalA->getPosY() + 35); break;
		case 1: player->setPos(portalA->getPosX() + 10, portalA->getPosY() + 25); break;
		case 2: player->setPos(portalA->getPosX(), portalA->getPosY() + 15); break;
		case 3: player->setPos(portalA->getPosX() - 10, portalA->getPosY() + 25); break;
		}
	}

	if (player->getPosX() > portalA->getPosX() - 5 && player->getPosX() < portalA->getPosX() + 5 && player->getPosY() > portalA->getPosY() - 100 && player->getPosY() < portalA->getPosY() + 100) {
		switch (portalA->getPortalRot())
		{
		case 0: player->setPos(portalB->getPosX(), portalB->getPosY() + 35); break;
		case 1: player->setPos(portalB->getPosX() + 10, portalB->getPosY() + 25); break;
		case 2: player->setPos(portalB->getPosX(), portalB->getPosY() + 15); break;
		case 3: player->setPos(portalB->getPosX() - 10, portalB->getPosY() + 25); break;
		}
	}

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (lwall->IsPointInRect(inputManager->GetMousePos())) {
			portalA->setPortalRot(lwall->getWallRot());
			portalA->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (rwall->IsPointInRect(inputManager->GetMousePos())) {
			portalA->setPortalRot(rwall->getWallRot());
			portalA->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (twall->IsPointInRect(inputManager->GetMousePos())) {
			portalA->setPortalRot(twall->getWallRot());
			portalA->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (bwall->IsPointInRect(inputManager->GetMousePos())) {
			portalA->setPortalRot(bwall->getWallRot());
			portalA->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		else
		{
			portalA->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		
	}
	if (inputManager->GetKeyState(VK_RBUTTON) == KEY_DOWN) {
		if (lwall->IsPointInRect(inputManager->GetMousePos())) {
			portalB->setPortalRot(lwall->getWallRot());
			portalB->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (rwall->IsPointInRect(inputManager->GetMousePos())) {
			portalB->setPortalRot(rwall->getWallRot());
			portalB->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (twall->IsPointInRect(inputManager->GetMousePos())) {
			portalB->setPortalRot(twall->getWallRot());
			portalB->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		if (bwall->IsPointInRect(inputManager->GetMousePos())) {
			portalB->setPortalRot(bwall->getWallRot());
			portalB->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
		else
		{
			portalB->setPos(inputManager->GetMousePos().x, inputManager->GetMousePos().y);
		}
	}
}
