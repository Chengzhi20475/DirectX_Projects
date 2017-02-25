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
	LightType m_Type;
	D3DLIGHT9 m_Light;
public:
	EngineLight();
	~EngineLight();
	static EngineLight * Create();
	virtual bool Init();

	static EngineLight * CreateWithLightType(LightType _type);
	bool InitWithLightType(LightType _type);

	virtual void Render();

};

#endif