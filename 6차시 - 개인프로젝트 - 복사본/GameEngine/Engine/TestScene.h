#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Player.h"
#include "Portal.h"
#include <list>
#include "Wall.h"

class TestScene :
    public Scene
{
private:
	Player* player;
	Portal* portalA;
	Portal* portalB;
	Wall* lwall;
	Wall* rwall;
	Wall* twall;
	Wall* bwall;
public:
	TestScene();
	~TestScene();

	void Render();
	void Update(float dTime);
};