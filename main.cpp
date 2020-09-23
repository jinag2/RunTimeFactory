// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sampe.h"


int main(int argc, char* argv[])
{
	IRunTimeObj* pSample1 = CRunTimeClsFactories::GetInstance().CreateInstance("CSampe1");
	if (pSample1)
	{
		printf("ClsName: %s, Value: %d\n", pSample1->GetClsName().c_str(), ((CSampe1*)pSample1)->GetValue());
		delete pSample1;
	}
	else
	{
		printf("Can not create CSample1.\n");
	}

	shared_ptr<CSampe1> spSample1 = static_pointer_cast<CSampe1>(CRunTimeClsFactories::GetInstance().CreateSharePtrInstance("CSampe1"));
	if (spSample1)
	{
		printf("ClsName: %s, Value: %d\n", spSample1->GetClsName().c_str(), spSample1->GetValue());
	}
	else
	{
		printf("Can not create CSample1.\n");
	}

	IRunTimeObj* pSample2 = CRunTimeClsFactories::GetInstance().CreateInstance("CSampe2");
	if (pSample2)
	{
		printf("ClsName: %s, Value: %d\n", (char*)pSample2->GetClsName().c_str(), ((CSampe2*)pSample2)->GetValue());
		delete pSample2;
	}
	else
	{
		printf("Can not create CSample2.\n");
	}

	IRunTimeObj* pSample3 = CRunTimeClsFactories::GetInstance().CreateInstance("CSampe3");
	if (pSample3)
	{
		printf("ClsName: %s, Value: %d\n", pSample3->GetClsName().c_str(), ((CSampe2*)pSample3)->GetValue());
		delete pSample3;
	}
	else
	{
		printf("Can not create CSample3.\n");
	}

	return 0;
}

