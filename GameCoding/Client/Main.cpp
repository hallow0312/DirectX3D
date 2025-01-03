#include "pch.h"
#include "Main.h"
#include"Engine/Game.h"
#include"01.TriangleDemo.h"
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevInstance, LPSTR ipCmdLine, int nShowCmd)
{
	GameDesc  desc;
	desc.appName = L"GameCoding";
	desc.hInstance = hinstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
	desc.app = make_shared<TriangleDemo>();
	GAME->Run(desc);

	return 0;
}