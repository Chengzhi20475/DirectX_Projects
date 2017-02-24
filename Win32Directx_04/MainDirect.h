#ifndef MainDirect_H_
#define MainDirect_H_
#pragma once
#include "Utility.h"
#include "Camera.h"
//init Direct

struct stCustomVertex	//�Զ��嶥��
{
	D3DXVECTOR4 vPos;	//��������ת������Ļ����
	DWORD dwColor;		//������ɫ
};
#define D3DFVF_CUSTOMVERTEX  (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

class MainDirect : public Singleton<MainDirect>
{
private:
	LPDIRECT3D9 m_pD3d;						//Direct �ӿ�ָ��
	LPDIRECT3DDEVICE9 m_pDevice;			//Direct �豸ָ��
	Camera * m_pCamera;	
	LPDIRECT3DVERTEXBUFFER9 m_pVertexBuffer;//���㻺��
	stCustomVertex m_stCustomVertex[6];
public:
	MainDirect();
	~MainDirect();

	LPDIRECT3D9 getD3d()const { return m_pD3d; }
	LPDIRECT3DDEVICE9 getD3dDevice()const { return m_pDevice; }

	void onInit();
	void onBeginRender();
	void onEndRender();
	void onExit();
	void onInitVertexBuffer();

};

#endif