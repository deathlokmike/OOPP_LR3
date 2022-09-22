#include "pch.h"
#include "Car.h"
IMPLEMENT_SERIAL(vehicleDrozdov, CObject, 0);

void vehicleDrozdov::StrLen(int* aLen, CDC* pDC)
{
	aLen[0] = pDC->GetTextExtent(name).cx;
	aLen[1] = pDC->GetTextExtent((CString)to_string(year).c_str()).cx;
	aLen[2] = pDC->GetTextExtent((CString)to_string(strt_prc).c_str()).cx;
}

void vehicleDrozdov::output(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	CString buf;
	pDC->TextOut(aLeft[0], top, name);
	pDC->TextOut(aLeft[1], top, (CString)to_string(year).c_str());
	pDC->TextOut(aLeft[2], top, (CString)to_string(strt_prc).c_str());
	top += lineHeight;
}

void vehicleDrozdov::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) 
	{
		ar << year;
		ar << strt_prc; 
		ar << name;
	}
	else
	{
		ar >> year;
		ar >> strt_prc;
		ar >> name;
	}
}
