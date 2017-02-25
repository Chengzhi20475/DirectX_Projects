#include "EngineDirector.h"
#include "MainWindow.h"
#include "MainDirect.h"

EngineDirector::EngineDirector()
{
	m_pCamera = NULL;
	m_pTest = NULL;
	m_pTest1 = NULL;
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
	////----ÉãÏñ»ú----
	m_pCamera = Camera::Create();
	m_pCamera->setvEyePt(0.f, 6.f, 5.f);
	m_pCamera->setvLookAt(0.f, 0.f, 0.f);
	m_pCamera->setvUp(0.f, 1.f, 0.f);
	//----------------------------------
	
	m_pTest = Test::Create();
	m_pTest->setLocalPos(D3DXVECTOR3(0, 0, 0));
	m_pTest1 = Test::Create();
	m_pTest1->setLocalPos(D3DXVECTOR3(5, 0, 0));
	m_pTest->addChild(m_pTest1);
	
}

void EngineDirector::onLogic(float fElapsedTime)
{
	static float fangle = 0.0f;
	fangle += fElapsedTime;
	m_pTest->setLocalRota(D3DXVECTOR3(0, 4.0f * sin(fangle), 0));
}

void EngineDirector::onRender(float fElapsedTime)
{
	MainDirect::GetSingletonPtr()->onBeginRender();
	//-----------------------------------
	m_pCamera->Visit();
	m_pTest->Visit();
	//m_pTest1->Visit();



	//-----------------------------------
	MainDirect::GetSingletonPtr()->onEndRender();
}

void EngineDirector::onExit()
{



	MainDirect::GetSingletonPtr()->onExit();
	MainWindow::GetSingletonPtr()->onExit();
}
