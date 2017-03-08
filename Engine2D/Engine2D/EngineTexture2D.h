#ifndef EngineTexture2D_H_
#define EngineTexture2D_H_
#pragma once
#include "Engine2D.h"
class EngineTexture2D
{
protected:
	LPDIRECT3DTEXTURE9 m_pTexture;		//Direct Textureָ��
	D3DXIMAGE_INFO m_ImageInfo;			//ͼ���������� �ṹ��
	Size m_Size;						//ͼƬ��С
	RECT m_Rect;						//��������
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