#include "StdAfx.h"
#include "Sampe.h"


////////////////////////////////////////////////////////////////////////////////
// CSampe1
// 

IMP_RUNTIME_OBJ(CSampe1)

CSampe1::CSampe1()
{
	m_nValue = 100;
}

CSampe1::~CSampe1()
{
}

int CSampe1::GetValue()
{
	return m_nValue * 100;
}


////////////////////////////////////////////////////////////////////////////////
// CSampe2
// 

IMP_RUNTIME_OBJ(CSampe2)

CSampe2::CSampe2()
{
	m_nValue = 5;
}

CSampe2::~CSampe2()
{
}


////////////////////////////////////////////////////////////////////////////////
// CSampe3
// 

CSampe3::CSampe3()
{
	m_nValue = 77;
}

CSampe3::~CSampe3()
{
}
