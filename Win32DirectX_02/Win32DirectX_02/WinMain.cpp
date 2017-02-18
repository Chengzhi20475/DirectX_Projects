#include "Utility.h"

HWND g_hWnd = NULL;													//���ھ��
HINSTANCE g_hInstance = NULL;										//ʵ�����

//////////////////////////////////////////////////////////////////////////
LPDIRECT3D9 g_pD3D = NULL;											//D3D	�ӿ�ָ��
LPDIRECT3DDEVICE9 g_pD3Ddevice9 = NULL;								//D3D device	�豸ָ��

//////////////////////////////////////////////////////////////////////////

void onInitD3D()													//��ʼ��D3D���л���
{
	//����D3D�ӿ�ָ��
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//�ݴ�
	if (!g_pD3D)													//�����ж� �Ƿ񴴽��ɹ�
	{																//����ʧ�ܣ�����MessageBox��ʾ��
		MessageBox(NULL, TEXT("Create D3D Error"), TEXT("Error"), MB_OK);
		return;
	}
	//D3DDISPLAYMODE�ṹ��    ������ȡ�Կ�����ʾģʽ
	D3DDISPLAYMODE d3ddm;
	ZeroMemory(&d3ddm, sizeof(d3ddm));
	//��ȡ��ʾģʽ����
	g_pD3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,											//Ĭ����ʾģʽ
		&d3ddm);													//��ȡ�����Կ���Ϣ ���ݸ�D3DDISPLAYMODE d3ddm
	//D3DPRESENT_PARAMETERS�ṹ��	�����豸����
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferCount = 1;					//��̨����������
	d3dpp.BackBufferFormat = d3ddm.Format;		//��̨������ÿ���ظ�ʽ
	d3dpp.Windowed = TRUE;						//�Ƿ�Ϊ����ģʽ  (true = ���ڣ�false = ȫ��)
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	//ǰ��̨��תģʽ discard ��������  ������
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	//�Զ����ģ�建���ʽ
	d3dpp.EnableAutoDepthStencil = TRUE;		//�Ƿ������Զ����ģ�建��

	//�����豸ָ��g_pD3Ddevice9
	g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,						//Ĭ���Կ�
		D3DDEVTYPE_HAL,							//Ӳ�������
		g_hWnd,									//�����ĸ�������ʾ
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,	//��������	������Ϣ���������
		&d3dpp,
		&g_pD3Ddevice9);						//�����豸ָ��

	if (!g_pD3Ddevice9)												//�����ж� �Ƿ񴴽��ɹ�
	{																//����ʧ�ܣ�����MessageBox��ʾ��
		MessageBox(NULL, TEXT("Create D3Ddevice Error"), TEXT("Error"), MB_OK);
		return;
	}

	//ͨ���豸ָ��������Ⱦ״̬
	g_pD3Ddevice9->SetRenderState(D3DRS_ZENABLE, TRUE);					//������Ȼ�����
	g_pD3Ddevice9->SetRenderState(D3DRS_LIGHTING, FALSE);				//ֹͣ��������
	g_pD3Ddevice9->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);	//�߿�ģʽ��Ⱦ
}

void onLogic()
{

}

void onRender()
{
	g_pD3Ddevice9->Clear(
		0,											//��ռ�������
		NULL,										//���ε��ٽ���Ϣ  (ǰ�������� ȷ�������������)
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,			//��ձ�ʶ����ɫ����Ȼ�����
		D3DCOLOR_XRGB(123,123,234),					//��ɫ��������ʼֵ
		1.0f,										//��Ȼ�������ʼֵ
		0);											//ģ�建������ʼֵ

	g_pD3Ddevice9->BeginScene();					//begin






	g_pD3Ddevice9->EndScene();						//end	
	g_pD3Ddevice9->Present(NULL, NULL, NULL, NULL);	//ǰ��ת��Դ���� ִ�д˺��� �Żᴥ��ǰ��̨�Ľ���
}


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);				//��Ϣ������ ����

INT WINAPI WinMain(_In_ HINSTANCE hInstance,						//��ں���
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{

	WNDCLASS wc;													//WNDCLASS ������
	ZeroMemory(&wc, sizeof(wc));									//�ṹ�� ����ڴ�
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("DirectX");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	RegisterClass(&wc);												//ע��WNDCLASS��

	g_hWnd = CreateWindow(wc.lpszClassName,							//��������
		TEXT("DirectX_01"), WS_OVERLAPPEDWINDOW,
		300, 200,
		800, 600,
		NULL, NULL,
		hInstance, NULL);

	if (g_hWnd)														//�ݴ�
	{
		ShowWindow(g_hWnd, SW_SHOWNORMAL);							//��ʾ����
		UpdateWindow(g_hWnd);										//���´���

		onInitD3D();												//��ʼ��D3D

		MSG msg;													//��Ϣ�ṹ��
		ZeroMemory(&msg, sizeof(msg));								
			
		while (msg.message != WM_QUIT)								//��Ϣ����
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))			//�ɷ���Ϣ
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				onLogic();
				onRender();
			}
		}
	}
	else
	{
		MessageBox(NULL, TEXT("Create Window Error"), TEXT("Error"), MB_OK);
	}

	UnregisterClass(wc.lpszClassName, hInstance);					//���ע��

	return 0;
}

LRESULT CALLBACK WndProc(HWND _hWnd, UINT _uMsg, WPARAM _wParm, LPARAM _lParm)
{
	switch (_uMsg)													//��Ϣ����
	{
	case WM_KEYDOWN:
	{
		if (_wParm == VK_ESCAPE)
		{
			int Value = MessageBox(_hWnd, TEXT("Quit Window?"), TEXT("Message"), MB_YESNO);
			if (IDYES == Value)
				DestroyWindow(_hWnd);
		}
	}
	break;
	case WM_CLOSE:
		DestroyWindow(_hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(NULL);
		break;
	}

	return DefWindowProc(_hWnd, _uMsg, _wParm, _lParm);
}