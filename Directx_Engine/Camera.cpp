#include "Camera.h"
#include "MainDirect.h"


Camera::Camera()
{
	m_vEyePt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vLookAt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vUp = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
	//m_bIsRota = false;								//�Ƿ���ת
	//m_bIsTrans = false;								//�Ƿ�ƽ��
	//m_vDirection = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//������ķ���
	//m_vRight = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//��������ҷ���
	//m_LastPoint.x = 0;								//�����һ�ε�λ��
	//m_LastPoint.y = 0;								//�����һ�ε�λ��
	//m_vDletaMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//������ƶ��Ĳ�ֵ
	//m_fVelocity = 1.0f;								//�ٶ�					 
	//m_fYaw = 0.0f;									//ƫ��
	//m_fPitch = 0.0f;								//����
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

	return true;
}

void Camera::Render()
{
	//----�����----
	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &m_vUp);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
	//----͸��ͶӰ����----
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 3,
		4.0f / 3.0f, 1.0f, 5000.0f);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

//void Camera::Update()
//{
//	POINT ptCurrentPos = { 0, 0 };//��ǰ�����λ��
//	POINT ptDeltaPos = { 0, 0 };//�������λ�õĲ�ֵ
//
//								//=============  m_LastPoint  ============
//
//	if (m_bIsRota)
//	{
//		//�������ƫ��
//		GetCursorPos(&ptCurrentPos);		// �ֻ�ȡһ����굱ǰʱ�̵�λ����Ϣ
//		ptDeltaPos.x = ptCurrentPos.x - m_LastPoint.x;
//		ptDeltaPos.y = ptCurrentPos.y - m_LastPoint.y;
//		m_LastPoint = ptCurrentPos;
//
//		//�����������λ�õĲ�ֵ������ƫ��������
//		float fYaw = ptDeltaPos.x*0.01f;
//		float fPitch = ptDeltaPos.y*0.01f;
//
//		//�������ƫ����������ŷ����
//		m_fYaw += fYaw;
//		m_fPitch += fPitch;
//	}
//
//	// ����ŷ����Yaw��Pitch�������������ת�������������ת����
//	// ��ʵ����������������ĸ�����������������
//	D3DXMATRIX matCameraRot;
//	D3DXMatrixIdentity(&matCameraRot);
//	D3DXMatrixRotationYawPitchRoll(&matCameraRot, m_fYaw, m_fPitch, 0.0f);
//
//	// ������ת����������ľֲ�����������Direction�����Ϸ���������Up��תΪȫ������
//	D3DXVECTOR3 vWorldUp;//�������������
//	D3DXVECTOR3 vWorldDirection;//�������Direction
//	D3DXVECTOR3 vLocalUp = D3DXVECTOR3(0, 1, 0);//�������������ϵ������
//	D3DXVECTOR3 vLocalDirection = D3DXVECTOR3(0, 0, 1);//�������������ϵ�ĳ���
//
//	D3DXVec3TransformCoord(&vWorldUp, &vLocalUp, &matCameraRot);//����������һ������ȥ�ƶ�
//	D3DXVec3TransformCoord(&vWorldDirection, &vLocalDirection, &matCameraRot);//����������һ������ȥ�ƶ�
//
//																			  //=============�����������������������֮���λ��================
//	if (m_bIsTrans)
//	{
//		// ���ֲ�ƫ����ת��ȫ������
//		D3DXVECTOR3 vWorldDelta;
//		D3DXVec3TransformCoord(&vWorldDelta, &m_vDletaMove, &matCameraRot);
//		// ����ƫ���������ӵ�λ��q
//		m_vEyePt += vWorldDelta;
//	}
//	//===============================================================
//
//
//	// ����������Ŀ��� 
//	m_vLookAt = m_vEyePt + vWorldDirection;
//	// ������ͼ����
//	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &vWorldUp);
//	//���任�Ľ��Ӧ�õ���ͼ�任
//	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
//}

//void Camera::ProcessKeyboard(float fElapsedTime)
//{
//	//ÿ�δ�������ʱ�򣬶�Ҫ���DletaMove���ֵ
//	m_vDletaMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//
//	float fDistance = m_fVelocity * fElapsedTime;
//	//	d(����)	=�� v���ٶȣ� *  t ��ʱ�䣩 )
//	if (GetAsyncKeyState('W') & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.z += fDistance;
//	}
//	if (GetAsyncKeyState('S') & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.z -= fDistance;
//	}
//	if (GetAsyncKeyState('A') & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.x -= fDistance;
//	}
//	if (GetAsyncKeyState('D') & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.x += fDistance;
//	}
//	if (GetAsyncKeyState(VK_HOME) & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.y += fDistance;
//	}
//	if (GetAsyncKeyState(VK_END) & 0x8000)
//	{
//		m_bIsTrans = true;
//		m_vDletaMove.y -= fDistance;
//	}
//}

//void Camera::SetVelocity(float _Velocity)
//{
//	m_fVelocity = _Velocity;
//}

//void Camera::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_RBUTTONDOWN:
//	{
//		m_bIsRota = true;
//		SetCapture(hWnd);//�������е�������붼���뵽hWnd��ָ���������� 
//		GetCursorPos(&m_LastPoint);	//��ȡ������Ļ���ص��λ��	
//	}
//	break;
//	case WM_RBUTTONUP:
//	{
//		m_bIsRota = false;
//		ReleaseCapture();//�ͷ�
//	}
//	break;
//	}
//}
