#include "pch.h"
#include "Main.h"
#include "Engine/Game.h"
#include "OrthographicDemo.h"
#include"ButtonDemo.h"
#include"BillBoardDemo.h"
#include"SnowDemo.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameDesc desc;
	desc.appName = L"GameCoding";
	desc.hInstance = hInstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.f, 0.f, 0.f, 0.f);
	desc.app = make_shared<SnowDemo>();

	GAME->Run(desc);

	return 0;
}