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
	virtual const string& GetClsName() = 0;
};


////////////////////////////////////////////////////////////////////////////////
// IRunTimeCreateFactory
// 

class IRunTimeCreateFactory
{
public:
	virtual IRunTimeObj* Create() = 0;
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

	virtual IRunTimeObj* Create()	{ return (IRunTimeObj*)(new T);}

protected:
	void _Register(const string& strClsName)	{ CRunTimeClsFactories::GetInstance().RegisterFactory(strClsName, this); }
};


////////////////////////////////////////////////////////////////////////////////
// CRunTimeClsFactories
// 

class CRunTimeClsFactories
{
public:
	static CRunTimeClsFactories& GetInstance();

	~CRunTimeClsFactories();

	bool RegisterFactory(const string& strClsName, IRunTimeCreateFactory* pFactory);
	IRunTimeObj* CreateInstance(const string& strClsName);

protected:
	static shared_ptr<CRunTimeClsFactories> m_spInstance;

	map<string, IRunTimeCreateFactory*> m_colFactories;

	CRunTimeClsFactories();
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
