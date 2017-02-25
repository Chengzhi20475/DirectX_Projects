#ifndef EngineLight_H_
#define EngineLight_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
enum LightType
{
	Light_Nothing = 0,
	Light_Directional,
	Light_Point,
	Light_Spot
};
class EngineLight :	public EngineNode
{
private:
	LightType m_type;
public:
	EngineLight();
	~EngineLight();
	static EngineLight * Create();
	virtual bool Init();
	virtual void Render();

};

#endif