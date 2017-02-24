#include "MainDirect.h"
#include "MainWindow.h"


MainDirect::MainDirect()
{
	m_pD3d = NULL;
	m_pDevice = NULL;
	m_pCamera = NULL;
	m_pFont = NULL;
	m_pFontRect = NULL;
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
	//----��ʼ��Ⱦ״̬----
	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	////----�����----
	m_pCamera = Camera::Create();
	m_pCamera->setvEyePt(0.f, 0.f, -10.f);
	m_pCamera->setvLookAt(0.f, 0.f, 0.f);
	m_pCamera->setvUp(0.f, 1.f, 0.f);
	//---------------------------------------------
	onInitFont();



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


	Safe_Release(m_pDevice);
	Safe_Release(m_pD3d);
}

void MainDirect::onInitFont()
{
	//�������庯��
	D3DXCreateFont(
		m_pDevice,			//�豸ָ��
		60,					//����߶�
		0,					//������ ����Ϊ0ʱ  �Զ�ƥ��
		400,				//����Ĵ� (0-1000)
		0,					//�༶����
		false,				//�Ƿ���б б��
		DEFAULT_CHARSET,	//Ĭ�ϲ��� �����ַ���
		0,					//�������
		0,					//�����ȼ�
		0,					//����������Ϣ
		TEXT("΢���ź�"),	//������ʽ
		&m_pFont			//���ص�ָ��
	);

	m_pFontRect = new RECT();
	SetRect(m_pFontRect, 100, 100, 300, 200);

}
