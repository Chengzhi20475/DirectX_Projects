#ifndef Camera_H_
#define Camera_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"

class Camera : public EngineNode
{
private:
	D3DXVECTOR3 m_vEyePt;		//位置
	D3DXVECTOR3 m_vLookAt;		//看向
	D3DXVECTOR3 m_vUp;			//正向
	D3DXMATRIX m_matView;		//视图矩阵
	D3DXMATRIX m_matProj;

	//D3DXVECTOR3  m_vDirection;	//摄像机的朝向
	//D3DXVECTOR3  m_vRight;		//摄像机的右方向

	//D3DXVECTOR3 m_vDletaMove;	//移动的位移量

	//bool m_bIsRota;				//摄像机是否旋转
	//bool m_bIsTrans;			//是否平移

	//float m_fVelocity;			//移动的速度
	//float m_fYaw;				//偏角
	//float m_fPitch;				//仰角

	//POINT m_LastPoint;			//鼠标上一次点击的位置

public:
	Camera();
	~Camera();

	static Camera * Create();
	virtual bool Init();
	virtual void Render();
	/*virtual void Update();*/

	//void ProcessKeyboard(float fElapsedTime);										//处理键盘输入
	//void SetVelocity(float _Velocity);											//设置摄像机移动快慢速度
	//void HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);		//处理消息

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