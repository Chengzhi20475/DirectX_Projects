#ifndef Camera_H_
#define Camera_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"

class Camera : public EngineNode
{
private:
	D3DXVECTOR3 m_vEyePt;		//λ��
	D3DXVECTOR3 m_vLookAt;		//����
	D3DXVECTOR3 m_vUp;			//����
	D3DXMATRIX m_matView;		//��ͼ����
	D3DXMATRIX m_matProj;

	//D3DXVECTOR3  m_vDirection;	//������ĳ���
	//D3DXVECTOR3  m_vRight;		//��������ҷ���

	//D3DXVECTOR3 m_vDletaMove;	//�ƶ���λ����

	//bool m_bIsRota;				//������Ƿ���ת
	//bool m_bIsTrans;			//�Ƿ�ƽ��

	//float m_fVelocity;			//�ƶ����ٶ�
	//float m_fYaw;				//ƫ��
	//float m_fPitch;				//����

	//POINT m_LastPoint;			//�����һ�ε����λ��

public:
	Camera();
	~Camera();

	static Camera * Create();
	virtual bool Init();
	virtual void Render();
	/*virtual void Update();*/

	//void ProcessKeyboard(float fElapsedTime);										//�����������
	//void SetVelocity(float _Velocity);											//����������ƶ������ٶ�
	//void HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);		//������Ϣ

	void setvEyePt(float _x, float _y, float _z) { m_vEyePt = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvEyePt() { return m_vEyePt; }

	void setvLookAt(float _x, float _y, float _z) { m_vLookAt = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvLookAt() { return m_vLookAt; }

	void setvUp(float _x, float _y, float _z) { m_vUp = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvUp() { return m_vUp; }

	/*D3DXMATRIX getMatView() { return m_matView; }
	D3DXMATRIX getMatProj() { return m_matProj; }*/

};

#endif