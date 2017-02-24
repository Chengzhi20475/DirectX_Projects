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

	//MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_POINTLIST, 0, 6);		//����6����

	//MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_LINELIST, 0, 3);		//������
	//MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_LINESTRIP, 0, 5);		//��β��������

	//MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);	//����������
	//MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 4);	//���������ι���һ����
	MainDirect::GetSingletonPtr()->getD3dDevice()->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 4);		//���������ĸ�������


	//-----------------------------------
	MainDirect::GetSingletonPtr()->onEndRender();
}

void EngineDirector::onExit()
{



	MainDirect::GetSingletonPtr()->onExit();
	MainWindow::GetSingletonPtr()->onExit();
}
