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

bool CRunTimeClsFactories::_RegisterFactory(const string& strClsName, IRunTimeCreateFactory* pFactory)
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

IRunTimeObj* CRunTimeClsFactories::CreateInstance(const char* szClsName)
{
	if (szClsName == nullptr)
	{
		assert(false);
		return nullptr;
	}

	IRunTimeCreateFactory* pFactory = m_colFactories[string(szClsName)];
	if (pFactory)
	{
		return pFactory->Create();
	}
	else
	{
		return nullptr;
	}
}
