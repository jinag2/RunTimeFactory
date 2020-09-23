/* 
  RunTimeFactory.h -- interface of a C++ dynamic create objects pattern

  Copyright (C) 2018 Chao-Hung Chiang

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
	 claim that you wrote the original software. If you use this software
	 in a product, an acknowledgment in the product documentation would be
	 appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
	 misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Chao-Hung Chiang       jinag2@gmail.com
*/

#pragma once

#include <string>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// IRunTimeObj
// 

class IRunTimeObj
{
public:
	virtual ~IRunTimeObj() {}
	virtual const string& GetClsName() = 0;
};


////////////////////////////////////////////////////////////////////////////////
// IRunTimeCreateFactory
// 

class IRunTimeCreateFactory
{
public:
	virtual ~IRunTimeCreateFactory() {}
	virtual IRunTimeObj* Create() = 0;
	virtual shared_ptr<IRunTimeObj> CreateSharePtr() = 0;
};


////////////////////////////////////////////////////////////////////////////////
// CRunTimeCreateFactory
// 

template <class T>
class CRunTimeCreateFactory: public IRunTimeCreateFactory
{
public:
	CRunTimeCreateFactory(const string& strClsName)	{ _Register(strClsName); }
	virtual ~CRunTimeCreateFactory()	{}

	virtual IRunTimeObj* Create() override						{ return dynamic_cast<IRunTimeObj*>(new T()); }
	virtual shared_ptr<IRunTimeObj> CreateSharePtr() override	{ return static_pointer_cast<IRunTimeObj>(make_shared<T>()); }

protected:
	void _Register(const string& strClsName)	{ CRunTimeClsFactories::GetInstance()._RegisterFactory(strClsName, this); }
};


////////////////////////////////////////////////////////////////////////////////
// CRunTimeClsFactories
// 

class CRunTimeClsFactories
{
public:
	static CRunTimeClsFactories& GetInstance();

	IRunTimeObj* CreateInstance(const char* szClsName);
	shared_ptr<IRunTimeObj> CreateSharePtrInstance(const char* szClsName);

protected:
	static shared_ptr<CRunTimeClsFactories> m_spInstance;

	map<string, IRunTimeCreateFactory*> m_colFactories;

	CRunTimeClsFactories()	{}
	bool _RegisterFactory(const string& strClsName, IRunTimeCreateFactory* pFactory);

	template <class T> friend class CRunTimeCreateFactory;
};


#define USE_RUNTIME_OBJ(class_name) \
public: \
	virtual const string& GetClsName(); \
protected: \
	static CRunTimeCreateFactory<class_name> m_aFactory; \
	static string m_strClsName;


#define IMP_RUNTIME_OBJ(class_name) \
	string class_name::m_strClsName = #class_name; \
	CRunTimeCreateFactory<class_name> class_name::m_aFactory(class_name::m_strClsName); \
	const string& class_name::GetClsName()			{ return class_name::m_strClsName; }
