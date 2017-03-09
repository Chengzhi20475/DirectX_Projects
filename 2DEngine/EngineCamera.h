#ifndef EngineCamera_H_
#define EngineCamera_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
#include "EngineDirect.h"
#include "EngineWindow.h"
class EngineCamera : public EngineNode
{
private:
	D3DXVECTOR3 m_vEyePt;		//位置
	D3DXVECTOR3 m_vLookAt;		//看向
	D3DXVECTOR3 m_vUp;			//正向
	D3DXMATRIX m_matView;		//视图矩阵
	D3DXMATRIX m_matProj;
public:
	EngineCamera();
	~EngineCamera();

	static EngineCamera * Create();
	virtual bool onInit();
	virtual void onRender();

	void setvEyePt(float _x, float _y, float _z) { m_vEyePt = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvEyePt() { return m_vEyePt; }

	void setvLookAt(float _x, float _y, float _z) { m_vLookAt = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvLookAt() { return m_vLookAt; }

	void setvUp(float _x, float _y, float _z) { m_vUp = D3DXVECTOR3(_x, _y, _z); }
	D3DXVECTOR3 getvUp() { return m_vUp; }

};

#endif