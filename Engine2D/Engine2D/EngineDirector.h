#ifndef EngineDirector_H_
#define EngineDirector_H_
#pragma once
#include "Engine2D.h"
class EngineDirector : public Singleton<EngineDirector>		//Director��Ϊ����ģʽ ģ��Cocos2d ���𳡾�����
{
protected:
	//��ǰ���еĳ������ڵ�
	EngineNode * m_pCurrentSceneNode;
public:
	EngineDirector();
	~EngineDirector();
	
	void Run();												//��ʼִ��ѭ��
	
	void onInit();											//��ʼ��
	void onLogic(float fElapsedTime);						//�߼�
	void onRender(float fElapsedTime);						//��Ⱦ
	void onExit();											//�˳�
	void RunWithScene(EngineScene * _pScene);
};

#endif