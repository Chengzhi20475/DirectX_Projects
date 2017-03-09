#ifndef GameLayer_H_
#define GameLayer_H_
#pragma once
#include "Engine2D.h"
#include "ObjectTeapot.h"
class GameLayer : public EngineLayer
{
public:
	ObjectTeapot * m_pTeapot;
	ObjectTeapot * m_pTeapotChild;
public:
	GameLayer();
	~GameLayer();
	static GameLayer * Create();
	static EngineScene * Scene();
	virtual bool onInit();
	virtual void onUpdate();
};

#endif
