#ifndef ObjectTeapot_H_
#define ObjectTeapot_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
#include "EngineDirect.h"
class ObjectTeapot : public EngineNode
{
private:
	LPD3DXMESH m_pTeapot;
	D3DMATERIAL9 m_matTeapot;
public:
	ObjectTeapot();
	~ObjectTeapot();
	static ObjectTeapot * Create();
	virtual bool onInit();
	virtual void onRender();
};

#endif