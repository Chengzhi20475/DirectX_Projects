#include "MainDirect.h"
#include "MainWindow.h"


MainDirect::MainDirect()
{
	m_pD3d = NULL;
	m_pDevice = NULL;
	m_pCamera = NULL;
	m_pVertexBuffer = NULL;
	//ZeroMemory(&m_stCustomVertex, sizeof(stCustomVertex));
}


MainDirect::~MainDirect()
{
}

void MainDirect::onInit()
{
	m_pD3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!m_pD3d)
	{
		OutputDebugString(TEXT("CREATE D3D ERROR!!!!!!!!"));
		return;
	}
	D3DDISPLAYMODE d3ddm;
	ZeroMemory(&d3ddm, sizeof(d3ddm));
	m_pD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.EnableAutoDepthStencil = TRUE;

	m_pD3d->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		MainWindow::GetSingletonPtr()->getHWnd(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pDevice);
	if (!m_pDevice)
	{
		OutputDebugString(TEXT("CREATE D3DDevice ERROR!!!!!!!!"));
		return;
	}
	////----初始渲染状态----
	//m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	//m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);					//开启深度缓冲区
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);				//停止光照运算
	m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);	//线框模式渲染
	//m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);		//实体模式渲染
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	
	////----摄像机----
	m_pCamera = Camera::Create();
	m_pCamera->setvEyePt(0.f, 0.f, -10.f);
	m_pCamera->setvLookAt(0.f, 0.f, 0.f);
	m_pCamera->setvUp(0.f, 1.f, 0.f);
	onInitVertexBuffer();
	//--------------------------------------------------------------
	//D3DXVECTOR3 vEyePt(0, 0, -10);
	//D3DXVECTOR3 vLookAt(0, 0, 0);
	//D3DXVECTOR3 vUp(0, 1, 0);
	//D3DXMATRIX matView;
	//D3DXMatrixIdentity(&matView);
	//D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookAt, &vUp);
	//m_pDevice->SetTransform(D3DTS_VIEW, &matView);

	////----透视投影矩阵----
	//D3DXMATRIX matProj;
	//D3DXMatrixIdentity(&matProj);
	//D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 3,
	//	4.0f / 3.0f, 1.0f, 5000.0f);
	//m_pDevice->SetTransform(D3DTS_PROJECTION, &matProj);
	//--------------------------------------------------------------

	m_pDevice->SetStreamSource(	//设置数据来源
		0,						//数据流编号（0 - 15）
		m_pVertexBuffer,		//数据源
		0,						//数据偏移量
		sizeof(stCustomVertex)	//顶点数据所占用的字节数
		);

	m_pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);



}

void MainDirect::onBeginRender()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 123, 123, 234), 1.0f, 0);
	m_pDevice->BeginScene();
}

void MainDirect::onEndRender()
{
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}

void MainDirect::onExit()
{

	Safe_Release(m_pVertexBuffer);
	Safe_Release(m_pDevice);
	Safe_Release(m_pD3d);
}

void MainDirect::onInitVertexBuffer()
{
	//1.定义顶点数组
	m_stCustomVertex[0] = { D3DXVECTOR4(50.0f,500.0f,0.0f,1.0f),D3DCOLOR_XRGB(255,0,0) };
	m_stCustomVertex[1] = { D3DXVECTOR4(150.0f,100.0f,0.0f,1.0f),D3DCOLOR_XRGB(0,255,0) };
	m_stCustomVertex[2] = { D3DXVECTOR4(250.0f,500.0f,0.0f,1.0f),D3DCOLOR_XRGB(0,0,255) };
	m_stCustomVertex[3] = { D3DXVECTOR4(350.0f,100.0f,0.0f,1.0f),D3DCOLOR_XRGB(255,255,0) };
	m_stCustomVertex[4] = { D3DXVECTOR4(450.0f,500.0f,0.0f,1.0f),D3DCOLOR_XRGB(0,255,255) };
	m_stCustomVertex[5] = { D3DXVECTOR4(550.0f,100.0f,0.0f,1.0f),D3DCOLOR_XRGB(255,0,255) };
	
	//2.创建顶点缓冲区
	m_pDevice->CreateVertexBuffer(
		sizeof(m_stCustomVertex),	//顶点缓冲区大小
		D3DUSAGE_WRITEONLY,			//
		D3DFVF_CUSTOMVERTEX,		//顶点格式
		D3DPOOL_MANAGED,			//受系统控制的内存空间
		&m_pVertexBuffer,			//返回的指针
		NULL						//保留信息
		);
	//3.将顶点数组数据copy至顶点缓冲区
	void * pVectex = NULL;
	m_pVertexBuffer->Lock(				//锁定
		0,								//偏移量
		sizeof(m_stCustomVertex),		//锁定数据大小
		&pVectex,						//锁定空间后返回的指针 = m_pVertexBuffer 
		0
		);
	memcpy(								//copy
		pVectex,						//
		m_stCustomVertex,				//
		sizeof(m_stCustomVertex)		//
	);							
	m_pVertexBuffer->Unlock();			//解锁
}
