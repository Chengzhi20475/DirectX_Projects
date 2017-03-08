#include "EngineWindow.h"



EngineWindow::EngineWindow()
{
	m_hWnd = NULL;
	m_hInstance = NULL;
	m_WindowSize = Size(0, 0);
}


EngineWindow::~EngineWindow()
{
}

void EngineWindow::onInit(const Size & _WindowSize)
{
	//注册窗口类
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("DirectX");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);

	m_WindowSize = _WindowSize;

	m_hInstance = wc.hInstance;
	m_hWnd = CreateWindow(wc.lpszClassName,
		TEXT("Engine2D"), WS_OVERLAPPEDWINDOW, 300, 200,
		m_WindowSize.m_iWidth + 16, m_WindowSize.m_iHeight + 39,
		NULL, NULL, m_hInstance, NULL);
	//显示窗口 刷新窗口
	if (m_hWnd)
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}

void EngineWindow::onExit()
{
	//注销窗口
	UnregisterClass(TEXT("DirectX"), m_hInstance);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,
	WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}