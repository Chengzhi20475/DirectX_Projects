#include "EngineLayer.h"



EngineLayer::EngineLayer()
{
}


EngineLayer::~EngineLayer()
{
	OutputDebugString(TEXT("EngineLayer::~EngineLayer() Called...\n"));
}

EngineLayer * EngineLayer::Create()
{
	EngineLayer * pLayer = new EngineLayer();
	if (pLayer && pLayer->onInit())
	{
		OutputDebugString(TEXT("EngineLayer::Create() Called...\n"));
	}
	else
		Safe_Delete(pLayer);

	return pLayer;
}

bool EngineLayer::onInit()
{
	if (!EngineNode::onInit())
		return false;

	OutputDebugString(TEXT("EngineLayer::onInit() Called...\n"));
	return true;
}
