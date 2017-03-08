#include <iostream>
using namespace std;

struct Student 
{
	int m_idata;
	Student * m_pNext;
};

Student * Create_List()
{
	Student * pHead, *pCur, *pNode;
	pHead = (Student *)malloc(sizeof(Student));
	if (!pHead)
	{
		cout << "Create pHead error..." << endl;
		return NULL;
	}
	pHead->m_idata = 0;
	pHead->m_pNext = NULL;

	int _idata = 0;
	cout << "Please input data:" << endl;
	cin >> _idata;

	pCur = pHead;

	while (_idata != 0)
	{
		pNode = (Student *)malloc(sizeof(Student));
		if (!pNode)
		{
			cout << "Create pNode error..." << endl;
			return NULL;
		}
		pNode->m_idata = _idata;
		pNode->m_pNext = NULL;

		pCur->m_pNext = pNode;
		pCur = pNode;
		cin >> _idata;
	}
	return pHead;
}

void Print_List(Student * _pHead)
{
	if (!_pHead)
	{
		cout << "_pHead == NULL error..." << endl;
	}
	Student * pTemp = _pHead->m_pNext;
	cout << "Begin:" << " ";
	while (pTemp)
	{
		cout << pTemp->m_idata << " ";
		pTemp = pTemp->m_pNext;
	}
	cout << ":End" << endl;

}

void InsertWithIndex_List(Student * _pHead, int _index, int _insertData)
{
	if (!_pHead)
	{
		cout << " _pHead == NULL ..." << endl;
	}
	Student * pTemp, *pCur, *pNode;
	pTemp = _pHead;
	pCur = pTemp->m_pNext;
	
	pNode = (Student *)malloc(sizeof(Student));
	if (!pNode)
	{
		cout << "Create pNode error..." << endl;
	}
	pNode->m_idata = _insertData;
	pNode->m_pNext = NULL;
	while (pCur)
	{
		if (pCur->m_idata == _index)
		{
			break;
		}
		pTemp = pCur;
		pCur = pTemp->m_pNext;
	}
	pNode->m_pNext = pTemp->m_pNext;
	pTemp->m_pNext = pNode;
}

void DeleteWithIndex_List(Student * _pHead, int _index)
{
	if (!_pHead)
	{
		cout << " _pHead == NULL ..." << endl;
	}

	Student * pTemp, *pCur;
	pTemp = _pHead;
	pCur = pTemp->m_pNext;

	while (pCur)
	{
		if (pCur->m_idata == _index)
		{
			break;
		}
		pTemp = pCur;
		pCur = pTemp->m_pNext;
	}
	if (pCur != NULL)
	{
		pTemp->m_pNext = pCur->m_pNext;
		free(pCur);
		cout << _index << " will be delete" << endl;
	}
	else
	{
		cout << _index << " not found" << endl;
	}
}
void Destroy_List(Student * _pHead)
{
	if (!_pHead)
	{
		cout << " _pHead == NULL ..." << endl;
	}
	Student * pTemp = NULL;

	while (_pHead)
	{
		pTemp = _pHead->m_pNext;
		free(_pHead);
		_pHead = pTemp;
	}
}


void main()
{
	Student * pHead = Create_List();
	Print_List(pHead);
	InsertWithIndex_List(pHead, 5, 4);
	Print_List(pHead);
	DeleteWithIndex_List(pHead, 3);
	Print_List(pHead);
	Destroy_List(pHead);
	system("pause");
}