#ifndef EngineDirect_H_
#define EngineDirect_H_
#pragma once
#include "Utility.h"
#include "EngineWindow.h"
class EngineDirect	: public Singleton<EngineDirect>	//Singleton class
{
private:
	LPDIRECT3D9 m_pD3d;									//Direct �ӿ�ָ��
	LPDIRECT3DDEVICE9 m_pDevice;						//Direct �豸ָ��
	LPD3DXSPRITE m_pSprite;								//Direct ����ָ��
public:
	EngineDirect();
	~EngineDirect();

	void onInit();
	void onBeginRender();
	void onEndRender();
	void onExit();

	LPDIRECT3D9 GetD3d()const { return m_pD3d; }
	LPDIRECT3DDEVICE9 GetD3dDevice()const { return m_pDevice; }
	LPD3DXSPRITE GetSprite()const { if (m_pSprite) return m_pSprite; else return NULL; }
};

#endif