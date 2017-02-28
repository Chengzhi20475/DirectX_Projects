#include "Camera.h"
#include "MainDirect.h"


Camera::Camera()
{
	m_vEyePt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vLookAt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vUp = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
	//m_bIsRota = false;								//是否旋转
	//m_bIsTrans = false;								//是否平移
	//m_vDirection = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//摄像机的方向
	//m_vRight = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//摄像机的右方向
	//m_LastPoint.x = 0;								//鼠标上一次的位置
	//m_LastPoint.y = 0;								//鼠标上一次的位置
	//m_vDletaMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//摄像机移动的差值
	//m_fVelocity = 1.0f;								//速度					 
	//m_fYaw = 0.0f;									//偏角
	//m_fPitch = 0.0f;								//仰角
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
	//----摄像机----
	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &m_vUp);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
	//----透视投影矩阵----
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 3,
		4.0f / 3.0f, 1.0f, 5000.0f);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

//void Camera::Update()
//{
//	POINT ptCurrentPos = { 0, 0 };//当前鼠标点的位置
//	POINT ptDeltaPos = { 0, 0 };//两次鼠标位置的差值
//
//								//=============  m_LastPoint  ============
//
//	if (m_bIsRota)
//	{
//		//计算鼠标偏移
//		GetCursorPos(&ptCurrentPos);		// 又获取一次鼠标当前时刻的位置信息
//		ptDeltaPos.x = ptCurrentPos.x - m_LastPoint.x;
//		ptDeltaPos.y = ptCurrentPos.y - m_LastPoint.y;
//		m_LastPoint = ptCurrentPos;
//
//		//根据两次鼠标位置的差值来计算偏角与仰角
//		float fYaw = ptDeltaPos.x*0.01f;
//		float fPitch = ptDeltaPos.y*0.01f;
//
//		//根据鼠标偏仰角来计算欧拉角
//		m_fYaw += fYaw;
//		m_fPitch += fPitch;
//	}
//
//	// 根据欧拉角Yaw，Pitch计算摄像机的旋转矩阵，摄像机的旋转矩阵
//	// 其实就是用来对摄像机的各个量进行相乘运算的
//	D3DXMATRIX matCameraRot;
//	D3DXMatrixIdentity(&matCameraRot);
//	D3DXMatrixRotationYawPitchRoll(&matCameraRot, m_fYaw, m_fPitch, 0.0f);
//
//	// 根据旋转矩阵将摄像机的局部朝向向量（Direction）和上方向向量（Up）转为全局向量
//	D3DXVECTOR3 vWorldUp;//摄像机的正方向
//	D3DXVECTOR3 vWorldDirection;//摄像机的Direction
//	D3DXVECTOR3 vLocalUp = D3DXVECTOR3(0, 1, 0);//摄像机自身坐标系的正向
//	D3DXVECTOR3 vLocalDirection = D3DXVECTOR3(0, 0, 1);//摄像机自身坐标系的朝向
//
//	D3DXVec3TransformCoord(&vWorldUp, &vLocalUp, &matCameraRot);//将向量按照一个矩阵去移动
//	D3DXVec3TransformCoord(&vWorldDirection, &vLocalDirection, &matCameraRot);//将向量按照一个矩阵去移动
//
//																			  //=============这里是用来计算摄像机更新之后的位置================
//	if (m_bIsTrans)
//	{
//		// 将局部偏移量转到全局坐标
//		D3DXVECTOR3 vWorldDelta;
//		D3DXVec3TransformCoord(&vWorldDelta, &m_vDletaMove, &matCameraRot);
//		// 根据偏移量计算视点位置q
//		m_vEyePt += vWorldDelta;
//	}
//	//===============================================================
//
//
//	// 计算摄像机的看向 
//	m_vLookAt = m_vEyePt + vWorldDirection;
//	// 更新视图矩阵
//	D3DXMatrixLookAtLH(&m_matView, &m_vEyePt, &m_vLookAt, &vWorldUp);
//	//将变换的结果应用到视图变换
//	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_VIEW, &m_matView);
//}

//void Camera::ProcessKeyboard(float fElapsedTime)
//{
//	//每次处理按键的时候，都要清空DletaMove这个值
//	m_vDletaMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
//
//	float fDistance = m_fVelocity * fElapsedTime;
//	//	d(距离)	=（ v（速度） *  t （时间） )
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
//		SetCapture(hWnd);//设置所有的鼠标输入都传入到hWnd所指向的这个窗口 
//		GetCursorPos(&m_LastPoint);	//获取鼠标的屏幕像素点的位置	
//	}
//	break;
//	case WM_RBUTTONUP:
//	{
//		m_bIsRota = false;
//		ReleaseCapture();//释放
//	}
//	break;
//	}
//}
