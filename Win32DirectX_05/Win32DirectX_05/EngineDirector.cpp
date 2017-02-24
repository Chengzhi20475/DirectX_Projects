#include "EngineDirector.h"
#include "MainWindow.h"
#include "MainDirect.h"

EngineDirector::EngineDirector()
{
}


EngineDirector::~EngineDirector()
{
}

void EngineDirector::Run()
{
	onInit();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			static DWORD dwTime = timeGetTime();
			DWORD dwCurrentTime = timeGetTime();
			DWORD dwElapsedTime = dwCurrentTime - dwTime;
			float fElapsedTime = dwElapsedTime * 0.001f;
			onLogic(fElapsedTime);
			onRender(fElapsedTime);
			if (dwElapsedTime < 1000 / 60)
				Sleep(1000 / 60 - dwElapsedTime);
			dwTime = dwCurrentTime;
		}
	}

	onExit();
}

void EngineDirector::onInit()
{
	MainWindow::GetSingletonPtr()->onInit(SetSize(800,600));
	MainDirect::GetSingletonPtr()->onInit();
}

void EngineDirector::onLogic(float fElapsedTime)
{

}

void EngineDirector::onRender(float fElapsedTime)
{
	MainDirect::GetSingletonPtr()->onBeginRender();
	//-----------------------------------
	MainDirect::GetSingletonPtr()->getD3dFont()->DrawTextW(
		NULL,														//精灵
		TEXT("I'm font"),											//内容
		-1,															//写多少个   -1为显示全部
		MainDirect::GetSingletonPtr()->getD3dFontRect(),			//矩形区域
		DT_CENTER | DT_VCENTER,										//显示位置 居中 水平
		D3DCOLOR_XRGB(255,0,0)
	);




	//-----------------------------------
	MainDirect::GetSingletonPtr()->onEndRender();
}

void EngineDirector::onExit()
{



	MainDirect::GetSingletonPtr()->onExit();
	MainWindow::GetSingletonPtr()->onExit();
}
