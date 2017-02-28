#ifndef Test_H_
#define Test_H_
#pragma once
#include "Utility.h"
#include "EngineNode.h"
class Test : public EngineNode
{
private:
	LPD3DXMESH m_pTeapot;
	D3DMATERIAL9 m_matTeapot;
public:
	Test();
	~Test();
	static Test * Create();
	virtual bool Init();
	virtual void Render();
};

#endif