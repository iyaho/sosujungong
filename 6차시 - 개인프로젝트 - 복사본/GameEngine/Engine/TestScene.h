#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Player.h"
#include "Portal.h"
#include <list>

class TestScene :
    public Scene
{
private:
	Player* player;
	Portal* portalA;
	Portal* portalB;

public:
	TestScene();
	~TestScene();

	void Render();
	void Update(float dTime);
};