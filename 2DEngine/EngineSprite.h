#ifndef EngineSprite_H_
#define EngineSprite_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
#include "EngineTexture2D.h"
#include "EngineTextureCache.h"
#include "EngineDirect.h"

class EngineSprite : public EngineNode
{
public:
	EngineTexture2D* m_pTexture2D;
public:
	EngineSprite();
	virtual ~EngineSprite();

	static EngineSprite * Create();
	static EngineSprite * CreateWithFileName(LPCTSTR _fileName);
	virtual bool onInit();
	bool initWithFileName(LPCTSTR _fileName);
	virtual Size getContentSize();
	virtual void onRender();

};

#endif