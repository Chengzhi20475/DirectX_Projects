#ifndef EngineNode_H_
#define EngineNode_H_
#pragma once
#include "Utility.h"
/*
	Vector3 x (x������) y (y������) z (z������  ������Ϊ���ֵ zOrder)
*/
class EngineNode
{
protected:
	EngineNode * m_pParent;						//��ǰ�ڵ�ĸ��ڵ�
	std::vector<EngineNode *> m_vChildren;		//�ӽڵ�����

	bool m_bIsUpdate;							//�Ƿ����

	D3DXVECTOR3 m_vWorldPos;					//��ǰ�ڵ����������

	D3DXVECTOR3 m_vLocalPos;					//����ڸ��ڵ������
	D3DXVECTOR3 m_vLocalRota;					//����ڸ��ڵ����ת
	D3DXVECTOR3 m_vLocalScale;					//����ڸ��ڵ������

	D3DXMATRIX m_matWorld;						//�������任
	D3DXMATRIX m_matLocal;						//�������任
	D3DXMATRIX m_matIdentity;					//��λ����


public:
	EngineNode();
	virtual ~EngineNode();

	EngineNode * getParent()const { return m_pParent; }										//��ȡ���ڵ�
	void setParent(EngineNode * _Parent) { m_pParent = _Parent; }							//���ø��ڵ�

	std::vector<EngineNode *> & getChildren() { return m_vChildren; }						//��ȡ�ӽڵ�����

	void addChild(EngineNode * _node)
	{
		if (_node)
		{
			m_vChildren.push_back(_node);													//�����ڵ���Ϊ��ǰ�ڵ�������
			_node->setParent(this);															//��ǰ�ڵ���Ϊ�����ڵ�ĸ�����
		}
	}

	bool getIsUpdate() { return m_bIsUpdate; }
	void setUpdate(bool _update) { m_bIsUpdate = _update; }

	D3DXVECTOR3 getLocalPos()const { return m_vLocalPos; }
	void setLocalPos(D3DXVECTOR3 _vPos) { m_vLocalPos = _vPos; }

	D3DXVECTOR3 getLocalRota()const { return m_vLocalRota; }
	void setLocalRota(D3DXVECTOR3 _vRota) { m_vLocalRota = _vRota; }

	D3DXVECTOR3 getLocalScale()const { return m_vLocalScale; }
	void setLocalScale(D3DXVECTOR3 _vScale) { m_vLocalScale = _vScale; }

	D3DXMATRIX getWorldMatrix() { return m_matWorld; }
	D3DXVECTOR3 getWorldPos() { return m_vWorldPos; }

	static EngineNode * Create();	//����
	virtual bool onInit();			//��ʼ��
	virtual void onVisit();			//�������ͽṹ
	virtual void onUpdate();			//����
	virtual void onRender();			//��Ⱦ
	virtual void onExit();			//����
	virtual Size getContentSize();  //��ȡʵ�ʳߴ�

	void scheduleUpdate() { m_bIsUpdate = true; };		//���õ��ȣ��ñ����update������ʼִ��
	void unScheduleUpdate() { m_bIsUpdate = false; };	//ֹͣ���ȣ����������update��������
};

#endif