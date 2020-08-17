#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
#include "Player.h"

class Portal :
	public Object
{
private:
	Animation* PortalB;
	Animation* PortalO;
public:
	Portal();
	~Portal();

	void Render();
	void Update(float dTime);
};

