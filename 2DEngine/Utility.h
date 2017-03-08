#pragma once
#ifndef DirectX_Tools_H_							//DirectX 头文件与Lib文件
#define DirectX_Tools_H_

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")

#include <d3dx9.h>
#pragma comment(lib,"d3dx9.lib")

#endif

#ifndef Windows_Tools_H_							//Windows 头文件与Lib文件
#define Windows_Tools_H_

#include <windows.h>

#include <MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#include <vector>									//C++常用STL 头文件
#include <string>
#include <map>
#endif

#ifndef Safe_Delete_Tools_							//安全释放模板
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

#ifndef Singleton_Tools_							//单利模式
#define Singleton_Tools_
#include <assert.h>									//断言

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

template<typename T>T* Singleton<T>::m_pSingleton = NULL;//静态类成员 需在类外部初始化 静态成员是属于整个类的而不是某个对象，静态成员变量只存储一份供所有对象共用

#endif

//宽窄字符集自适应
#ifdef UNICODE											//如果使用UNICODE字符集
#define STRRCHR wcsrchr
#define MEMCPY wmemcpy
#define STRING std::wstring								//string 应为宽字符 wstring （为正确显示汉字）
#else
#define STRRCHR strrchr
#define MEMCPY memcpy
#define STRING std::string
#endif

#ifndef	WinSize_Tools_									//此工具用来设置窗体大小
#define WinSize_Tools_

struct Size 
{
	unsigned int m_iWidth;	//宽度 横向像素点个数
	unsigned int m_iHeight;	//高度 纵向像素点个数

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
