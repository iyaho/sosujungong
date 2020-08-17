#include "stdafx.h"
#include "Portal.h"

Portal::Portal()
{
	// 0 top, 1 right, 2 bottom, 3 left 
	portalRot = 0;
	// 0 O, 1 B
	portalType = 0;

	portalO = new Animation(20);
	portalO->AddFrame("Resources/portalO1.png");
	portalO->AddFrame("Resources/portalO2.png");
	portalO->AddFrame("Resources/portalO3.png");
	portalO->AddFrame("Resources/portalO4.png");
	portalO->AddFrame("Resources/portalO5.png");
	portalO->AddFrame("Resources/portalO6.png");
	portalO->AddFrame("Resources/portalO7.png");
	portalO->AddFrame("Resources/portalO8.png");
	portalO->AddFrame("Resources/portalO9.png");

	portalB = new Animation(20);
	portalB->AddFrame("Resources/portalB1.png");
	portalB->AddFrame("Resources/portalB2.png");
	portalB->AddFrame("Resources/portalB3.png");
	portalB->AddFrame("Resources/portalB4.png");
	portalB->AddFrame("Resources/portalB5.png");
	portalB->AddFrame("Resources/portalB6.png");
	portalB->AddFrame("Resources/portalB7.png");
	portalB->AddFrame("Resources/portalB8.png");
	portalB->AddFrame("Resources/portalB9.png");


	AddChild(portalO);
	AddChild(portalB);

	setScalingCenter(portalO->getWidth() / 2, portalO->getWidth() / 2);
	portalO->setScale(2.5, 2.5);
	setScalingCenter(portalB->getWidth() / 2, portalB->getWidth() / 2);
	portalB->setScale(2.5, 2.5);
}

Portal::~Portal()
{
}

void Portal::Render()
{
	Object::Render();
	if (portalType)
		portalB->Render();
	else
		portalO->Render();
}

void Portal::Update(float dTime)
{
	Object::Update(dTime);
}

int Portal::getPortalRot()
{
	return portalRot;
}

int Portal::getPortalType()
{
	return portalType;
}

void Portal::setPortalRot(int rot)
{
	portalRot = rot;
}

void Portal::setPortalType(int type)
{
	portalType = type;
}
