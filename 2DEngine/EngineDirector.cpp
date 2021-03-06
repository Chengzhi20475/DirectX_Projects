#include "EngineDirector.h"



EngineDirector::EngineDirector()
{
	m_pCurrentSceneNode = NULL;
	m_pCamera = NULL;
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
			static DWORD dwTime = timeGetTime();			//�޶�60֡
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
	
	m_pCamera = EngineCamera::Create();
	m_pCamera->setvEyePt(0.f, 8.f, 8.f);
	m_pCamera->setvLookAt(0.f, 0.f, 0.f);
	m_pCamera->setvUp(0.f, 1.f, 0.f);

	this->RunWithScene(GameLayer::Scene());
}

void EngineDirector::onLogic(float fElapsedTime)
{

}

void EngineDirector::onRender(float fElapsedTime)
{
	EngineDirect::GetSingletonPtr()->onBeginRender();
	//--------------------test-----------------------
	m_pCamera->onVisit();
	m_pCurrentSceneNode->onVisit();




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
