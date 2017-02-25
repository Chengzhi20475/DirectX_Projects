#include "Utility.h"
#include "EngineDirector.h"

INT WINAPI WinMain(__in HINSTANCE hInstance,
	__in_opt HINSTANCE hPrevInstance,
	__in_opt LPSTR lpCmdLine,
	__in int nShowCmd)
{
	EngineDirector::GetSingletonPtr()->Run();
	return 0;
}