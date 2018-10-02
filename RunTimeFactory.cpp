#include "StdAfx.h"
#include <assert.h>

#include "RunTimeFactory.h"

shared_ptr<CRunTimeClsFactories> CRunTimeClsFactories::m_spInstance = nullptr;

CRunTimeClsFactories& CRunTimeClsFactories::GetInstance()
{
	if (m_spInstance == nullptr)
	{
		struct MakeSharedEnabled : public CRunTimeClsFactories {};
		m_spInstance = make_shared<MakeSharedEnabled>();
	}

	return *m_spInstance;
}

CRunTimeClsFactories::CRunTimeClsFactories()
{
}

CRunTimeClsFactories::~CRunTimeClsFactories()
{
}

bool CRunTimeClsFactories::RegisterFactory(const string& strClsName, IRunTimeCreateFactory* pFactory)
{
	assert(pFactory);

	if (m_colFactories[strClsName] == nullptr)
	{
		m_colFactories[strClsName] = pFactory;
		return true;
	}
	else
	{
		assert(false);
		return false;
	}
}

IRunTimeObj* CRunTimeClsFactories::CreateInstance(const string& strClsName)
{
	IRunTimeCreateFactory* pFactory = m_colFactories[strClsName];
	if (pFactory)
	{
		return pFactory->Create();
	}
	else
	{
		return nullptr;
	}
}
