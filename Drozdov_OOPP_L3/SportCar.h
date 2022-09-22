#pragma once
#include "Car.h"
class SportCarDrozdov : public vehicleDrozdov
{
	int engine_power = 0;
	int torque = 0;
public:
	DECLARE_SERIAL(SportCarDrozdov)
	SportCarDrozdov() {};
	virtual ~SportCarDrozdov() {};

	void StrLen(int* aLen, CDC* pDC) override;
	void output(CDC* pDC, int* aLeft, int& top, int lineHeight);
	void Serialize(CArchive& ar);
};

