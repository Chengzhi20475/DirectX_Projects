#include "MainWindow.h"



MainWindow::MainWindow()
{
	m_hWnd = NULL;
	m_hInstance = NULL;
	m_WindowSize = Size(0, 0);
}


MainWindow::~MainWindow()
{
}

void MainWindow::onInit(const Size & _WindowSize)
{
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("Direct");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);

	m_WindowSize = _WindowSize;

	m_hInstance = wc.hInstance;
	m_hWnd = CreateWindow(wc.lpszClassName,
		TEXT("Win32DirectX_03"), WS_OVERLAPPEDWINDOW, 300, 200,
		m_WindowSize.width + 16, m_WindowSize.height + 39,
		NULL, NULL, m_hInstance, NULL);

	if (m_hWnd)
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}

void MainWindow::onExit()
{
	UnregisterClass(TEXT("Direct"), m_hInstance);
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