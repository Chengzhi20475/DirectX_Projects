#ifndef EngineDirector_H_
#define EngineDirector_H_
#pragma once
#include "Engine2D.h"
#include "GameLayer.h"
class EngineDirector : public Singleton<EngineDirector>		//Director类为单利模式 模仿Cocos2d 负责场景调度
{
protected:
	//当前运行的场景根节点
	EngineNode * m_pCurrentSceneNode;
public:
	EngineDirector();
	~EngineDirector();
	
	void Run();												//开始执行循环
	
	void onInit();											//初始化
	void onLogic(float fElapsedTime);						//逻辑
	void onRender(float fElapsedTime);						//渲染
	void onExit();											//退出
	void RunWithScene(EngineScene * _pScene);
};

#endif