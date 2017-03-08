#pragma once
#ifndef DirectX_Tools_H_							//DirectX ͷ�ļ���Lib�ļ�
#define DirectX_Tools_H_

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")

#include <d3dx9.h>
#pragma comment(lib,"d3dx9.lib")

#endif

#ifndef Windows_Tools_H_							//Windows ͷ�ļ���Lib�ļ�
#define Windows_Tools_H_

#include <windows.h>

#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#include <vector>									//C++����STL ͷ�ļ�
#include <string>
#include <map>
#endif

#ifndef Safe_Delete_Tools_							//��ȫ�ͷ�ģ��
#define Safe_Delete_Tools_

template<typename T>inline void Safe_Delete(T* &p)
{
	if (p)
	{
		delete p;
		p = NULL;
	}
}

template<typename T>inline void Safe_Delete_Array(T* &p)
{
	if (p)
	{
		delete[] p;
		p = NULL;
	}
}

template<typename T>inline void Safe_Release(T* &p)
{
	if (p)
	{
		p->Release();
		p = NULL;
	}
}

#endif

#ifndef Singleton_Tools_							//����ģʽ
#define Singleton_Tools_
#include <assert.h>									//����

template<typename T>class Singleton
{
public:
	static T* m_pSingleton;
public:
	Singleton()
	{
		assert(!m_pSingleton);
		m_pSingleton = static_cast<T*>(this);
	}
	~Singleton()
	{
		assert(m_pSingleton);
		m_pSingleton = NULL;
	}
	static T* GetSingletonPtr()
	{
		if (m_pSingleton != NULL)
			return m_pSingleton;
		m_pSingleton = new T();
		assert(m_pSingleton != NULL);
		return m_pSingleton;
	}
};

template<typename T>T* Singleton<T>::m_pSingleton = NULL;//��̬���Ա �������ⲿ��ʼ�� ��̬��Ա������������Ķ�����ĳ�����󣬾�̬��Ա����ֻ�洢һ�ݹ����ж�����

#endif

//��խ�ַ�������Ӧ
#ifdef UNICODE											//���ʹ��UNICODE�ַ���
#define STRRCHR wcsrchr
#define MEMCPY wmemcpy
#define STRING std::wstring								//string ӦΪ���ַ� wstring ��Ϊ��ȷ��ʾ���֣�
#else
#define STRRCHR strrchr
#define MEMCPY memcpy
#define STRING std::string
#endif

#ifndef	WinSize_Tools_									//�˹����������ô����С
#define WinSize_Tools_

struct Size 
{
	unsigned int m_iWidth;	//��� �������ص����
	unsigned int m_iHeight;	//�߶� �������ص����

	Size(){}
	Size(unsigned int _iWidth, unsigned int _iHeight)
	{
		m_iWidth = _iWidth;
		m_iHeight = _iHeight;
	}
};

inline Size SetSize(unsigned int _iWidth, unsigned int _iHeight)
{
	return Size(_iWidth, _iHeight);
}

#endif
