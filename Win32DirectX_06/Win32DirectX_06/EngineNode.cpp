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
}

EngineNode * EngineNode::Create()
{
	EngineNode * pNode = new EngineNode();
	if (pNode && pNode->Init())
	{
		
	}
	else
		Safe_Delete(pNode);

	return pNode;
}

bool EngineNode::Init()
{
	return true;
}

void EngineNode::Visit()
{
	//��ǰ�ڵ��ҵ���߼�
	if (getIsUpdate())
		Update();

	//���µ�ǰ�ڵ��������Ϣ
	//�ӽڵ���������任 = �ӽڵ�ı��ؾ���任 * ���ڵ���������任

	//--��ȡ�����屾�صľ���任--
	D3DXQUATERNION rota;
	D3DXMATRIX matRota;
	D3DXMatrixRotationYawPitchRoll(&matRota,
		m_vLocalRota.y, m_vLocalRota.x, m_vLocalRota.z);
	D3DXQuaternionRotationMatrix(&rota, &matRota);

	D3DXMatrixTransformation(
		&m_matLocal, &D3DXVECTOR3(0, 0, 0),
		NULL, &m_vLocalScale, &D3DXVECTOR3(0, 0, 0),
		&rota, &m_vLocalPos);

	if (!m_pParent)	//û�и��ڵ�
	{
		m_matWorld = m_matLocal;
	}
	else
	{
		this->m_matWorld = this->m_matLocal * m_pParent->getWorldMatrix();
	}


	//��Ⱦ
	Render();

	//�������ܴ��ڵ�������
	if (m_vChildren.size() > 0)
	{
		for (std::vector<EngineNode *>::iterator iter = m_vChildren.begin();
			iter != m_vChildren.end();++iter)
		{
			(*iter)->Visit();
		}
	}

}

void EngineNode::Update()
{

}

void EngineNode::Render()
{

}

void EngineNode::Exit()
{
	//����ǰ�ڵ���ӽڵ�
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


	//����ǰ�ڵ�ĸ��ڵ�ָ�룺����ǰ�ڵ�Ӹ��ڵ�ĺ����������Ƴ�
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
