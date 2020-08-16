#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Player.h"
#include <list>

class TestScene :
    public Scene
{
private:
	float gravity;
	bool isJump;

	Player* player;
public:
	TestScene();
	~TestScene();

	void Render();
	void Update(float dTime);
};