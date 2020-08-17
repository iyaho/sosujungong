#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
	player = new Player();
	portal = new Portal();
}

TestScene::~TestScene()
{
}

void TestScene::Render()
{
	player->Render();
	portal->Render();
}

void TestScene::Update(float dTime)
{
	player->Update(dTime);
	portal->Update(dTime);
}
