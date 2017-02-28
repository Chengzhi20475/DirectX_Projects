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
	case Light_Directional://Æ½ÐÐ¹â
		m_Light.Type = D3DLIGHT_DIRECTIONAL;
		m_Light.Diffuse.r = 1.0f;
		m_Light.Diffuse.g = m_Light.Diffuse.b = m_Light.Diffuse.a = 0.0f;
		m_Light.Specular.r = m_Light.Specular.g = m_Light.Specular.b = m_Light.Specular.a = 1.0f;
		m_Light.Ambient.r = m_Light.Ambient.g = m_Light.Ambient.b = m_Light.Ambient.a = 0.0f;
		m_Light.Direction = D3DXVECTOR3(-1, -1, 0);
		break;
	case Light_Point:
		m_Light.Type = D3DLIGHT_POINT;
		m_Light.Diffuse.r = 0.0f;
		m_Light.Diffuse.g = 1.0f;
		m_Light.Diffuse.b = m_Light.Diffuse.a = 0.0f;
		m_Light.Specular.r = m_Light.Specular.g = m_Light.Specular.b = m_Light.Specular.a = 0.0f;
		m_Light.Ambient.r = m_Light.Ambient.g = m_Light.Ambient.b = m_Light.Ambient.a = 0.0f;

		m_Light.Position = D3DXVECTOR3(0, 5, 0);
		m_Light.Range = 8.0f;
		m_Light.Attenuation0 = 0.1f;
		break;
	case Light_Spot:
		m_Light.Type = D3DLIGHT_SPOT;
		m_Light.Diffuse.r = m_Light.Diffuse.r = 0.0f;
		m_Light.Diffuse.b = m_Light.Diffuse.a = 1.0f;
		m_Light.Specular.r = m_Light.Specular.g = m_Light.Specular.b = m_Light.Specular.a = 0.0f;
		m_Light.Ambient.r = m_Light.Ambient.g = m_Light.Ambient.b = m_Light.Ambient.a = 0.0f;

		m_Light.Position = D3DXVECTOR3(0, 0, -3);
		m_Light.Direction = D3DXVECTOR3(0, 0, 1);
		m_Light.Theta = D3DX_PI / 6;
		m_Light.Phi = D3DX_PI / 4;
		m_Light.Range = 10.0f;
		m_Light.Attenuation0 = 0.1f;
		m_Light.Falloff = 0.1f;
		break;
	default:
		break;
	}


	return true;
}
