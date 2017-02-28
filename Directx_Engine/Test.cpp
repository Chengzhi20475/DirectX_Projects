#include "Test.h"
#include "MainDirect.h"


Test::Test()
{
	m_pTeapot = NULL;
	ZeroMemory(&m_matTeapot, sizeof(D3DMATERIAL9));
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

	m_matTeapot.Diffuse.r = 1.0f;	//红色全反射
	m_matTeapot.Diffuse.g = 1.0f;	//绿色全反射
	m_matTeapot.Diffuse.b = 1.0f;	//蓝色全反射
	m_matTeapot.Diffuse.a = 1.0f;

	m_matTeapot.Specular.r = 1.0f;	//红色全反射
	m_matTeapot.Specular.g = 1.0f;	//绿色全反射
	m_matTeapot.Specular.b = 1.0f;	//蓝色全反射
	m_matTeapot.Specular.a = 1.0f;
	m_matTeapot.Power = 0.2f;		//越大，高光区域越小

	MainDirect::GetSingletonPtr()->getD3dDevice()->SetMaterial(&m_matTeapot);

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
