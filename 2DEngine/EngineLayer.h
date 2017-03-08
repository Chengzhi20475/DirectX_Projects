#ifndef EngineLayer_H_
#define EngineLayer_H_
#pragma once
#include "EngineNode.h"
class EngineLayer	: public EngineNode
{
public:
	EngineLayer();
	virtual ~EngineLayer();

	static EngineLayer * Create();
	virtual bool onInit();
};

#endif