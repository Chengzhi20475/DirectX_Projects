#include "Camera.h"
#include "MainDirect.h"


Camera::Camera()
{
	m_vEyePt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vLookAt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vUp = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
}


Camera::~Camera()
{
}

Camera * Camera::Create()
{
	Camera * pCamera = new Camera();
	if (pCamera && pCamera->Init())
	{

	}
	else
		Safe_Delete(pCamera);
	return pCamera;
}

bool Camera::Init()
{
	if (!EngineNode::Init())
		return false;

	//----摄像机----
	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &m_vUp);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
	//----透视投影矩阵----
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 3,
		4.0f / 3.0f, 1.0f, 5000.0f);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_PROJECTION, &m_matProj);
	return true;
}

//void Camera::Render()
//{
//
//}
