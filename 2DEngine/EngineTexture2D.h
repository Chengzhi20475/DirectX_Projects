#ifndef EngineTexture2D_H_
#define EngineTexture2D_H_
#pragma once
#include "Utility.h"
#include "EngineDirect.h"
class EngineTexture2D
{
protected:
	LPDIRECT3DTEXTURE9 m_pTexture;		//Direct Texture指针
	D3DXIMAGE_INFO m_ImageInfo;			//图像内容描述 结构体
	Size m_Size;						//图片大小
	RECT m_Rect;						//矩形区域
public:
	EngineTexture2D();
	~EngineTexture2D();

	static EngineTexture2D * Create(LPCTSTR _pfileName);

	bool initWithFile(LPCTSTR _pfileName);

	LPDIRECT3DTEXTURE9 GetTexture()const { return m_pTexture; }

	Size getContentSize()const { return m_Size; }

	STRING getImageType();
};

#endif