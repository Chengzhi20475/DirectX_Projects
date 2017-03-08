#include "EngineTextureCache.h"



EngineTextureCache::EngineTextureCache()
{
}


EngineTextureCache::~EngineTextureCache()
{
}

EngineTexture2D * EngineTextureCache::addImage(LPCTSTR _pfileName)
{
	//-----处理键值对儿当中的key-----
	LPCTSTR pStart = STRRCHR(_pfileName, TEXT('\\'));			//
	LPCTSTR pEnd = STRRCHR(pStart, TEXT('.'));
	TCHAR str[50] = {};
	MEMCPY(str, pStart + 1, pEnd - pStart - 1);
	STRING nameKey = str;

	//-----处理键值对而当中的value-----
	EngineTexture2D * pTexture2D = EngineTexture2D::Create(_pfileName);

	//-----向容器中添加元素-----
	m_TextureCache.insert(make_pair(nameKey, pTexture2D));

	return pTexture2D;
}

EngineTexture2D * EngineTextureCache::textureForKey(STRING _name)
{
	EngineTexture2D * pResult = NULL;
	std::map<STRING, EngineTexture2D*>::iterator iter;

	iter = m_TextureCache.find(_name);
	pResult = iter->second;

	return pResult;
}
