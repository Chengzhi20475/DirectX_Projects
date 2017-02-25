#include "MainDirect.h"
#include "MainWindow.h"


MainDirect::MainDirect()
{
	m_pD3d = NULL;
	m_pDevice = NULL;
}


MainDirect::~MainDirect()
{
}

void MainDirect::onInit()
{
	m_pD3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!m_pD3d)
	{
		OutputDebugString(TEXT("Create D3d Error..."));
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
		OutputDebugString(TEXT("Create D3dDevice Error..."));
		return;
	}
	//----��ʼ��Ⱦ״̬----
	m_pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);				//�Ƿ�����������
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);					//
	//m_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);	//�߿�ģʽ��Ⱦ
	m_pDevice->SetRenderState(D3DRS_SPECULARENABLE, TRUE);			//
	m_pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);		//
	//---����ģ��---
	//������ɫ�ܺ� = ���巴�价���� + ���巴��������� + ���巴�侵�淴��� + �Է���
	//������Ļ�ϵ�����  ���������ֹ�Ӱ��
	//�����������ɫ�Ǽ�����������ɫ֮�� ���ڸ���RGB�������ӵ�ֵ���ܻᳬ��1 �����Ⱦʱ��Ҫ��������ɫѹ����[0-1]֮�� ��� ���ܻ������ɫƫ��
}

void MainDirect::onBeginRender()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_ARGB(255, 123, 123, 123), 1.0f, 0);
	m_pDevice->BeginScene();
}

void MainDirect::onEndRender()
{
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, NULL, NULL);
}

void MainDirect::onExit()
{


	Safe_Release(m_pDevice);
	Safe_Release(m_pD3d);
}
