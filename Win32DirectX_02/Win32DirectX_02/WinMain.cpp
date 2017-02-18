#include "Utility.h"

HWND g_hWnd = NULL;													//窗口句柄
HINSTANCE g_hInstance = NULL;										//实例句柄

//////////////////////////////////////////////////////////////////////////
LPDIRECT3D9 g_pD3D = NULL;											//D3D	接口指针
LPDIRECT3DDEVICE9 g_pD3Ddevice9 = NULL;								//D3D device	设备指针

//////////////////////////////////////////////////////////////////////////

void onInitD3D()													//初始化D3D运行环境
{
	//创建D3D接口指针
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//容错
	if (!g_pD3D)													//用来判断 是否创建成功
	{																//创建失败（创建MessageBox提示）
		MessageBox(NULL, TEXT("Create D3D Error"), TEXT("Error"), MB_OK);
		return;
	}
	//D3DDISPLAYMODE结构体    用来获取显卡的显示模式
	D3DDISPLAYMODE d3ddm;
	ZeroMemory(&d3ddm, sizeof(d3ddm));
	//获取显示模式函数
	g_pD3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,											//默认显示模式
		&d3ddm);													//获取到的显卡信息 传递给D3DDISPLAYMODE d3ddm
	//D3DPRESENT_PARAMETERS结构体	描述设备能力
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferCount = 1;					//后台缓冲区个数
	d3dpp.BackBufferFormat = d3ddm.Format;		//后台缓冲区每像素格式
	d3dpp.Windowed = TRUE;						//是否为窗口模式  (true = 窗口，false = 全屏)
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	//前后台翻转模式 discard （丢弃）  交换链
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	//自动深度模板缓冲格式
	d3dpp.EnableAutoDepthStencil = TRUE;		//是否启用自动深度模板缓冲

	//创建设备指针g_pD3Ddevice9
	g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,						//默认显卡
		D3DDEVTYPE_HAL,							//硬件抽象层
		g_hWnd,									//基于哪个窗口显示
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,	//顶点软处理	顶点信息由软件处理
		&d3dpp,
		&g_pD3Ddevice9);						//返回设备指针

	if (!g_pD3Ddevice9)												//用来判断 是否创建成功
	{																//创建失败（创建MessageBox提示）
		MessageBox(NULL, TEXT("Create D3Ddevice Error"), TEXT("Error"), MB_OK);
		return;
	}

	//通过设备指针设置渲染状态
	g_pD3Ddevice9->SetRenderState(D3DRS_ZENABLE, TRUE);					//开启深度缓冲区
	g_pD3Ddevice9->SetRenderState(D3DRS_LIGHTING, FALSE);				//停止光照运算
	g_pD3Ddevice9->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);	//线框模式渲染
}

void onLogic()
{

}

void onRender()
{
	g_pD3Ddevice9->Clear(
		0,											//清空几个矩形
		NULL,										//矩形的临接信息  (前两个参数 确定清空整个窗口)
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,			//清空标识，颜色，深度缓冲区
		D3DCOLOR_XRGB(123,123,234),					//颜色缓冲区初始值
		1.0f,										//深度缓冲区初始值
		0);											//模板缓冲区初始值

	g_pD3Ddevice9->BeginScene();					//begin






	g_pD3Ddevice9->EndScene();						//end	
	g_pD3Ddevice9->Present(NULL, NULL, NULL, NULL);	//前后翻转的源动力 执行此函数 才会触发前后台的交换
}


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);				//消息处理函数 声明

INT WINAPI WinMain(_In_ HINSTANCE hInstance,						//入口函数
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{

	WNDCLASS wc;													//WNDCLASS 窗口类
	ZeroMemory(&wc, sizeof(wc));									//结构体 清空内存
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

	RegisterClass(&wc);												//注册WNDCLASS类

	g_hWnd = CreateWindow(wc.lpszClassName,							//创建窗口
		TEXT("DirectX_01"), WS_OVERLAPPEDWINDOW,
		300, 200,
		800, 600,
		NULL, NULL,
		hInstance, NULL);

	if (g_hWnd)														//容错
	{
		ShowWindow(g_hWnd, SW_SHOWNORMAL);							//显示窗口
		UpdateWindow(g_hWnd);										//更新窗口

		onInitD3D();												//初始化D3D

		MSG msg;													//消息结构体
		ZeroMemory(&msg, sizeof(msg));								
			
		while (msg.message != WM_QUIT)								//消息传递
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))			//派发消息
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

	UnregisterClass(wc.lpszClassName, hInstance);					//解除注册

	return 0;
}

LRESULT CALLBACK WndProc(HWND _hWnd, UINT _uMsg, WPARAM _wParm, LPARAM _lParm)
{
	switch (_uMsg)													//消息处理
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