#include "EngineLight.h"



EngineLight::EngineLight()
{
	m_Type = Light_Nothing;
	ZeroMemory(&m_Light, sizeof(D3DLIGHT9));
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
	if (!EngineNode::Init())
		return false;

	return true;
}

EngineLight * EngineLight::CreateWithLightType(LightType _type)
{
	EngineLight * pLightType = new EngineLight();
	if (pLightType && pLightType->InitWithLightType(_type))
	{

	}
	else
		Safe_Delete(pLightType);

	return pLightType;
}

bool EngineLight::InitWithLightType(LightType _type)
{
	if (!EngineNode::Init())
		return false;

	switch (_type)
	{
	case Light_Nothing:
		MessageBox(NULL, TEXT("Light type Nothing"), TEXT("Create Light Error..."), MB_OK);
		break;
	case Light_Directional:

		break;
	case Light_Point:
		break;
	case Light_Spot:
		break;
	default:
		break;
	}


	return true;
}

void EngineLight::Render()
{

}

