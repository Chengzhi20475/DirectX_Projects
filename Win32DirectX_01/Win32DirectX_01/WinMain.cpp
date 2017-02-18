#include "Utility.h"

HWND g_hWnd = NULL;												
HINSTANCE g_hInstance = NULL;						



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{

	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("DirectX");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	RegisterClass(&wc);

	g_hWnd = CreateWindow(wc.lpszClassName,
		TEXT("DirectX_01"), WS_OVERLAPPEDWINDOW,
		300, 200,
		800, 600,
		NULL, NULL,
		hInstance, NULL);

	if (g_hWnd)
	{
		ShowWindow(g_hWnd, SW_SHOWNORMAL);
		UpdateWindow(g_hWnd);

		MSG msg;
		ZeroMemory(&msg, sizeof(msg));

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				//
				//
				//
				//
				//
				//
			}
		}
	}
	else
	{
		MessageBox(NULL, TEXT("Create Window Error"), TEXT("Error"), MB_OK);
	}

	UnregisterClass(wc.lpszClassName,hInstance);

	return 0;
}

LRESULT CALLBACK WndProc(HWND _hWnd, UINT _uMsg, WPARAM _wParm, LPARAM _lParm)
{
	switch (_uMsg)
	{
	case WM_KEYDOWN:
		{
			if (_wParm == VK_ESCAPE)
			{
				int Value = MessageBox(_hWnd, TEXT("Quit Window?"), TEXT("Message"), MB_YESNO);
				if (IDYES == Value)
					DestroyWindow(_hWnd);
			}
		}
		break;
	case WM_CLOSE:
		DestroyWindow(_hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(NULL);
		break;
	}

	return DefWindowProc(_hWnd, _uMsg, _wParm, _lParm);
}