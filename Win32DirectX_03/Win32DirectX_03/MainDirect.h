#ifndef MainDirect_H_
#define MainDirect_H_
#pragma once
#include "Utility.h"
#include "Camera.h"
//init Direct
class MainDirect : public Singleton<MainDirect>
{
private:
	LPDIRECT3D9 m_pD3d;
	LPDIRECT3DDEVICE9 m_pDevice;
	Camera * m_pCamera;
public:
	MainDirect();
	~MainDirect();

	LPDIRECT3D9 getD3d()const { return m_pD3d; }
	LPDIRECT3DDEVICE9 getD3dDevice()const { return m_pDevice; }

	void onInit();
	void onBeginRender();
	void onEndRender();
	void onExit();

};

#endif