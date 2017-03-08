#ifndef EngineWindow_H_
#define EngineWindow_H_
#pragma once
#include "Utility.h"
class EngineWindow : public Singleton<EngineWindow>		//Singleton Class
{
private:
	HWND m_hWnd;										//窗口句柄
	HINSTANCE m_hInstance;								//实例句柄
	Size m_WindowSize;									//窗口大小
public:
	EngineWindow();
	~EngineWindow();

	void onInit(const Size & _WindowSize);
	void onExit();
	HWND getHWnd()const { return m_hWnd; }
	HINSTANCE getHInstance()const { return m_hInstance; }
	Size getWinSize()const { return m_WindowSize; }
};
//消息处理函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#endif