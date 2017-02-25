#include "Test.h"
#include "MainDirect.h"


Test::Test()
{
	m_pTeapot = NULL;
}


Test::~Test()
{
	Safe_Release(m_pTeapot);
}

Test * Test::Create()
{
	Test * pTest = new Test();
	if (pTest && pTest->Init())
	{
	}
	else
	{
		Safe_Delete(pTest);
	}
	return pTest;
}

bool Test::Init()
{
	if (!EngineNode::Init())
		return false;

	D3DXCreateTeapot(
		MainDirect::GetSingletonPtr()->getD3dDevice(),
		&m_pTeapot, NULL);

	return true;
}

void Test::Render()
{
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_WORLD, &m_matWorld);
	m_pTeapot->DrawSubset(0);
	MainDirect::GetSingletonPtr()->getD3dDevice()->SetTransform(D3DTS_WORLD, &m_matIdentity);
}
