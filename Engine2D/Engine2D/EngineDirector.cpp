#include "EngineDirector.h"



EngineDirector::EngineDirector()
{
	m_pCurrentSceneNode = NULL;
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
			static DWORD dwTime = timeGetTime();			//ÏÞ¶¨60Ö¡
			DWORD dwCurrentTime = timeGetTime();
			DWORD dwElapsedTime = dwCurrentTime - dwTime;
			float fElapsedTime = dwElapsedTime*0.001f;
			onLogic(fElapsedTime);
			onRender(fElapsedTime);
			if (dwElapsedTime < 1000 / 60)
				Sleep(1000 / 60 - dwElapsedTime);
		}
	}
	onExit();
}

void EngineDirector::onInit()
{
	EngineWindow::GetSingletonPtr()->onInit(SetSize(800, 600));
	EngineDirect::GetSingletonPtr()->onInit();

	//this->RunWithScene();
}

void EngineDirector::onLogic(float fElapsedTime)
{

}

void EngineDirector::onRender(float fElapsedTime)
{
	EngineDirect::GetSingletonPtr()->onBeginRender();
	//--------------------test-----------------------






	//--------------------test-----------------------
	EngineDirect::GetSingletonPtr()->onEndRender();
}

void EngineDirector::onExit()
{
	EngineDirect::GetSingletonPtr()->onExit();
	EngineWindow::GetSingletonPtr()->onExit();
}

void EngineDirector::RunWithScene(EngineScene * _pScene)
{
	m_pCurrentSceneNode = (EngineNode *)_pScene;
}
