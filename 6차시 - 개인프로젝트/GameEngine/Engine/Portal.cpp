#include "stdafx.h"
#include "Portal.h"

Portal::Portal()
{
	
	PortalB = new Animation(4);
	PortalB->AddFrame("Resources/portalB1.png");
	PortalB->AddFrame("Resources/portalB2.png");
	PortalB->AddFrame("Resources/portalB3.png");
	PortalB->AddFrame("Resources/portalB4.png");
	PortalB->AddFrame("Resources/portalB5.png");
	PortalB->AddFrame("Resources/portalB6.png");
	PortalB->AddFrame("Resources/portalB7.png");
	PortalB->AddFrame("Resources/portalB8.png");
	PortalB->AddFrame("Resources/portalB9.png");

	AddChild(PortalB);

	PortalO = new Animation(4);
	PortalO->AddFrame("Resources/PortalO1.png");
	PortalO->AddFrame("Resources/PortalO2.png");
	PortalO->AddFrame("Resources/PortalO3.png");
	PortalO->AddFrame("Resources/PortalO4.png");
	PortalO->AddFrame("Resources/PortalO5.png");
	PortalO->AddFrame("Resources/PortalO6.png");
	PortalO->AddFrame("Resources/PortalO7.png");
	PortalO->AddFrame("Resources/PortalO8.png");
	PortalO->AddFrame("Resources/PortalO9.png");

	AddChild(PortalO);

	PortalB->setPos(400, 500);
	PortalO->setPos(1000, 500);
}

Portal::~Portal()
{
}

void Portal::Render()
{
	Object::Render();
	PortalB->Render();
	PortalO->Render();
}

void Portal::Update(float dTime)
{
	PortalB->Update(dTime);
	PortalO->Update(dTime);
}
