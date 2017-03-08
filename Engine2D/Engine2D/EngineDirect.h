#ifndef EngineDirect_H_
#define EngineDirect_H_
#pragma once
#include "Utility.h"
#include "EngineWindow.h"
class EngineDirect	: public Singleton<EngineDirect>	//Singleton class
{
private:
	LPDIRECT3D9 m_pD3d;									//Direct 接口指针
	LPDIRECT3DDEVICE9 m_pDevice;						//Direct 设备指针
public:
	EngineDirect();
	~EngineDirect();

	void onInit();
	void onBeginRender();
	void onEndRender();
	void onExit();

	LPDIRECT3D9 GetD3d()const { return m_pD3d; }
	LPDIRECT3DDEVICE9 GetD3dDevice()const { return m_pDevice; }
};

#endif