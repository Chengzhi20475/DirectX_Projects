#ifndef EngineNode_H_
#define EngineNode_H_
#pragma once
#include "Utility.h"
class EngineNode
{
private:
	EngineNode * m_pParent;						//当前节点的父节点
	std::vector<EngineNode *> m_vChildren;		//子节点容器

	bool m_bIsUpdate;							//是否更新

	D3DXVECTOR3 m_vWorldPos;					//当前节点的世界坐标

	D3DXVECTOR3 m_vLocalPos;					//相对于父节点的坐标
	D3DXVECTOR3 m_vLocalRota;					//相对于父节点的旋转
	D3DXVECTOR3 m_vLocalScale;					//相对于父节点的缩放

	D3DXMATRIX m_matWorld;						//世界矩阵变换
	D3DXMATRIX m_matLocal;						//自身矩阵变换
	D3DXMATRIX m_matIdentity;					//单位矩阵


public:
	EngineNode();
	~EngineNode();

	EngineNode * getParent()const { return m_pParent; }										//获取父节点
	void setParent(EngineNode * _Parent) { m_pParent = _Parent; }							//设置父节点

	std::vector<EngineNode *> & getChildren() { return m_vChildren; }						//获取子节点容器
	void addChild(EngineNode * _node)
	{
		if (_node)
		{
			m_vChildren.push_back(_node);													//参数节点作为当前节点子物体
			_node->setParent(this);															//当前节点作为参数节点的父物体
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

	static EngineNode * Create();	//创建函数
	virtual bool Init();			//初始化函数
	virtual void Visit();			//遍历树型结构函数
	virtual void Update();			//更新函数
	virtual void Render();			//渲染函数
	virtual void Exit();			//销毁函数

	void scheduleUpdate() { m_bIsUpdate = true; };		//启用调度，让本类的update函数开始执行
	void unScheduleUpdate() { m_bIsUpdate = false; };	//停止调度，结束本类的update函数调用

};

#endif