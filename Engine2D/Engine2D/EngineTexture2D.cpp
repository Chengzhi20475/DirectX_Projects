#include "EngineTexture2D.h"



EngineTexture2D::EngineTexture2D()
{
	m_pTexture = NULL;
	ZeroMemory(&m_ImageInfo, sizeof(m_ImageInfo));
	ZeroMemory(&m_Size, sizeof(Size));
	ZeroMemory(&m_Rect, sizeof(RECT));
}


EngineTexture2D::~EngineTexture2D()
{
}

EngineTexture2D * EngineTexture2D::Create(LPCTSTR _pfileName)
{
	EngineTexture2D * pTexture2D = new EngineTexture2D();
	if (pTexture2D && pTexture2D->initWithFile(_pfileName))
	{
		return pTexture2D;
	}
	else
	{
		Safe_Delete(pTexture2D);
		return NULL;
	}
}

bool EngineTexture2D::initWithFile(LPCTSTR _pfileName)
{
	if (!_pfileName)
	{
		return false;
	}
	else
	{
		D3DXCreateTextureFromFileEx(
			EngineDirect::GetSingletonPtr()->GetD3dDevice(),
			_pfileName, D3DX_FROM_FILE, D3DX_FROM_FILE, 0,
			0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
			D3DX_FILTER_LINEAR, D3DX_FILTER_LINEAR,
			D3DCOLOR_XRGB(255, 255, 255), &m_ImageInfo, NULL,
			&m_pTexture);

		if (m_pTexture)
		{
			m_Size = Size(m_ImageInfo.Width, m_ImageInfo.Height);
		}
	}
	return true;
}
//获取图片类型
STRING EngineTexture2D::getImageType()
{
	switch (m_ImageInfo.ImageFileFormat)
	{
	case D3DXIFF_PNG:
		return TEXT("PNG");
	case D3DXIFF_JPG:
		return TEXT("JPG");
	case D3DXIFF_DDS:
		return TEXT("DDS");
	case D3DXIFF_BMP:
		return TEXT("BMP");
	default:
		return TEXT("UNKNOW");
	}
}
