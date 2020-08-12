#pragma once
//게임 매니저 헤더
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

//Program Setting
#define CONSOLE_OFF false
#define SCREEN_WIDTH 1024//가로
#define SCREEN_HEIGHT 768//높이
#define BG_COLOR D3DCOLOR_ARGB(255,255,255,255)//배경색
#define PROGRAM_NAME TEXT("Engine")//이름
#define CONSOLE_NAME TEXT("Console")//콘솔이름

//윈도우 헤더
#include <Windows.h>
#include <XAudio2.h>

//다이렉트X 헤더
#include <d3d9.h>
#include <d3dx9.h>

//디버그 헤더
#include <iostream>

//게임 매니저 헤더

//상수
#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define SAFE_RELEASE(p) {if(p) {p->Release();(p)=NULL;}}
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete [](p);(p)=nullptr;}}

//전역변수
extern LPDIRECT3D9 pd3d;
extern D3DPRESENT_PARAMETERS d3dapp;
extern LPDIRECT3DDEVICE9 pd3dDevice;
extern LPD3DXSPRITE pd3dSprite;
extern HWND hWnd;
extern SceneManager* sceneManager;
extern TextureManager* textureManager;
extern InputManager* inputManager;
