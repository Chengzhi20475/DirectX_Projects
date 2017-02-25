#include "EngineLight.h"



EngineLight::EngineLight()
{
	m_type = Light_Nothing;
}


EngineLight::~EngineLight()
{
}

EngineLight * EngineLight::Create()
{
	EngineLight * pEngineLight = new EngineLight();
	if (pEngineLight && pEngineLight->Init())
	{
		
	}
	else
		Safe_Delete(pEngineLight);

	return pEngineLight;
}

bool EngineLight::Init()
{
	return true;
}

void EngineLight::Render()
{

}
