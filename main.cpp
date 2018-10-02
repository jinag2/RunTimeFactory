// RunTimeFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sampe.h"


int main(int argc, char* argv[])
{
	IRunTimeObj* pSample1 = CRunTimeClsFactories::GetInstance().CreateInstance("CSampe1");
	IRunTimeObj* pSample2 = CRunTimeClsFactories::GetInstance().CreateInstance("CSampe2");

	printf("ClsName: %s, Value: %d\n", (char*)pSample1->GetClsName().c_str(), ((CSampe1*)pSample1)->GetValue());
	printf("ClsName: %s, Value: %d\n", (char*)pSample2->GetClsName().c_str(), ((CSampe2*)pSample2)->GetValue());
	return 0;
}

