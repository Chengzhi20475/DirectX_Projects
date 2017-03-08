#ifndef EngineTextureCache_H_
#define EngineTextureCache_H_
#pragma once
#include "Utility.h"
#include "EngineTexture2D.h"
class EngineTextureCache : public Singleton<EngineTextureCache>
{
protected:
	std::map<STRING, EngineTexture2D *> m_TextureCache;
public:
	EngineTextureCache();
	~EngineTextureCache();

	//�����������ͼƬ
	EngineTexture2D * addImage(LPCTSTR _pfileName);
	//�������з���ͼƬ
	EngineTexture2D * textureForKey(STRING _name);
};

#endif