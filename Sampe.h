#pragma once
#include "RunTimeFactory.h"


////////////////////////////////////////////////////////////////////////////////
// CBaseSampe
// 

class CBaseSampe
{
public:
	CBaseSampe()					{ m_nValue = 0; }
	virtual ~CBaseSampe()			{}

	void SetValue(int nValue)		{ m_nValue = nValue; }
	virtual int GetValue()			{ return m_nValue; }

protected:
	int m_nValue;
};


////////////////////////////////////////////////////////////////////////////////
// CSampe1
// 

class CSampe1 : public CBaseSampe, public IRunTimeObj
{
public:
	CSampe1();
	virtual ~CSampe1();

	virtual int GetValue();

	USE_RUNTIME_OBJ(CSampe1)
};


////////////////////////////////////////////////////////////////////////////////
// CSampe2
// 

class CSampe2 : public CBaseSampe, public IRunTimeObj
{
public:
	CSampe2();
	virtual ~CSampe2();

	USE_RUNTIME_OBJ(CSampe2)
};


////////////////////////////////////////////////////////////////////////////////
// CSampe3
// 

class CSampe3 : public CBaseSampe
{
public:
	CSampe3();
	virtual ~CSampe3();
};
