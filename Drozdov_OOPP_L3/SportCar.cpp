#include "pch.h"
#include "SportCar.h"

IMPLEMENT_SERIAL(SportCarDrozdov, vehicleDrozdov, VERSIONABLE_SCHEMA | 0);

void SportCarDrozdov::StrLen(int* aLen, CDC* pDC)
{
	vehicleDrozdov::StrLen(aLen, pDC);
	aLen[3] = pDC->GetTextExtent((CString)to_string(engine_power).c_str()).cx;
	aLen[4] = pDC->GetTextExtent((CString)to_string(torque).c_str()).cx;
}

void SportCarDrozdov::output(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	pDC->TextOut(aLeft[3], top, (CString)to_string(engine_power).c_str());
	pDC->TextOut(aLeft[4], top, (CString)to_string(torque).c_str());
	vehicleDrozdov::output(pDC, aLeft, top, lineHeight);
}

void SportCarDrozdov::Serialize(CArchive& ar)
{
	vehicleDrozdov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << engine_power;
		ar << torque;
	}
	else
	{
		ar >> engine_power;
		ar >> torque;
	}
}