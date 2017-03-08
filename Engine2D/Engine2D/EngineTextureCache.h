#ifndef EngineTextureCache_H_
#define EngineTextureCache_H_
#pragma once
#include "EngineTexture2D.h"
class EngineTextureCache : public Singleton<EngineTextureCache>
{
protected:
	std::map<STRING, EngineTexture2D *> m_TextureCache;
public:
	EngineTextureCache();
	~EngineTextureCache();

	//向容器里添加图片
	EngineTexture2D * addImage(LPCTSTR _pfileName);
	//从容器中访问图片
	EngineTexture2D * textureForKey(STRING _name);
};

#endif