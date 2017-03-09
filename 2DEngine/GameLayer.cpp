#include "GameLayer.h"



GameLayer::GameLayer()
{
	m_pTeapot = NULL;
	m_pTeapotChild = NULL;
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

	m_pTeapot = ObjectTeapot::Create();
	m_pTeapot->setLocalPos(D3DXVECTOR3(0, 0, 0));
	this->addChild(m_pTeapot);

	m_pTeapotChild = ObjectTeapot::Create();
	m_pTeapotChild->setLocalPos(D3DXVECTOR3(4, 0, 0));
	m_pTeapot->addChild(m_pTeapotChild);
	this->setUpdate(true);

	return true;
}

void GameLayer::onUpdate()
{
	static float fangle = 0.0f;
	fangle += 0.05f;
	m_pTeapot->setLocalRota(D3DXVECTOR3(0,fangle, 0));
	m_pTeapotChild->setLocalRota(D3DXVECTOR3(0, fangle, 0));
}
