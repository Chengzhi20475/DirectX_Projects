#include "EngineDirect.h"



EngineDirect::EngineDirect()
{
	m_pD3d = NULL;
	m_pDevice = NULL;
	m_pSprite = NULL;
}


EngineDirect::~EngineDirect()
{
}

void EngineDirect::onInit()
{
	m_pD3d = Direct3DCreate9(D3D_SDK_VERSION);						//创建接口指针
	if (!m_pD3d)
	{
		OutputDebugString(TEXT("Create D3d Error..."));
		return;
	}
	D3DDISPLAYMODE d3ddm;											//显示模式 结构体
	ZeroMemory(&d3ddm, sizeof(d3ddm));
	m_pD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);

	D3DPRESENT_PARAMETERS d3dpp;									//设备能力 结构体
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.EnableAutoDepthStencil = TRUE;

	m_pD3d->CreateDevice(											//创建设备指针
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		EngineWindow::GetSingletonPtr()->getHWnd(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pDevice);
	if (!m_pDevice)
	{
		OutputDebugString(TEXT("Create D3dDevice Error..."));
		return;
	}

	D3DXCreateSprite(m_pDevice, &m_pSprite);

	//----初始渲染状态----
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);				//是否开启光照运算
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);					//
	//m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);	//线框模式渲染
	m_pDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);			//
	m_pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);		//
}

void EngineDirect::onBeginRender()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 123, 123, 123), 1.0f, 0);
	m_pDevice->BeginScene();
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void EngineDirect::onEndRender()
{
	m_pSprite->End();
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}

void EngineDirect::onExit()
{
	Safe_Release(m_pSprite);
	Safe_Release(m_pDevice);
	Safe_Release(m_pD3d);
}
