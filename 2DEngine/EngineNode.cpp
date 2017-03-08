#include "EngineNode.h"



EngineNode::EngineNode()
{
	m_pParent = NULL;

	m_bIsUpdate = false;

	m_vWorldPos = D3DXVECTOR3(0, 0, 0);
	m_vLocalPos = D3DXVECTOR3(0, 0, 0);
	m_vLocalRota = D3DXVECTOR3(0, 0, 0);
	m_vLocalScale = D3DXVECTOR3(1, 1, 1);

	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matLocal);
	D3DXMatrixIdentity(&m_matIdentity); 
}


EngineNode::~EngineNode()
{
	onExit();
	OutputDebugString(TEXT("EngineNode::~EngineNode() Called...\n"));
}

EngineNode * EngineNode::Create()
{
	EngineNode * pNode = new EngineNode();
	if (pNode && pNode->onInit())
	{
		OutputDebugString(TEXT("EngineNode::Create() Called..\n"));
	}
	else
		Safe_Delete(pNode);

	return pNode;
}

bool EngineNode::onInit()
{
	OutputDebugString(TEXT("EngineNode::~onInit() Called...\n"));
	return true;
}

void EngineNode::onVisit()
{
	//当前节点的业务逻辑
	if (getIsUpdate())
		onUpdate();

	//更新当前节点的坐标信息
	//子节点的世界矩阵变换 = 子节点的本地矩阵变换 * 父节点的世界矩阵变换

	//--获取子物体本地的矩阵变换--
	D3DXQUATERNION rota;
	D3DXMATRIX matRota;
	D3DXMatrixRotationYawPitchRoll(&matRota,
		m_vLocalRota.y, m_vLocalRota.x, m_vLocalRota.z);
	D3DXQuaternionRotationMatrix(&rota, &matRota);

	D3DXMatrixTransformation(
		&m_matLocal, &D3DXVECTOR3(0, 0, 0),
		NULL, &m_vLocalScale, &D3DXVECTOR3(0, 0, 0),
		&rota, &m_vLocalPos);

	if (!m_pParent)	//没有父节点
	{
		m_matWorld = m_matLocal;
	}
	else
	{
		this->m_matWorld = this->m_matLocal * m_pParent->getWorldMatrix();
	}


	//渲染
	onRender();

	//遍历可能存在的子物体
	if (m_vChildren.size() > 0)
	{
		for (std::vector<EngineNode *>::iterator iter = m_vChildren.begin();
			iter != m_vChildren.end();++iter)
		{
			(*iter)->onVisit();
		}
	}

}

void EngineNode::onUpdate()
{

}

void EngineNode::onRender()
{

}

void EngineNode::onExit()
{
	//处理当前节点的子节点
	if (m_vChildren.size() > 0)
	{
		for (std::vector<EngineNode *>::iterator iter = m_vChildren.begin();
			iter != m_vChildren.end(); ++iter)
		{
			EngineNode * pTemp = (*iter);
			Safe_Delete(pTemp);

		}
		m_vChildren.clear();
	}


	//处理当前节点的父节点指针：将当前节点从父节点的孩子容器中移除
	EngineNode * pParent = getParent();
	std::vector<EngineNode *> vecTemp = pParent->getChildren();

	for (std::vector<EngineNode *>::iterator iter = vecTemp.begin();
		iter != vecTemp.end(); ++iter)
	{
		if ((*iter) == this)
		{
			vecTemp.erase(iter);
			break;
		}
	}
}

Size EngineNode::getContentSize()
{
	return Size(0, 0);
}
