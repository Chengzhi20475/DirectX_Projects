#ifndef EngineScene_H_
#define EngineScene_H_
#pragma once
#include "EngineNode.h"
class EngineScene	: public EngineNode
{
public:
	EngineScene();
	virtual ~EngineScene();
	static EngineScene * Create();
	virtual bool onInit();

};

#endif