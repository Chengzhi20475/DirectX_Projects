#include "EngineSprite.h"



EngineSprite::EngineSprite()
{
}


EngineSprite::~EngineSprite()
{
	OutputDebugString(TEXT("EngineSprite::~EngineSprite() Called...\n"));
}

EngineSprite * EngineSprite::Create()
{
	EngineSprite * pSprite = new EngineSprite();
	if (pSprite && pSprite->onInit())
	{
		OutputDebugString(TEXT("EngineSprite::create() Called...\n"));
	}
	else
	{
		Safe_Delete(pSprite);
	}
	return pSprite;
}

EngineSprite * EngineSprite::CreateWithFileName(LPCTSTR _fileName)
{
	EngineSprite * pSprite = new EngineSprite();
	if (pSprite && pSprite->initWithFileName(_fileName))
	{
		OutputDebugString(TEXT("EngineSprite::CreateWithFileName() Called...\n"));
	}
	else
	{
		Safe_Delete(pSprite);
	}
	return pSprite;
}

bool EngineSprite::onInit()
{
	if (!EngineNode::onInit())
		return false;

	OutputDebugString(TEXT("EngineSprite::onInit() Called...\n"));

	return true;
}

bool EngineSprite::initWithFileName(LPCTSTR _fileName)
{
	if (!EngineNode::onInit())
		return false;

	m_pTexture2D = EngineTextureCache::GetSingletonPtr()->addImage(_fileName);
	OutputDebugString(TEXT("EngineSprite::initWithFileName() Called... \n"));

	return true;
}

Size EngineSprite::getContentSize()
{
	return m_pTexture2D->getContentSize();
}

void EngineSprite::onRender()
{
	EngineDirect::GetSingletonPtr()->GetSprite()->Draw(
		m_pTexture2D->GetTexture(), NULL,
		&D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0),
		D3DCOLOR_XRGB(255, 255, 255));
}
