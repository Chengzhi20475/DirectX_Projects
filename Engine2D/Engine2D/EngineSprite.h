#ifndef EngineSprite_H_
#define EngineSprite_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
#include "EngineTexture2D.h"
#include "EngineTextureCache.h"
#include "EngineDirect.h"
class EngineSprite	: public EngineNode
{
protected:
	EngineTexture2D * m_pTexture2D;		//
public:
	EngineSprite();
	virtual ~EngineSprite();

	static EngineSprite * Create();
	static EngineSprite * CreateWithFileName();
	virtual bool onInit();
	bool initWithFileName();
	virtual Size getContentSize();

};

#endif