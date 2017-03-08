#include "EngineScene.h"



EngineScene::EngineScene()
{
}


EngineScene::~EngineScene()
{
	OutputDebugString(TEXT("EngineScene::~EngineScene() Called...\n"));
}

EngineScene * EngineScene::Create()
{
	EngineScene * pScene = new EngineScene();
	if (pScene && pScene->onInit())
	{
		OutputDebugString(TEXT("EngineScene::Create() Called...\n"));
	}
	else
		Safe_Delete(pScene);

	return pScene;
}

bool EngineScene::onInit()
{
	if (!EngineNode::onInit())
		return false;

	OutputDebugString(TEXT("EngineScene::onInit() Called...\n"));

	return true;
}
