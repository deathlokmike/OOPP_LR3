#pragma once
#include "framework.h"
class vehicleDrozdov: public CObject
{
protected:
	CString name;
	int year = 0;
	double strt_prc = 0;

public:
	DECLARE_SERIAL(vehicleDrozdov)
	vehicleDrozdov() {}
	virtual ~vehicleDrozdov() {}
	virtual void Serialize(CArchive& ar);
	virtual void StrLen(int* aLen, CDC* pDC);
	virtual void output(CDC* pDC, int* aLeft, int& top, int lineHeight);
};

template <typename T>
void check_menu(T& input, T min, T max)
{
	while (!(cin >> input) || (input > max) || (input < min))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "�������� ������" << endl;
	}
}
