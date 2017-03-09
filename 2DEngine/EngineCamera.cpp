#include "EngineCamera.h"



EngineCamera::EngineCamera()
{
	m_vEyePt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vLookAt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vUp = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
}


EngineCamera::~EngineCamera()
{
	OutputDebugString(TEXT("EngineCamera::~EngineCamera() Called...\n"));
}

EngineCamera * EngineCamera::Create()
{
	EngineCamera * pCamera = new EngineCamera();
	if (pCamera && pCamera->onInit())
	{
		OutputDebugString(TEXT("EngineCamera::Create() Called...\n"));
	}
	else
	{
		Safe_Delete(pCamera);
	}
	return pCamera;
}

bool EngineCamera::onInit()
{
	if (!EngineNode::onInit())
		return false;

	OutputDebugString(TEXT("EngineCamera::onInit() Called...\n"));

	return true;
}

void EngineCamera::onRender()
{
	//----摄像机----
	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &m_vUp);
	EngineDirect::GetSingletonPtr()->GetD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
	//----透视投影矩阵----
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 3,
		4.0f / 3.0f, 1.0f, 5000.0f);
	EngineDirect::GetSingletonPtr()->GetD3dDevice()->SetTransform(D3DTS_PROJECTION, &m_matProj);
	//----正交投影矩阵----
	/*D3DXMatrixOrthoLH(&m_matProj, EngineWindow::GetSingletonPtr()->getWinSize().m_iWidth,
		EngineWindow::GetSingletonPtr()->getWinSize().m_iHeight, 1.0f, 1000.0f);*/
}
