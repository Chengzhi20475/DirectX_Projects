#ifndef EngineDirector_H_
#define EngineDirector_H_
#pragma once
#include "Utility.h"
#include "Camera.h"
#include "Test.h"
class EngineDirector : public Singleton<EngineDirector>
{
private:
	Camera * m_pCamera;
	Test * m_pTest;
	Test * m_pTest1;
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