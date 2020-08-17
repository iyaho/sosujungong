#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
class Portal :
	public Object
{
private:
	Animation* portalO;
	Animation* portalB;
	int portalRot;
	int portalType;

public:
	Portal();
	~Portal();


	void Render();
	void Update(float dTime);

	int getPortalRot();
	int getPortalType();

	void setPortalRot(int rot);
	void setPortalType(int type);
};

