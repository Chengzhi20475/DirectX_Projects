#ifndef GameLayer_H_
#define GameLayer_H_
#pragma once
#include "Engine2D.h"
class GameLayer : public EngineLayer
{
public:
	GameLayer();
	~GameLayer();
	static GameLayer * Create();
	static EngineScene * Scene();
	virtual bool onInit();
};

#endif
