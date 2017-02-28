#include "EngineDirector.h"
#include "MainWindow.h"
#include "MainDirect.h"

EngineDirector::EngineDirector()
{
	m_pCamera = NULL;
	m_pTest = NULL;
	m_pTest1 = NULL;
	m_directional = NULL;
	m_point = NULL;
	m_spot = NULL;
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
	m_pCamera->setvEyePt(0.f, 6.f, 10.f);
	m_pCamera->setvLookAt(0.f, 0.f, 0.f);
	m_pCamera->setvUp(0.f, 1.f, 0.f);
	//-----------test---------------
	
	m_pTest = Test::Create();
	m_pTest->setLocalPos(D3DXVECTOR3(0, 0, 0));
	m_pTest1 = Test::Create();
	m_pTest1->setLocalPos(D3DXVECTOR3(5, 0, 0));
	m_pTest->addChild(m_pTest1);
	//----------------------------------
	m_directional = EngineLight::CreateWithLightType(Light_Directional);
	m_point = EngineLight::CreateWithLightType(Light_Point);
	m_spot = EngineLight::CreateWithLightType(Light_Spot);

	MainDirect::GetSingletonPtr()->getD3dDevice()->SetLight(0, &(m_directional->getLight()));
	MainDirect::GetSingletonPtr()->getD3dDevice()->LightEnable(0, true);

	//MainDirect::GetSingletonPtr()->getD3dDevice()->SetLight(1, &(m_point->getLight()));
	//MainDirect::GetSingletonPtr()->getD3dDevice()->LightEnable(1, true);

	//MainDirect::GetSingletonPtr()->getD3dDevice()->SetLight(2, &(m_spot->getLight()));
	//MainDirect::GetSingletonPtr()->getD3dDevice()->LightEnable(2, true);
	//-----------test---------------
}

void EngineDirector::onLogic(float fElapsedTime)
{
	static float fangle = 0.0f;
	fangle += fElapsedTime;
	m_pTest->setLocalRota(D3DXVECTOR3(0, 4.0f * fangle, 0));
	m_pTest1->setLocalRota(D3DXVECTOR3(0, 4.0f * fangle, 0));
}

void EngineDirector::onRender(float fElapsedTime)
{
	MainDirect::GetSingletonPtr()->onBeginRender();
	//-----------------------------------
	m_pCamera->Visit();
	m_pTest->Visit();
	m_pTest1->Visit();
	

	//-----------------------------------
	MainDirect::GetSingletonPtr()->onEndRender();
}

void EngineDirector::onExit()
{



	MainDirect::GetSingletonPtr()->onExit();
	MainWindow::GetSingletonPtr()->onExit();
}
