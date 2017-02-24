#ifndef EngineDirector_H_
#define EngineDirector_H_
#pragma once
#include "Utility.h"

class EngineDirector : public Singleton<EngineDirector>
{
public:
	EngineDirector();
	~EngineDirector();

	void Run();
	void onInit();
	void onLogic(float fElapsedTime);
	void onRender(float fElapsedTime);
	void onExit();
};

#endif