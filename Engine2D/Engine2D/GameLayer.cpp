#include "GameLayer.h"



GameLayer::GameLayer()
{
}


GameLayer::~GameLayer()
{
	OutputDebugString(TEXT("GameLayer::~GameLayer() Called...\n"));
}

GameLayer * GameLayer::Create()
{
	GameLayer * pGameLayer = new GameLayer();
	if (pGameLayer && pGameLayer->onInit())
	{
		OutputDebugString(TEXT("GameLayer::Create() Called...\n"));
	}
	else
	{
		Safe_Delete(pGameLayer);
	}
	return pGameLayer;
}

EngineScene * GameLayer::Scene()
{
	EngineScene * pScene = NULL;

	pScene = EngineScene::Create();

	GameLayer * pLayer = GameLayer::Create();

	pScene->addChild(pLayer);

	return pScene;
}

bool GameLayer::onInit()
{
	if (!EngineLayer::onInit())
		return false;

	/*EngineSprite *pBg = EngineSprite::CreateWithFileName(TEXT("res\\BG.png"));
	Size sizebg = pBg->getContentSize();
	this->addChild(pBg);*/




	return true;
}
