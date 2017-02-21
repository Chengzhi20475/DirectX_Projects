#ifndef MainWindow_H_
#define MainWindow_H_
#pragma once
#include "Utility.h"
//Create Window   Only one

class MainWindow : public Singleton<MainWindow>
{
private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
	Size m_WindowSize;
public:
	MainWindow();
	~MainWindow();
	void onInit(const Size & _WindowSize);		//init window
	void onExit();
	HWND getHWnd()const { return m_hWnd; }
	HINSTANCE getHInstance()const { return m_hInstance; }
	Size getWinSize()const { return m_WindowSize; }
};
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#endif
