#include "ObjectTeapot.h"



ObjectTeapot::ObjectTeapot()
{
	m_pTeapot = NULL;
	ZeroMemory(&m_matTeapot, sizeof(D3DMATERIAL9));
}


ObjectTeapot::~ObjectTeapot()
{
}

ObjectTeapot * ObjectTeapot::Create()
{
	ObjectTeapot * pObjectTeapot = new ObjectTeapot();
	if (pObjectTeapot && pObjectTeapot->onInit())
	{

	}
	else
	{
		Safe_Delete(pObjectTeapot);
	}
	return pObjectTeapot;
}

bool ObjectTeapot::onInit()
{
	if (!EngineNode::onInit())
		return false;

	D3DXCreateTeapot(
		EngineDirect::GetSingletonPtr()->GetD3dDevice(),
		&m_pTeapot, NULL);

	return true;
}

void ObjectTeapot::onRender()
{
	EngineDirect::GetSingletonPtr()->GetD3dDevice()->SetTransform(D3DTS_WORLD, &m_matWorld);
	m_pTeapot->DrawSubset(0);
	EngineDirect::GetSingletonPtr()->GetD3dDevice()->SetTransform(D3DTS_WORLD, &m_matIdentity);
}

