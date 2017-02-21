#pragma once
#ifndef DirectX_Tools_H
#define DirectX_Tools_H

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")

#include <d3dx9.h>
#pragma comment(lib,"d3dx9.lib")

#endif

#ifndef Windows_Tools_H
#define Windows_Tools_H

#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#endif

#ifndef Safe_Delete_Tools_
#define Safe_Delete_Tools_
//new
template <typename T>inline void Safe_Delete(T* &p)
{
	if (p)
	{
		delete p;
		p = NULL;
	}
}
//new
template <typename T>inline void Safe_Delete_Array(T* &p)
{
	if (p)
	{
		delete[] p;
		p = NULL;
	}
}
//system create
template<typename T>inline void Safe_Release(T* &p)
{
	if (p)
	{
		p->Release();
		p = NULL;
	}
}

#endif

#ifndef CSingleton_Tools_		//singleton pattern
#define CSingleton_Tools_
#include <assert.h>				//���Ժ��� assert()

template <typename T> class Singleton
{
public:
	static T* m_Singleton;
public:
	Singleton()
	{
		assert(!m_Singleton);
		m_Singleton = static_cast<T*>(this);			//��ʼ��ʱ m_Singleton ֵΪNULL  �ж�m_Singleton�Ƿ���Ч �����Ч ��ת��Ϊ�����ָ��
	}
	~Singleton()
	{
		assert(m_Singleton);							
		m_Singleton = NULL;
	}
	static T* GetSingletonPtr()
	{
		if (m_Singleton != NULL)
			return m_Singleton;
		m_Singleton = new T();
		assert(m_Singleton != NULL);
		return m_Singleton;
	}
};

template <typename T>T* Singleton<T>::m_Singleton = NULL;	//��̬���Ա �������ⲿ��ʼ�� ��̬��Ա������������Ķ�����ĳ�����󣬾�̬��Ա����ֻ�洢һ�ݹ����ж�����

#endif

//��խ�ַ�������Ӧ
#ifdef UNICODE	
#define STRING std::wstring
#else	
#define STRING std::string
#endif

#ifndef WinSize_Tools_
#define WinSize_Tools_
//describe window size
struct Size 
{
	unsigned int width;
	unsigned int height;
	Size(){}
	Size(unsigned int _width, unsigned int _height)
	{
		width = _width;
		height = _height;
	}
};

inline Size SetSize(unsigned int _width, unsigned int _height)
{
	return Size(_width, _height);
}

#endif
