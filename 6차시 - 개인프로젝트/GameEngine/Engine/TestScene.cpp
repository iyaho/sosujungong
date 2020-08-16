#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
	player = new Player();
}

TestScene::~TestScene()
{
}

void TestScene::Render()
{
	player->Render();
}

void TestScene::Update(float dTime)
{
	player->Update(dTime);
}
