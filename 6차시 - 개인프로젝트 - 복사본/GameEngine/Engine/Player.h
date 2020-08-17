#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"

class Player :
    public Object
{
private:
    Animation* playerAnimation;
    float gravity;
    bool isJump;
    bool left, right;
    float angle;
public:
    Player();
    ~Player();

    void Render();
    void Update(float dTime);

    void PlayerUpdate(float dTime);
};

