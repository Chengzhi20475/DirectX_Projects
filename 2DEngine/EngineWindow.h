#ifndef EngineWindow_H_
#define EngineWindow_H_
#pragma once
#include "Utility.h"
class EngineWindow : public Singleton<EngineWindow>		//Singleton Class
{
private:
	HWND m_hWnd;										//���ھ��
	HINSTANCE m_hInstance;								//ʵ�����
	Size m_WindowSize;									//���ڴ�С
public:
	EngineWindow();
	~EngineWindow();

	void onInit(const Size & _WindowSize);
	void onExit();
	HWND getHWnd()const { return m_hWnd; }
	HINSTANCE getHInstance()const { return m_hInstance; }
	Size getWinSize()const { return m_WindowSize; }
};
//��Ϣ������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#endif